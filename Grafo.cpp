/** Arquivo Grafo.cpp. Segundo trabalho avaliado EEL670 2022.2
*   Aluno: Luis Guilherme Neri Ferreira */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <limits.h>
#include <float.h>
#include "Grafo.h"

using namespace std;

void Grafo::insereAresta(Aresta* aresta) {
    arestas.push_back(aresta);
}

set <Vertice*> Grafo::getVertices() {
    for (unsigned aresta = 0; aresta < arestas.size(); aresta++) {
        verticesUnicos.insert(arestas[aresta]->getVertice1());
        verticesUnicos.insert(arestas[aresta]->getVertice2());
    }

    return verticesUnicos;
}

vector <Aresta*> Grafo::getArestas() {
    return arestas;
}

float Grafo::dijkstra(Vertice* origem, Vertice* destino) {
    set <Vertice*> naoVisitados = getVertices();
    map <Vertice*, float> distancias;
    map <Vertice*, Vertice*> verticeAnterior;

    for (Vertice* v: naoVisitados)
        distancias[v] = FLT_MAX;

    distancias[origem] = 0;

    while (naoVisitados.size() != 0) {
        Vertice* verticeAtual = *naoVisitados.begin();
        float menorDistancia = FLT_MAX;

        for (Vertice* v: naoVisitados) {
            if (distancias[v] < menorDistancia) {
                menorDistancia = distancias[v];
                verticeAtual = v;
            }
        }

        naoVisitados.erase(verticeAtual);

        if(verticeAtual != destino) {
            for (unsigned a = 0; a < arestas.size(); a++) {
                if (arestas[a]->possuiVertice(verticeAtual)) {
                    Vertice* adjacente = arestas[a]->verticeAdjacente(verticeAtual);

                    if (naoVisitados.find(adjacente) != naoVisitados.end()) {
                        float distancia = distancias[verticeAtual] + arestas[a]->getPeso();

                        if (distancia < distancias[adjacente]) {
                            distancias[adjacente] = distancia;
                            verticeAnterior[adjacente] = verticeAtual;
                        }
                    }
                }
            }
        }
    }

    menorCaminho.push_back(destino);
    Vertice* auxiliar = destino;
    while (verticeAnterior.find(auxiliar) != verticeAnterior.end()) {
        auxiliar = verticeAnterior[auxiliar];
        menorCaminho.insert(menorCaminho.begin(), auxiliar);
    }

    return distancias[destino];
}

void Grafo::imprimeCaminho() {
    unsigned i = 0;
    cout << "\nCaminho: ";
    for (Vertice* v: menorCaminho) {
        i += 1;
        cout << v->getRotulo();
        if (i < menorCaminho.size())
            cout << "->";
    }
    cout << endl;
}

void Grafo::constroiAdjacentes() {
    for (Vertice* v: verticesUnicos) {
        for (Aresta* a: arestas) {
            if (a->possuiVertice(v))
                adjacentes[v].insert(a->verticeAdjacente(v));
        }
    }
}

void Grafo::inicializaVisitados() {
    set <Vertice*> vertices = getVertices();
    for (Vertice* v: vertices)
        visitados[v] = false;
}

Vertice* Grafo::caminhaParaNaoVisitado(Vertice* atual) {
    visitados[atual] = true;

    for (Vertice* v: adjacentes[atual])
        if (!visitados[v])
            caminhaParaNaoVisitado(v);

    return atual;
}

bool Grafo::ehConectado() {
    inicializaVisitados();
    constroiAdjacentes();
    caminhaParaNaoVisitado(*verticesUnicos.begin());

    bool conectado = true;
    for (Vertice* v: verticesUnicos)
        if (!visitados[v])
            conectado = false;

    return conectado;
}

void Grafo::printVerticesEnlaces() {
    getVertices();
    unsigned enlaces = 0, i = 0;
    cout << "(";

    for (Vertice* v: verticesUnicos) {
        for (Aresta* a: arestas)
            if (a->possuiVertice(v))
                enlaces++;

        i++;
        cout << v->getRotulo() << ": " << enlaces;

        if (i != verticesUnicos.size())
            cout << ", ";
        enlaces = 0;
    }

    cout << ")\n";
}

void Grafo::printVertices() {
    getVertices();
    unsigned i = 0;

    cout << "(";
    for (Vertice* v: verticesUnicos) {
        cout << v->getRotulo();
        i++;
        if (i != verticesUnicos.size())
            cout << ", ";
    }
    cout << ")\n";
}

void Grafo::printArestas() {
    unsigned i = 0;

    cout << "(";
    for (Aresta* a: arestas) {
        cout << a->getVertice1()->getRotulo() << a->getVertice2()->getRotulo();
        i++;
        if (i != arestas.size())
            cout << ", ";
    }
    cout << ")\n";
}

void Grafo::maiorCentralidadeDeGrau() {
    getVertices();
    Vertice* maiorVertice;
    float pesoMaiorVertice = 0;

    for(Vertice* v: verticesUnicos) {
        float somaPesos = 0;

        for (Aresta* a: arestas)
            if (a->possuiVertice(v))
                somaPesos += a->getPeso();

        if (somaPesos > pesoMaiorVertice) {
            pesoMaiorVertice = somaPesos;
            maiorVertice = v;
        }
    }

    cout << "\nVertice com maior centralidade de grau: "
         << maiorVertice->getRotulo() << "\nGrau: "
         << pesoMaiorVertice << endl;
}