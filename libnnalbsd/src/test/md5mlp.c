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
#include <string.h>
#include <malloc.h>
#include <mathf.h>
#include <pthread.h>
#include <math.h>
#include <openssl/md5.h>

double *str2double(char *s, size_t len, double *d)
{
	int i;
	for(i = 0; i < len; i++)
		d[i] = (double) s[i] / 1000.0;	
	
	return d;
}


char *double2str(double *d, size_t len, char *s)
{
	int i;
	for(i = 0; i < len; i++)
	{
		s[i] = (char) (d[i] * 1000);
		printf("%lf - %d - %c\n", d[i], s[i], s[i]);
	}
	s[len] = '\0';
	return s;
}

char *random_str(char *s, size_t len)
{
	
}

/**
 * Test of the library
 */
int 
main(int argc, char **argv)
{
	double in[32];
	double out[12];
	int i;

	mlp_neural_network_t *n;
	
	int ls[] = { 16, 512, 8 };
	n = mlp_new(ls, 3);
	n->transf_func = &sigmodial;
	n->transf_func_derivate = &sigmodial_derivate;
	mlp_set_learning_rate(n, 0.6);

	//char string[12];
	long long string = 0;
	//for(i = 0; i < 12; i++)
	//	string[i] = 0;
	//printf("%d\n", sizeof(string));
	
	for(i = 0; i < 10000; i++)
	{
		int j;
		char md5[16];
		
		string++;
		//MD5((char *) &string, 8, md5);
	
		char string2[32];
		strcpy(string2, "ciaooooo");
		MD5((char *) &string2, 8, md5);
	
		printf("%lld - \n", string);
		//for(j = 0; j < 16; j++)
		//	printf("%x", (unsigned char) md5[j]);
		//printf("\n");
		
		str2double((char *) &md5, 16, in);
		str2double((char *) &string, 8, out);

		mlp_back_propagate(n, in, out);
	}


	// Facciamo un test
	char test[] = "ciaooooo";
	char md5[16];
	
	MD5((char *) &test, 8, md5);
	str2double((char *) md5, 16, in);

	mlp_execute(n, in, out);

	char output_s[20];
	double2str(out, 8, output_s);

	printf("\n\t");
	//for(i = 0; i < 8; i++)
	//	printf("'%lf' ", out[i]);
	//printf("\n");
		
	printf("'%s' - ", output_s);
	for(i = 0; i < 8; i++)
		printf("'%c' ", output_s[i]);
	printf("\n");

	mlp_delete(n);
	return 0;
}



