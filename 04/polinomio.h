//Manuel Monforte Escobar
//E37

#ifndef polinomio_h
#define polinomio_h

#include <iostream>
#include <algorithm>
#include <vector>
struct monomio{//structura de pares
	int coeficiente;
	int exponente;
};
class polinomio{//creamos clase
public:
	polinomio();
	~polinomio();
	void nuevoMonomio(int c, int exp);
	int evalua(int x);
private:
	std::vector<monomio>pol;//vector con elemento (structura de pares)
};


#endif