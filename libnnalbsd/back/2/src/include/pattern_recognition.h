#ifndef PATTERN_RECOGNITION_H
#define PATTERN_RECOGNITION_H

#include "mlp.h"

double pattern_backpropagate(mlp_neural_network_t *, char *, int);
double *pattern_recognition(mlp_neural_network_t *, char *, double *);
char pattern_getchar(double *, int);


#endif
