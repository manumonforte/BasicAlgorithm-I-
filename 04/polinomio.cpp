//Manuel Monforte Escobar
//E37
#include "polinomio.h"

polinomio::polinomio(){};

polinomio::~polinomio(){};


void polinomio::nuevoMonomio(int c, int exp){
	monomio x;
	x.coeficiente = c;
	x.exponente = exp;
	pol.push_back(x);
	//ordenamos el vector tras insercion por metodo burbuja coste n^2
	int i, j;
	for (i = 0; i < pol.size() - 1; i++){
		for (j = 0; j < pol.size() - i - 1; j++){
			if (pol[j].exponente < pol[j + 1].exponente) std::swap(pol[j], pol[j + 1]);
		}
	}
}

int polinomio::evalua(int x){//calcula el valor para una numero introducido
	int valor = 0;
	for (int i = 0; i < pol.size(); i++){
		valor += pol[i].coeficiente *pow(x, pol[i].exponente);
	}
	return valor;
}
