swig -python wrapper/wrapper_py.i
gcc -c wrapper/wrapper_py_wrap.c mathf.c mlp.c -I/usr/include/python2.6 -Iinclude
mv wrapper_py_wrap.o wrapper
ld -shared wrapper/wrapper_py_wrap.o mlp.o mathf.o -o wrapper/_nnal.so 

