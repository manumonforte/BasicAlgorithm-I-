// Manuel Monforte Escobar
// E37
#include "horas.h"
#include <iostream>
#include <iomanip>


horario::horario(int s, int m, int h) :seg(s), minuto(m), hour(h){
	if (MIN>seg || seg >= MAX || MIN>minuto || minuto >= MAX || MIN>hour || hour >= MAX2) 	throw std::domain_error("ERROR\n");
};
horario::horario(){};
horario::~horario(){};

bool horario::operator<(horario const &other){
	if (other.hour>hour)return true;
	else if (other.hour < hour)return false;
	else{
		if (other.minuto>minuto)return true;
		else if (other.minuto < minuto)return false;
		else{
			if (other.seg > seg)return true;
			else return false;
		}
	}
}

void horario::printHora()const {
	std::cout << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minuto << ":" << std::setw(2) << std::setfill('0') << seg;
}