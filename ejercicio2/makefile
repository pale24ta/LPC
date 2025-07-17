

all: nodos.o lista.o ejercicio.o
	g++ nodos.o lista.o ejercicio.o -g -o run

nodos.o: nodos.hpp nodos.cpp
	g++ -c nodos.cpp

lista.o: lista.hpp lista.cpp
	g++ -c lista.cpp

ejercicio.o: ejercicio.cpp
	g++ -c ejercicio.cpp

clean:
	rm -f ./*.o ./run


correr: run
	./run