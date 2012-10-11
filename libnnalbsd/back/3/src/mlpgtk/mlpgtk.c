/**
 * 
 */
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
#include <pattern_recognition.h>
#include <mlp.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <gtk/gtk.h>

GtkWidget* window;
GtkWidget* status_bar;
mlp_neural_network_t *nn;


// Train the network
void
train_cb()
{
	// Ask for epoch and data
	
	// Train
}



// Load the net from file
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



// Save the net in a file
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



// Execute the net
void
execute_cb()
{
	// Execute and display a window with results
}



// Delete net
void
delete_cb()
{
	if(nn == NULL)
		return;
		
	// Are you sure? Delete, Delete&Save, Cancel
}




// New net
GtkWidget *input_spin;
GtkWidget *output_spin;
GtkWidget *hidden_spin;
GtkWidget *learning_spin;
GtkWidget *new_w;

void 
new3_cb()
{

}

void 
new2_cb()
{
	int l[3];
	l[0] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_spin));
	l[1] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hidden_spin));
	l[2] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(output_spin));
	
	nn = mlp_new(l, 3);
	nn->learning_rate = gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(learning_spin));

	//gtk_window_destroy(new_n);
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Network created.");
}


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
	g_signal_connect(G_OBJECT(new_button), "clicked", G_CALLBACK(new2_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp), new_button);
	GtkWidget *cancel_button = gtk_button_new_with_label("Cancel");
	g_signal_connect(G_OBJECT(cancel_button), "clicked", G_CALLBACK(new3_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp), cancel_button);

	 
    gtk_widget_show_all(new_w);
    //gtk_main();	
}



/**
 * 
 */
int 
main(int argc, char **argv)
{
	GtkWidget* boxes[5];
    GtkWidget* tmp;
    gtk_init(&argc, &argv);

	nn = NULL;
	
	new_cb();
	
	// Crea la finestra
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "MultiLayeredPerceptons Gtk");
    gtk_window_resize(GTK_WINDOW(window), 400, 180);
    g_signal_connect(G_OBJECT(window), "destroy", 
                         G_CALLBACK(gtk_main_quit), NULL);
 
	// Aggiunge le box
	boxes[0] = gtk_vbox_new(0, 0);
	boxes[1] = gtk_hbox_new(0, 0);
	boxes[2] = gtk_vbox_new(0, 0);
 	boxes[3] = gtk_vbox_new(0, 0);
 	boxes[4] = gtk_hbox_new(0, 0);
 
	gtk_container_add(GTK_CONTAINER(window), boxes[0]);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[1],FALSE,FALSE,0); 
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[2],FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[3],FALSE,FALSE,0);
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
	g_signal_connect(G_OBJECT(menuitem), "clicked", G_CALLBACK(save_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_separator_menu_item_new();
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);

	menuitem = gtk_menu_item_new_with_label ("Save");
	g_signal_connect(G_OBJECT(menuitem), "clicked", G_CALLBACK(save_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Load");
	g_signal_connect(G_OBJECT(menuitem), "clicked", G_CALLBACK(load_cb), NULL);
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
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Execute");
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
	

	// Status bar
	status_bar = gtk_statusbar_new();
	gtk_container_add(GTK_CONTAINER(boxes[4]), status_bar);
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Ready.");
 
    gtk_widget_show_all(window);
 
    gtk_main();	
}
