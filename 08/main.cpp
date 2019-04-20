// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h";
#include "persona.h";

class filtroEdad {
public:
	filtroEdad(int mi, int ma) :min(mi), max(ma){};
	bool operator()(persona const& uno){
		return  !(min <= uno.consultarEdad() && max >=  uno.consultarEdad());
	}
private:
	int min;
	int max;
};
// función que resuelve el problema
void resolver(list<persona>&lista, int edadMin, int edadMax) {
	//pasar objeto funcion creando classe filtrar por edad con atributos edadMin, edad Max,  que recibe una persona que modifica operador parentesis y devleve sin 
	 lista.remove_if(filtroEdad(edadMin, edadMax));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPersonas;
	int edadMin;
	int edadMax;
	std::cin >> numPersonas;
	std::cin >> edadMin;
	std::cin >> edadMax;
	if (numPersonas == 0 && edadMax == 0 && edadMin == 0)
		return false;
	list<persona>lista;
	int edad;
	char aux;
	std::string nombre;
	for (int i = 0; i < numPersonas; i++){
		std::cin >> edad;
		std::cin.get(aux);
		getline(std::cin, nombre);
		persona aux = persona(edad, nombre);
		lista.push_back(aux);
	}
	//creamos iterator
	list<persona>::iterator pos;
	//lo situamos al comienzo de la lista
	pos = lista.begin();
	resolver(lista, edadMin, edadMax);
	// escribir sol
	pos = lista.begin();
	for (auto elem : lista){
		std::cout << elem.consultarNombre() << "\n";
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