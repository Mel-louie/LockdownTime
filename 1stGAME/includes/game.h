/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../lib/gbdk-n/include/gb/gb.h"
#include "./tilemap_home.h"
#include "./tileset_home.h"
#include "./player1.h"

/*
** FUNCTIONS
*/

void	perform_delay(UINT8 num_loops);

/* MAPS */
void	init_map(void);

/* PLAYER */
void	init_player(void);
void	moves(void);