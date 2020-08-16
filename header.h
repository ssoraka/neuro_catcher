//
// Created by ssoraka on 15.08.2020.
//

#ifndef NEURO_KOKOHEN_HEADER_H
#define NEURO_KOKOHEN_HEADER_H


#include <string.h>
#include <stdio.h>
#include <time.h>
#include "math.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

#define LETTER_IN_STRING 15
#define STRING_COUNT 2
#define ANSWER_COUNT 30
#define LETTER_WIDTH 5
#define LETTER_HEIGHT 5
#define STRING_LEN (LETTER_IN_STRING * LETTER_WIDTH)


// Параметры НС
// высота карты
#define MAP_H 7
// ширина карты
#define MAP_W (MAP_H)
// Число входов,
#define N_POS (MAP_H * MAP_W)
#define N_INPUT (N_POS + MAP_W)
// Число нейронов в скрытом слое
#define N_HIDDEN (100)
// Число нейронов в скрытом слое
#define N_MAX_IN_LAYER (100)
// Скорость обучения
#define ALPHA 0.5
// Количество эпох обучения
#define LAST_ERA 7000

char g_letters[ANSWER_COUNT * LETTER_HEIGHT * LETTER_WIDTH];
double input[LETTER_IN_STRING * STRING_COUNT][N_INPUT];
char g_ru_letter[ANSWER_COUNT][5];

//структура слоя
typedef struct		s_layer
{
	//функция активации нейрона
	double			(*func)(double);
	//массив выходов нейронов (зарезервировал 100 на просто для удобства)
	double			f[N_MAX_IN_LAYER];
	//массив ошибок для нейронов слоя
	double			error[N_MAX_IN_LAYER];
	//количество нейронов в этом слое
	int				i_n;
	// количество нейронов в предыдущем слое
	int				j_n;
	// массив связей размером i_count * j_count (зарезервировал 10000 на просто для удобства)
	double			w_ij[N_MAX_IN_LAYER][N_MAX_IN_LAYER];
}					t_layer;

//структура слоя
typedef struct		s_brain
{
	double			*input;
	double			*output;
	//массив слоев нейронов
	t_layer			*layer;
	//количество слоев в массиве
	int				layers_count;
}					t_brain;

typedef struct		s_game
{
	//массив клеточек с флагами заполненности
	double			map[N_INPUT];
	double			weight[MAP_H];
	double			g_story[MAP_H];
	double			c_story[MAP_H];
	int				partition;
	int				gamer_pos;
	int				curr_pos;
	t_brain			*brain;
}					t_game;

typedef enum	e_direction
{
	DONT_MOVE,
	LEFT,
	RIGHT,
	DIR_COUNT
}				t_dir;

t_game	init_game(t_brain *brain);
void	set_new_current(t_game *game);
void	print_map(t_game game);
t_bool	move_current(t_game *game);
void	move_gamer(t_game *game, t_dir dir);
void	save_position(t_game *game);
void	run_one_game(t_game *game, t_bool need_print);

void	set_input(t_brain *brain, double *input);
void	set_output(t_brain *brain, double *output);
void	init_brain(t_brain *brain, t_layer *layer, int layer_count);
t_dir	get_dicision(t_brain *brain);
void	calculate_brain(t_brain *brain);

void	init_layer(t_layer *layer, int n_count, int w_n_count);

#endif //NEURO_KOKOHEN_HEADER_H
