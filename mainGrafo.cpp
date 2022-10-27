/** Arquivo mainGrafo.cpp. Segundo trabalho avaliado EEL670 2022.2
*   Aluno: Luis Guilherme Neri Ferreira */

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "Grafo.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<vector<string>> conteudo;
    vector<string> linhas;
    string linha, dado;


    fstream file (argv[1], ios::in);
    if (file.is_open())
    {
        while(getline(file, linha))
        {
            linhas.clear();
            stringstream str(linha);

            while(getline(str, dado, ','))
            {
                linhas.push_back(dado);
            }

            conteudo.push_back(linhas);
        }
    }
    else
        cout << "Nao foi possivel abrir o arquivo.\n";


    Grafo Grafo;
    map <string, Vertice*> vertices;

    for (unsigned i = 0; i < conteudo.size(); i++) {
        string nomeVertice1 = conteudo[i][0];
        string nomeVertice2 = conteudo[i][1];
        float peso = stof(conteudo[i][2]);

        if (vertices.find(nomeVertice1) == vertices.end())
            vertices[nomeVertice1] = new Vertice(nomeVertice1);

        if (vertices.find(nomeVertice2) == vertices.end())
            vertices[nomeVertice2] = new Vertice(nomeVertice2);

        Grafo.insereAresta(new Aresta(vertices[nomeVertice1], vertices[nomeVertice2], peso));
    }

    while (true) {
        cout << "\nEntre com o numero correspondente ao dado que deseja visualizar:"
        << "\n1: Lista de vertices e o respectivo numero de enlaces."
        << "\n2: Lista de todos os vertices e enlaces existentes no grafo."
        << "\n3: Caminho de menor custo entre dois vertices escolhidos."
        << "\n4: Se o grafo eh totalmente conectado ou nao."
        << "\n5: Vertice com a maior centralidade de grau."
        << endl;
        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            cout << "\nLista de vertices e o respectivo numero de enlaces:\n";
            Grafo.printVerticesEnlaces();
            int escolha2;
            cout << "\nDigite 0 para voltar ao menu ou qualquer coisa para sair: ";
            cin >> escolha2;
            if (escolha2 != 0)
                break;
        }

        else if (escolha == 2) {
            cout << "\nLista de todos os vertices e enlaces existentes no grafo:\n";
            Grafo.printVertices();
            Grafo.printArestas();
            int escolha2;
            cout << "\nDigite 0 para voltar ao menu ou qualquer coisa para sair: ";
            cin >> escolha2;
            if (escolha2 != 0)
                break;
        }

        else if (escolha == 3) {
            string origem, destino;
            cout << "\nDigite o nome do vertice de origem: ";
            cin >> origem;
            cout << "Digite o nome do vertice de destino: ";
            cin >> destino;
            cout << "\nDistancia = " << Grafo.dijkstra(vertices[origem], vertices[destino]);
            Grafo.imprimeCaminho();
            int escolha2;
            cout << "\nDigite 0 para voltar ao menu ou qualquer coisa para sair: ";
            cin >> escolha2;
            if (escolha2 != 0)
                break;
        }

        else if (escolha == 4) {
            if (Grafo.ehConectado())
                cout << "\nTrue, o grafo eh totalmente conectado." << endl;
            else
                cout << "\nFalse, o grafo nao eh totalmente conectado." << endl;

            int escolha2;
            cout << "\nDigite 0 para voltar ao menu ou qualquer coisa para sair: ";
            cin >> escolha2;
            if (escolha2 != 0)
                break;
        }

        else if (escolha == 5) {
            Grafo.maiorCentralidadeDeGrau();
            int escolha2;
            cout << "\nDigite 0 para voltar ao menu ou qualquer coisa para sair: ";
            cin >> escolha2;
            if (escolha2 != 0)
                break;
        }

        else {
            cout << "\nOpcao invalida." << endl;
            break;
        }
    }

return 0;
}
