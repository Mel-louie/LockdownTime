/*#+/+/+/+/+/+/+/+/+/+/+/+/+/#
#    Escape the Mansion  	 #
#						     #
#       ©H GRAY 2021    	 #
#+/+/+/+/+/+/+/+/+/+/+/+/+/+#*/

#ifndef GAME_H
# define GAME_H

#include "../gbdk2020/include/gb/gb.h"
#include "../gbdk2020/include/gb/cgb.h"
#include "../gbdk2020/include/stdio.h"

#include "texts.h"
#include "tileset_font.h"
#include "titleScreen.h"
#include "titleMapScreen.h"
#include "tilemap_splashscreen.h"
#include "tileset_splashscreen.h"

// Values must be in the range 0-31! For example, CGB_PAL(31, 31, 31) is white, CGB_PAL(0, 0, 0) is black, and CGB_PAL(0, 31, 0) is green
#define	CGB_PAL(r, g, b) (((b) & 31) << 10 | ((g) & 31) << 5 | ((r) & 31))

void	title_screen(void);
void	splash_screen(void);
void	clear_title_screen(void);

/* @void	perform_delay_player(UINT8 time);	 */
/*												 */
/* number of sec before refresh the sreen, if not*/
/* , the moves will be too quick				 */
/* time: can adjust for how much loop it can be  */
/* slow; 										 */
void	perform_delay(UINT8 time);

/* @UINT8	perform_delay_(UINT8 time);			 */
/*												 */
/* number of sec OR a touch key before refresh	 */
/* the sreen, if not							 */			
/* , the moves will be too quick				 */
/* time: can adjust for how much loop it can be  */
/* slow; 										 */
UINT8	perform_delay_joypad(UINT8 time);

#endif