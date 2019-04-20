// Manuel Monforte
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>


// función que resuelve el problema
long long int resolver(int capitulos) {
	std::unordered_map<int, int> lista;//captulo y ultima pos
	long long int distancia=0;
	int ini = 1;
	long long int max=0;
	int elem;

	for (int i = 1; i <= capitulos; i++){
		std::cin >> elem;

		if (lista[elem]>= ini){
			ini = lista[elem] + 1;
			distancia = i-lista[elem];
		}
		else {
			distancia++;
			if (distancia > max){
				max = distancia;
			}
		}
		lista[elem] = i;
	}
	return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int capitulos;
	std::cin >> capitulos;
	long long int max = resolver(capitulos);
	// escribir sol
	std::cout << max << "\n";

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