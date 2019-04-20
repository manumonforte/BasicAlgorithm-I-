// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver() {
	int niveles = 1;
	int hijos;
	int max = -1;
	std::cin >> hijos;
	if (hijos == 0) return 1;
	else{
		for (int i = 0; i < hijos; i++){
			int aux = resolver();
			if (aux>max)max = aux;
		}
		return max + 1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int max = 0;
	int sol = resolver();
	// escribir sol
	 std::cout << sol << "\n";
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