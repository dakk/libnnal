/**
 * Simple program to show how letter recognition work
 * 
 * \author Davide Gessa
 * \date 20/04/2010
 * 
 * \todo add a button to show the graphic network
 * \todo frames
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
#include <gtkmlpwidget.h>
#include "patterngtk.h"


int 
main(int argc, char **argv)
{
	GtkWidget* boxes[5];
	GtkWidget* tmp_frame;
    GtkWidget* tmp;
    window2 = NULL;
    gtk_init(&argc, &argv);

	pattern_net = NULL;
	
	reset_cb();
	
	// Crea la finestra
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "PatternGtk");
    gtk_container_set_border_width (GTK_CONTAINER (window), 2);

    GtkWidget *image = gtk_image_new(); 
    GdkPixbuf *pixbuf = gtk_widget_render_icon(image, GTK_STOCK_REFRESH, 32, NULL); 

    gtk_window_set_default_icon(pixbuf);

    gtk_window_resize(GTK_WINDOW(window), 200, 180);
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
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[2],1,1,0);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[3],FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(boxes[0]),boxes[4],FALSE,FALSE,0); 
 
	// Menubar
	GtkWidget *menu;
	GtkWidget *menuitem;
	GtkWidget *menu_sub;
	GtkWidget *menu_show;
	GtkWidget *menu_net;
	GtkWidget *menu_help;
	
	menu = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(boxes[1]),menu,TRUE,TRUE,0);

	// Net Menu
	menu_net = gtk_menu_item_new_with_label("Neural Network");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_net);

	menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_net), menu_sub);

	menuitem = gtk_menu_item_new_with_label ("Train");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(train_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Execute");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(eval_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Reset");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(reset_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	
	menuitem = gtk_separator_menu_item_new();
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	
	menuitem = gtk_menu_item_new_with_label ("Save");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(save_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	menuitem = gtk_menu_item_new_with_label ("Load");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(load_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);
	
	
	// Show
	menu_show = gtk_menu_item_new_with_label("Show");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_show);

	menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_show), menu_sub);

	menuitem = gtk_menu_item_new_with_label ("Cairo");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(show_cairo_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);


	
	// Help
	menu_help = gtk_menu_item_new_with_label("Help");
	gtk_menu_bar_append (GTK_MENU_BAR(menu), menu_help);
	gtk_menu_item_set_right_justified(GTK_MENU_ITEM(menu_help), 1);

	menu_sub = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_help), menu_sub);

	menuitem = gtk_menu_item_new_with_label ("About");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(about_cb), NULL);
	gtk_menu_append(GTK_MENU(menu_sub), menuitem);


	

	// Train section
	tmp_frame = gtk_frame_new("Training");
	gtk_frame_set_shadow_type (GTK_FRAME (tmp_frame), GTK_SHADOW_OUT);
	gtk_box_pack_start(GTK_BOX(boxes[2]),tmp_frame,FALSE,FALSE,0); 
	//gtk_container_add (GTK_CONTAINER(tmp_frame), tmp);
	GtkWidget *tmp_box = gtk_vbox_new(1, 0);
	 
	gtk_container_add (GTK_CONTAINER(tmp_frame), tmp_box);
	
	tmp = gtk_hbox_new(1, 0);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp,FALSE,FALSE,0);
	
	gtk_box_pack_start(GTK_BOX(tmp), gtk_label_new("Training patterns directory: "),FALSE,FALSE,0);
	train_dir = gtk_file_chooser_button_new("Directory", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	gtk_container_add(GTK_CONTAINER(tmp), train_dir);

	tmp = gtk_hbox_new(1, 0);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp,FALSE,FALSE,0); 
	
	gtk_box_pack_start(GTK_BOX(tmp),gtk_label_new("Epoch number: "),FALSE,FALSE,0);
	train_spin = gtk_spin_button_new(
		GTK_ADJUSTMENT(gtk_adjustment_new(10.0, 0.0, 10000.0, 1.0, 10.0, 10.0)), 
		1.0, 0);
	gtk_container_add(GTK_CONTAINER(tmp), train_spin);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp,FALSE,FALSE,0); 


	tmp = gtk_hbox_new(1, 0);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp,FALSE,FALSE,0); 
	
	gtk_box_pack_start(GTK_BOX(tmp),gtk_label_new("Learning rate: "),FALSE,FALSE,0);
	lr_spin = gtk_spin_button_new(
		GTK_ADJUSTMENT(gtk_adjustment_new(0.6, 0.0, 1.0, 0.02, 0.2, 1.0)), 
		1.0, 2);
	gtk_container_add(GTK_CONTAINER(tmp), lr_spin);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp,FALSE,FALSE,0); 


	progress_bar = gtk_progress_bar_new();
	gtk_container_add(GTK_CONTAINER(tmp_box), progress_bar);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress_bar), GTK_PROGRESS_LEFT_TO_RIGHT);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 1.0);


	GtkWidget *tmp2 = gtk_hbox_new(1, 0);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp2,FALSE,FALSE,0); 
 
 
	train_button = gtk_button_new_with_label("Train");
	g_signal_connect(G_OBJECT(train_button), "clicked", G_CALLBACK(train_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp2), train_button);
	
	/*tmp = gtk_button_new_with_label("Save");
	g_signal_connect(G_OBJECT(tmp), "clicked", G_CALLBACK(save_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp2), tmp);
 
	tmp = gtk_button_new_with_label("Load");
	g_signal_connect(G_OBJECT(tmp), "clicked", G_CALLBACK(load_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp2), tmp);
	*/
	// Test section
	tmp_frame = gtk_frame_new("Execute");
	gtk_frame_set_shadow_type (GTK_FRAME (tmp_frame), GTK_SHADOW_OUT);
	gtk_box_pack_start(GTK_BOX(boxes[3]),tmp_frame,FALSE,FALSE,0); 

	tmp_box = gtk_vbox_new(0, 0);
	 
	gtk_container_add (GTK_CONTAINER(tmp_frame), tmp_box);

	tmp = gtk_hbox_new(1, 0);
	gtk_box_pack_start(GTK_BOX(tmp_box),tmp,FALSE,FALSE,0); 
	
	gtk_box_pack_start(GTK_BOX(tmp), gtk_label_new("Image to evalute: "),FALSE,FALSE,0);
	eval_file = gtk_file_chooser_button_new("Image file", GTK_FILE_CHOOSER_ACTION_OPEN);
	g_signal_connect(G_OBJECT(eval_file), "file-set", G_CALLBACK(image_set_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp), eval_file);


	tmp = gtk_hbox_new(1, 0);
	eval_image = gtk_image_new_from_file("//");
	gtk_container_add(GTK_CONTAINER(tmp), eval_image);
	gtk_box_pack_start(GTK_BOX(tmp), gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD, 36),FALSE,FALSE,0);
	eval_entry = gtk_entry_new();
	gtk_container_add(GTK_CONTAINER(tmp), eval_entry);
	gtk_container_add(GTK_CONTAINER(tmp_box), tmp);
	
	eval_button = gtk_button_new_with_label("Execute");
	g_signal_connect(G_OBJECT(eval_button), "clicked", G_CALLBACK(eval_cb), NULL);
	gtk_container_add(GTK_CONTAINER(tmp_box), eval_button);


	// Status bar
	status_bar = gtk_statusbar_new();
	gtk_container_add(GTK_CONTAINER(boxes[4]), status_bar);
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Ready.");
 
    gtk_widget_show_all(window);
 
    gtk_main();	
}



