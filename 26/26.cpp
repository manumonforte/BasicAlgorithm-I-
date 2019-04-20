// Manuel Monforte Esocbar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tSol{
	int max = -1;
	int min = -1;
	bool valido;
};
// función que resuelve el problema
tSol esBusqueda(const bintree<int> & tree) {
	tSol sol;
	if (tree.empty()) sol.valido = true;
	else if (tree.left().empty() && tree.right().empty()){
		sol.max = tree.root();
		sol.min = tree.root();
		sol.valido = true;
	}
	else if (tree.left().empty()){
		sol = esBusqueda(tree.right());
		if (tree.root() < sol.min && sol.valido) sol.valido = true;
		else sol.valido = false;
		sol.min = std::min(sol.min, tree.root());
		sol.max = std::max(sol.max, tree.root());
	}
	else if (tree.right().empty()){
		sol = esBusqueda(tree.left());
		if (tree.root() > sol.max && sol.valido ) sol.valido = true;
		else sol.valido = false;
		sol.min = std::min(sol.min, tree.root());
		sol.max = std::max(sol.max, tree.root());
	}
	else{
		tSol izq = esBusqueda(tree.left());
		tSol derec = esBusqueda(tree.right());
		sol.max = std::max(derec.max,izq.max);
		sol.max = std::max(sol.max, tree.root());

		sol.min = std::min(izq.min, derec.min);
		sol.min = std::min(sol.min, tree.root());


		if (izq.valido && derec.valido && izq.max < tree.root() && derec.min > tree.root()) sol.valido = true;
		else sol.valido = false;

	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	if (esBusqueda(tree).valido) std::cout << "SI\n";
	else std::cout << "NO\n";


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