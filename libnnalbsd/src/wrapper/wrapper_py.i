%module nnal
%{
#include <mlp.h>
#include <mathf.h>

extern mlp_neural_network_t *mlp_new(int *, int);
extern double mlp_back_propagate(mlp_neural_network_t *, double *, double *);
extern void mlp_set_learning_rate(mlp_neural_network_t *, double);
extern void mlp_delete(mlp_neural_network_t *);
extern void mlp_display(mlp_neural_network_t *, int, int);
extern int mlp_get_used_memory(mlp_neural_network_t *);
extern mlp_neural_network_t *mlp_load(char *);
extern int mlp_save(mlp_neural_network_t *, char *);
extern int mlp_execute(mlp_neural_network_t *, double *, double *);
extern double rand1();
extern double hyperbolic(double);
extern double hyperbolic_derivate(double);
extern double sigmodial(double);
extern double sigmodial_derivate(double);
extern double heavyside_derivate(double);
extern double heavyside(double);
extern double heavyside_derivate(double);

%}
 
#include <mlp.h>
#include <mathf.h>


extern mlp_neural_network_t *mlp_new(int *, int);
extern double mlp_back_propagate(mlp_neural_network_t *, double *, double *);
extern void mlp_set_learning_rate(mlp_neural_network_t *, double);
extern void mlp_delete(mlp_neural_network_t *);
extern void mlp_display(mlp_neural_network_t *, int, int);
extern int mlp_get_used_memory(mlp_neural_network_t *);
extern mlp_neural_network_t *mlp_load(char *);
extern int mlp_save(mlp_neural_network_t *, char *);
extern int mlp_execute(mlp_neural_network_t *, double *, double *);

extern double rand1();
extern double hyperbolic(double);
extern double hyperbolic_derivate(double);
extern double sigmodial(double);
extern double sigmodial_derivate(double);
extern double heavyside_derivate(double);
extern double heavyside(double);
extern double heavyside_derivate(double);
