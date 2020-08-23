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

// Производная от функции активации
double dsoftmax_dsumm(double error)
{
	return (-error);
}

void	init_layer(t_layer *layer, int n_count, int w_n_count, t_type type) {
	int i;
	int j;

	layer->type = type;
	layer->i_n = n_count;
	layer->j_n = w_n_count;
	layer->func = f;
	// Инициализация связей между входом НС и скрытым слоем случайными значениями
	srand(time(NULL));
	i = 0;
	while (i < n_count) {
		layer->error[i] = 0.0;
		j = 0;
		while (j < w_n_count) {
			layer->w_ij[i][j] = ((double)rand()) / RAND_MAX;
			j++;
		}
		i++;
	}
	fill_arr(layer->f, n_count, 0.0);
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
//	print_arr_double(layer->f, layer->i_n);
}

void calculate_softmax_layer(double const *f_prev, t_layer *layer) {
	int i;
	int j;
	double sum;
	double sum_f;

	sum_f = 0;
	i = 0;
	while (i < layer->i_n) {
		sum = 0.0;
		j = 0;
		while (j < layer->j_n) {
			sum += layer->w_ij[i][j] * f_prev[j];
			j++;
		}
		layer->f[i] = exp(sum);
		sum_f += layer->f[i];
		i++;
	}
	i = 0;
	while (i < layer->i_n) {
		layer->f[i] /= sum_f;
		i++;
	}
//	print_arr_double(layer->f, layer->i_n);
}

void calculate_out_error(double const *t, t_layer *layer) {
	int i;

	i = 0;
	while (i < layer->i_n) {
		layer->error[i] = t[i];
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
			current->error[j] += next->f[i] - next->error[i];
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

void change_softmax_weight(double *f_prev, t_layer *layer) {
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
			layer->w_ij[i][j] += layer->error[i] * f_prev[j] * ALPHA;
			j++;
		}
		i++;
	}
}

void	print_layer_weight(t_layer *layer) {
	int i;

	if (layer->type == SOFTMAX)
		printf("softmax\n");
	if (layer->type == SIMPLE)
		printf("simple\n");
	i = 0;
	while ( i < layer->i_n) {
		int j = 0;
		while ( j < layer->j_n) {
			printf("%lf, ", layer->w_ij[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
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
void	print_arr_int(int *arr, int size) {
	int i;

	i = 0;
	while (i < size) {
		printf("%2d ", arr[i]);
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
void	init_brain(t_brain *brain, t_layer *layer, int layer_count) {
	brain->layer = layer;
	brain->layers_count = layer_count;
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
	t_layer *layer;

	f_prev = brain->input;
	layer = brain->layer;
	i = 0;
	while (i < brain->layers_count) {
		if (layer->type == SIMPLE)
			calculate_layer(f_prev, layer);
		if (layer->type == SOFTMAX)
			calculate_softmax_layer(f_prev, layer);
		f_prev = layer->f;
		layer++;
		i++;
	}
}

void	teaching_brain(t_brain *brain) {
	int i;
	double *f_prev;
	double *f_out;
	t_layer *out;
	t_layer *layer;

	//высчисляем ошибку последнего слоя
	out = brain->layer + (brain->layers_count - 1);
	f_out = brain->output;
	calculate_out_error(f_out, out);

	//высчисляем ошибку скрытых слоев
	layer = brain->layer;
	i = brain->layers_count - 1;
	while (i > 0) {
		calculate_hidden_error(layer, layer - 1);
		layer++;
		i--;
	}

	//меняем веса связей
	layer = brain->layer;
	f_prev = brain->input;
	i = 0;
	while (i < brain->layers_count) {
		if (layer->type == SIMPLE)
			change_weight(f_prev, layer);
		if (layer->type == SOFTMAX)
			change_softmax_weight(f_prev, layer);
		f_prev = layer->f;
		layer++;
		i++;
	}
}

