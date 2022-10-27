/** Arquivo Grafo.h. Segundo trabalho avaliado EEL670 2022.2
*   Aluno: Luis Guilherme Neri Ferreira */

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <set>
#include <map>
#include "Aresta.h"

class Grafo {
    public:
        void insereAresta(Aresta*);
        void imprimeCaminho();
        set <Vertice*> getVertices();
        vector <Aresta*> getArestas();
        float dijkstra(Vertice*, Vertice*);
        bool ehConectado();
        void printVerticesEnlaces();
        void printVertices();
        void printArestas();
        void maiorCentralidadeDeGrau();
    private:
        vector <Aresta*> arestas;
        set <Vertice*> verticesUnicos;
        vector<Vertice*> menorCaminho;
        map <Vertice*, bool> visitados;
        map <Vertice*, set <Vertice*>> adjacentes;
        Vertice* caminhaParaNaoVisitado(Vertice*);
        void inicializaVisitados();
        void constroiAdjacentes();
        void inicializaVertices();
};

#endif