// Manuel Monforte Escobar
// E37


#include <iostream>
#include <iomanip>
#include <fstream>

// función que resuelve el problema
int resolver(int k,int llamada) {
	int hijos;
	int validos = 0;
	std::cin >> hijos;
	if (hijos == 0){
		if (llamada >= k)return 1;
		else return 0;
	}
	else{
		for (int i = 0; i < hijos; i++){
			llamada++;
			int aux = resolver(k,llamada);
			llamada--;
			validos += aux;
		}
		return validos;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int k;
	int llamada = 0;
	std::cin >> k;
	if (!std::cin)
		return false;

	int sol = resolver(k,llamada);

	// escribir sol
	std::cout << sol << "\n";
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