/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../lib/gbdk-n/include/gb/gb.h"
#include "../includes/tilemap_bckgrnd.h"
#include "../includes/tileset_bckgrnd.h"
#include "../includes/player_sprites.h"
#include <stdio.h>

UINT8 player_pos[2];

void	perform_delay(UINT8 num_loops) {
	UINT8 i = 0;

	while (i++ < num_loops) {
		wait_vbl_done();
	}
}

UBYTE	can_player_move(UINT8 new_posx, UINT8 new_posy) {
	UINT16 top_left_x, top_left_y, tile_top_left;
	UBYTE res, i = 0;

	top_left_x = (new_posx - 8) / 8; // it's where there is the little collision imperfection
	top_left_y = (new_posy - 4) / 8; // fix atm, but am not satisfy, retry when i have my final sprite (and check pkmn)
	tile_top_left = 20 * top_left_y + top_left_x;

	res = TILEMAP[tile_top_left];

	if (res == 0x1D || res == 0x29 || res == 0x2A || res == 0x2B
		|| res == 0x2C || res == 0x45 || res == 0x46)
		res = 1;
	else
		res = 0;
	return (res);
}

void	moves(void) {
	if (joypad() & J_UP) {
		if ((can_player_move(player_pos[0], player_pos[1] - 8)) == 1
				&& (player_pos[1] - 4) >= 0 ) {
			player_pos[1] -= 4;
			move_sprite(0, player_pos[0], player_pos[1]);
		}
	}
	if (joypad() & J_DOWN) {
		if ((can_player_move(player_pos[0], player_pos[1] + 8)) == 1
				&& (player_pos[1] + 4) <= 144 ) {
			player_pos[1] += 4;
			move_sprite(0, player_pos[0], player_pos[1]);
		}
	}
	if (joypad() & J_LEFT) {
		if ((can_player_move(player_pos[0] - 12, player_pos[1])) == 1
				&& (player_pos[0] - 4) >= 8 ) {
			player_pos[0] -= 4;
			move_sprite(0, player_pos[0], player_pos[1]);
		}
	}
	if (joypad() & J_RIGHT) {
		if ((can_player_move(player_pos[0] + 8, player_pos[1])) == 1
				&& (player_pos[0] + 4) <= 160 ) {
			player_pos[0] += 4;
			move_sprite(0, player_pos[0], player_pos[1]);
		}
	}
	perform_delay(3);
}

int		main(void) {

	set_bkg_data(0, TILESET_TILE_COUNT, TILESET);
	set_bkg_tiles(0, 0, TILEMAP_WIDTH, TILEMAP_HEIGHT, TILEMAP);

	set_sprite_data(0, PLAYER_SPRITES2_TILE_COUNT, PLAYER_SPRITES2);
	set_sprite_tile(0, 0);
	SPRITES_8x16;

	player_pos[0] = 84;
	player_pos[1] = 78;

	move_sprite(0, player_pos[0], player_pos[1]);

	SHOW_BKG;
	SHOW_SPRITES;
	DISPLAY_ON;

	while (1) {
		moves();
	}
//	return (0);
}