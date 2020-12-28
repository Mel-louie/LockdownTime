/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

/*
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
}*/

int		main(void) {

	init_player();

	DISPLAY_ON;

	while (1) {
		moves();
	}
}
