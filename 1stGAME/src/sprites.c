/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

// id ('nb' of move_sprite()) to the left side and the right side of the player 
#define PLAYER_SPRITE_L_ID 0
#define PLAYER_SPRITE_R_ID 1

void	init_player(sprites *pl) {

	pl->player_pos_world[0] = 5;
	pl->player_pos_world[1] = 4;
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

void	init_cat(sprites *cat) {

	cat->player_pos_world[0] = 12;
	cat->player_pos_world[1] = 3;
	cat->player_pos_screen[0] = cat->player_pos_world[0] * 8;
	cat->player_pos_screen[1] = cat->player_pos_world[1] * 8;
	cat->player_animation_frame = 0;
	cat->frame_skip = 6;
	set_sprite_data(38, CAT_TILE_COUNT, CAT);
	set_sprite_tile(3, 62);
	set_sprite_tile(4, 64);
	move_sprite(3, cat->player_pos_screen[0], cat->player_pos_screen[1]);
	move_sprite(4, cat->player_pos_screen[0] + 8, cat->player_pos_screen[1]);
}

void	init_png(sprites *rmt) {

	rmt->player_pos_world[0] = 17;
	rmt->player_pos_world[1] = 7;
	rmt->player_pos_screen[0] = rmt->player_pos_world[0] * 8;
	rmt->player_pos_screen[1] = rmt->player_pos_world[1] * 8;
	rmt->player_animation_frame = 0;
	rmt->frame_skip = 6;
	set_sprite_data(70, PNG_ONE_TILE_COUNT, PNG_ONE);
	set_sprite_tile(5, 70);
	set_sprite_tile(6, 72);
	move_sprite(5, rmt->player_pos_screen[0], rmt->player_pos_screen[1]);
	move_sprite(6, rmt->player_pos_screen[0] + 8, rmt->player_pos_screen[1]);
}

void	init_sprites(sprites *pl, sprites *cat, sprites *roomate) {

	pl->o = 1;
	init_player(pl);
	init_cat(cat);
	init_png(roomate);

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