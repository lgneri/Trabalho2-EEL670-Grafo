/** Arquivo Aresta.cpp. Segundo trabalho avaliado EEL670 2022.2
*   Aluno: Luis Guilherme Neri Ferreira */

#include <string>
#include "Aresta.h"
#include "Vertice.h"

using namespace std;

Aresta::Aresta(Vertice* v1, Vertice* v2, float p) {
	vertice1 = v1;
	vertice2 = v2;
 	peso = p;
}

float Aresta::getPeso() {
	return peso;
}

Vertice* Aresta::getVertice1() {
	return vertice1;
}

Vertice* Aresta::getVertice2() {
	return vertice2;
}

bool Aresta::possuiVertice(Vertice* vertice) {
	if (vertice == vertice1 || vertice == vertice2)
		return true;

	return false;
}

Vertice* Aresta::verticeAdjacente(Vertice* vertice) {
	if(vertice == vertice1)
		return vertice2;
	return vertice1;
}
