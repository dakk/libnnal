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
#include <string.h>
#include <math.h>

/**
 * Test of the library
 */
int 
main(int argc, char **argv)
{
	double in[2];
	double out[1];
	int i;
	int done = 0;
	
	mlp_neural_network_t *n;
	
	if((argc == 2) && (strcmp(argv[1], "save_all") == 0))
	{
		char tmp[1024];
		strcpy(tmp, argv[0]);
		strcat(tmp, " or");
		system(tmp);
		
		strcpy(tmp, argv[0]);
		strcat(tmp, " and");
		system(tmp);
		
		strcpy(tmp, argv[0]);
		strcat(tmp, " not");
		system(tmp);
		
		strcpy(tmp, argv[0]);
		strcat(tmp, " sin");
		system(tmp);
		
		strcpy(tmp, argv[0]);
		strcat(tmp, " sum");
		system(tmp);
	
		return 0;
	}
	
	else if((argc < 2) || (strcmp(argv[1], "or") == 0))
	{	
		//n = mlp_load("saved/or.nn");
	
		int ls[] = { 2, 4, 1 };
		n = mlp_new(ls, 3);
		n->transf_func = &sigmodial; //&heavyside;
		n->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
		mlp_set_learning_rate(n, 0.6);

		done = 1;
		for(i = 0; i < 10000; i++)
		{
			// Istruiamo con la or
			in[0] = 1.0;
			in[1] = 1.0;
			out[0] = 0.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 1.0;
			in[1] = 0.0;
			out[0] = 1.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 0.0;
			in[1] = 1.0;
			out[0] = 1.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 0.0;
			in[1] = 0.0;
			out[0] = 0.0;	
			mlp_back_propagate(n, in, out);

		}
		mlp_save(n, "saved/or.nn");
		printf("Test: or\n");
	}
	else if((strcmp(argv[1], "and") == 0))
	{
		int ls[] = { 2, 4, 1 };
		n = mlp_new(ls, 3);
		n->transf_func = &sigmodial; //&heavyside;
		n->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
		mlp_set_learning_rate(n, 0.6);
		
		done = 1;
		for(i = 0; i < 10000; i++)
		{
			// Istruiamo con la and
			in[0] = 1.0;
			in[1] = 0.0;
			out[0] = 0.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 0.0;
			in[1] = 1.0;
			out[0] = 0.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 1.0;
			in[1] = 1.0;
			out[0] = 1.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 0.0;
			in[1] = 0.0;
			out[0] = 1.0;	
			mlp_back_propagate(n, in, out);
			
			printf("epoch: %d\n",i);
		}
		mlp_save(n, "saved/and.nn");
		printf("Test: and\n");
	}
	else if((strcmp(argv[1], "sin") == 0))
	{
		int ls[] = { 1, 9, 1 };
		n = mlp_new(ls, 3);
		n->transf_func = &hyperbolic;//sigmodial; //&heavyside;
		n->transf_func_derivate = &hyperbolic_derivate;//sigmodial_derivate; //heavyside_derivate;
		mlp_set_learning_rate(n, 0.6);
		
		done = 1;
		int a = 0;
		for(i = 0; i < 10000; i++)
		{
			if(a > 360)
				a = 0;
			// Istruiamo con la sin
			in[0] = ((double) a)/1000;
			out[0] = sin((double) a);
			printf("%lf\t%lf\n", in[0], out[0]);	
			mlp_back_propagate(n, in, out);

			a++;
			//printf("epoch: %d\n",i);
		}
		mlp_save(n, "saved/sin.nn");
		printf("Test: sin\n");
	}
	else if((strcmp(argv[1], "not") == 0))
	{
		int ls[] = { 1, 4, 1 };
		n = mlp_new(ls, 3);
		n->transf_func = &sigmodial; //&heavyside;
		n->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
		mlp_set_learning_rate(n, 0.6);
		
		done = 1;
		for(i = 0; i < 10000; i++)
		{
			// Istruiamo con la not
			in[0] = 1.0;
			out[0] = 0.0;	
			mlp_back_propagate(n, in, out);

			in[0] = 0.0;
			out[0] = 1.0;	
			mlp_back_propagate(n, in, out);
			
			printf("epoch: %d\n",i);
		}
		mlp_save(n, "saved/not.nn");
		printf("Test: not\n");
	}
	else if((strcmp(argv[1], "sum") == 0))
	{
		int ls[] = { 2, 4, 1 };
		n = mlp_new(ls, 3);
		n->transf_func = &sigmodial; //&heavyside;
		n->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
		mlp_set_learning_rate(n, 0.6);
		
		done = 1;
		for(i = 0; i < 10000; i++)
		{
			// Istruiamo con la somma
			in[0] = i/100;
			in[1] = (i+1)/100;
			out[0] = (i+i+1)/100;	
			mlp_back_propagate(n, in, out);
		}
		mlp_save(n, "saved/sum.nn");
		printf("Test: sum\n");
	}
	else if((strcmp(argv[1], "dis") == 0))
	{
		int ls[] = { 1, 4, 1 };
		n = mlp_new(ls, 3);
		n->transf_func = &sigmodial; //&heavyside;
		n->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
		mlp_set_learning_rate(n, 0.6);
		
		done = 1;
		for(i = 0; i < 10000; i++)
		{
			// Istruiamo con la disparita'
			in[0] = i/100;
			out[0] = (i%2);	
			mlp_back_propagate(n, in, out);
		}
		mlp_save(n, "saved/dis.nn");
		printf("Test: dis\n");
	}
	else if((strcmp(argv[1], "load") == 0) && argc > 2)
	{
		n = mlp_load(argv[2]);
		if(n != NULL)
			done = 1;		
	}
	
	if(done)
	{
		// Facciamo un test
		in[0] = 1.;
		in[1] = 0.;	
		mlp_execute(n, in, out);
		//mlp_display(n, 0, 10);
		
		printf("Inputs:\t");
		for(i = 0; i < n->input_n; i++)
			printf("\t%lf", in[i]);
		printf("\n");
		
		printf("Outputs:");
		for(i = 0; i < n->output_n; i++)
			printf("\t%lf", out[i]);
		printf("\n");
	}
	mlp_delete(n);

	return 0;
}



