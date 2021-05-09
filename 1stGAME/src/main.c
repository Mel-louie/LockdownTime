/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

const UWORD palette_table[] =
{
  CGB_PAL(31,31,31), CGB_PAL(24,24,24), CGB_PAL(16,16,16), CGB_PAL(8,8,8),    /* Grays */ //0
  CGB_PAL(31,31,24), CGB_PAL(0,22,25), CGB_PAL(0,12,13), CGB_PAL(10,0,10),    //4
  CGB_PAL(0,20,25), CGB_PAL(31,31,24),  CGB_PAL(0,10,13), CGB_PAL(10,0,10),	//8
  CGB_PAL(0,0,0), CGB_PAL(31,26,26),  CGB_PAL(20,0,20), CGB_PAL(10,0,10),	//12
  CGB_PAL(31,31,1),  CGB_PAL(24,24,1),  CGB_PAL(16,16,1),  CGB_PAL(8,8,1),  /* Yellows */ //16
  CGB_PAL(27,31,27),  CGB_PAL(19,29,15),  CGB_PAL(9,16,16),  CGB_PAL(5,7,5), //sweet green  //20
  CGB_PAL(27,31,27),  CGB_PAL(27,31,27),  CGB_PAL(9,16,16),  CGB_PAL(5,7,5), //sweet green sprites  //24
};

void	sound(void) {
	// the registers should be init in this order
	NR52_REG = 0x80; // 1000 0000 in binary, turns on the sound
	NR50_REG = 0x77; // sets the volum to left and right channels, to the max 0x77
	NR51_REG = 0xff; // 1111 1111 select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels
}

void	main(void) {

	sound();

	set_bkg_palette( 0, 1, &palette_table[20] );
	set_sprite_palette( 0, 1, &palette_table[24] );

	splash_screen();
//	HIDE_BKG;
	title_screen();
	clear_title_screen();

	sprites	pl;
	sprites	cat;
	sprites roomate;

	pl.o = 0;
	init_game();
	while (1) {
		game(&pl, &cat, &roomate);
	}
}
