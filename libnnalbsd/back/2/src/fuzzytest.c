/**
 * Fuzzy Logic functions
 * 
 * \file fuzzy.c
 * \author Davide Gessa
 * \date 13-04-2010
 */

#include <fuzzy.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <mathf.h>


/**
 * Example code to test fuzzy functions
 */
int 
main(int argc, char **argv)
{
	unsigned i;
	fuzzy_set_t *f = fuzzy_new();
	fuzzy_add_entry(f, "true", 0.5, 1.0);
	fuzzy_add_entry(f, "false", 0.0, 0.5);
	
	printf("Fuzzy test\n");
	for(i = 0; i < 10; i++)
	{
		double v = rand1()/2;
		printf("\t%d - %lf -> %s\n", i+1, v, fuzzy_evalute(f, v));
	}
	fuzzy_delete(f);
	return 0;
}
