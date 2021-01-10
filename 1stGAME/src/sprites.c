/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

// id ('nb' of move_sprite()) to the left side and the right side of the player 
#define PLAYER_SPRITE_L_ID 0
#define PLAYER_SPRITE_R_ID 1

void	init_player(sprites *pl) {

	pl->player_pos_world[0] = 10;
	pl->player_pos_world[1] = 9;
	pl->player_pos_screen[0] = pl->player_pos_world[0] * 8;
	pl->player_pos_screen[1] = pl->player_pos_world[1] * 8;
	pl->player_animation_frame = 0;
	pl->frame_skip = 6;

	// load tiles sprites in video memory
	set_sprite_data(0, PLAYER_ONE_TILE_COUNT, PLAYER_ONE);
	set_sprite_tile(0, 0);

	set_sprite_tile(1, 2);
	set_sprite_prop(0, S_PALETTE);
	set_sprite_prop(1, S_PALETTE);
	move_sprite(PLAYER_SPRITE_L_ID, pl->player_pos_screen[0], pl->player_pos_screen[1]);
	move_sprite(PLAYER_SPRITE_R_ID, pl->player_pos_screen[0] + 8, pl->player_pos_screen[1]);
}

void	init_sprites(sprites *pl) {

	pl->o = 1;
	init_player(pl);
	/*player_pos_world[0] = 10;
	player_pos_world[1] = 9;
	player_pos_screen[0] = player_pos_world[0] * 8;
	player_pos_screen[1] = player_pos_world[1] * 8;
	player_direction = PLAYER_DIRECTION_DOWN;
	player_animation_frame = 0;
	frame_skip = 6;*/

	// load tiles sprites in video memory
/*	set_sprite_data(0, PLAYER_SPRITES1_TILE_COUNT, PLAYER_SPRITES1);
	set_sprite_tile(0, 0);*/
/*	set_sprite_data(0, CAT_TILE_COUNT, CAT); // the player is a cat
	set_sprite_tile(0, 0);*/
/*	set_sprite_data(0, PLAYER_ONE_TILE_COUNT, PLAYER_ONE);
	set_sprite_tile(0, 0);*/
/*	set_sprite_data(0, PNG_ONE_TILE_COUNT, PNG_ONE);
	set_sprite_tile(0, 0);*/

	//   set_sprite_tile(1, 2);
/*	set_sprite_prop(0, S_PALETTE);
	set_sprite_prop(1, S_PALETTE);
	move_sprite(PLAYER_SPRITE_L_ID, player_pos_screen[0], player_pos_screen[1]);
	move_sprite(PLAYER_SPRITE_R_ID, player_pos_screen[0] + 8, player_pos_screen[1]);	*/
	
}