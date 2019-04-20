// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tAfluente{
	int caudal;
	int navegables;
};

// función que resuelve el problema
tAfluente tramos(bintree<int>const &tree) {
	if (tree.left().empty() && tree.right().empty()){//si es manantial caudal 1
		tAfluente base;
		base.caudal = 1;
		base.navegables = 0;
		return base;
	}
	else{
		if (!tree.empty()){
			tAfluente sol;
			if (!tree.left().empty() && !tree.right().empty()){//calculamos caudal izq
				tAfluente izq = tramos(tree.left());
				tAfluente derec = tramos(tree.right());
				sol.caudal = izq.caudal + derec.caudal - tree.root();//calculamos caudal total
				sol.navegables = izq.navegables + derec.navegables;
			}
			else if (tree.left().empty()){
				sol = tramos(tree.right());
				sol.caudal = sol.caudal - tree.root();
			}
			else if (tree.right().empty()){
				sol = tramos(tree.left());
				sol.caudal = sol.caudal - tree.root();
			}
			if (sol.caudal < 0) sol.caudal = 0;
			if (sol.caudal >= 3)sol.navegables++;
			return sol;
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int vacio = -1;
	bintree<int>arbol = leerArbol(vacio);
	tAfluente sol = tramos(arbol);
	// escribir sol
	if (sol.caudal >= 3 && sol.caudal >0) sol.navegables--;
	std::cout << sol.navegables << "\n";

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