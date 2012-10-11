/**
 * Epochtest neural network
 * 
 * \file epochtest.c
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
#include <mathf.h>
#include <pthread.h>
#include <config.h>

#include <stdlib.h>
#ifndef FREEBSD
	#include <malloc.h>
#endif

#include <stdio.h>


/**
 * Test of the library
 */
int 
main(int argc, char **argv)
{
	double in[2];
	double out[1];
	int i;
	int k;
	int j;
	int ok;
	int epoch = 10;
	int test_rate = 1;
	mlp_neural_network_t *n;
	int ls[] = { 2, 4, 1 };
	double m;
	FILE *f = NULL;
	
	if(argc > 1)
		f = fopen(argv[1], "w");
		
	for(k = 1; k < 1500; k++)
	{
		m = 0.0;
		ok = 0;
	
		for(j = 0; j < test_rate; j++)
		{
			n = mlp_new(ls, 3);
			n->transf_func = &sigmodial; //&heavyside;
			n->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
			mlp_set_learning_rate(n, 0.999);

			for(i = 0; i < epoch; i++)
			{

				in[0] = 1.0;
				in[1] = 0.0;
				out[0] = 1.0;	
				mlp_back_propagate(n, in, out);

				in[0] = 0.0;
				in[1] = 1.0;
				out[0] = 1.0;	
				mlp_back_propagate(n, in, out);

				in[0] = 1.0;
				in[1] = 1.0;
				out[0] = 0.0;	
				mlp_back_propagate(n, in, out);

				in[0] = 0.0;
				in[1] = 0.0;
				out[0] = 0.0;	
				mlp_back_propagate(n, in, out);
			}
			// Facciamo un test
			in[0] = 0.;
			in[1] = 1.;	
			mlp_execute(n, in, out);
			if(out[0] > 0.9)
				ok++;
	
			m += out[0];
			mlp_delete(n);
		}
		m = m/test_rate;
		printf("epoch: %d out: %lf delta: %lf\n",epoch, m, 1.0 - m);
		
		if(f != NULL)
			fprintf(f, "%d %lf\n", epoch, 1.0 - m);
			
		epoch += 10;
	}

	if(f != NULL)
		fclose(f);
	return 0;
}



