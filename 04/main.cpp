//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "polinomio.h"



// función que resuelve el problema
int resolver(polinomio actual, int n) {
	return actual.evalua(n);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int c, exp;
	std::cin >> c;
	if (!std::cin)
		return false;
	std::cin >> exp;
	polinomio nuevo;
	while (c != 0 || exp != 0){
		nuevo.nuevoMonomio(c, exp);
		std::cin >> c;
		std::cin >> exp;
	}
	int n;
	std::cin >> n;
	int sol = -1;
	int x;
	for (int i = 0; i < n; i++){
		std::cin >> x;
		sol = resolver(nuevo, x);
		std::cout << sol << " ";
	}
	std::cout << "\n";
	return true;
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}