/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

// id ('nb' of move_sprite()) to the left side and the right side of the player 
#define PLAYER_SPRITE_L_ID 0
#define PLAYER_SPRITE_R_ID 1

// datas to animate the player
UINT8 PLAYER_ANIMATION_SIDE[] = {24, 28, 24, 32};
UINT8 PLAYER_ANIMATION_UP[] = {12, 16, 12, 20};
UINT8 PLAYER_ANIMATION_DOWN[] = {0, 4, 0, 8};

// the numbers represent the byte where the
// sub-animation starts in the global data of the
// player
#define PLAYER_DIRECTION_DOWN	0
#define PLAYER_DIRECTION_UP		6
#define PLAYER_DIRECTION_RIGHT	12
#define PLAYER_DIRECTION_LEFT	18

// Player's state
UINT8 player_pos_screen[2];
UINT8 player_pos_world[2];
UINT8 player_direction;
UINT8 player_animation_frame;
UINT8 frame_skip = 4;

/* @UINT8	can_player_move(INT8 dx, INT8 dy);	 */
/*												 */
/* number of sec before refresh the sreen, if not*/
/* , the moves will be too quick				 */
/* time: can adjust for hoz much loop it can be  */
/* slow; 										 */

UINT8	can_player_move(INT8 dx, INT8 dy) {

// don't exit the screen
// ! it's not in pixel, but in square of the grid, one by one
	if ((player_pos_world[0] + dx < 1) ||
		(player_pos_world[0] + dx == 20) ||
		(player_pos_world[1] + dy == 19) ||
		(player_pos_world[1] + dy < 1))
		return (0);
	UINT8 cx = (player_pos_world[0] + dx) - 1;
	UINT8 cy = (player_pos_world[1] + dy) - 1;	// -1 or +1, it's a problem, we step on the left side of the furnitures
	UINT8 tile;
	get_bkg_tiles(cx, cy, 1, 1, &tile);
	return (tile == 0x1B || tile == 0x49 || tile == 0x4A ||	// return a tile where the player can walk
			tile == 0x29 || tile == 0x2A || tile == 0x27 ||
			tile == 0x28);
}

void	move_player(INT8 dx, INT8 dy) {

	if (!can_player_move(dx, dy))
		return;
	// init the new position of the player by adding the value of the move_player()
	player_pos_world[0] += dx;
	player_pos_world[1] += dy;

	for (UINT8 delta = 8 ; delta ; delta--) {	// moving 8 squares by 8 squares, maybe change in 16x16
	// move player
		player_pos_screen[0] += dx;
		player_pos_screen[1] += dy;
		move_sprite(PLAYER_SPRITE_L_ID, player_pos_screen[0], player_pos_screen[1]);
		move_sprite(PLAYER_SPRITE_R_ID, player_pos_screen[0] + 8, player_pos_screen[1]);
		perform_delay_player(1);

	// manage animation
		frame_skip -= 1;
		if (!frame_skip) {
			switch (player_direction) {
				case PLAYER_DIRECTION_UP :
					set_sprite_prop(0, get_sprite_prop(0) | S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
					set_sprite_tile(1, PLAYER_ANIMATION_UP[player_animation_frame]);
					set_sprite_tile(0, PLAYER_ANIMATION_UP[player_animation_frame] + 2);
					break;
				case PLAYER_DIRECTION_DOWN :
					set_sprite_prop(0, get_sprite_prop(0) | S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
					set_sprite_tile(1, PLAYER_ANIMATION_DOWN[player_animation_frame]);
					set_sprite_tile(0, PLAYER_ANIMATION_DOWN[player_animation_frame] + 2);
					break;
				case PLAYER_DIRECTION_LEFT:
					set_sprite_prop(0, get_sprite_prop(0) | S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
					set_sprite_tile(1, PLAYER_ANIMATION_SIDE[player_animation_frame]);
					set_sprite_tile(0, PLAYER_ANIMATION_SIDE[player_animation_frame] + 2);
					break;
				case PLAYER_DIRECTION_RIGHT:
					set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
					set_sprite_tile(0, PLAYER_ANIMATION_SIDE[player_animation_frame]);
					set_sprite_tile(1, PLAYER_ANIMATION_SIDE[player_animation_frame] + 2);
					break;
			}
			// to pass at the next sprite of the tileset
			player_animation_frame = (player_animation_frame + 1) % 4;
			frame_skip = 4;
		}
	}
}

void	game(void) {

	if (joypad() & J_UP) {
		player_direction = PLAYER_DIRECTION_UP;		// init the direction according to the joypad
			move_player(0, -1);						// increment or decrement the square of the grid where is the player,
	}												// here, -1 square on y;
	else if (joypad() & J_DOWN) {					// if chose if instead of else if: moving in diagonal
		player_direction = PLAYER_DIRECTION_DOWN;
			move_player(0, +1);
	}
	else if (joypad() & J_LEFT) {
		player_direction = PLAYER_DIRECTION_LEFT;
			move_player(-1, 0);
	}
	else if (joypad() & J_RIGHT) {
		player_direction = PLAYER_DIRECTION_RIGHT;
			move_player(+1, 0);
	}
}

void	init_player(void) {

	HIDE_BKG;
	init_map();
	// init the player
	OBP0_REG = OBP1_REG = 0xe2; // choosen colors
	player_pos_world[0] = 10;
	player_pos_world[1] = 9;
	player_pos_screen[0] = player_pos_world[0] * 8;
	player_pos_screen[1] = player_pos_world[1] * 8;
	player_direction = PLAYER_DIRECTION_DOWN;
	player_animation_frame = 0;

	// load tiles sprites in vidoe memory
	set_sprite_data(0, PLAYER_SPRITES1_TILE_COUNT, PLAYER_SPRITES1);
	set_sprite_tile(0, 0);
	// init the 2nd part of the player, 'cause the sprite is a metaSprite (16x16)
    set_sprite_tile(1, 2);
	SPRITES_8x16;
	set_sprite_prop(0, S_PALETTE);
	set_sprite_prop(1, S_PALETTE);
	SHOW_SPRITES;
	move_sprite(PLAYER_SPRITE_L_ID, player_pos_screen[0], player_pos_screen[1]);
	move_sprite(PLAYER_SPRITE_R_ID, player_pos_screen[0] + 8, player_pos_screen[1]);	
}
