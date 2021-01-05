/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

void	splash_screen(void) {

	set_bkg_data(0, TILESET_TILE_COUNTSP, TILESETSP);
	set_bkg_tiles(0, 0, TILEMAP_WIDTHSP, TILEMAP_HEIGHTSP, TILEMAPSP);
	SHOW_BKG;
	// Black screen (initial state)
	BGP_REG = 0xFF;
	perform_delay_player(60);  // ~ 1s

	// Fade-in
	BGP_REG = 0xff;
	perform_delay_player(15);
	BGP_REG = 0xfe;
	perform_delay_player(15);
	BGP_REG = 0xf9;
	perform_delay_player(15);
	BGP_REG = 0xe4;
	perform_delay_player(15);

	perform_delay_player(90);  // ~ 1.5s

	// Fade-out
	BGP_REG = 0xe4; // normal palette
	perform_delay_player(15);
	BGP_REG = 0xf9;
	perform_delay_player(15);
	BGP_REG = 0xfe;
	perform_delay_player(15);
	BGP_REG = 0xff;
	perform_delay_player(15);

	perform_delay_player(60);
	HIDE_BKG;
}

void	title_screen(void) {

	perform_delay_player(10);
	BGP_REG = 0xfe;
	perform_delay_player(25);
	BGP_REG = 0xf9;
	perform_delay_player(45);
	BGP_REG = 0xe4; // puts back the PALETTE to its init point, very important to not have a forever with/black background

	set_bkg_data(0, TILESETSC_TILE_COUNT, TILESETSC);
	set_bkg_tiles(0, 0, TILEMAPSC_WIDTH, TILEMAPSC_HEIGHT, TILEMAPSC);
	SHOW_BKG;

	// TEXT
	text_load_font(1);
	move_win(0, 16*8);
	text_putstr_win(0, 0, "     press start!    \n                     ");
	// show text
	SHOW_WIN;
	// blinking text
	while (1) {
		if (perform_delay(45))
			break ;
		HIDE_WIN;
		if (perform_delay(25))
			break ;
		SHOW_WIN;
	}
}
