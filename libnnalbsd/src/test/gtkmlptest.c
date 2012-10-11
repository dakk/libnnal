/**
 * \file test/gtkmlptest.c
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
#include <gtkmlpwidget.h>
#include <gtk/gtk.h>
#include <cairo/cairo.h>
#include <time.h>
#include <config.h>

#include <stdlib.h>
#ifndef FREEBSD
	#include <malloc.h>
#endif

GtkWidget *mlp;
mlp_neural_network_t *net;
GtkWidget *window;
GtkWidget *mlp;
       
       
/* Learning callback */       
static gboolean
update_cb(GtkWidget *widget)
{
	gtk_widget_queue_draw(mlp);	
  	double *in = (double *) malloc(sizeof(double) * 2);
	double *out = (double *) malloc(sizeof(double));
	
	in[0] = 1.0;
	in[1] = 1.0;
	out[0] = 0.0;	
	mlp_back_propagate(net, in, out);

	in[0] = 1.0;
	in[1] = 0.0;
	out[0] = 1.0;	
	mlp_back_propagate(net, in, out);

	in[0] = 0.0;
	in[1] = 1.0;
	out[0] = 1.0;	
	mlp_back_propagate(net, in, out);

	in[0] = 0.0;
	in[1] = 0.0;
	out[0] = 0.0;	
	mlp_back_propagate(net, in, out);
	
	free(in);
	free(out);
	
	return TRUE;
}


int
main (int argc, char **argv)
{
	srand(time(NULL));
	int layers[] = { 2, 4, 1 };		

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "gtk_mlp widget: or test");
	gtk_window_resize(GTK_WINDOW(window), 500, 500);

	mlp = gtk_mlp_new();
	net = mlp_new(layers, 3);
	net->transf_func = &sigmodial; //&heavyside;
	net->transf_func_derivate = &sigmodial_derivate; //heavyside_derivate;
	mlp_set_learning_rate(net, 0.6);
		
	gtk_mlp_set_network(GTK_MLP(mlp), net);
	gtk_container_add (GTK_CONTAINER (window), mlp);

	g_signal_connect (window, "destroy",
	                        G_CALLBACK (gtk_main_quit), NULL);

	g_timeout_add(10, (GSourceFunc) update_cb, (gpointer) mlp);

	gtk_widget_show_all (window);
	//update_cb(mlp);
	gtk_main();
}
