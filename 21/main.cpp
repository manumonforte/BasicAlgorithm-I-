
#include <iostream>
#include <fstream>

#include "consultorio.h"

bool resuelveCaso() {
	int i = 0;
	int operaciones;
	std::cin >> operaciones;
	if (!std::cin) return false;
	std::string orden;
	medico m;
	fecha f;
	paciente p;
	bool escrito = false;

	consultorio c;

	while (i < operaciones) {
		try {
			std::cin >> orden;
			if (orden == "nuevoMedico") {
				std::cin >> m;
				c.nuevoMedico(m);
			}
			else if (orden == "pideConsulta") {
				int dia, hora, minuto;
				std::cin >> p >> m >> dia >> hora >> minuto;
				f = fecha(dia, hora, minuto);
				c.pideConsulta(p, m, f);
			}
			else if (orden == "listaPacientes") {
				int dia;
				std::cin >> m;
				std::cin >> dia;
				std::vector<tElem> lista = c.listaPacientes(m, dia);
				std::cout << "Doctor " << m << " " << "dia " << dia << "\n";
				for (auto &p : lista){
					std::cout << p.p << " ";
					p.f.pintarHora();
					std::cout << "\n";
				}
				escrito = true;
			}
			else if (orden == "siguientePaciente") {
				std::cin >> m;
				p = c.siguientePaciente(m);
				std::cout << "Siguiente paciente doctor " << m << "\n" << p << '\n';
				escrito = true;
			}
			else if (orden == "atiendeConsulta"){
				std::cin >> m;
				c.atiendeConsulta(m);
			}
		}
		catch (std::domain_error e) {
			std::cout << e.what() << '\n';
			escrito = true;
		}
		if (escrito) std::cout << "---\n";
		escrito = false;
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

	while(resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}

