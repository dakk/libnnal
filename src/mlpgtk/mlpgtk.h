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
#ifndef MLPGTK_H_
#define MLPGTK_H_

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


GtkWidget* mlp;
GtkWidget* window;
GtkWidget* entry_box;
GtkWidget* status_bar;
mlp_neural_network_t *nn;
GtkWidget** neural_input;
GtkWidget** neural_output;

void save_cb();
void train_cb();
void load_cb();
void execute_cb();
void delete_cb();
void new_cb();
static gboolean update_cb(GtkWidget *);

#endif
