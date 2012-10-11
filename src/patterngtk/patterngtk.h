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
#include <malloc.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <gtk/gtk.h>

GtkWidget* window;
GtkWidget* lr_spin;
GtkWidget* train_button;
GtkWidget* train_spin;
GtkWidget* train_dir;
GtkWidget* eval_button;
GtkWidget* eval_file;
GtkWidget* eval_image;
GtkWidget* status_bar;
GtkWidget* progress_bar;
GtkWidget *window2;
GtkWidget *mlp;
GtkWidget* eval_entry;
mlp_neural_network_t *pattern_net;


void reset_cb();
void train_cb();
void about_cb();
void image_set_cb();
void load_cb();
void save_cb();
void eval_cb();
void show_cairo_cb();

