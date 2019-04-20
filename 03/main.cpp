//Manuel Monforte Escobar
//E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "complejo.h"

// función que resuelve el problema
bool resolver(complejo<float> &num,int n) {
	bool valido = true;
	int i = 0;
	complejo<float> nuevo = complejo<float>(0, 0);
	while (nuevo.modulo() <= 2 && i < n){
		nuevo = (nuevo*nuevo) + num;
		i++;
	}
	return i == n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	float r, i;
	int n;
	std::cin >> r;
	std::cin >> i;
	std::cin >> n;
	complejo<float> numero = complejo<float>(r, i);

	bool sol = resolver(numero,n);
	// escribir sol
	if (sol)std::cout << "SI\n";
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