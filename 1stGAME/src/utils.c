/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

/* @void	perform_delay_player(UINT8 time);	 */
/*												 */
/* number of sec before refresh the sreen, if not*/
/* , the moves will be too quick				 */
/* time: can adjust for hoz much loop it can be  */
/* slow; 										 */

void	perform_delay_player(UINT8 time) {
	UINT8 i = 0;

	while (i++ < time) {
		wait_vbl_done();
	}
}

/* @UINT8	perform_delay_(UINT8 time);			 */
/*												 */
/* number of sec OR a touch key before refresh	 */
/* the sreen, if not							 */			
/* , the moves will be too quick				 */
/* time: can adjust for hoz much loop it can be  */
/* slow; 										 */

UINT8	perform_delay(UINT8 time) {
	UINT8 i = 0;
	UINT8 keys = 0;

	while (i++ < time) {
		keys = joypad();
		if (keys == J_START || keys == J_A)
			return (keys);
		wait_vbl_done();
	}
	return (0);
}

void	clear_title_screen(void) {

	perform_delay_player(15);
	BGP_REG = 0xf9;
	perform_delay_player(20);
	BGP_REG = 0xfe;
	perform_delay_player(25);
	BGP_REG = 0xff;
	perform_delay_player(30);
	BGP_REG = 0xe4;
	HIDE_WIN;
	HIDE_BKG;
}

void	sleep_animation(UINT8 player_x, UINT8 player_y) {

	HIDE_WIN;
	perform_delay_player(50);
	move_sprite(0, 0, 0);
	move_sprite(1, 0 + 8, 0);
	BGP_REG = 0xf9;
	perform_delay_player(50);
	BGP_REG = 0xfe;
	perform_delay_player(50);
	BGP_REG = 0xff;
	perform_delay_player(90);
	BGP_REG = 0xfe;
	perform_delay_player(50);
	BGP_REG = 0xf9;
	perform_delay_player(50);
	move_sprite(0, player_x, player_y);
	move_sprite(1, player_x + 8, player_y);	
	BGP_REG = 0xe4;
	SHOW_WIN;
}