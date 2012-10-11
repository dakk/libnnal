/**
 * 
 * \todo automatically list passed directory to search files 
 * \todo time calc
 */
#include <pattern_recognition.h>
#include <mlp.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>



/**
 * Test functions
 */
int
main(int argc, char **argv)
{
	if(argc < 4)
	{
		printf("use: %s directory epoch file_to_test\n", argv[0]);
		return 0;
	}
	
	unsigned i, j, k;
	int epoch = atoi(argv[2]);
	printf("Pattern Recognition Test\n");
	int ls[] = { 16*16, 16*16, 36 };
	mlp_neural_network_t *pattern_net = mlp_new(ls, 3);
	mlp_set_learning_rate(pattern_net, 0.6);
	pattern_net->transf_func = &heavyside;
	pattern_net->transf_func_derivate = &heavyside_derivate;
	
	printf("Used %dMB of ram\n\n", mlp_get_used_memory(pattern_net) / 1024 / 1024);
	
	// Teach the net
	int time_a = time(NULL);
	int time_b;
	int time_start = time_a;
	
	for(i = 0; i < epoch; i++)
	{
		DIR *d = opendir(argv[1]);
		if(d != NULL)
		{
			struct dirent *de;
			while((de = readdir(d)) != NULL)
			{
				char a = de->d_name[0];
				char p[1024];
				strcpy(p, argv[1]);
				strcat(p, de->d_name);
				if(de->d_name[0] == '.')
					continue;
						
				pattern_backpropagate(pattern_net, p, a - 'a'); 

				
			}
		}
		closedir(d);
		
		if((i % 10) == 0)
		{
			time_b = time(NULL);
			int inter = (((float) time_b - (float) time_a) / 10) * (epoch - i);
			printf("epoch %d (%d sec eta) %d%%   \r", i, inter, 100*i/epoch);
			time_a = time_b;
			
			fflush(stdout);
		}
	}
	mlp_save(pattern_net, "saved/alphanum.mlp");
	
	// Test
	double *outs = (double *) malloc(sizeof(double) * pattern_net->output_n);
	pattern_recognition(pattern_net, argv[3], outs);
	char c = pattern_getchar(outs, 36);
	printf("\n\t'%s' -> '%c'\n", argv[3], c);
	
	//mlp_display(pattern_net, 0,0);
	mlp_delete(pattern_net);
	free(outs);
}
