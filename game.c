//
// Created by ssoraka on 15.08.2020.
//
#include "header.h"

void	save_position(t_game *game) {
	game->c_story[game->partition] = game->curr_pos;
	game->g_story[game->partition] = game->gamer_pos;
	game->a_story[game->partition] = game->action;
	game->partition++;
}

void	set_new_current(t_game *game) {
	game->partition = 0;
//	game->curr_pos = 1;//rand() % MAP_W;
	game->curr_pos = rand() % MAP_W;
}

void	fill_arr(double *arr, int count, double value) {
	int i;

	i = 0;
	while (i < count) {
		arr[i] = value;
		i++;
	}
}

t_game	init_game(t_brain *brain) {
	t_game game;
	int i;

	fill_arr(game.input, N_INPUT, 0.0);
	fill_arr(game.output, DIR_COUNT, 0.0);
	i = 0;
	while (i < STORE) {
		game.weight[i] = pow(0.95, (double)(STORE - i));
		i++;
	}
	game.gamer_pos = N_INPUT - MAP_W / 2 - 1;
	srand(time(NULL));
	game.curr_pos = -1;
	game.brain = brain;
	return (game);
}

void	print_line() {
	int i;

	i = -2;
	while (i < MAP_W) {
		printf("=");
		i++;
	}
	printf("\n");
}

void	print_map(t_game *game) {
	int n;

	print_line();

	n = 0;
	while (n < N_POS) {
		if (n % MAP_W == 0) {
			printf("|");
		}
		if (n == game->gamer_pos - MAP_W)
			printf("\033[7;37m%s\033[00m", "U");
		else if (n == game->curr_pos)
			printf("\033[7;37m%s\033[00m", "X");
		else
			printf(" ");

		if ((n + 1) % MAP_W == 0) {
			printf("|\n");
		}
		n++;
	}
	print_line();
	printf("\n");
}

void	prepare_buffer(t_game *game) {
	char *buffer;
	int i;

	buffer = game->buffer;
	i = 0;
	while(i < ((MAP_W + 2) * (STORE + 1) + 1) * (MAP_H + 2)) {
		int x = i % ((MAP_W + 2) * (STORE + 1) + 1);
		int y = i / ((MAP_W + 2) * (STORE + 1) + 1);

		if (x == (MAP_W + 2) * (STORE + 1) + 0)
			buffer[i] = '\n';
		else if (y == 0 || y == MAP_H + 1)
			buffer[i] = '=';
		else if (x % (MAP_W + 2) == 0 || x % (MAP_W + 2) == MAP_W + 1)
			buffer[i] = '|';
		else
			buffer[i] = ' ';
		i++;
	}
	buffer[((MAP_W + 2) * (STORE + 1) + 1) * (MAP_H + 2)] = '\0';
}

void	set_pos_in_buffer(t_game *game, int step) {
	char *buffer;
	int x;
	int y;

	buffer = game->buffer;

	x = (MAP_W + 2) * step + (game->curr_pos) % MAP_W + 1;
	y = game->curr_pos / MAP_W + 1;
	buffer[y * ((MAP_W + 2) * (STORE + 1) + 1) + x] = 'X';

	x = (MAP_W + 2) * step + (game->gamer_pos) % MAP_W + 1;
	y = game->gamer_pos / MAP_W;
	buffer[y * ((MAP_W + 2) * (STORE + 1) + 1) + x] = 'U';
}

t_bool	move_current(t_game *game) {
	if (game->curr_pos + MAP_W >= N_POS)
		return (FALSE);
	game->curr_pos += MAP_W;
	game->c_story[game->partition] = game->curr_pos;
	return (TRUE);
}

void	move_gamer(t_game *game, t_dir dir) {
	if (dir == DONT_MOVE || dir >= DIR_COUNT)
		return ;
	if (dir == LEFT && game->gamer_pos == N_INPUT - MAP_W)
		return ;
	if (dir == RIGHT && game->gamer_pos == N_INPUT - 1)
		return ;
	if (dir == LEFT)
		game->gamer_pos--;
	if (dir == RIGHT)
		game->gamer_pos++;
}

void	set_pos_on_map(t_game *game) {
	game->input[game->gamer_pos] = 1.0;
	game->input[game->curr_pos] = 1.0;
}
void	clear_map(t_game *game) {
	game->input[game->gamer_pos] = 0.0;
	game->input[game->curr_pos] = 0.0;
}
void	set_pos_on_map_from_store(t_game *game, int ex) {
	game->input[game->g_story[ex]] = 1.0;
	game->input[game->c_story[ex]] = 1.0;
	game->output[game->a_story[ex]] = 1.0 * game->reward * game->weight[ex];
}
void	clear_map_from_store(t_game *game, int ex) {
	game->input[game->g_story[ex]] = 0.0;
	game->input[game->c_story[ex]] = 0.0;
	game->output[game->a_story[ex]] = 0.0;
}

t_dir	make_dicision(t_game *game) {
	set_pos_on_map(game);
	set_input(game->brain, game->input);
	calculate_brain(game->brain);
	clear_map(game);
	return (get_dicision(game->brain));
}

void	run_one_game(t_game *game, t_bool need_print) {
	set_new_current(game);
	if (need_print){
		prepare_buffer(game);
		set_pos_in_buffer(game, 0);
	}
		//print_map(game);

	while(move_current(game)) {
		game->action = make_dicision(game);
		move_gamer(game, game->action);
		save_position(game);

		if (need_print)
			set_pos_in_buffer(game, game->partition);
	}
	if (need_print)
		printf("%s\n", game->buffer);
}

int		get_reward(t_game *game) {
	if (game->gamer_pos - MAP_W == game->curr_pos)
		return(1);
	return (-1);
}