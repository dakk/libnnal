cmake_minimum_required (VERSION 2.6)
project (libneuralnetwork)

include_directories (include)

add_library (neuralnetwork mlp.c pattern_recognition.c fuzzy.c mathf.c) 
add_executable (../bin/mlptest mlptest.c)
add_executable (../bin/fuzzytest fuzzytest.c)
add_executable (../bin/patterntest patterntest.c)
target_link_libraries (../bin/mlptest neuralnetwork m)
target_link_libraries (../bin/fuzzytest neuralnetwork m)
target_link_libraries (../bin/patterntest neuralnetwork m pnglite)

