/**
 * Multi Layered Perceptons neural network
 * 
 * \file mlp.c
 * \author Davide Gessa
 * \date 13-04-2010
 */
#include <mlp.h>
#include <malloc.h>
#include <mathf.h>
#include <pthread.h>

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
	
	if((argc < 2) || (strcmp(argv[1], "or") == 0))
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

	if(done)
	{
		// Facciamo un test
		in[0] = 0.;
		in[1] = 1.;	
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



