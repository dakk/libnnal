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
#include <math.h>
#include <mathf.h>
#include <time.h>

double hyperbolic_derivate(double x)
{
	return (1 - pow(x, 2));
}
double hyperbolic(double x)
{
	return (tanhf(x));
}

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
