// Manuel Monforte Escobar
// E37


#include "Horario.h"
#include <fstream>
#include <iostream>
#include <vector>

void rellenarLista(std::vector<horario> &rellenar,int limite){
	int hora, min, seg;
	char aux;
	for (int i = 0; i < limite; i++){//introducimos el horario
		std::cin >> hora;//leemos seg
		std::cin.get(aux);
		std::cin >> min;//leemos min
		std::cin.get(aux);
		std::cin >> seg;//leemos hora
		rellenar[i] = horario(seg, min, hora);
	}
}
// función que resuelve el problema
void resolver(std::vector<horario> &lista,horario  &consulta) {
	bool encontrado = false;
	int j= 0;
	while (!encontrado && j < lista.size()){
		if (consulta < lista[j]) encontrado = true;
		j++;
	}
	if (encontrado) lista[j - 1].printHora();
	else if (!encontrado) std::cout << "NO\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int trenes, horas;
	std::cin >> trenes;
	std::cin >> horas;
	if (trenes == 0 && horas ==0)
		return false;
	std::vector<horario> lista(trenes);
	horario consulta;
	rellenarLista(lista, trenes);
	
	
	int hora, min, seg;
	char aux;
	for (int i = 0; i < horas; i++){//introducimos el horario
		std::cin >> hora;//leemos seg
		std::cin.get(aux);
		std::cin >> min;//leemos min
		std::cin.get(aux);
		std::cin >> seg;//leemos hora
		try{
		consulta = horario(seg, min, hora);
		resolver(lista, consulta);
		}catch (std::domain_error const &e){
			std::cout << e.what();
		}
	}
	std::cout << "---\n";
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