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
	perform_delay(60);  // ~ 1s

	// Fade-in
	BGP_REG = 0xff;
	perform_delay(15);
	BGP_REG = 0xfe;
	perform_delay(15);
	BGP_REG = 0xf9;
	perform_delay(15);
	BGP_REG = 0xe4;
	perform_delay(15);

	perform_delay(90);  // ~ 1.5s

	// Fade-out
	BGP_REG = 0xe4;
	perform_delay(15);
	BGP_REG = 0xf9;
	perform_delay(15);
	BGP_REG = 0xfe;
	perform_delay(15);
	BGP_REG = 0xff;
	perform_delay(15);

	perform_delay(60);
	HIDE_BKG;
}

void	home_screen(void) {
//
perform_delay(10);
BGP_REG = 0xfe;
perform_delay(15);
BGP_REG = 0xf9;
perform_delay(15);
BGP_REG = 0xe4; // puts back the PALETTE to its init point, very important to not have a forever with/black background

	set_bkg_data(0, TILESETSC_TILE_COUNT, TILESETSC);
	set_bkg_tiles(0, 0, TILEMAPSC_WIDTH, TILEMAPSC_HEIGHT, TILEMAPSC);
	SHOW_BKG;
}

void	main(void) {

	splash_screen();
//

perform_delay(10);
BGP_REG = 0xfe;
perform_delay(15);
BGP_REG = 0xf9;
perform_delay(15);
BGP_REG = 0xe4;
// del when home_screen() ok
//	home_screen();

	init_player();

	DISPLAY_ON; // ?

	while (1) {
		game();
	}
}
