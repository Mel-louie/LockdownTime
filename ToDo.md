# To do

:radio_button: to do; :ballot_box_with_check: OK; :exclamation: priority<br><br><br>

:exclamation::radio_button: add a title screen with a press start button to enter the game<br>
:radio_button: add a cat<br>
:radio_button: change player colors and hair + correction of the animation, test with the little gb<br>
:radio_button: add a roomate<br>
:radio_button: add a gif in this readme of the game/titlescreen<br>
:radio_button: adding some text and intercations with items<br>
:radio_button: adding sound<br><br>

:radio_button: exterior with a scroll (! the player moves with the screen limits)<br><br>

:ballot_box_with_check: splash screen with fadding palette<br>
:ballot_box_with_check: manage collisions with background<br>
:ballot_box_with_check: tidy up the files + comments<br>
:ballot_box_with_check: create and animate a real sprite <br>
:ballot_box_with_check: pimper les Makefile<br><br><br>


:green_book:<h3>random notes</h3>
To have the right shades of color for a sprite (black, gray, white, and light gray transparent):<br>
	- draw with WHITE for transparence, and LIGHT GREY for white;
	- convert to gb with img2gb ans this commande:
	img2gb tileset \
    --output-c-file=../src/tiles_player.c \
    --output-header-file=../includes/tiles_player.h \
    --output-image=./player.sprites.png \
    --sprite8x16 \
    --name PLAYER_SPRITES1 \
    ./player1.png
	- when init sprite, add this change fot default palettes: 'OBP0_REG = OBP1_REG = 0xe2';
	- can test other combinason
