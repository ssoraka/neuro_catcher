#include "header.h"



int main() {
	printf("Hello, World!\n");

	t_game game;

	game = init_game();

	run_one_game(&game);



	return 0;
}
