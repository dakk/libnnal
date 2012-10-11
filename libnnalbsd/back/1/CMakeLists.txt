cmake_minimum_required (VERSION 2.6)
project (libneuralnetwork)

include_directories (include)

add_library (neuralnetwork neuralnetwork.c) 
add_executable (nntest neuralnetwork.c)
