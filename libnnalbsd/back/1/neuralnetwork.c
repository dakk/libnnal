#include <neuralnetwork.h>
#include <malloc.h>


/**
 * Create a neural network
 * 
 * \param in input neurons
 * \param hi hidden neurons
 * \param out output neurons
 * 
 * \return pointer to the network
 */
neural_network_t *
nn_new(int in, int hi, int out)
{
	unsigned i, j;
	neural_network_t *n = (neural_network_t *) malloc(sizeof(neural_network_t));
	
	n->input_n = in;
	n->hidden_n = hi;
	n->output_n = out;
	
	n->input = (neuron_t *) malloc(sizeof(neuron_t) * in);
	n->hidden = (neuron_t *) malloc(sizeof(neuron_t) * hi);
	n->output = (neuron_t *) malloc(sizeof(neuron_t) * out);
	
	n->learning_rate = 0.8;
	n->transf_func = &sigma_logistic;
	
 	srandom(time(NULL));

	for(i = 0; i < in; i++)
	{
		(n->input[i]).weights = (double *) malloc(sizeof(double) * hi);
		for(j = 0; j < hi; j++)
			(n->input[i]).weights[j] = nn_rand();
	}

	for(i = 0; i < hi; i++)
	{
		(n->hidden[i]).weights = (double *) malloc(sizeof(double) * out);
		for(j = 0; j < out; j++)
			(n->hidden[i]).weights[j] = nn_rand();
	}

	for(i = 0; i < out; i++)
	{
		(n->output[i]).weights = (double *) malloc(sizeof(double) * 1);
		for(j = 0; j < 1; j++)
			(n->output[i]).weights[j] = nn_rand();
	}
	
	return n;
}



/**
 * Generate a random number between 1 and 0
 */
double nn_rand()
{
	double v = rand() / 1000000000.0;
	return v - (int) v;
}



/**
 * Delete a neural network
 */
void
nn_delete(neural_network_t *n)
{
	unsigned i;
	
	for(i = 0; i < n->input_n; i++)
		free((n->input[i]).weights);

	for(i = 0; i < n->hidden_n; i++)
		free((n->hidden[i]).weights);

	for(i = 0; i < n->output_n; i++)
		free((n->output[i]).weights);

	free(n->input);
	free(n->hidden);
	free(n->output);
	free(n);
}




double 
nn_back_propagate(neural_network_t *n, double *input, double *doutput)
{
	unsigned i;
	unsigned j;
	unsigned k;
	
}



/**
 * Set the learning rate
 */
void 
nn_set_learning_rate(neural_network_t *n, double lr) 
{ 	
	n->learning_rate = lr;
}




/**
 * Set the transfer function
 */
void 
nn_set_function(neural_network_t *n, double (*transf_func)(double)) 
{ 	
	n->transf_func = transf_func;
}	
	




/**
 * Load the neural network from a file
 */
int 
nn_load(neural_network_t *n, char *path) 
{ 	
	FILE *f;
	unsigned i;
	
	f = fopen(path, "rb");
	
	if(f == NULL)
		return 0;
		
	fclose(f);	
	
	return 1;	
}




/**
 * Save the neural network in a file
 */
int 
nn_save(neural_network_t *n, char *path) 
{ 	
	FILE *f;
	unsigned i;
	
	f = fopen(path, "wb");
	
	if(f == NULL)
		return 0;
		
	fwrite(n, sizeof(n), 1, f);
	fwrite(n->input, sizeof(neuron_t), n->input_n, f);
	fwrite(n->hidden, sizeof(neuron_t), n->hidden_n, f);
	fwrite(n->output, sizeof(neuron_t), n->output_n, f);
	fclose(f);	
	
	return 1;
}



/**
 * Execute the neural network
 * 
 * \param n neural net
 * \param input input data
 * \param output output data
 */
int 
nn_execute(neural_network_t *n, double *input, double *output) 
{ 
	unsigned i;
	unsigned k;
	double a;
	
	// Put input
	for(i = 0; i < n->input_n; i++)
		(n->input[i]).value = input[i];

	// Execute
	
	
	// Get output
	for(i = 0; i < n->output_n; i++)
		output[i] = (n->output[i]).value;
}



/**
 * Show neural network values on stdio
 */
void nn_display(neural_network_t *n, int l, int v)
{
	printf("Input neurons: %d\nHidden neurons: %d\nOutput neurons: %d\n",
			n->input_n, n->hidden_n, n->output_n);
	printf("Learning rate: %lf\n", n->learning_rate);
	
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
		printf("Input layer:\n");
		for(i = 0; i < n->input_n; i++)
		{
			printf("\t%d)", i);
			for(j = 0; j < n->hidden_n; j++)
				printf("\t%lf", (n->input[i]).weights[j]);
			printf("\n");
		}
		printf("\nHidden layer:\n");
		for(i = 0; i < n->hidden_n; i++)
		{
			printf("\t%d)", i);
			for(j = 0; j < n->output_n; j++)
				printf("\t%lf", (n->hidden[i]).weights[j]);
			printf("\n");
		}
	} 

}



/**
 * Test of the library
 */
int 
main(int argc, char **argv)
{
	if((argc < 2) || (strcmp(argv[1], "and") == 0))
	{
		double in[2];
		double out[1];
		int i;
		
		neural_network_t *n = nn_new(2, 3, 1);
		n->transf_func = &sigma_logistic;
		
		// Istruiamo con la and
		in[0] = 1.0;
		in[1] = 1.0;
		out[0] = 1.0;	
		nn_back_propagate(n, in, out);

		in[0] = 1.0;
		in[1] = 0.0;
		out[0] = 0.0;	
		nn_back_propagate(n, in, out);

		in[0] = 0.0;
		in[1] = 1.0;
		out[0] = 0.0;	
		nn_back_propagate(n, in, out);

		in[0] = 0.0;
		in[1] = 0.0;
		out[0] = 1.0;	
		nn_back_propagate(n, in, out);

		nn_display(n, 0, 0);
		
		// Facciamo un test
		in[0] = 1.0;
		in[1] = 1.0;
		out[0] = 1.0;			
		nn_execute(n, in, out);
		nn_save(n, "and.nn");
		//printf("%lf\n", (float) out[0]);
		
		//nn_delete(n);
	}
	
	return 0;
}
