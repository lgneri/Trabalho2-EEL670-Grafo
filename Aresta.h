/** Arquivo Aresta.h. Segundo trabalho avaliado EEL670 2022.2
*   Aluno: Luis Guilherme Neri Ferreira */

#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

using namespace std;

class Aresta {
	public:
		Aresta(Vertice*, Vertice*, float = 1.0);
		float getPeso();
		Vertice* getVertice1();
		Vertice* getVertice2();
		bool possuiVertice(Vertice*);
		Vertice* verticeAdjacente(Vertice*);
	private:
		Vertice* vertice1;
		Vertice* vertice2;
		float peso;
};

#endif
