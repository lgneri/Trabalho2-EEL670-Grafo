CPP = g++
CPPFLAGS = -Wall -std=c++11

all:
	$(CPP) $(CPPFLAGS) -o grafo Aresta.cpp Vertice.cpp Grafo.cpp mainGrafo.cpp

clean:
	rm grafo