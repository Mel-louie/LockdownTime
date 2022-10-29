/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

const UINT8	BORDER[20] = {TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER,TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER, TEXT_CHAR_BORDER};
const UINT8	BLANK_LINE[20] = {TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE, TEXT_CHAR_SPACE};


void	show_message_box(UINT8 player_y) {
	UINT8	y;
	UINT16	y_start = (18 * 8) + 12;
	UINT8	y_end = ((18 * 8) + 12) - (5 * 8);

	move_win(7, y_start);
	SHOW_WIN;
	for (y = y_start ; y >= y_end ; y--) {
		move_win(7, y);
		wait_vbl_done();
	}
	if (player_y > y_end + 5) {
		move_sprite(0, 0, 0);
		move_sprite(1, 0 + 8, 0);
	}
}

void	hide_message_box(UINT8 player_x, UINT8 player_y) {
	UINT8	y;
	UINT16	y_start = (18 * 8) + 12;
	UINT8	y_end = ((18 * 8) + 12) - (5 * 8);

	move_win(7, y_start);
	for (y = y_end ; y <= y_start ; y++) {
		move_win(7, y);
		wait_vbl_done();
	}
	if (player_y > y_end + 5) {
		move_sprite(0, player_x, player_y);
		move_sprite(1, player_x + 8, player_y);
	}
	HIDE_WIN;
}

void	clear_message(void) {

	 set_win_tiles(0, 0, 21, 1, BORDER);
	 set_win_tiles(0, 1, 21, 1, BLANK_LINE);
	 set_win_tiles(0, 2, 21, 1, BLANK_LINE);
	 set_win_tiles(0, 3, 21, 1, BLANK_LINE);
	 set_win_tiles(0, 4, 21, 1, BLANK_LINE);
	 set_win_tiles(0, 5, 21, 1, BLANK_LINE);
}

void	show_message(unsigned char *str, UINT8 player_x, UINT8 player_y) {
	clear_message();
	show_message_box(player_y);

	UINT8 i = 0;
	UINT8 tmpX = 1;
	UINT8 tmpY = 1;
	UINT8 newline = 2;

	while (str[i]) {
		if (str[i] == '\n') {
			tmpY++;
			tmpX = 1;
			newline--;
		}
		else {
			text_putchar_win(tmpX, tmpY, str[i]);
			tmpX++;
		}
		if (!newline) {
			while (!(joypad() & J_A))
				wait_vbl_done();
			clear_message();
			tmpX = 1;
			tmpY = 1;
			newline = 2;
		}
		i++;
		perform_delay_player(2);
	}

	while (!(joypad() & J_A))
		wait_vbl_done();

	hide_message_box(player_x, player_y);
}