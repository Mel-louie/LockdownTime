PROG = game

GBDK_N = ../lib/gbdk-n
CC = $(GBDK_N)/bin/gbdk-n-compile.sh
LD = $(GBDK_N)/bin/gbdk-n-link.sh
MR = $(GBDK_N)/bin/gbdk-n-make-rom.sh

_OBJ = $(patsubst %.c,%.rel,$(wildcard *.c))

.PHONY: gbdk-n

$(PROG).gb: $(_OBJ)
	@$(LD) -o $(PROG).ihx $^
	@$(MR) $(PROG).ihx $(PROG).gb

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
	@$(PROG).gb

%.rel: %.c
	@$(CC) -o $@ -c $<

gbdk-n:
	cd $(GBDK_N) && make

clean:
	@rm -rf *.rel *.lst *.sym *.asm *.o $(PROG).gb $(PROG).ihx \
	$(PROG).map $(PROG).sym $(PROG).noi $(PROG).lk
	@echo $(_RED)"Cleaning in progress..."$(_END)
	@echo $(_GREEN)"Cleaning done!"$(_END)

re:
	@clean all

#IMG2GB = img2gb

#assets:
#	$(IMG2GB) tileset \
#		--output-c-file=src/player.sprites.c \
#		--output-header-file=src/player.sprites.h \
#		--output-image=src/player.sprites.png \
#		--alternative-palette \
#		--sprite8x16 \
#		--name PLAYER_SPRITES \
#		./player.png
