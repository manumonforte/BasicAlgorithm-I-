// Manuel Monforte Escobar
// E37
#include "persona.h"
#include <iostream>
#include <iomanip>


persona::persona(int e, std::string n) :edad(e), nombre(n){

};
persona::persona(){};
persona::~persona(){};

std::string persona::consultarNombre()const{
	return nombre;
}

int persona::consultarEdad()const {
	return edad;
}

