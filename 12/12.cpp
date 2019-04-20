// Manuel Monforte
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_hija.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int vacio = -1;
	bintree_ext<int> arbol;
	arbol = leerArbol_ext(vacio);
	std::vector<int>frontera;
	arbol.frontera(frontera);
	for (int i = 0; i < frontera.size(); i++)std::cout << frontera[i] << " ";
	std::cout << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}