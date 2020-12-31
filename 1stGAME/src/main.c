/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

#define WHITE	0
#define LIGHTGR	1
#define GREY	2
#define BLACK	3

#define PALETTE(c0, c1, c2, c3) c0 | c1 << 2 | c2 << 4 | c3 << 6

void	splash_screen(void) {

	set_bkg_data(0, TILESET_TILE_COUNTSP, TILESETSP);
	set_bkg_tiles(0, 0, TILEMAP_WIDTHSP, TILEMAP_HEIGHTSP, TILEMAPSP);
	SHOW_BKG;
	// Black screen (initial state)
	BGP_REG = PALETTE(BLACK, BLACK, BLACK, BLACK);
	perform_delay(60);  // ~ 1s

	// Fade-in
	BGP_REG = PALETTE(BLACK, BLACK, BLACK, BLACK);
	perform_delay(10);
	BGP_REG = PALETTE(GREY, BLACK, BLACK, BLACK);
	perform_delay(10);
	BGP_REG = PALETTE(LIGHTGR, GREY, BLACK, BLACK);
	perform_delay(10);
	BGP_REG = PALETTE(WHITE, LIGHTGR, GREY, BLACK);

	perform_delay(90);  // ~ 1.5s

	// Fade-out
	BGP_REG = PALETTE(WHITE, LIGHTGR, GREY, BLACK);
	perform_delay(10);
	BGP_REG = PALETTE(LIGHTGR, GREY, BLACK, BLACK);
	perform_delay(10);
	BGP_REG = PALETTE(GREY, BLACK, BLACK, BLACK);
	perform_delay(10);
	BGP_REG = PALETTE(BLACK, BLACK, BLACK, BLACK);
	perform_delay(10);

	perform_delay(60);
	HIDE_BKG;
}

void	home_screen(void) {

	BGP_REG = PALETTE(WHITE, LIGHTGR, GREY, BLACK); // puts back the PALETTE to its init point, very important to not have a forever with/black background

	set_bkg_data(0, TILESETSC_TILE_COUNT, TILESETSC);
	set_bkg_tiles(0, 0, TILEMAPSC_WIDTH, TILEMAPSC_HEIGHT, TILEMAPSC);
	SHOW_BKG;
}

void	main(void) {

	splash_screen();
BGP_REG = PALETTE(WHITE, LIGHTGR, GREY, BLACK); // del when home_screen() ok
	//home_screen();

	init_player();

	DISPLAY_ON; // ?

	while (1) {
		game();
	}
}
