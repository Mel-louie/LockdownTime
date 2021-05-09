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
	@./gbdk2020/bin/lcc -Wa-l -Wm-yc -Wl-m -Wl-j -o escapeTheMansion.gb src/*.c
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
