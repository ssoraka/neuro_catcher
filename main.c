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

	set_input(&brain, game.input);
	set_output(&brain, game.output);
	//это написал нормально вроде
	//run_one_game(&game, TRUE);

//	int eval = get_reward(&game);
	int example;
	int ep;

	ep = 0;
	while (ep < 1000) {
		//проиграли игру, получили историю
		run_one_game(&game, FALSE);
		//определили награду
		game.reward = get_reward(&game);
		//теперь для каждого случая истории оучаем
		example = 0;
		while (example < MAP_H) {
			//восстанавливаем
			set_pos_on_map_from_store(&game, example);
			calculate_brain(&brain);
			teaching_brain(&brain);

			clear_map_from_store(&game, example);
			example++;
		}
		ep++;
	}

	run_one_game(&game, TRUE);

	print_arr_int(game.g_story, MAP_H);
	print_arr_int(game.c_story, MAP_H);


	//надо ошибку последнего слоя получать из перекрестной энтропии
	//по награде среды агенту
	//was_game_winned(&game)
	//set_output(t_brain *brain, double *output)
	//set_pos_on_map(t_game *game)


	return 0;
}
