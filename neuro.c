//
// Created by ssoraka on 16.08.2020.
//
#include "header.h"

// Функция активации
double f(double x)
{
	double e_x;
	e_x = exp(-x);
	if (-1 == e_x)
		return (0.0);
	return (1 / (1 + e_x));
}

// Производная от функции активации
double df_dx(double fx)
{
	return (fx * (1 - fx));
}

void	init_layer(t_layer *layer, int n_count, int w_n_count) {
	int i;
	int j;

	layer->i_n = n_count;
	layer->j_n = w_n_count;
	layer->func = f;
	// Инициализация связей между входом НС и скрытым слоем случайными значениями
	srand(time(NULL));
	i = 0;
	while (i < n_count) {
		layer->f[i] = 0.0;
		layer->error[i] = 0.0;
		j = 0;
		while (j < w_n_count) {
			layer->w_ij[i][j] = ((double)rand()) / RAND_MAX;
			j++;
		}
		i++;
	}
}

void calculate_layer(double const *f_prev, t_layer *layer) {
	int i;
	int j;
	double sum;

	i = 0;
	while (i < layer->i_n) {
		sum = 0.0;
		j = 0;
		while (j < layer->j_n) {
			sum += layer->w_ij[i][j] * f_prev[j];
			j++;
		}
		layer->f[i] = layer->func(sum);
		i++;
	}
}



void calculate_out_error(double const *t, t_layer *layer) {
	int i;

	while (i < layer->i_n) {
		layer->error[i] = t[i] - layer->f[i];
		i++;
	}
}

void calculate_hidden_error(t_layer *next, t_layer *current) {
	int j;
	int i;

	j = 0;
	while (j < next->j_n) {
		current->error[j] = 0.0;
		i = 0;
		while (i < next->i_n) {
			current->error[j] += next->w_ij[i][j] * next->error[i];
			i++;
		}
		j++;
	}
}

void change_weight(double *f_prev, t_layer *layer) {
	int i;
	int j;
	int i_n;
	int j_n;

	i_n = layer->i_n;
	j_n = layer->j_n;
	i = 0;
	while (i < i_n) {
		j = 0;
		while (j < j_n) {
			layer->w_ij[i][j] += layer->error[i] * df_dx(layer->f[i]) * f_prev[j] * ALPHA;
			j++;
		}
		i++;
	}
}

void	print_arr_double(double *arr, int size) {
	int i;

	i = 0;
	while (i < size) {
		printf("%.4lf ", arr[i]);
		i++;
	}
	printf("\n");
}

void	set_input(t_brain *brain, double *input) {
	brain->input = input;
}
void	set_output(t_brain *brain, double *output) {
	brain->output = output;
}

t_dir	get_dicision(t_brain *brain) {
	int i;
	int max;
	t_layer *out;

	out = brain->layer + (brain->layers_count - 1);
	max = 0;
	i = 1;
	while (i < DIR_COUNT) {
		if (out->f[i] > out->f[max])
			max = i;
		i++;
	}
	return (max);
}

void	calculate_brain(t_brain *brain) {
	int i;
	double *f_prev;

	f_prev = brain->input;
	i = 0;
	while (i < brain->layers_count) {
		calculate_layer(f_prev, brain->layer + i);
		f_prev = brain->layer[i].f;
		i++;
	}
}

void	teaching_brain(t_brain *brain) {
	int i;
	double *f_prev;
	double *f_out;
	t_layer *out;

	//высчисляем ошибку последнего слоя
	out = brain->layer + (brain->layers_count - 1);
	f_out = brain->output;
	calculate_out_error(f_out, out);

	//высчисляем ошибку скрытых слоев
	i = brain->layers_count - 1;
	while (i > 0) {
		calculate_hidden_error(brain->layer + i, brain->layer + i - 1);
		i--;
	}

	//меняем веса связей
	f_prev = brain->input;
	i = 0;
	while (i < brain->layers_count) {
		change_weight(f_prev, brain->layer + i);
		f_prev = brain->layer[i].f;
		i++;
	}
}



