#     libnnal
#     Copyright (C) 2010 Davide Gessa
# 
# 	This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required (VERSION 2.6)
project (libnnal)
SET (AUTHOR "Davide Gessa" INTERNAL "Author")
SET (VERSION "0.1.0")

INCLUDE (FindPkgConfig)

IF (NOT PKG_CONFIG_FOUND)
	MESSAGE (FATAL_ERROR "pkg-config not found...")
ENDIF (NOT PKG_CONFIG_FOUND)

pkg_check_modules (GTK REQUIRED gtk+-2.0>=2.6)
pkg_check_modules (OPENSSL REQUIRED openssl)


IF (NOT GTK_FOUND)
	MESSAGE(FATAL_ERROR "You don't seem to have gtk >= 2.6 development libraries installed...")
ENDIF (NOT GTK_FOUND)

ADD_DEFINITIONS()


include_directories (include ${GTK_INCLUDE_DIRS})
include_directories (include ${OPENSSL_INCLUDE_DIRS})
include_directories (include ${SDL_INCLUDE_DIRS})
include_directories (include /usr/include/python2.6)
include_directories (include /usr/local/include/)
include_directories (include /usr/local/include/gtk-2.0/)
include_directories (include /usr/local/include/)
include_directories (include /usr/local/include/glib-2.0/)
include_directories (include /usr/local/include/cairo/)
include_directories (include /usr/local/include/pango-1.0/)
include_directories (include /usr/local/include/atk-1.0)

add_library (neuralnetwork mlp.c pattern_recognition.c fuzzy.c mathf.c som.c pnglite.c) 
add_library (gtkmlpwidget gtkmlpwidget.c) 
add_library (pnglite pnglite.c) 

add_executable (../bin/mlptest test/mlptest.c)
add_executable (../bin/patterngtk patterngtk/patterngtk.c)
add_executable (../bin/mlpgtk mlpgtk/mlpgtk.c mlpgtk/new_net.c)
add_executable (../bin/fuzzytest test/fuzzytest.c)
add_executable (../bin/patterntest test/patterntest.c)
add_executable (../bin/bptimetest test/bptimetest.c)
add_executable (../bin/epochtest test/epochtest.c)
#add_executable (../bin/md5mlp test/md5mlp.c)
add_executable (../bin/gtkmlptest test/gtkmlptest.c)

target_link_libraries (../bin/mlptest neuralnetwork m)
target_link_libraries (../bin/patterngtk pnglite /usr/lib/libz.so  /usr/local/lib/libgtk-x11-2.0.so neuralnetwork m gtkmlpwidget)
target_link_libraries (../bin/gtkmlptest pnglite gtkmlpwidget /usr/lib/libz.so /usr/local/lib/libcairo.so /usr/local/lib/libgtk-x11-2.0.so neuralnetwork m)
target_link_libraries (../bin/mlpgtk /usr/local/lib/libgtk-x11-2.0.so neuralnetwork m gtkmlpwidget)
target_link_libraries (../bin/fuzzytest neuralnetwork m)
target_link_libraries (../bin/epochtest neuralnetwork m)
#target_link_libraries (../bin/md5mlp ${OPENSSL_LIBRARIES} neuralnetwork m)
target_link_libraries (../bin/bptimetest neuralnetwork m)
target_link_libraries (../bin/patterntest /usr/lib/libz.so  neuralnetwork m pnglite)

