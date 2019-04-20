#include "consultorio.h"

void consultorio::nuevoMedico(medico m){
	tabla.insert({ m, {} }).second;
}

void consultorio::pideConsulta(paciente p, medico m, fecha f){
	auto itm = tabla.find(m);
	if (itm == tabla.end()){
		throw std::domain_error("Medico no existente");
	}
	else{
		auto itf = tabla[m].find(f);
		if (itf != tabla[m].end()){
			throw std::domain_error("Fecha ocupada");
		}
		//introducimos paciente en la fecha para el medico m
		else tabla[m][f] = p;
	}
}

paciente consultorio::siguientePaciente(medico m){
	auto itm = tabla.find(m);
	if (itm == tabla.end()){
		throw std::domain_error("Medico no existente");
	}
	else{
		if (tabla[m].size() == 0){
			throw std::domain_error("No hay pacientes");
		}
		else return tabla[m].begin()->second;
	}
}

void consultorio::atiendeConsulta(medico m){
	auto itm = tabla.find(m);
	if (itm == tabla.end()){
		throw std::domain_error("Medico no existente");
	}
	else{
		if (tabla[m].size() == 0){
			throw std::domain_error("No hay pacientes");
		}
		else tabla[m].erase(tabla[m].begin());
	}
}

std::vector<tElem> consultorio::listaPacientes(medico m, int d){
	std::vector<tElem>listaPacientes;
	tElem elemento;
	auto itm = tabla.find(m);
	if (itm == tabla.end()){
		throw std::domain_error("Medico no existente");
	}
	else{
		if (tabla[m].size() == 0){
			return listaPacientes;
		}
		else{
			for (auto p : tabla[m]){
					if (p.first.getDia()==d){
						elemento = { p.second, p.first };
						listaPacientes.push_back(elemento);
					}
			}
			return listaPacientes;
		}
	}
	return listaPacientes;
}

