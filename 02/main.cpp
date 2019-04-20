// Manuel Monforte Escobar
// E37


#include "Pelicula.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
void rellenarLista(std::vector<pelicula> &rellenar, int limite){
	int hora, min, seg;
	std::string n;
	horario ini;
	horario d;
	char aux;
	for (int i = 0; i < limite; i++){//introducimos el horario
		/*HORA COMIENZO*/
		std::cin >> hora;//leemos seg
		std::cin.get(aux);
		std::cin >> min;//leemos min
		std::cin.get(aux);
		std::cin >> seg;//leemos hora
		ini = horario(seg, min, hora);
		/*DURACION*/
		std::cin >> hora;//leemos seg
		std::cin.get(aux);
		std::cin >> min;//leemos min
		std::cin.get(aux);
		std::cin >> seg;//leemos hora
		d = horario(seg, min, hora);
		/*NOMBRE DE LA PELICULA*/
		std::getline(std::cin, n);
		rellenar[i] = pelicula(ini, d, n);
	}
}
// función que resuelve el problema
void resolver(std::vector<pelicula> &lista) {
	std::sort(lista.begin(), lista.end());
	for (int i = 0; i < lista.size(); i++){
		lista[i].pintar();
	}
	std::cout << "---\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elementos;
	std::cin>> elementos;
	if (elementos == 0)
		return false;
	std::vector<pelicula> lista(elementos);
	rellenarLista(lista, elementos);
	resolver(lista);

	// escribir sol

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