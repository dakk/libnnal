/*
 *     libneuralnetwork
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
#ifndef FUZZY_H
#define FUZZY_H

#define FUZZY_NAME	64

/**
 * Entry of a fuzzy set
 */
typedef struct fuzzy_entry_p
{
	double xa;				///< Lower limit 
	double xb;				///< Higgher limit
	char name[FUZZY_NAME];	///< Name of the entry
	
	struct fuzzy_entry_p *next;
} fuzzy_entry_t;


/**
 * Fuzzy set struct
 */
typedef struct
{
	fuzzy_entry_t *entries;
	
} fuzzy_set_t;



fuzzy_set_t *fuzzy_new();
void fuzzy_delete(fuzzy_set_t *);
int fuzzy_add_entry(fuzzy_set_t *, char *, double, double);
char *fuzzy_evalute(fuzzy_set_t *, double);

#endif
