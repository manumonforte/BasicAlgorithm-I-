//Manuel Monforte Escobar
//E37
#include <iostream>
#include <fstream>

#include "autoescuela.h"

bool resuelveCaso() {
	
	autoescuela A;
	alumno a;
	profesor p;
	int n;
	std::string orden;
	std::cin >> orden;
	if (!std::cin) return false;
	while (orden !="FIN") {
		try {
			if (orden == "alta") {
				std::cin >> a >> p;
				A.alta(a, p);
			}
			else if (orden == "es_alumno") {
				std::cin >> a >> p;
				if (A.esAlumno(a, p)) std::cout << a << " es alumno de " << p << "\n";
				else std::cout << a << " no es alumno de " << p << "\n";
			}
			else if (orden == "puntuacion") {
				std::cin >> a;
				int puntuacion = A.puntuacion(a);
				std::cout << "Puntuacion de " << a <<": " << puntuacion << "\n";
			}
			else if (orden == "actualizar") {
				std::cin >> a >> n;
				A.actualizar(a, n);
			}
			else if (orden == "examen"){
				std::cin >> p >>n;
				std::vector<alumno> lista = A.examen(p, n);
				std::cout << "Alumnos de " << p << " a examen:\n";
				for (auto &a : lista){
					std::cout << a << "\n";
				}
			}
			else if (orden == "aprobar"){
				std::cin >> a;
				A.aprobar(a);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		std::cin >> orden;
	}
	std::cout << "------\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());
	return 0;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
}

