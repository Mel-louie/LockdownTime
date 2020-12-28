/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

/* init 1st map*/
void	init_map(void) {
	// set the backgroud
	set_bkg_data(0, TILESET_TILE_COUNT, TILESET);
	set_bkg_tiles(0, 0, TILEMAP_WIDTH, TILEMAP_HEIGHT, TILEMAP);
	SHOW_BKG;
}