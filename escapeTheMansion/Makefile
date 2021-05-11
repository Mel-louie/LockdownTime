#*/*/*/*/*/*/*/*/*/*/*/*/*/#
#    Escape the Mansion    #
#						   #
#       ©H GRAY 2021       #
#*/*/*/*/*/*/*/*/*/*/*/*/*/#

SRC_DIR = ./src/

PROG = escapeTheMansion

################
#    COLORS    #
################

_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_VIOLET		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"

################
#   TARGETS    #
################

all:
	@echo $(_BLUE)"Building ... "$(_YELLOW)
	@./mod2gbt musics/mainTheme.mod song 2
	@./gbdk2020/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o src/main.o src/main.c
	@./gbdk2020/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o output.o output.c
	@./gbdk2020/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o gbt_player.o gbt_player.s
	@./gbdk2020/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o gbt_player_bank1.o gbt_player_bank1.s

	@./gbdk2020/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wl-yt1 -Wl-yo4 -Wl-ya0 -o test.gb src/main.o output.o gbt_player.o gbt_player_bank1.o


	cp escapeTheMansion.gb escapeTheMansion/rom/game.gb
	@echo $(_GREEN)"Done!"$(_END)

clean:
	@echo $(_RED)"Cleaning in progress..."$(_END)
	@rm -rf escapeTheMansion.map escapeTheMansion.noi
	@echo $(_GREEN)"Cleaning done!"$(_END)
#	@make clean -C $(SRC_DIR)

fclean:	clean
	@rm -rf escapeTheMansion.gb
	@echo $(_GREEN)"escapeTheMansion.gb is delete!"$(_END)

re: clean all
