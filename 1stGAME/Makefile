SRC_DIR = ./src/

GAME = game.gb

PROG = game

all:
	$(MAKE) -C $(SRC_DIR)
	cp $(SRC_DIR)$(GAME) .

clean:
	make clean -C $(SRC_DIR)

fclean:
	make clean -C $(SRC_DIR)
	rm -rf game.gb