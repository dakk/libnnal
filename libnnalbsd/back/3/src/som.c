/*
 *     libneuralnetwork
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
#include <mlp.h>
#include <som.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>


/**
 * Create new som network
 */
som_neural_network_t *som_new(int in, int out)
{
	unsigned i, j;
	som_neural_network_t *n = (som_neural_network_t *) malloc(sizeof(som_neural_network_t));
	
	if(n == NULL)
		return n;
			
	n->input_n = in;
	n->output_n = out;
	
	n->input = (som_neuron_t *) malloc(sizeof(som_neuron_t) * in);
	n->output = (som_neuron_t *) malloc(sizeof(som_neuron_t) * out);
	
	if((n->input == NULL) || (n->output == NULL))
	{
		if(n->input != NULL)
			free(n->input);
		if(n->output != NULL)
			free(n->output);
			
		free(n);
		return NULL;
	}
	
	n->learning_rate = 0.6;
	n->transf_func = &heavyside;
	n->transf_func_derivate = &heavyside_derivate;
	
	
	
	// Impostiamo i pesi random
 	srandom(time(NULL));

	for(i = 0; i < out; i++)
	{
		(n->output[i]).weights = (double *) malloc(sizeof(double) * in);
		
		if((n->output[i]).weights == NULL)
		{
			free(n->input);
			free(n->output);
			free(n);
			return NULL;
		}
		
		for(j = 0; j < in; j++)
			(n->output[i]).weights[j] = rand1();
	}

	
	for(i = 0; i < n->output_n; i++)
	{
		(n->output[i]).delta = rand1();
		(n->output[i]).bias = rand1()/1000;
	}
		
	for(i = 0; i < n->input_n; i++)
	{
		(n->input[i]).delta = rand1();
		(n->input[i]).bias = rand1()/1000;
	}
		
	return n;
}



/**
 * Execute som network with given data
 */
int som_execute(som_neural_network_t *n, double *input, double *output)
{
	unsigned i;
	unsigned j;
	double a;
	
	// Put input
	for(i = 0; i < n->input_n; i++)
	{
		(n->input[i]).value = input[i];
	}
	
	
	// Execute - output
	for(i = 0; i < n->output_n; i++)
	{
		a = 0.0;
		for(j = 0; j < n->input_n; j++)
			a += (n->output[i]).weights[j] * (n->input[j]).value;

		a += (n->output[i]).bias;
		
		(n->output[i]).value = n->transf_func(a);
	}
	
	// Get output
	for(i = 0; i < n->output_n; i++)
		output[i] = (n->output[i]).value;
}



/**
 * Train som network with given inputs
 */
double som_train(som_neural_network_t *som, double *in)
{
	return 0.0;
}
