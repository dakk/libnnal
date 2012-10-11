#include <pattern_recognition.h>
#include <pnglite.h>
#include <mlp.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>


/**
 * Backpropagate a given image
 * 
 * \param n neural network
 * \param f image file
 * \param num number of the output to set to 1
 */
double pattern_backpropagate(mlp_neural_network_t *n, char *f, int num)
{
	double *ins = (double *) malloc(sizeof(double) * n->input_n);
	double *outs = (double *) malloc(sizeof(double) * n->output_n);
	int i;
	
	for(i = 0; i < n->output_n; i++)
	{
		if(i == num)
		{
			//printf("%d\n", i);
			outs[i] = 1.0;
		}
		else
			outs[i] = 0.0;
	}
	
	
	// Load the file and put data in ins
	png_t png;
	
	png_init(malloc, free);

	png_open_file_read(&png, f);
	char *data = (char *) malloc(png.depth * png.width * png.height);
	png_get_data(&png, data);
	
	for(i = 0; i < (png.height * png.width * png.depth); i++)
	{
		if(png.png_data[i] > 10)
		{
			ins[i] = 1.0;
		}
		else
			ins[i] = 0.0;
	}
	
	free(data);
	png_close_file(&png);
	
	// Backpropagate 
	double delta = mlp_back_propagate(n, ins, outs); 
	free(ins);
	free(outs);
	return delta;
}


/**
 * Execute the network with a given image
 */
double *pattern_recognition(mlp_neural_network_t *n, char *f, double *outs)
{
	unsigned i;
	double *ins = (double *) malloc(sizeof(double) * n->input_n);
	
	// Load the file and put data in ins
	png_t png;
	
	png_init(malloc, free);
	png_open_file_read(&png, f);

	char *data = (char *) malloc(png.depth * png.width * png.height);
	png_get_data(&png, data);

	for(i = 0; i < (png.height * png.width); i++)
	{
		if(png.png_data[i] > 10)
			ins[i] = 1.0;
		else
			ins[i] = 0.0;
		
	}
	
	free(data);
	png_close_file(&png);
	
	
	// Execute	
	mlp_execute(n, ins, outs);
	
	free(ins);
	return outs;
}



/**
 * Return a char from given outputs
 */
char pattern_getchar(double *outs, int n)
{
	int i;
	int best = 0;
	
	for(i = 0; i < n; i++)
	{
		if(outs[i] > outs[best])
			best = i;
	}
	
	if(best < 25)
		return 'a' + best;
	else
		return '0' + best - 25;
}
