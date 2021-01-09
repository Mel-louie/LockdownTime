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
#include "text.h"
#include "tileset_font.h"
#include "tiles_cat.h"
#include "tiles_player_one.h"
#include "tiles_png_one.h"
#include "tilemap_screen_new.h"
#include "tileset_screen_new.h"

/*
** FUNCTIONS
*/

UINT8	perform_delay(UINT8 time);
void	perform_delay_player(UINT8 time);
void	clear_title_screen(void);

/* Screens */
void	splash_screen(void);
void	title_screen(void);

/* Maps */
void	init_map(void);

/* Player */
void	init_game(void);
void	game(void);
void	interact(void);

/* Messages boxes */
void	show_message_box(void);
void	show_message(unsigned char *str);
