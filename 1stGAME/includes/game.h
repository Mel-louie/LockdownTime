/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../lib/gbdk-n/include/gb/gb.h"
#include "./tilemap_home.h"
#include "./tileset_home.h"
#include "./tiles_player.h"

/*
** FUNCTIONS
*/

void	perform_delay(UINT8 num_loops);

/* Maps */
void	init_map(void);

/* Player */
void	init_player(void);
void	game(void);
