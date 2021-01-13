/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

const UWORD palette_splash[] =
{
	CGB_PAL(31,31,24), CGB_PAL(0,20,25), CGB_PAL(0,10,13), CGB_PAL(10,0,10), // origin state: BGP_REG = 0xe4
	CGB_PAL(0,20,25), CGB_PAL(0,20,25), CGB_PAL(0,10,13), CGB_PAL(10,0,10), // BGP_REG = 0xf9
	CGB_PAL(0,10,13), CGB_PAL(0,10,13), CGB_PAL(0,10,13), CGB_PAL(10,0,10), // BGP_REG = 0xfe
	CGB_PAL(10,0,10), CGB_PAL(10,0,10), CGB_PAL(10,0,10), CGB_PAL(10,0,10), // BGP_REG = 0xff
};

void	splash_screen(void) {

	set_bkg_data(0, TILESET_TILE_COUNTSP, TILESETSP);
	set_bkg_tiles(0, 0, TILEMAP_WIDTHSP, TILEMAP_HEIGHTSP, TILEMAPSP);
	SHOW_BKG;
	// Black screen (initial state)
	BGP_REG = 0xFF;
	set_bkg_palette( 0, 1, &palette_splash[12] );
	perform_delay_player(60);  // ~ 1s

	// Fade-in
	BGP_REG = 0xff;
	set_bkg_palette( 0, 1, &palette_splash[12] );
	perform_delay_player(15);
	BGP_REG = 0xfe;
	set_bkg_palette( 0, 1, &palette_splash[8] );
	perform_delay_player(15);
	BGP_REG = 0xf9;
	set_bkg_palette( 0, 1, &palette_splash[4] );
	perform_delay_player(15);
	BGP_REG = 0xe4;
	set_bkg_palette( 0, 1, &palette_splash[0] );
	perform_delay_player(15);

	perform_delay_player(90);  // ~ 1.5s

	// Fade-out
	BGP_REG = 0xe4; // normal palette
	set_bkg_palette( 0, 1, &palette_splash[0] );
	perform_delay_player(15);
	BGP_REG = 0xf9;
	set_bkg_palette( 0, 1, &palette_splash[4] );
	perform_delay_player(15);
	BGP_REG = 0xfe;
	set_bkg_palette( 0, 1, &palette_splash[8] );
	perform_delay_player(15);
	BGP_REG = 0xff;
	set_bkg_palette( 0, 1, &palette_splash[12] );
	perform_delay_player(15);

	perform_delay_player(60);
	HIDE_BKG;
}

void	title_screen(void) {

	perform_delay_player(10);

/*	set_bkg_data(0, TILESETSC_TILE_COUNT, TILESETSC);
	set_bkg_tiles(0, 0, TILEMAPSC_WIDTH, TILEMAPSC_HEIGHT, TILEMAPSC);*/
	set_bkg_data(0, TILESETSC_NEW_TILE_COUNT, TILESETSC_NEW);
	set_bkg_tiles(0, 0, TILEMAPSC_NEW_WIDTH, TILEMAPSC_NEW_HEIGHT, TILEMAPSC_NEW);
	BGP_REG = 0xe4; // puts back the PALETTE to its init point, very important to not have a forever with/black background
	set_bkg_palette( 0, 1, &palette_splash[0] );
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
