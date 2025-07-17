

all: nodos.o lista.o main.o
	g++ nodos.o lista.o main.o -g -o run

nodos.o: nodos.hpp nodos.cpp
	g++ -c nodos.cpp

lista.o: lista.hpp lista.cpp
	g++ -c lista.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f ./*.o ./run


correr: run
	./run