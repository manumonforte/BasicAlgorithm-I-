// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "horas.h"
#include "queueHija.h"



// función que resuelve el problema
void resolver(ListaElimina<horario> &lista) {
	lista.eliminaPares();

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elems;
	int hora, min, seg;
	char aux;
	std::cin >> elems;
	if (elems==0)
		return false;
	ListaElimina<horario>lista;
	for (int i = 0; i < elems; i++){
		std::cin >> hora;
		std::cin.get(aux);
		std::cin >> min;
		std::cin.get(aux);
		std::cin >> seg;
		lista.push(horario(seg, min, hora));
	}
	resolver(lista);
	lista.print();
	// escribir sol
	std::cout << "\n";
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