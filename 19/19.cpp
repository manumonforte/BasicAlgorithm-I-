// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int lineas;
	std::cin >> lineas;
	std::cin.get();
	std::string linea;
	std::string clave;
	std::map<std::string, std::vector<int>>mapa;
	if (lineas == 0)
		return false;
	for (int i = 1; i <= lineas; i++){
		getline(std::cin, linea);
		std::stringstream v(linea);
		while (v >> clave) {
			for (int t = 0; t < clave.size(); t++) clave[t] = tolower(clave[t]);
			if (clave.size() > 2) {
				if (mapa[clave].size()>0 && mapa[clave][mapa[clave].size() - 1] != i) mapa[clave].push_back(i);
				else if (mapa[clave].size() == 0)mapa[clave].push_back(i);
			}
		}
	}
	// escribir sol
	for (auto &m : mapa){
		std::cout << m.first;
		for (int i = 0; i < m.second.size(); i++) std::cout << " " << m.second[i];
		std::cout << "\n";
	}
	std::cout << "----\n";
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