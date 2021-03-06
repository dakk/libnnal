/**
 * 
 * \file config.h
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
#ifndef NNAL_CONFIG_H
#define NNAL_CONFIG_H


/* Neural precision */
#define DOUBLE_PRECISION
#ifndef DOUBLE_PRECISION
//#define FLOAT_PRECISION
#endif



/* Enable opencl support */
//#define OPENCL_SUPPORT

/* Enable cuda support */
#ifndef OPENCL_SUPPORT
//	#define CUDA_SUPPORT
#endif

/* Enable debug*/
//#define DEBUG


/* Python bindings */
#define PYTHON_SUPPORT

/* Perl bindings */
//#define PERL_SUPPORT

#endif
