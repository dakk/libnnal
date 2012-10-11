/**
 * Fuzzy Logic functions
 * 
 * \file fuzzy.c
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
#include <fuzzy.h>
#include <config.h>

#include <stdlib.h>
#ifndef FREEBSD
	#include <malloc.h>
#endif

#include <stdio.h>
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
