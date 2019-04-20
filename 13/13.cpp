// Manuel Monforte
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <string>


// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char type;
	std::cin >> type;
	if (!std::cin)
		return false;

	if (type == 'P'){
		bintree<std::string>arbol;
		std::string vacioP = "#";
		arbol = leerArbol(vacioP);
		std::cout << arbol.findLess();
	}
	else {
		bintree<int>arbol;
		int vacioN = -1;
		arbol = leerArbol(vacioN);
		std::cout << arbol.findLess();
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