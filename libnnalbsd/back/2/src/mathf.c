#include <math.h>
#include <mathf.h>
#include <time.h>

double sigmodial(double x)
{
    return ((1.0)/(1.0 + pow(M_E, -x)));
}

double sigmodial_derivate(double x)
{
    return (x - pow(x, 2) );
}



/**
 * Return 1 or 0
 */
double heavyside(double x)
{
	if(x >= 0) 
		return 1.0;
	else 
		return 0.0;
}

/**
 * 
 */
double heavyside_derivate(double x)
{
	return 1.0;
}




/**
 * Generate a random number between 1 and 0
 */
double rand1()
{
	double v = rand() / 1000000000.0;
	//return -v; //v - (int) v;
	return v;
}
