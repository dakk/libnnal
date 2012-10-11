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
 * \param f png greyscale image file
 * \param num number of the output to set to 1
 */
double pattern_backpropagate(mlp_neural_network_t *n, char *f, int num)
{
	// Allocate inputs space
	double *ins = (double *) malloc(sizeof(double) * n->input_n);
	
	if(ins == NULL)
		return 0.0;
	
	// Allocate outputs space	
	double *outs = (double *) malloc(sizeof(double) * n->output_n);
	if(outs == NULL)
	{
		free(ins);
		return 0.0;
	}
	
	// Prepare output data
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
	
	
	// Load the file
	png_t png;
	png_init(malloc, free);

	png_open_file_read(&png, f);
	if(png.bpp != 0)
	{
		//printf("unsupported image %s: must be .png greyscale\n", f);
		png_close_file(&png);
		free(ins);
		free(outs);
		return 0.0;
	}

	char *data = (char *) malloc(png.depth * png.width * png.height);
	if(data == NULL)
	{
		free(ins);
		free(outs);
		return 0.0;
	}
	png_get_data(&png, data);
	
	
	// Put data in ins
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
 * 
 * \param n neural network
 * \param f png greyscale image file
 * \param outs pointer of an array where outputs will be stored
 * 
 * \return pointer of outs
 */
double *pattern_recognition(mlp_neural_network_t *n, char *f, double *outs)
{
	unsigned i;
	double *ins = (double *) malloc(sizeof(double) * n->input_n);
	
	if(ins == NULL)
		return NULL;
		
	// Load the file
	png_t png;
	
	png_init(malloc, free);
	png_open_file_read(&png, f);
	if(png.bpp != 0)
	{
		//printf("unsupported image %s: must be .png greyscale\n", f);
		//png_close_file(&png);
		free(ins);
		return NULL;
	}

	char *data = (char *) malloc(png.depth * png.width * png.height);
	if(data == NULL)
	{
		png_close_file(&png);
		free(ins);
		return NULL;
	}
	png_get_data(&png, data);


	// Put data in ins
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
 * 
 * \param outs output array
 * \param n number of elements in outs
 * 
 * \return char of the specific outputs
 */
char pattern_getchar(double *outs, int n)
{
	int i;
	int best = 0;
	
	// Search for the max
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
