/**
 * 
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
#include <pattern_recognition.h>
#include <mlp.h>
#include <math.h>
#include <stdio.h>
#include <config.h>

#include <stdlib.h>
#ifndef FREEBSD
	#include <malloc.h>
#endif

#include <mathf.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtkmlpwidget.h>
#include "mlpgtk.h"


GtkWidget *input_spin;
GtkWidget *output_spin;
GtkWidget *hidden_spin;
GtkWidget *learning_spin;
GtkWidget *new_w;


/* Cancel creating */
void 
new_cancel_cb()
{
	gtk_widget_destroy(new_w);
}



/* Create the network */
void 
new_do_cb()
{
	int i;
	int l[3];
	l[0] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_spin));
	l[1] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hidden_spin));
	l[2] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(output_spin));
	
	nn = mlp_new(l, 3);
	nn->transf_func = &heavyside;
	nn->transf_func_derivate = &heavyside_derivate;

	nn->learning_rate = gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(learning_spin));
	gtk_mlp_set_network(GTK_MLP(mlp), nn);


	// Add the input boxes in the main window
	neural_input = (GtkWidget **) malloc(sizeof(GtkWidget *) * l[0]);
	neural_output = (GtkWidget **) malloc(sizeof(GtkWidget *) * l[2]);	

	gtk_box_pack_start(GTK_BOX(entry_box),gtk_label_new("Input values"),FALSE,FALSE,0);

	for(i = 0; i < l[0]; i++)
	{
		char str_c[16];
		sprintf(str_c, "Neuron %d ", i);
		GtkWidget *tmp_box = gtk_hbox_new(0, 0);
		neural_input[i] = gtk_spin_button_new(
			GTK_ADJUSTMENT(
				gtk_adjustment_new((nn->input[i]).value, 0.0, 1.0, 0.02, (nn->input)[i].value, 0.1)), 
				1.0, 2);

		gtk_box_pack_start(GTK_BOX(tmp_box),gtk_label_new(str_c),FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(tmp_box),neural_input[i],TRUE,TRUE,0);

		gtk_box_pack_start(GTK_BOX(entry_box),tmp_box,FALSE,FALSE,0);

		gtk_widget_show_all(window);
	}

	gtk_box_pack_start(GTK_BOX(entry_box),gtk_label_new("Output values"),FALSE,FALSE,0);

	for(i = 0; i < l[2]; i++)
	{
		char str_c[16];
		sprintf(str_c, "Neuron %d ", i);
		GtkWidget *tmp_box = gtk_hbox_new(0, 0);
		neural_output[i] = gtk_spin_button_new(
			GTK_ADJUSTMENT(
				gtk_adjustment_new((nn->output)[i].value, 0.0, 1.0, 0.02, (nn->output)[i].value, 0.1)), 
				1.0, 2);

		gtk_box_pack_start(GTK_BOX(tmp_box),gtk_label_new(str_c),FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(tmp_box),neural_output[i],TRUE,TRUE,0);

		gtk_box_pack_start(GTK_BOX(entry_box),tmp_box,FALSE,FALSE,0);

		gtk_widget_show_all(window);
	}

	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Network created.");

	// Destroy the window
	gtk_widget_destroy(new_w);
}



/* New dialog */
void
new_cb()
{
	// If another nn is open, call delete_cb()
	if(nn != NULL)
		delete_cb();
	
	GtkWidget *tmp;	

	// Dialog where select the net neurons number
	new_w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(new_w), "New Neural Network");
	gtk_window_resize(GTK_WINDOW(new_w), 300, 180);
	//g_signal_connect(G_OBJECT(window), "destroy", 
	//                     G_CALLBACK(gtk_main_quit), NULL);
    
	GtkWidget *mbox = gtk_vbox_new(1, 0);
	gtk_container_add(GTK_CONTAINER(new_w), mbox);


	GtkWidget *menu = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(mbox),menu,TRUE,TRUE,0);

	// 
	GtkWidget *menu_file = gtk_menu_item_new_with_label("File");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_file);

	GtkWidget *menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_file), menu_sub);

	GtkWidget *menuitem = gtk_menu_item_new_with_label ("Quit");
	g_signal_connect(G_OBJECT(menuitem), "clicked", G_CALLBACK(save_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);


	// Input neurons
	tmp = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(mbox),tmp,FALSE,FALSE,0);

	gtk_box_pack_start(GTK_BOX(tmp),gtk_label_new("Input neurons: "),FALSE,FALSE,0);
	input_spin = gtk_spin_button_new(
		GTK_ADJUSTMENT(gtk_adjustment_new(2.0, 0.0, 10000.0, 1.0, 10.0, 10.0)), 
		1.0, 0);
	gtk_box_pack_start(GTK_BOX(tmp),input_spin,FALSE,FALSE,0);

	// Hidden neurons
	tmp = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(mbox),tmp,FALSE,FALSE,0);

	gtk_box_pack_start(GTK_BOX(tmp),gtk_label_new("Hidden neurons: "),FALSE,FALSE,0);
	hidden_spin = gtk_spin_button_new(
		GTK_ADJUSTMENT(gtk_adjustment_new(3.0, 0.0, 10000.0, 1.0, 10.0, 10.0)), 
		1.0, 0);
	gtk_box_pack_start(GTK_BOX(tmp),hidden_spin,FALSE,FALSE,0);

	// Output neurons
	tmp = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(mbox),tmp,FALSE,FALSE,0);

	gtk_box_pack_start(GTK_BOX(tmp),gtk_label_new("Output neurons: "),FALSE,FALSE,0);
	output_spin = gtk_spin_button_new(
		GTK_ADJUSTMENT(gtk_adjustment_new(1.0, 0.0, 10000.0, 1.0, 10.0, 10.0)), 
		1.0, 0);
	gtk_box_pack_start(GTK_BOX(tmp),output_spin,FALSE,FALSE,0);
	
	// Learning neurons
	tmp = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(mbox),tmp,FALSE,FALSE,0);

	gtk_box_pack_start(GTK_BOX(tmp),gtk_label_new("Learning rate: "),FALSE,FALSE,0);
	learning_spin = gtk_spin_button_new(
		GTK_ADJUSTMENT(gtk_adjustment_new(0.6, 0.0, 1.0, 0.02, 0.6, 0.1)), 
		1.0, 2);
	gtk_box_pack_start(GTK_BOX(tmp),learning_spin,FALSE,FALSE,0);
	
	// Combo for transfer function
	
	tmp = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(mbox),tmp,FALSE,FALSE,0);
	GtkWidget *new_button = gtk_button_new_with_label("New");
	g_signal_connect(G_OBJECT(new_button), "clicked", G_CALLBACK(new_do_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp), new_button);
	GtkWidget *cancel_button = gtk_button_new_with_label("Cancel");
	g_signal_connect(G_OBJECT(cancel_button), "clicked", G_CALLBACK(new_cancel_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp), cancel_button);
	 
	gtk_widget_show_all(new_w);
}


