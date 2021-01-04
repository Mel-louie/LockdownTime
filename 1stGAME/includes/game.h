/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../lib/gbdk2020/include/gb/gb.h"
// #include "../lib/gbdk-n/include/gb/gb.h" // to build with gbdk-n
#include "tilemap_splashscreen.h"
#include "tileset_splashscreen.h"
#include "tilemap_home.h"
#include "tileset_home.h"
#include "tiles_player.h"
#include "tileset_screen.h"
#include "tilemap_screen.h"
#include "text.h"
#include "tileset_font.h"

/*
** FUNCTIONS
*/

UINT8	perform_delay(UINT8 time);
void	perform_delay_player(UINT8 time);

/* Maps */
void	init_map(void);

/* Player */
void	init_player(void);
void	game(void);
