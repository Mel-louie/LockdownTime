/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

// id ('nb' of move_sprite()) to the left side and the right side of the player 
//#define PLAYER_SPRITE_L_ID 0
//#define PLAYER_SPRITE_R_ID 1

// datas to animate the player
UINT8 PLAYER_ANIMATION_SIDE[] = {24, 28, 24, 32};
UINT8 PLAYER_ANIMATION_UP[] = {12, 16, 12, 20};
UINT8 PLAYER_ANIMATION_DOWN[] = {0, 4, 0, 8};

// Liste des sous-animation (les nombre représentent l'octet où la
// sous-animation commence dans les données globales de l'animation du
// joueur)
#define PLAYER_DIRECTION_DOWN	0
#define PLAYER_DIRECTION_UP		6
#define PLAYER_DIRECTION_RIGHT	12
#define PLAYER_DIRECTION_LEFT	18

// Player's state
UINT8 player_pos[2];
UINT8 player_direction;
UINT8 player_animation_frame;
UINT8 is_player_walking;
UINT8 frame_skip = 8;

void	perform_delay(UINT8 num_loops) {
	UINT8 i = 0;

	while (i++ < num_loops) {
		wait_vbl_done();
	}
}

void	move_player(INT8 dx, INT8 dy) {
//	if (!can_player_move(dx, dy))
//		return;
	player_pos[0] += dx;
	player_pos[1] += dy;
	move_sprite(0, player_pos[0], player_pos[1]);
	move_sprite(1, player_pos[0] + 8, player_pos[1]);

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
		player_animation_frame = (player_animation_frame + 1) % 4;
		frame_skip = 8;
	}
}

void	moves(void) {
	// update the animation every 8 frames, otherwise the animation will be to quick 
	if (joypad() & J_UP) {
		player_direction = PLAYER_DIRECTION_UP;
		move_player(0, -1);
	}
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
	perform_delay(1);
}


void	init_player(void) {

	init_map();
	// init the player
	player_pos[0] = 84;
	player_pos[1] = 78;
	player_direction = PLAYER_DIRECTION_DOWN;
	player_animation_frame = 0;
	is_player_walking = 0;

	// load tiles sprites in vidoe memory
	set_sprite_data(0, PLAYER_SPRITES1_TILE_COUNT, PLAYER_SPRITES1);
	set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
	// init the 2 sprites which are the player
	SPRITES_8x16;
	set_sprite_prop(0, S_PALETTE);
	set_sprite_prop(1, S_PALETTE);
	SHOW_SPRITES;
	move_sprite(0, player_pos[0], player_pos[1]);
	move_sprite(1, player_pos[0] + 8, player_pos[1]);	
}
