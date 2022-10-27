/** Arquivo Vertice.h. Segundo trabalho avaliado EEL670 2022.2
*   Aluno: Luis Guilherme Neri Ferreira */

#ifndef VERTICE_H
#define VERTICE_H

#include <string>

using namespace std;

class Vertice {
	public:
		Vertice(string);
		string getRotulo();
	private:
		string rotulo;
};

#endif
