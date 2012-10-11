/*
 *     libnnal
 *     Copyright (C) 2010 Davide Gessa
 * 
 * 	This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MLP_H
#define MLP_H

#include <math.h>
#include <mathf.h>

typedef struct mlp_neuron_p
{
	double value;
	double *weights;
	double bias;
	double delta;
} mlp_neuron_t;

typedef struct
{
	unsigned input_n;
	unsigned hidden_n;
	unsigned output_n;
	
	mlp_neuron_t *input;
	mlp_neuron_t *output;
	mlp_neuron_t *hidden;
	
	double learning_rate;

	double (*transf_func)(double);
	double (*transf_func_derivate)(double);
} mlp_neural_network_t;


mlp_neural_network_t *mlp_new(int *, int);
double mlp_back_propagate(mlp_neural_network_t *, double *, double *);
void mlp_set_learning_rate(mlp_neural_network_t *, double);
void mlp_delete(mlp_neural_network_t *);
void mlp_display(mlp_neural_network_t *, int, int);
int mlp_get_used_memory(mlp_neural_network_t *);
mlp_neural_network_t *mlp_load(char *);
int mlp_save(mlp_neural_network_t *, char *);
int mlp_execute(mlp_neural_network_t *, double *, double *);
int mlp_file_train(mlp_neural_network_t *, char *);

#endif