// Train the network
void
train_cb()
{
	int i;
	int epoch = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(train_spin));
	char a[64];

	pattern_net->learning_rate = (double) gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(lr_spin));
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Training started.");
	
	for(i = 0; i < epoch; i++)
	{
		DIR *d = opendir(gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(train_dir)));
		if(d != NULL)
		{
			struct dirent *de;
			while((de = readdir(d)) != NULL)
			{
				char a = de->d_name[0];
				char p[1024];
				strcpy(p, gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(train_dir)));
				strcat(p, "/");
				strcat(p, de->d_name);
				if(de->d_name[0] == '.')
					continue;
						
				pattern_backpropagate(pattern_net, p, a - 'a'); 		
			}
		}
		closedir(d);
		
		if((i % 2) == 0)
			gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progress_bar));
	
		else if((i%15) == 0)
			if(window2 != NULL)
				gtk_widget_queue_draw(mlp);	

		sprintf(a, "%d%%", 100*i/epoch+1);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress_bar), a);
		gtk_main_iteration_do(1);
	}	
	
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "Training completed!");
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress_bar), "Completed!");
	GtkWidget *d = gtk_message_dialog_new(	GTK_WINDOW(window),
											GTK_DIALOG_DESTROY_WITH_PARENT,
											GTK_MESSAGE_INFO,
											GTK_BUTTONS_OK,
											"Training complete");
	gtk_dialog_run(GTK_DIALOG(d));
	gtk_widget_destroy(d);
}




