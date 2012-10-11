#ifndef LNN_H
#define LNN_H

#include <math.h>


double sigma_logistic(double x)
{
	return ( 1 / (1 + 1));//expf(-(x)))); 
}

typedef struct neuron_p
{
	double value;
	double *weights;
	double bias;
	double delta;
} neuron_t;

typedef struct
{
	unsigned input_n;
	unsigned hidden_n;
	unsigned output_n;
	
	neuron_t *input;
	neuron_t *output;
	neuron_t *hidden;
	
	double learning_rate;

	double (*transf_func)(double);
} neural_network_t;


neural_network_t *nn_new(int, int, int);
double nn_back_propagate(neural_network_t *, double *, double *);
double nn_rand();
void nn_set_learning_rate(neural_network_t *, double);
void nn_delete(neural_network_t *);
void nn_set_function(neural_network_t *, double (*transf_func)(double));
void nn_display(neural_network_t *, int, int);
int nn_load(neural_network_t *, char *);
int nn_save(neural_network_t *, char *);
int nn_execute(neural_network_t *, double *, double *);

#endif
