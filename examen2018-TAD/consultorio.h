//Manuel Monforte Escobar
//E37

// En el examen pense que habia que sumar el tiempo  que te daban como entrada como faulty
// no dio tiempo a corregirse

#ifndef concurso_h
#define concurso_h

#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using problema = std::string;
using equipo = std::string;


struct tProblema{
	std::string judge;
	int faulty = 0;
};
struct tEquipo{
	int time= 0;
	int resueltos = 0;
	std::unordered_map<problema, tProblema> tablaProblemas;
};

struct tSol{
	equipo team;
	int completed = 0;
	int time = 0;
};

bool operator<(const tSol & a, const tSol & b){
	if (a.completed > b.completed) return true;
	else if (a.completed < b.completed) return false;
	else{
		if (a.time < b.time) return true;
		else if (a.time > b.time) return false;
		else {
			return a.team < b.team;
		}
	}
}
class concurso{
private:
	//mapa ordenado por numero de problemas resueltos, y como valor un conjunto con los equipos con esos problemas
	std::map < int, std::set<equipo>> tablaClasif;
	//mapa para almacenar el equipo y sus estadisticas, usamos resueltos para indexar con tablaClasif
	std::unordered_map<equipo,tEquipo> tablaEquipos;
public:

	void nuevoEnvio(const equipo & eq, const problema & prob, int min, std::string veredicto){
		//sino existe el equipo lo registramos
		if (tablaEquipos.find(eq) == tablaEquipos.end()){
			tEquipo nuevo;
			tablaEquipos.insert({ eq, nuevo });
			tablaClasif[0].insert(eq);
			//registramos veredicto
			tablaEquipos[eq].tablaProblemas[prob].judge = veredicto;
			//una vez registrado vemos si el veredicto es correcto
			if (veredicto != "AC"){//si no es correcto habra penalizacion
				tablaEquipos[eq].tablaProblemas[prob].faulty += 20;
			}
			else{// si es correcto 
				//sumamos tiempo
				tablaEquipos[eq].time += min;
				//eliminamos de los que tenia resueltos
				tablaClasif[tablaEquipos[eq].resueltos].erase(eq);
				//agregamos en la siguiente tupla de la clasif
				tablaClasif[tablaEquipos[eq].resueltos + 1].insert(eq);
				//sumamos otro resuelto
				tablaEquipos[eq].resueltos++;

			}
		}
		// si el equipo ya existia
		else{
			//comprobamos veredicto 
			// si no esta resuelto
			if (tablaEquipos[eq].tablaProblemas[prob].judge != "AC"){
				if (veredicto != "AC"){//si no es correcto habra penalizacion
					tablaEquipos[eq].tablaProblemas[prob].faulty += 20;
				}
				else{// si es correcto
					tablaEquipos[eq].time += min + tablaEquipos[eq].tablaProblemas[prob].faulty;
					//eliminamos de los que tenia resueltos
					tablaClasif[tablaEquipos[eq].resueltos].erase(eq);
					//agregamos en la siguiente tupla de la clasif
					tablaClasif[tablaEquipos[eq].resueltos + 1].insert(eq);
					//sumamos otro resuelto
					tablaEquipos[eq].resueltos++;
				}
			}
			//actualizamos veredicto
			tablaEquipos[eq].tablaProblemas[prob].judge = veredicto;
		}
	}

	std::vector<tSol> imprimeClasificacion(){
		std::vector<tSol> lista;
		for (auto const & elem : tablaClasif){
			for (auto const & eq : elem.second){
				tSol sol;
				sol.team = eq;
				sol.completed = tablaEquipos[eq].resueltos;
				sol.time = tablaEquipos[eq].time;
				lista.push_back(sol);
			}
		}
		std::sort(lista.begin(), lista.end());
		return lista;
	}
};

#endif
