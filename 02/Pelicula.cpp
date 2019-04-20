#include "Pelicula.h"
#include <iostream>
pelicula::pelicula(horario ini, horario durac, std::string n){
	horaIni = ini;
	duracion = durac;
	horaFin = horaIni + duracion;
	nombre = n;
}
pelicula::pelicula(){};
pelicula::~pelicula(){};

void pelicula::pintar(){
	horaFin.printHora();
	std::cout << nombre << "\n";
}

bool pelicula::operator<(pelicula &other){
	if (other.horaFin<horaFin)return false;
	else if (other.horaFin>horaFin)return true;
	else{
		return other.nombre > nombre;
	}
}