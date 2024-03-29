/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../lib/gbdk2020/include/gb/gb.h"
#include "../lib/gbdk2020/include/gb/cgb.h"
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

// Values must be in the range 0-31! For example, CGB_PAL(31,31,31) is white, CGB_PAL(0,0,0) is black, and CGB_PAL(0,31,0) is green.
#define CGB_PAL(r,g,b) (((b)&31)<<10 | ((g)&31)<<5 | ((r)&31))

// sprites's state
typedef struct	sprites
{
	UINT8	player_pos_screen[2];
	UINT8	player_pos_world[2];
	UINT8	player_direction;
	UINT8	player_animation_frame;
	UINT8	frame_skip;
	UBYTE	o;
}				sprites;

/*
** FUNCTIONS
*/

UINT8	perform_delay(UINT8 time);
void	perform_delay_player(UINT8 time);
void	clear_title_screen(void);
void	sleep_animation(sprites *pl, sprites *cat, sprites *roomate);

void	init_sprites(sprites *pl, sprites *cat, sprites *roomate);

/* Screens */
void	splash_screen(void);
void	title_screen(void);

/* Maps */
void	init_map(void);

/* Player */
void	init_game(void);
void	game(sprites *pl, sprites *cat, sprites *roomate);
void	interact(sprites *pl, sprites *cat, sprites *roomate);

/* Messages boxes */
void	show_message_box(UINT8 player_y);
void	show_message(unsigned char *str, UINT8 player_x, UINT8 player_y);
