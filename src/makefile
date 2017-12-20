SUFFIX=`python3-config --extension-suffix`
PYTHON_ARGS=`pkg-config --cflags --libs python3`
CXX_FLAGS=-std=c++14 -shared -fPIC

all: module

print.o: print.cpp
	g++ ${CXX_FLAGS} -I../include -I../pybind11/include print.cpp -c

module: module.cpp print.o ../include/sequence.hpp
	g++ ${CXX_FLAGS} -I../include -I../pybind11/include ${PYTHON_ARGS} module.cpp -o module${SUFFIX} print.o
	touch module

clean:
	rm -f *.so
	rm -f *.o
	rm -f module
