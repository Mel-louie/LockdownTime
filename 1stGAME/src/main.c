/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

int		main(void) {

	init_player();

	DISPLAY_ON;

	while (1) {
		game();
	}
}
