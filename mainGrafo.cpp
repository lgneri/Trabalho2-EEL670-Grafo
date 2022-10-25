#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    Vertice A("A");
    Vertice B("1");
    Vertice C("2");
    Vertice D("3");
    Vertice E("4");
    Vertice F("5");
    Vertice G("6");
    Vertice H("7");
    Vertice I("8");

    Aresta AB(&A, &B, 4);
    Aresta BC(&B, &C, 8);
    Aresta CD(&C, &D, 7);
    Aresta DE(&D, &E, 9);
    Aresta EF(&E, &F, 10);
    Aresta FG(&F, &G, 2);
    Aresta GH(&G, &H, 1);
    Aresta GI(&G, &I, 6);
    Aresta HA(&H, &A, 8);
    Aresta BH(&B, &H, 11);
    Aresta HI(&H, &I, 7);
    Aresta CI(&C, &I, 2);
    Aresta CF(&C, &F, 4);
    Aresta DF(&D, &F, 14);

    Grafo Grafo;
    Grafo.insereAresta(&AB);
    Grafo.insereAresta(&BC);
    Grafo.insereAresta(&CD);
    Grafo.insereAresta(&DE);
    Grafo.insereAresta(&EF);
    Grafo.insereAresta(&FG);
    Grafo.insereAresta(&GH);
    Grafo.insereAresta(&GI);
    Grafo.insereAresta(&HA);
    Grafo.insereAresta(&BH);
    Grafo.insereAresta(&HI);
    Grafo.insereAresta(&CI);
    Grafo.insereAresta(&CF);
    Grafo.insereAresta(&DF);

    //cout << "\nDistancia = " << Grafo.dijkstra(&C, &H);
    //Grafo.imprimeCaminho();

    //Grafo.printVerticesEnlaces();
    Grafo.printVertices();
    Grafo.printArestas();
    //Grafo.ehConectado(&A);

}