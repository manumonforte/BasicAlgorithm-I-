//Manuel Monforte Escobar
//E37
#include <iostream>
#include <fstream>

#include "ipud.h"

bool resuelveCaso() {

	ipud I;
	cancion s;
	artista a;
	int d;
	std::string orden;
	std::cin >> orden;
	if (!std::cin) return false;
	while (orden != "FIN") {
		try {
			if (orden == "addSong") {
				std::cin >> s >> a >> d;
				I.addSong(s, a, d);
			}
			else if (orden == "addToPlaylist") {
				std::cin >> s;
				I.addToPlayList(s);
			}
			else if (orden == "play") {
				cancion  aux = I.play();
				if (!aux.empty()) std::cout << "Sonando " << aux << "\n";
				else std::cout << "No hay canciones en la lista\n";

			}
			else if (orden == "deleteSong") {
				std::cin >> s;
				I.deleteSong(s);
			}
			else if (orden == "totalTime"){
				std::cout << "Tiempo total " << I.totalTime() << "\n";
			}
			else if (orden == "recent"){
				std::cin >> d;
				std::list<cancion> lista = I.recent(d);
				if (!lista.empty()){
					std::cout << "Las " << lista.size() << " mas recientes\n";
					for (auto const & c : lista){
						std::cout << "    " << c << "\n";
					}
				}
				else std::cout << "No hay canciones recientes\n";
			}
			else if (orden == "current"){
				I.current();
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR "  << e.what() << "\n";
		}
		std::cin >> orden;
	}
	std::cout << "----\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	return 0;
#endif
}

