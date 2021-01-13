################
#    My 1st    #
#    GB GAME   #
#    MAKEFILE  #
################

SRC_DIR = ./src/

GAME = game.gb

PROG = game

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
#	@$(MAKE) -C $(SRC_DIR) # to compile with gbdk-n; or gbdk2020:
	@./lib/gbdk2020/bin/lcc -Wa-l -Wm-yc -Wl-m -Wl-j -o game.gb src/*.c
#	@echo $(_BLUE)"Copy "$(_YELLOW)$(GAME)$(_BLUE)" in the current directory..."$(_END)
#	@cp $(SRC_DIR)$(GAME) .
	@echo $(_GREEN)"Done!"$(_END)

clean:
	@echo $(_RED)"Cleaning in progress..."$(_END)
	@rm -rf game.map game.noi
	@echo $(_GREEN)"Cleaning done!"$(_END)
#	@make clean -C $(SRC_DIR)

fclean:	clean
	@rm -rf game.gb
	@echo $(_GREEN)"game.gb is delete!"$(_END)

re: clean all
