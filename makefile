# Arquivo makefile para o programa do grafo.
# Segundo trabalho avaliado EEL670 2022.2
# Aluno: Luis Guilherme Neri Ferreira

CPP = g++
CPPFLAGS = -Wall -std=c++11

all:
	$(CPP) $(CPPFLAGS) -o grafo Aresta.cpp Vertice.cpp Grafo.cpp mainGrafo.cpp

clean:
	rm grafo