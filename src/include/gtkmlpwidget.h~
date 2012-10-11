/**
 * A scalable gtk widget to show and train neural network mlp
 * 
 * \file gtkmlpwidget.h
 * \author Davide Gessa
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
#ifndef GTKMLPWIDGET_H
#define GTKMLPWIDGET_H

#include <gtk/gtk.h>
#include <mlp.h>


struct _GtkMlp
{
	GtkWidget parent;
	
	mlp_neural_network_t *network;
};

struct _GtkMlpClass
 {
        GtkDrawingAreaClass parent_class;
 };



typedef struct _GtkMlp			GtkMlp;
typedef struct _GtkMlpClass		GtkMlpClass;



#define GTK_TYPE_MLP             (gtk_mlp_get_type ())
#define GTK_MLP(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_MLP, GtkMlp))
#define GTK_MLP_CLASS(obj)       (G_TYPE_CHECK_CLASS_CAST ((obj), GTK_MLP,  GtkMlpClass))
#define GTK_IS_MLP(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_MLP))
#define GTK_IS_MLP_CLASS(obj)    (G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_MLP))
#define GTK_MLP_GET_CLASS        (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_MLP, GtkMlpClass))


//http://www.gnomejournal.org/article/34/writing-a-widget-using-cairo-and-gtk28

void gtk_mlp_set_network(GtkMlp *, mlp_neural_network_t *);
mlp_neural_network_t *gtk_mlp_get_network(GtkMlp *);
static void gtk_mlp_class_init(GtkMlpClass *);
static void gtk_mlp_init(GtkMlp *);
GtkWidget *gtk_mlp_new (void);
void __gtk_mlp_draw(GtkWidget *, cairo_t *);
static gboolean gtk_mlp_expose (GtkWidget *, GdkEventExpose *);

#endif
