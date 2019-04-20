
#include <iostream>
#include <fstream>

#include "tiendaLibros.h"

bool resuelveCaso() {
	int i = 0;
	int operaciones;
	std::cin >> operaciones;
	if (!std::cin) return false;
	std::string orden;
	libro l;
	int n;

	tiendaLibros TL;

	while (i < operaciones) {
		try {
			std::cin >> orden;
			if (orden == "nuevoLibro") {
				std::cin >> n;
				std::cin.get();
				getline(std::cin, l);
				TL.nuevoLibro(n,l);
			}
			else if (orden == "comprar") {
				std:: cin.get();
				getline(std::cin, l);
				TL.comprar(l);
			}
			else if (orden == "estaLibro") {
				std::cin.get();
				getline(std::cin, l);
				if (TL.estaLibro(l)) std::cout << "El libro " << l << " esta en el sistema\n";
				else  std::cout << "No existe el libro " << l << " en el sistema\n";
				std::cout << "---\n";
			}
			else if (orden == "numEjemplares") {
				std::cin.get();
				getline(std::cin, l);
				try {
					int p = TL.numEjemplares(l);
					std::cout << "Existen " << p << " ejemplares del libro " << l << "\n";
				}
				catch (std::exception){
					std::cout << "No existe el libro " << l << " en el sistema\n";
				}
				std::cout << "---\n";
			}
			else if (orden == "elimLibro"){
				std::cin.get();
				getline(std::cin, l);
				TL.elimLibro(l);
			}
			else if (orden == "top10"){
				std::vector<libro> sol = TL.top10();
				for (auto const & lib : sol) std::cout << lib << "\n";
				std::cout << "---\n";
			}
		}
		catch (std::exception & e) {
			std::cout << e.what() << '\n';
			std::cout << "---\n";
		}
		i++;
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

