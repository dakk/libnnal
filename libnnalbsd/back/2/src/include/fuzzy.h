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
