// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tSolucion{
	int equipos;
	int max;
};

// función que resuelve el problema
tSolucion rescate(bintree<int> const & tree) {
	if (tree.left().empty() && tree.right().empty()){
		tSolucion sol;
		if (tree.root() > 0) {
			sol.equipos = 1;
			sol.max = tree.root();
		}
		else{
			sol.equipos = 0;
			sol.max = 0;
		}
		return sol;
	}
	else{
		tSolucion sol;
		if (!tree.left().empty() && !tree.right().empty()){
			tSolucion izq = rescate(tree.left());
			tSolucion derec = rescate(tree.right());
			if (izq.max > derec.max) sol.max = izq.max;
			else sol.max = derec.max;
			sol.equipos = izq.equipos + derec.equipos;
		}
		else if (!tree.left().empty()){
			sol = rescate(tree.left());
		}
		else if (!tree.right().empty()){
			sol = rescate(tree.right());
		}
		sol.max += tree.root();
		if (sol.equipos == 0 && tree.root() > 0)sol.equipos++;
		return sol;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int vacio = -1;
	bintree<int>arbol = leerArbol(vacio);
	std::vector<int>rescates;

	if (arbol.empty()) std::cout << 0 << " " << 0 << "\n";
	else {
		tSolucion sol = rescate(arbol);
		std::cout << sol.equipos << " " << sol.max << "\n";
	}
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