// About message dialog
void
about_cb()
{
	GtkWidget *d = gtk_message_dialog_new(	GTK_WINDOW(window),
											GTK_DIALOG_DESTROY_WITH_PARENT,
											GTK_MESSAGE_INFO,
											GTK_BUTTONS_OK,
											"This program was realized by Davide Gessa (dak.linux@gmail.com)");
	gtk_dialog_run(GTK_DIALOG(d));
	gtk_widget_destroy(d);
}



// Set image callback
void
image_set_cb()
{
	gtk_image_set_from_file(GTK_IMAGE(eval_image), 
							gtk_file_chooser_get_filename(
									GTK_FILE_CHOOSER(eval_file)));	
}


// Load the net from file
void
load_cb()
{
	GtkWidget *d = gtk_file_chooser_dialog_new("Load the network", 
												GTK_WINDOW(window),
												GTK_FILE_CHOOSER_ACTION_OPEN, 
												GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
												GTK_STOCK_OPEN,   GTK_RESPONSE_OK,
												NULL);
	gtk_dialog_run(GTK_DIALOG(d));
	char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(d));
	mlp_delete(pattern_net);
	pattern_net = mlp_load(filename);
	gtk_widget_destroy(d);
	
	if(pattern_net == NULL)
	{
		
	}
}


// Save the net in a file
void
save_cb()
{
	GtkWidget *d = gtk_file_chooser_dialog_new("Save the network", 
												GTK_WINDOW(window),
												GTK_FILE_CHOOSER_ACTION_SAVE, 
												GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
												GTK_STOCK_SAVE,   GTK_RESPONSE_OK,
												NULL);
                                 
	gtk_dialog_run(GTK_DIALOG(d));
	char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(d));
	mlp_save(pattern_net, filename);
	gtk_widget_destroy(d);
}



// Execute the net
void
eval_cb()
{
	char c[24];
	double *outs;
	
	outs = (double *) malloc(sizeof(double) * pattern_net->output_n);
	
	if(outs == NULL)
	{
		gtk_entry_set_text(GTK_ENTRY(eval_entry), "#ER#");		
		return;
	}
	if(pattern_recognition(pattern_net, 
						gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(eval_file)), 
						outs) == NULL)
	{
		gtk_entry_set_text(GTK_ENTRY(eval_entry), "#ER#");		
		free(outs);
		return;
	}
						
	sprintf(c, "%c", pattern_getchar(outs, 36));
	gtk_entry_set_text(GTK_ENTRY(eval_entry), c);
	 
	free(outs);
}


/* Create a window that show the gtkmlpwidget */
void 
show_cairo_cb()
{
	window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window2), "Show - Cairo");
    gtk_window_resize(GTK_WINDOW(window2), 500, 500);

	mlp = gtk_mlp_new();
    gtk_mlp_set_network(GTK_MLP(mlp), pattern_net);
    gtk_container_add (GTK_CONTAINER (window2), mlp);

    g_signal_connect (window, "destroy",
                        G_CALLBACK (gtk_main_quit), NULL);

    gtk_widget_show_all (window2);

    gtk_main();	
}



/* Delete (if any) and recreate the network */
void 
reset_cb()
{
	if(pattern_net != NULL)
		mlp_delete(pattern_net);

	// Create the net
	int ls[] = { 16*16, 16, 36 };
	pattern_net = mlp_new(ls, 3);
	
	if(pattern_net == NULL)
	{
		GtkWidget *d = gtk_message_dialog_new(	NULL,
												GTK_DIALOG_DESTROY_WITH_PARENT,
												GTK_MESSAGE_ERROR,
												GTK_BUTTONS_OK,
												"Cannot create neural network");
		gtk_dialog_run(GTK_DIALOG(d));
		gtk_widget_destroy(d);
		gtk_main_quit();		
	}
	
	mlp_set_learning_rate(pattern_net, 0.6);
	pattern_net->transf_func = &heavyside;
	pattern_net->transf_func_derivate = &heavyside_derivate;
}
