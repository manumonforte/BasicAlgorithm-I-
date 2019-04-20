// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


bool es_primo(int x){
	int i = x - 1;
	while (i > 1 && x %i != 0){
		i--;
	}
	return i == 1;
}

struct tSol{
	int multiplo = -1;
	int profundidad = 0;
	tSol() : multiplo(-1), profundidad(0){}
	tSol(int a, int b) : multiplo(a), profundidad(b){}
};
// función que resuelve el problema
tSol resolver(bintree<int> const &tree, int nivel ) {
	if (!tree.empty() &&!es_primo(tree.root())){
		bool valido = tree.root() % 7 == 0;
		if (tree.left().empty() && tree.right().empty()){
			tSol sol;
			if (valido){
				sol.multiplo = tree.root();
				sol.profundidad = nivel;
			}
			return sol;
		}
		else if (tree.left().empty()){
			tSol sol  = resolver(tree.right(), nivel +1);
			if (valido){
				sol.multiplo = tree.root();
				sol.profundidad = nivel;
			}
			return sol;
		}
		else if (tree.right().empty()){
			tSol sol = resolver(tree.left(), nivel + 1);
			if (valido){
				sol.multiplo = tree.root();
				sol.profundidad = nivel;
			}
			return sol;
		}
		else{
			tSol izq = resolver(tree.left(), nivel + 1);
			tSol derec = resolver(tree.right(), nivel + 1);
			tSol sol;
			if (izq.multiplo != -1 && derec.multiplo != -1){
				if (valido){
					sol.multiplo = tree.root();
					sol.profundidad = nivel;
				}
				else{
					if (izq.profundidad <= derec.profundidad){
						sol.profundidad = izq.profundidad;
						sol.multiplo = izq.multiplo;
					}
					else{
						sol.profundidad = derec.profundidad;
						sol.multiplo = derec.multiplo;
					}
				}
				return sol;
			}
			else if (izq.multiplo!=-1) {
				if (valido){
					sol.multiplo = tree.root();
					sol.profundidad = nivel;
					return sol;
				}
				return izq;
			}
			else{
				if (valido){
					sol.multiplo = tree.root();
					sol.profundidad = nivel;
					return sol;
				}
				return derec;
			}
		}

	}
	return { -1, 0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int vacio = -1;
	bintree<int>tree = leerArbol(vacio);

	tSol sol = resolver(tree,1);
	// escribir sol
	if (sol.multiplo == -1) std::cout << "NO HAY\n";
	else std::cout << sol.multiplo << " " << sol.profundidad << "\n";

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