#include <iostream>
#include <vector>
#include "Caminho.h"

using namespace std;

int main() {
	Vertice v1 ("A"), v2 ("B"), v3 ("C"), v4 ("D"), v5 ("E");
	Aresta a1 (&v1, &v2), a2 (&v2, &v3, 2.5), a3 (&v3, &v4, 1.5), aerr (&v4, &v5);

	Caminho caminho;
	caminho.insereAresta(&a1);
	caminho.insereAresta(&a2);
	caminho.insereAresta(&a3);
	caminho.insereAresta(&aerr);
	caminho.imprimeCaminho();
	
	return 0;
}
