/**
 * Self Organization Map neural network
 */
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
#ifndef SOM_H
#define SOM_H

#include <math.h>
#include <mathf.h>
#include "mlp.h"

//typedef struct mlp_neuron_p som_neuron_p;
//typedef struct som_neuron_p som_neuron_t;

typedef struct som_neuron_p
{
	double value;
	double *weights;
	double bias;
	double delta;
} som_neuron_t;

typedef struct
{
	unsigned input_n;
	unsigned output_n;
	
	som_neuron_t *input;
	som_neuron_t *output;
	
	double learning_rate;

	double (*transf_func)(double);
	double (*transf_func_derivate)(double);
} som_neural_network_t;


som_neural_network_t *som_new(int, int);
int som_execute(som_neural_network_t *, double *, double *);
double som_train(som_neural_network_t *, double *);

#endif
