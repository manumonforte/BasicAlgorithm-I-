// Manuel Monforte
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <list>


// función que resuelve el problema
void resolver(std::map<std::string, int>const & viejo, std::map<std::string, int>const & nuevo) {
	auto it = viejo.begin();
	auto it2 = nuevo.begin();
	std::list<std::string>nuevos;
	std::list<std::string>eliminados;
	std::list<std::string>modificados;
	while (it != viejo.end() || it2 != nuevo.end()){
		//si son iguales
		if (it != viejo.end() && it2 != nuevo.end() && it->first == it2->first){
			if (it->second != it2->second) modificados.push_back(it->first);
			it++;
			it2++;
		}
		//si hay nuevos en el mapa nuevo 
		else if (it2 != nuevo.end() && it != viejo.end() && it->first > it2->first){
			nuevos.push_back(it2->first);
			it2++;
		}
		//si hay eliminados en el mapa nuevo
		else if (it != viejo.end() && it2 != nuevo.end() && it->first < it2->first){
			eliminados.push_back(it->first);
			it++;
		}
		//si se ha acabado el mapa viejo pero el nuevo no --> introducimos
		else if (it == viejo.end() && it2 != nuevo.end()){
			nuevos.push_back(it2->first);
			it2++;
		}
		//si se ha acabado el mpa nuevo pero el viejo no -->quitamos
		else if (it != viejo.end() && it2 == nuevo.end()){
			eliminados.push_back(it->first);
			it++;
		}
		
	}

	//mostramos lista
	if (nuevos.size() == 0 && eliminados.size() == 0 && modificados.size() == 0) std::cout << "Sin cambios";
	else{
		if (nuevos.size() != 0){
			std::cout << "+";
			for (auto &n : nuevos){
				std::cout << " " << n;
			}
		}

		if (eliminados.size() != 0){
			std::cout << "\n" << "-";
			for (auto &e : eliminados){
				std::cout << " " << e;
			}
		}

		if (modificados.size() != 0){
			std::cout << "\n" << "*";
			for (auto &m : modificados){
				std::cout << " " << m;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::map<std::string, int> viejo;//nlogn->Coste de crearlo
	std::map<std::string, int> nuevo;//mlogn->Coste de crearlo
	std::string clave;
	int valor;
	std::string linea;
	getline(std::cin, linea);
	std::stringstream v(linea);
	while (v >> clave >> valor) {
		viejo[clave] = valor;
	}

	getline(std::cin, linea);
	std::stringstream n(linea);
	while (n >> clave >> valor) {
		nuevo[clave] = valor;
	}

	resolver(viejo,nuevo);
	std::cout << "\n----\n";

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
	std::cin.get();
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}