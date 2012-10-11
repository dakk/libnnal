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
#include <stdlib.h>
#include <fuzzy.h>
#include <stdlib.h>
#include <config.h>

#include <mlp.h>
#ifndef FREEBSD
	#include <malloc.h>
#endif

#include <time.h>
#include <string.h>
#include <mathf.h>


/**
 * Create an empty fuzzy set
 */
fuzzy_set_t *fuzzy_new()
{
	fuzzy_set_t *f = (fuzzy_set_t *) malloc(sizeof(fuzzy_set_t));
	f->entries = NULL;
}


/**
 * Add an entry in a fuzzy set
 */
int fuzzy_add_entry(fuzzy_set_t *f, char *n, double xa, double xb)
{
	fuzzy_entry_t *entry = (fuzzy_entry_t *) malloc(sizeof(fuzzy_entry_t));
	entry->next = f->entries;
	f->entries = entry;
	strcpy(entry->name, n);
	entry->xa = xa;
	entry->xb = xb;	
}


/**
 * Evalute a given value
 */
char *fuzzy_evalute(fuzzy_set_t *f, double v)
{
	fuzzy_entry_t *e = f->entries;
	
	while(e != NULL)
	{
		if((v <= e->xb) && (v >= e->xa))
			return e->name;
		e = e->next;
	}	
}


/**
 * Free used memory
 */
void fuzzy_delete(fuzzy_set_t *f)
{
	// Free entries
	
	// Free the set
	free(f);
}

