cmake_minimum_required (VERSION 2.6)
project (libneuralnetwork)
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

add_library (neuralnetwork mlp.c pattern_recognition.c fuzzy.c mathf.c som.c) 
add_library (gtkmlpwidget gtkmlpwidget.c) 
add_executable (../bin/mlptest test/mlptest.c)
add_executable (../bin/patterngtk patterngtk/patterngtk.c)
add_executable (../bin/mlpgtk mlpgtk/mlpgtk.c)
add_executable (../bin/fuzzytest test/fuzzytest.c)
add_executable (../bin/patterntest test/patterntest.c)
add_executable (../bin/bptimetest test/bptimetest.c)
add_executable (../bin/epochtest test/epochtest.c)
add_executable (../bin/md5mlp test/md5mlp.c)
add_executable (../bin/gtkmlptest test/gtkmlptest.c)
target_link_libraries (../bin/mlptest neuralnetwork m)
target_link_libraries (../bin/patterngtk pnglite ${GTK_LIBRARIES} neuralnetwork m gtkmlpwidget)
target_link_libraries (../bin/gtkmlptest pnglite gtkmlpwidget cairo ${GTK_LIBRARIES} neuralnetwork m)
target_link_libraries (../bin/mlpgtk ${GTK_LIBRARIES} neuralnetwork m gtkmlpwidget)
target_link_libraries (../bin/fuzzytest neuralnetwork m)
target_link_libraries (../bin/epochtest neuralnetwork m)
target_link_libraries (../bin/md5mlp ${OPENSSL_LIBRARIES} neuralnetwork m)
target_link_libraries (../bin/bptimetest neuralnetwork m)
target_link_libraries (../bin/patterntest neuralnetwork m pnglite)

