/*################*/
/*#    My 1st    #*/
/*#    GB GAME   #*/
/*################*/

#include "../includes/game.h"

/* @void	perform_delay_player(UINT8 time);			 */
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
