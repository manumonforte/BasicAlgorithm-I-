// Manuel Monforte Escobar
// E37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct tSolucion{
	std::string sport;
	int values;
};

bool myfunction (tSolucion a, tSolucion b){
	if (a.values > b.values) return true;
	else if (a.values == b.values && a.sport < b.sport) return true;
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string palabra;
	std::string alumno;
	std::string deporte;
	std::unordered_map<std::string, int>mapaInscritos;
	std::unordered_map<std::string, std::string>mapaAlumnos;
	std::cin >> palabra;
	if (!std::cin)
		return false;
	while (palabra != "_FIN_"){
		if (palabra[0] >= 'A' && palabra[0] <= 'Z'){			// es en mayus por tanto es nuevo deporte
			deporte = palabra;
			mapaInscritos[palabra] = 0;
		}
		else{// es un alumno
			if (mapaAlumnos.count(palabra)==0){// no esta en el mapa-->anadimos entrada
				mapaAlumnos[palabra] = deporte;
				mapaInscritos[deporte]++;
			}
			else if (mapaAlumnos.count(palabra) == 1 && mapaAlumnos[palabra] != "sinDeporte"){//ya existia
				std::string borrar;
				borrar = mapaAlumnos[palabra];
				if (borrar != deporte){//si no repite en la misma lista debemos marcarlo como no valido
					mapaInscritos[borrar]--;
					mapaAlumnos[palabra] = "sinDeporte";
				}
			}
		}
		std::cin >> palabra;
	}

	std::vector<tSolucion>sol;

	// escribir sols
	for (auto &m : mapaInscritos){
		tSolucion elem;
		elem.sport = m.first;
		elem.values = m.second;
		sol.push_back(elem);
	}
	std::sort(sol.begin(), sol.end(), myfunction);
	for (auto &t : sol) std::cout << t.sport << " " << t.values << "\n";
	std::cout << "***\n";

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