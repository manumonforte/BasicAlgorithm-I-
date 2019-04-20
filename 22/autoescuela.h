//Manuel Monforte Escobar
//E37

#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

using profesor = std::string;
using alumno = std::string;

class autoescuela{
private:
	std::unordered_map<alumno, int>tablaPuntuacion;
	std::unordered_map<alumno, profesor>tablaAlumnos;
	std::unordered_map<profesor, std::vector<alumno>>tablaProfesores;

public:
	autoescuela(){};

	void alta(alumno a, profesor p){//O(n)  en alumnos del profesor
		//si no existe alumno se crea
		if (tablaPuntuacion.count(a) == 0){
			tablaPuntuacion.insert({ a, 0 });
			tablaAlumnos[a] = p;
			tablaProfesores[p].push_back(a);
		}
		else{
			//si existe
			profesor aux = tablaAlumnos[a];
			tablaAlumnos[a] = p;
			//buscamos el aumno en el antiguo profsor y lo quitamos
			for (int i = 0; i < tablaProfesores[aux].size(); i++){
				if (tablaProfesores[aux][i] == a){
					tablaProfesores[aux][i] = tablaProfesores[aux][tablaProfesores[aux].size() - 1];
					tablaProfesores[aux].pop_back();
				}
			}
			//anadimos el alumno al nuevo profesor
			tablaProfesores[p].push_back(a);
		}
	}

	bool esAlumno(alumno a, profesor p){ //O(1)
		if (tablaAlumnos[a] == p)return true;
		else return false;
	}

	int puntuacion(alumno a){//O(1)
		auto itA = tablaAlumnos.find(a);
		if (itA == tablaAlumnos.end()) throw std::domain_error("El alumno " + a + "no esta matriculado");
		else{
			return tablaPuntuacion[a];
		}
	}

	void actualizar(alumno a, int n){//O(1)
		auto itA = tablaPuntuacion.find(a);
		if (itA == tablaPuntuacion.end()) throw std::domain_error("El alumno " + a + "no esta matriculado");
		else itA->second += n;
	}

	std::vector<alumno> examen(profesor p, int n){//O(n) numero de alumnos del profesor
		std::vector<alumno>sol;
		auto itP = tablaProfesores.find(p);
		if (itP == tablaProfesores.end()) tablaProfesores.insert({ p, {} });
		else{
			for (auto a : itP->second){
				if (tablaPuntuacion[a] >= n)sol.push_back(a);
			}
			std::sort(sol.begin(), sol.end());
		}
		return sol;
	}

	void aprobar(alumno a){//O(n*m) n-->numeros profesores, m-->numero de alumnos de un profesor
		if (tablaAlumnos.find(a) == tablaAlumnos.end()) throw std::domain_error("El alumno " + a + "no esta matriculado");
		tablaAlumnos.erase(a);
		tablaPuntuacion.erase(a);
		auto itP = tablaProfesores.begin();
		while (itP != tablaProfesores.end()){
			for (int i = 0; i < itP->second.size(); i++){
				if (itP->second[i] == a){
					itP->second[i] = itP->second[itP->second.size() - 1];
					itP->second.pop_back();
				}
			}
			itP++;
		}
	}
};

#endif