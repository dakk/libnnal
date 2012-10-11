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

#endif
