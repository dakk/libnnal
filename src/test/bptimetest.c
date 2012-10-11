/**
 * Back Propagation time test
 * 
 * \file bptimetest.c
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
#include <time.h>
#include <sys/time.h>

/**
 * Test of the library
 */
int 
main(int argc, char **argv)
{
	double *in;
	double *out;
	int i;
	mlp_neural_network_t *n;
	
	int ls[] = { 2, 4, 1 };
	
	FILE *f;
	if(argc > 1)
	{
		f = fopen(argv[1], "w");
	}
	
	for(i = 0; i < 1000; i++)
	{
		n = mlp_new(ls, 3);
		n->transf_func = &sigmodial;
		n->transf_func_derivate = &sigmodial_derivate;
		mlp_set_learning_rate(n, 0.6);

		in = (double *) malloc(sizeof(double) * ls[0]);
		out = (double *) malloc(sizeof(double) * ls[2]);

		for(i = 0; i < ls[0]; i++)
			in[i] = rand1();

		for(i = 0; i < ls[2]; i++)
			out[i] = rand1();	

		// Prende il tempo
		struct timeval tp;
		gettimeofday(&tp, NULL);
		int a = tp.tv_usec;
		
		mlp_back_propagate(n, in, out);
		// Calcola il tempo
		gettimeofday(&tp, NULL);
		int b = tp.tv_usec - a;
	
		if(b > 0)
		{
			printf("%d %d\n", ls[0] + ls[1] + ls[2], b);
			if(f != NULL)
				fprintf(f, "%d %d\n", ls[0] + ls[1] + ls[2], b);
		}
		mlp_delete(n);
		free(in);
		free(out);

		ls[0]++;
		ls[1]+=3;
		ls[2]+=2;

	}
	fclose(f);
	
	return 0;
}



