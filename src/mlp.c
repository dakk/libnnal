/**
 * Multi Layered Perceptons neural network
 * 
 * \file mlp.c
 * \author Davide Gessa
 * \date 13-04-2010
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
#include <mlp.h>
#include <malloc.h>
#include <mathf.h>
#include <pthread.h>
#include <config.h>


/**
 * Create a feed foward multi layered perceptons neural network
 *  
 * \param in input neurons
 * \param hi hidden neurons
 * \param out output neurons
 * 
 * \return pointer to the network
 */
mlp_neural_network_t *
mlp_new(int *layers, int nlayers)
{
	unsigned i, j;
	mlp_neural_network_t *n = (mlp_neural_network_t *) malloc(sizeof(mlp_neural_network_t));
	
	if(n == NULL)
		return n;
	
	int in = layers[0];
	int hi = layers[1];
	int out = layers[2];
	
	n->input_n = in;
	n->hidden_n = hi;
	n->output_n = out;
	
	n->input = (mlp_neuron_t *) malloc(sizeof(mlp_neuron_t) * in);
	n->hidden = (mlp_neuron_t *) malloc(sizeof(mlp_neuron_t) * hi);
	n->output = (mlp_neuron_t *) malloc(sizeof(mlp_neuron_t) * out);
	
	if((n->input == NULL) || (n->hidden == NULL) || (n->output == NULL))
	{
		if(n->input != NULL)
			free(n->input);
		if(n->hidden != NULL)
			free(n->hidden);
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
		(n->output[i]).weights = (double *) malloc(sizeof(double) * hi);
		
		if((n->output[i]).weights == NULL)
		{
			free(n->input);
			free(n->hidden);
			free(n->output);
			free(n);
			return NULL;
		}
		
		for(j = 0; j < hi; j++)
			(n->output[i]).weights[j] = rand1();
	}

	for(i = 0; i < hi; i++)
	{
		(n->hidden[i]).weights = (double *) malloc(sizeof(double) * in);

		if((n->hidden[i]).weights == NULL)
		{
			free((n->output[i]).weights);
			free(n->input);
			free(n->hidden);
			free(n->output);
			free(n);
			return NULL;
		}

		for(j = 0; j < in; j++)
			(n->hidden[i]).weights[j] = rand1();
	}
	
	
	
	for(i = 0; i < n->hidden_n; i++)
	{
		(n->hidden[i]).delta = rand1();
		(n->hidden[i]).bias = rand1()/1000;
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
 * Delete a neural network
 */
void
mlp_delete(mlp_neural_network_t *n)
{
	unsigned i;

	for(i = 0; i < n->hidden_n; i++)
		free((n->hidden[i]).weights);

	for(i = 0; i < n->output_n; i++)
		free((n->output[i]).weights);

	free(n->input);
	free(n->hidden);
	free(n->output);
	free(n);
}



/**
 * Back propagate learning from file
 */
int mlp_file_train(mlp_neural_network_t *n, char *file)
{
	int i;
	FILE *f = fopen(file, "r");
	char line[2048];
	double *output = (double *) malloc(sizeof(double) * n->output_n);
	double *input = (double *) malloc(sizeof(double) * n->input_n);
	
	if(f == NULL)
		return -1;
		
		
	while(!feof(f))
	{
		fscanf(f, "%s", line);
	
		for(i = 0; i < n->input_n; i++)
		{
			sscanf(line, "%lf", &input[i]);
		}
		
		for(i = 0; i < n->output_n; i++)
		{
			sscanf(line, "%lf", &output[i]);
		}
		
		mlp_back_propagate(n, input, output);
	}

	fclose(f);
}


/**
 * Back propagate learning
 */
double 
mlp_back_propagate(mlp_neural_network_t *n, double *input, double *doutput)
{
	unsigned i;
	unsigned j;
	unsigned k;
	double *output = (double *) malloc(sizeof(double) * n->output_n);
	double error;
	
	// Eseguiamo la rete con i dati dell'insegnamento
	mlp_execute(n, input, output);
	
	
	#ifdef CUDA_SUPPORT
	/* Cuda support */
	#endif
	
	#ifndef CUDA_SUPPORT
	#ifdef OPENCL_SUPPORT
	/* OpenCL support */
	#endif
	
	#ifndef OPENCL_SUPPORT
	// printf("Desidered: %lf\tOutput: %lf\n", doutput[0], output[0]);
	
	// Calcoliamo l'errore dell'output
	for(i = 0; i < n->output_n; i++)
	{
		error = doutput[i] - output[i];
		(n->output[i]).delta = error * n->transf_func_derivate((n->output[i]).value);
	} 
	
	// Calcoliamo l'errore dell'hidden
 	for(j = 0; j < n->hidden_n; j++)
 	{
		error = 0.0;
		for(k = 0; k < n->output_n; k++)
		{
			error += (n->output[k]).delta * (n->output[k]).weights[j];
		}
		(n->hidden[j]).delta = error * n->transf_func_derivate((n->hidden[j]).value);
	} 
	

	// Aggiorna i pesi dello strato di output
	for(j = 0; j < n->output_n; j++)
	{
		for(k = 0; k < n->hidden_n; k++)
			(n->output[j]).weights[k] += n->learning_rate * (n->output[j]).delta * (n->hidden[k]).value;
		(n->output[j]).bias += n->learning_rate * (n->output[j]).delta;
	}
	
	// Aggiorna i pesi dello strato hidden
	for(j = 0; j < n->hidden_n; j++)
	{
		for(k = 0; k < n->input_n; k++)
			(n->hidden[j]).weights[k] += n->learning_rate * (n->hidden[j]).delta * (n->input[k]).value;
		(n->hidden[j]).bias += n->learning_rate * (n->hidden[j]).delta;
	}
	
	// Calcoliamo l'errore
	error = 0.0;
	for(i = 0; i < n->output_n; i++)
		error = error + 0.5 * (output[i] - n->output[i].value) * (output[i] - n->output[i].value);

	#endif
	#endif
		
	return error;
}



/**
 * Set the learning rate
 */
void 
mlp_set_learning_rate(mlp_neural_network_t *n, double lr) 
{ 	
	n->learning_rate = lr;
}






/**
 * Load the neural network from a file
 */
mlp_neural_network_t * 
mlp_load(char *path) 
{ 	
	FILE *f;
	unsigned i, k;
	
	f = fopen(path, "rb");
	
	if(f == NULL)
		return NULL;
	
	int nnum[3];

	// Load layers neurons number
	fread(&nnum[0], sizeof(unsigned), 1, f);
	fread(&nnum[1], sizeof(unsigned), 1, f);
	fread(&nnum[2], sizeof(unsigned), 1, f);
	
	mlp_neural_network_t *n = mlp_new(nnum, 3);
	fread(&n->learning_rate, sizeof(n->learning_rate), 1, f);
	

	// Load all layers neuron - weights
	for(i = 0; i < n->input_n; i++)
		fread(&n->input[i], sizeof(mlp_neuron_t), 1, f);

	mlp_neuron_t tmp;
	
	for(i = 0; i < n->hidden_n; i++)
	{
		fread(&tmp, sizeof(mlp_neuron_t), 1, f);
		
		(n->hidden[i]).bias = tmp.bias;
		(n->hidden[i]).delta = tmp.delta;
		(n->hidden[i]).value = tmp.value;
		
		for(k = 0; k < n->input_n; k++)
			fread(&(n->hidden[i]).weights[k], sizeof(double), 1, f);
	}
	
	for(i = 0; i < n->output_n; i++)
	{
		fread(&tmp, sizeof(mlp_neuron_t), 1, f);
		
		(n->output[i]).bias = tmp.bias;
		(n->output[i]).delta = tmp.delta;
		(n->output[i]).value = tmp.value;
		
		for(k = 0; k < n->hidden_n; k++)
			fread(&(n->output[i]).weights[k], sizeof(double), 1, f);
	}	
	
	fclose(f);	
	
	return n;	
}




/**
 * Save the neural network in a file
 */
int 
mlp_save(mlp_neural_network_t *n, char *path) 
{ 	
	FILE *f;
	unsigned i, k;
	
	f = fopen(path, "wb");
	
	if(f == NULL)
		return 0;

	// Save layers neurons number
	fwrite(&n->input_n, sizeof(n->input_n), 1, f);
	fwrite(&n->hidden_n, sizeof(n->input_n), 1, f);
	fwrite(&n->output_n, sizeof(n->input_n), 1, f);
	fwrite(&n->learning_rate, sizeof(n->learning_rate), 1, f);
	
	// Save all layers neuron - weights
	for(i = 0; i < n->input_n; i++)
		fwrite(&n->input[i], sizeof(mlp_neuron_t), 1, f);

	for(i = 0; i < n->hidden_n; i++)
	{
		fwrite(&n->hidden[i], sizeof(mlp_neuron_t), 1, f);
		
		for(k = 0; k < n->input_n; k++)
			fwrite(&(n->hidden[i]).weights[k], sizeof(double), 1, f);
	}

	for(i = 0; i < n->output_n; i++)
	{
		fwrite(&n->output[i], sizeof(mlp_neuron_t), 1, f);
		
		for(k = 0; k < n->hidden_n; k++)
			fwrite(&(n->output[i]).weights[k], sizeof(double), 1, f);
	}
	
	fclose(f);	
	
	return 1;
}



/**
 * Execute the neural network
 * 
 * \note need to insert support for multiprocessor and distributed computing
 * 
 * \param n neural net
 * \param input input data
 * \param output output data
 */
int 
mlp_execute(mlp_neural_network_t *n, double *input, double *output) 
{ 
	unsigned i;
	unsigned j;
	double a;
	
	
	#ifdef CUDA_SUPPORT
	mlp_cuda_execute();	
	#endif
	
	#ifndef CUDA_SUPPORT
	#ifdef OPENCL_SUPPORT
	/* OpenCL support */
	#endif
	
	#ifndef OPENCL_SUPPORT
	// Put input
	for(i = 0; i < n->input_n; i++)
	{
		(n->input[i]).value = input[i];
	}
	
	// Execute - hidden
	for(i = 0; i < n->hidden_n; i++)
	{
		a = 0.0;
		for(j = 0; j < n->input_n; j++)
			a += (n->hidden[i]).weights[j] * (n->input[j]).value;
		
		a += (n->hidden[i]).bias;
		
		//printf("%lf\n",(n->hidden[i]).bias);
		(n->hidden[i]).value = n->transf_func(a);
	}
	
	// Execute - output
	for(i = 0; i < n->output_n; i++)
	{
		a = 0.0;
		for(j = 0; j < n->hidden_n; j++)
			a += (n->output[i]).weights[j] * (n->hidden[j]).value;

		a += (n->output[i]).bias;
		
		(n->output[i]).value = n->transf_func(a);
	}
	
	// Get output
	for(i = 0; i < n->output_n; i++)
		output[i] = (n->output[i]).value;
	#endif
	#endif
}



/**
 * Show neural network values on stdio
 * 
 * \param l number of the layer (0 for all)
 * \param v type of values you want
 */
void mlp_display(mlp_neural_network_t *n, int l, int v)
{
	printf("Input neurons: %d\nHidden neurons: %d\nOutput neurons: %d\n",
			n->input_n, n->hidden_n, n->output_n);
	printf("Learning rate: %lf\n", n->learning_rate);
	printf("Used memory: %dkb (%dMB)\n", mlp_get_used_memory(n) / 1024, mlp_get_used_memory(n) / 1024 / 1024);
	
	int i,j ;
	if( (l == 0) || (l == 1) )
	{
		printf("Bias values:\n");
		printf("Input layer:");
		for(i = 0; i < n->input_n; i++)
		{
			printf("\t%lf", (n->input[i]).bias);
		}
		printf("\nHidden layer:");
		for(i = 0; i < n->hidden_n; i++)
		{
			printf("\t%lf", (n->hidden[i]).bias);
		}
		printf("\nOutput layer:");
		for(i = 0; i < n->output_n; i++)
		{
			printf("\t%lf", (n->output[i]).bias);
		}
		printf("\n");
		
	} 
	if( (l == 0) || (l == 2) )
	{
		printf("\n\nNeuron value:\n");
		printf("Input layer:");
		for(i = 0; i < n->input_n; i++)
		{
			printf("\t%lf", (n->input[i]).value);
		}
		printf("\nHidden layer:");
		for(i = 0; i < n->hidden_n; i++)
		{
			printf("\t%lf", (n->hidden[i]).value);
		}
		printf("\nOutput layer:");
		for(i = 0; i < n->output_n; i++)
		{
			printf("\t%lf", (n->output[i]).value);
		}
		printf("\n");
		
	} 
	if( (l == 0) || (l == 3) )
	{
		printf("\n\nNeuron weights:\n");
		printf("Output layer:\n");
		for(i = 0; i < n->output_n; i++)
		{
			printf("\t%d)", i);
			for(j = 0; j < n->hidden_n; j++)
				printf("\t%lf", (n->output[i]).weights[j]);
			printf("\n");
		}
		printf("\nHidden layer:\n");
		for(i = 0; i < n->hidden_n; i++)
		{
			printf("\t%d)", i);
			for(j = 0; j < n->input_n; j++)
				printf("\t%lf", (n->hidden[i]).weights[j]);
			printf("\n");
		}
	} 
	printf("\n\n");
}



/**
 * \return used memory from a network
 */
int mlp_get_used_memory(mlp_neural_network_t *n)
{
	return 	sizeof(mlp_neural_network_t) + 
			sizeof(mlp_neuron_t) * (n->input_n + n->output_n + n->hidden_n) +
			sizeof(double) * (n->output_n * n->hidden_n + n->hidden_n * n->input_n); 
}

