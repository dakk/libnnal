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
#include "mlpgtk.h"
#include <mlp.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtkmlpwidget.h>




/* Train the network */
void
train_cb()
{
	int i;
	// Ask for epoch and data
	
	// Train


	GtkWidget *d = gtk_file_chooser_dialog_new("Train from file", 
												GTK_WINDOW(window),
												GTK_FILE_CHOOSER_ACTION_OPEN, 
												GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
												GTK_STOCK_OPEN,   GTK_RESPONSE_OK,
												NULL);

	gtk_dialog_run(GTK_DIALOG(d));
	gtk_widget_destroy(d);


	for(i=0;i<1000;i++)
		mlp_file_train(nn, gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(d)));
}



/* Load the net from file */
void
load_cb()
{
	GtkWidget *d = gtk_file_chooser_dialog_new("Load the network", 
							GTK_WINDOW(window),
							GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, 
							"Load", NULL);
	gtk_dialog_run(GTK_DIALOG(d));
	gtk_widget_destroy(d);
	
}



/* Save the net in a file */
void
save_cb()
{
	GtkWidget *d = gtk_file_chooser_dialog_new("Save the network", 
							GTK_WINDOW(window),
							GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, 
							"Save", NULL);
	gtk_dialog_run(GTK_DIALOG(d));
	gtk_widget_destroy(d);
}



/* Execute the net */
void
execute_cb()
{
	int i;
  	double *in = (double *) malloc(sizeof(double) * nn->input_n);
	double *out = (double *) malloc(sizeof(double) * nn->output_n);
	
	
	for(i = 0; i < nn->input_n; i++)
	{
		in[i] = gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(neural_input[i]));
	}
	
		
	mlp_execute(nn, in, out);
	
	for(i = 0; i < nn->output_n; i++)
	{
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(neural_output[i]), out[i]);
	}
	
	free(in);
	free(out);
}



/* Delete net */
void
delete_cb()
{
	if(nn == NULL)
		return;
		
	// Are you sure? Delete, Delete&Save, Cancel
}








/* Learning callback */       
static gboolean
update_cb(GtkWidget *widget)
{
	gtk_widget_queue_draw(mlp);	
}





/**
 * 
 */
int 
main(int argc, char **argv)
{
	GtkWidget* boxes[7];
	GtkWidget* tmp;
	gtk_init(&argc, &argv);

	nn = NULL;
	mlp = gtk_mlp_new();
	new_cb();
	
	// Crea la finestra
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "MultiLayeredPerceptons Gtk");
	gtk_window_resize(GTK_WINDOW(window), 600, 315);
	g_signal_connect(G_OBJECT(window), "destroy", 
                         G_CALLBACK(gtk_main_quit), NULL);
 
	// Aggiunge le box
	boxes[0] = gtk_vbox_new(0, 0);
	boxes[1] = gtk_hbox_new(0, 0);
	boxes[2] = gtk_vbox_new(0, 0);
 	boxes[3] = gtk_hbox_new(0, 0);
 	boxes[4] = gtk_hbox_new(0, 0);
 	boxes[5] = gtk_vbox_new(0, 0);
 	boxes[6] = gtk_vbox_new(0, 0);
 
	gtk_container_add(GTK_CONTAINER(window), boxes[0]);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[1],FALSE,FALSE,0); 
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[2],FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[3],TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[4],FALSE,FALSE,0); 
 
	// Menubar
	GtkWidget *menu;
	GtkWidget *menuitem;
	GtkWidget *menu_sub;
	
	menu = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(boxes[1]),menu,TRUE,TRUE,0);

	// 
	GtkWidget *menu_file = gtk_menu_item_new_with_label("File");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_file);

	menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_file), menu_sub);

	menuitem = gtk_menu_item_new_with_label ("Open");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(load_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_separator_menu_item_new();
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_menu_item_new_with_label ("Save");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(save_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Load");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(load_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_separator_menu_item_new();
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);


	menuitem = gtk_menu_item_new_with_label ("Close");
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	//	Network
	GtkWidget *menu_net = gtk_menu_item_new_with_label("Network");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_net);


	menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_net), menu_sub);

	menuitem = gtk_menu_item_new_with_label ("New");
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_menu_item_new_with_label ("Delete");
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_separator_menu_item_new();
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_menu_item_new_with_label ("Train");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(train_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Execute");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(execute_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	

	// Help
	GtkWidget *menu_help = gtk_menu_item_new_with_label("Help");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_help);

	menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_help), menu_sub);

	menuitem = gtk_menu_item_new_with_label ("About");
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Website");
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);


	// Inside show the network with neurons
	gtk_container_add(GTK_CONTAINER(boxes[3]), boxes[5]);
	gtk_container_add(GTK_CONTAINER(boxes[3]), boxes[6]);

	entry_box = boxes[6];

	gtk_container_add(GTK_CONTAINER(boxes[5]), mlp);
	g_timeout_add(10, (GSourceFunc) update_cb, (gpointer) mlp);


	// Status bar
	status_bar = gtk_statusbar_new();
	gtk_container_add(GTK_CONTAINER(boxes[4]), status_bar);
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Ready.");
 

	gtk_widget_show_all(window);
	gtk_main();	
}

