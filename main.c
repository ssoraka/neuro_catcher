#include "header.h"



int main() {
	printf("Hello, World!\n");

	t_game game;
	t_brain brain;
	t_layer layer[2];

	init_brain(&brain, layer, 2);
	init_layer(layer, N_HIDDEN, N_INPUT, SIMPLE);
	init_layer(layer + 1, DIR_COUNT, N_HIDDEN, SOFTMAX);
	game = init_game(&brain);

	//это написал нормально вроде
	run_one_game(&game, TRUE);

//	int eval = strategy_evaluation(&game);
	calculate_brain(&brain);
	teaching_brain(&brain);



	print_arr_double(game.g_story, MAP_H);
	print_arr_double(game.c_story, MAP_H);


	//надо ошибку последнего слоя получать из перекрестной энтропии
	//по награде среды агенту
	//was_game_winned(&game)
	//set_output(t_brain *brain, double *output)
	//set_pos_on_map(t_game *game)


	return 0;
}
