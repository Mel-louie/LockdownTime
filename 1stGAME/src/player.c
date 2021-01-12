/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

// datas to animate the player
UINT8 PLAYER_ANIMATION_SIDE[] = {24, 28, 24, 32};
UINT8 PLAYER_ANIMATION_UP[] = {12, 16, 12, 20};
UINT8 PLAYER_ANIMATION_DOWN[] = {0, 4, 0, 8};

// the numbers represent the byte where the
// sub-animation starts in the global data of the
// player
#define PLAYER_DIRECTION_DOWN	0
#define PLAYER_DIRECTION_UP		1
#define PLAYER_DIRECTION_RIGHT	2
#define PLAYER_DIRECTION_LEFT	3

#include <stdio.h> // tests and debug

void	interact(sprites *pl, sprites *cat, sprites *roomate) {

	UINT8 cx = pl->player_pos_world[0];
	UINT8 cy = pl->player_pos_world[1];
	UINT8 tile;

	if (pl->player_direction == PLAYER_DIRECTION_RIGHT) {
		cx = cx + 1;
		cy = cy - 1;
	}
	else if (pl->player_direction == PLAYER_DIRECTION_DOWN) {
		cy = cy + 2;
	}
	else if (pl->player_direction == PLAYER_DIRECTION_UP) {
		cy = cy - 2;
	}
	else if (pl->player_direction == PLAYER_DIRECTION_LEFT) {
		cx = cx - 2;
		cy = cy - 1;
	}
		
	get_bkg_tiles(cx , cy , 1, 1, &tile);
	//	printf("cx %d    ", cx );	// tests and debug
	//	printf("cy %d    ", cy );
	//	printf("tile %d    ", tile);

	if (tile == 0x1d)
		show_message("C'est la gamelle\ndu chat.\nElle est vide...", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	else if (tile == 0x3d || tile == 0x3e || tile == 0x44 || tile == 0x45 || tile == 0x47 || tile == 0x48)
		show_message("La plante n'a pas\nl'air d'avoir soif.", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	else if (tile == 0x26 || tile == 0x21 || tile == 0x20)
		show_message("C'est une\nsuper nintendo.\nElle fait un\nbruit bizarre.", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	else if (tile == 0x1f)
		show_message("Le frigo est\npresque vide.\nJe devrais faire\ndes courses.", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	else if (tile == 0x42)
		show_message("Il y a un email :\n\'chers concitoyens,\nle confinement\ndurera encore\n42 jours\n\nBisous,\nle gouvernement\'", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	else if (tile == 0x40)
		show_message("Une douce\nmusique sort du\nposte de radio.\n", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	else if (tile == 22 || tile == 36) {
		show_message("Je vais faire\nune sieste...\n", pl->player_pos_screen[0], pl->player_pos_screen[1]);
		sleep_animation(pl, cat, roomate);
		show_message("Le temps\npasse lentement\ndurant le\nconfinement...\n", pl->player_pos_screen[0], pl->player_pos_screen[1]);
	}
}

/* @UINT8	can_player_move(INT8 dx, INT8 dy);	 */
/*												 */
/* number of sec before refresh the sreen, if not*/
/* , the moves will be too quick				 */
/* time: can adjust for hoz much loop it can be  */
/* slow; 										 */

UINT8	can_player_move(INT8 dx, INT8 dy, sprites *pl) {

	UINT8 cx = (pl->player_pos_world[0] + dx) - 1;
	UINT8 cy = (pl->player_pos_world[1] + dy) - 1;	// -1 or +1, it's a problem, we step on the left side of the furnitures
	UINT8 tile;
	get_bkg_tiles(cx, cy, 1, 1, &tile);
// don't exit the screen
// ! it's not in pixel, but in square of the grid, one by one
	if ((pl->player_pos_world[0] + dx < 1) ||
		(pl->player_pos_world[0] + dx == 20) ||
		(pl->player_pos_world[1] + dy == 19) ||
		(pl->player_pos_world[1] + dy < 1))
		return (0);

	return (tile == 0x1B || tile == 0x49 || tile == 0x4A ||	// return a tile where the player can walk
			tile == 0x29 || tile == 0x2A || tile == 0x27 ||
			tile == 0x28);
}

void	move_player(INT8 dx, INT8 dy, sprites *pl) {

	UBYTE flag = 0;
	if (!can_player_move(dx, dy, pl))
		flag = 1;

	// init the new position of the player by adding the value of the move_player()
	// if !flag, collision so no new pos but movement still
	if (!flag) {
		pl->player_pos_world[0] += dx;
		pl->player_pos_world[1] += dy;
	}
	for (UINT8 delta = 8 ; delta ; delta--) {	// moving 8 squares by 8 squares, maybe change in 16x16
	// move player
		if (!flag) {
			pl->player_pos_screen[0] += dx;
			pl->player_pos_screen[1] += dy;
		}
		move_sprite(0, pl->player_pos_screen[0], pl->player_pos_screen[1]);
		move_sprite(1, pl->player_pos_screen[0] + 8, pl->player_pos_screen[1]);
		perform_delay_player(1);

	// manage animation
		pl->frame_skip -= 1;
		if (!pl->frame_skip) {
			switch (pl->player_direction) {
				case PLAYER_DIRECTION_UP :
					set_sprite_prop(0, get_sprite_prop(0) | S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
					set_sprite_tile(1, PLAYER_ANIMATION_UP[pl->player_animation_frame]);
					set_sprite_tile(0, PLAYER_ANIMATION_UP[pl->player_animation_frame] + 2);
					break;
				case PLAYER_DIRECTION_DOWN :
					set_sprite_prop(0, get_sprite_prop(0) | S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
					set_sprite_tile(1, PLAYER_ANIMATION_DOWN[pl->player_animation_frame]);
					set_sprite_tile(0, PLAYER_ANIMATION_DOWN[pl->player_animation_frame] + 2);
					break;
				case PLAYER_DIRECTION_LEFT:
					set_sprite_prop(0, get_sprite_prop(0) | S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
					set_sprite_tile(1, PLAYER_ANIMATION_SIDE[pl->player_animation_frame]);
					set_sprite_tile(0, PLAYER_ANIMATION_SIDE[pl->player_animation_frame] + 2);
					break;
				case PLAYER_DIRECTION_RIGHT:
					set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
					set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
					set_sprite_tile(0, PLAYER_ANIMATION_SIDE[pl->player_animation_frame]);
					set_sprite_tile(1, PLAYER_ANIMATION_SIDE[pl->player_animation_frame] + 2);
					break;
			}
			can_player_move(0, 0, pl);
			// to pass at the next sprite of the tileset
			pl->player_animation_frame = (pl->player_animation_frame + 1) % 4;
			pl->frame_skip = 6;
		}
	}
}

void	game(sprites *pl, sprites *cat, sprites *roomate) {

	if (!pl->o)
		init_sprites(pl, cat, roomate);
//	pl->player_direction = PLAYER_DIRECTION_DOWN;
	if (joypad() & J_UP) {
		pl->player_direction = PLAYER_DIRECTION_UP;		// init the direction according to the joypad
			move_player(0, -1, pl);						// increment or decrement the square of the grid where is the player,
	}												// here, -1 square on y;
	else if (joypad() & J_DOWN) {					// if chose if instead of else if: moving in diagonal
		pl->player_direction = PLAYER_DIRECTION_DOWN;
			move_player(0, +1, pl);
	}
	else if (joypad() & J_LEFT) {
		pl->player_direction = PLAYER_DIRECTION_LEFT;
			move_player(-1, 0, pl);
	}
	else if (joypad() & J_RIGHT) {
		pl->player_direction = PLAYER_DIRECTION_RIGHT;
			move_player(+1, 0, pl);
	}
	if (joypad() & J_A) {
		interact(pl, cat, roomate);
	}
}

void	init_game(void) {

	HIDE_BKG;
	SHOW_SPRITES;
	init_map();
	text_load_font(0);
	// init the sprites palette
	OBP0_REG = OBP1_REG = 0xe2; // choosen colors
	SPRITES_8x16;
	SHOW_SPRITES;

	//show_message("Hello young player.\nPress A to scroll\nthe text.\nGreat ! :)");
}
