// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tSol{
	int dragones = 0;
	int hoja = -1;
};

tSol minDragones(bintree<int> const & arbol){
	tSol sol;
	if (arbol.left().empty() && arbol.right().empty()){
		if (arbol.root() == 1) sol.dragones = 1;
		else  sol.dragones = 0;
		sol.hoja = arbol.root();
		return sol;
	}
	else{
		if (arbol.root() == 1) sol.dragones++;
		if (arbol.right().empty()){
			tSol aux = minDragones(arbol.left());
			sol.dragones += aux.dragones;
			sol.hoja = aux.hoja;
			return sol;
		}
		else if (arbol.left().empty()){
			tSol aux = minDragones(arbol.right());
			sol.dragones += aux.dragones;
			sol.hoja = aux.hoja;
			return sol;
		}
		else{
			tSol izq = minDragones(arbol.left());
			tSol derec = minDragones(arbol.right());
			if (izq.dragones <= derec.dragones){
				sol.dragones += izq.dragones;
				sol.hoja = izq.hoja;
			}
			else{
				sol.dragones += derec.dragones;
				sol.hoja = derec.hoja;
			}
			return sol;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int>arbol = leerArbol(-1);
	std::cout << minDragones(arbol).hoja;

	// escribir sol
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