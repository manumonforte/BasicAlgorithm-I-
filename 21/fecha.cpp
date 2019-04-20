#include "fecha.h"

fecha::fecha(int d, int h, int m){
	if (d<1 || d > 30) throw std::domain_error("Dia no valido");
	else dia = d;
	
	if (h<0 || h > 23) throw std::domain_error("Dia no valido");
	else hora = h;

	if (m<0 || m > 59) throw std::domain_error("Dia no valido");
	else min = m;

}
fecha::fecha(){};
fecha::~fecha(){};
bool fecha::operator<(fecha other)const {
	if (dia< other.dia)return true;
	else if (dia > other.dia)return false;
	else{
		if (hora< other.hora)return true;
		else if (hora > other.hora)return false;
		else{
			if (min < other.min)return true;
			else return false;
		}
	}
}
int fecha::getDia()const { return dia; }
int fecha::getMin()const { return min; }
int fecha::getHora()const { return hora; }
void fecha::pintarHora(){
	std::cout << std::setw(2) << std::setfill('0') << hora << ":" << std::setw(2) << std::setfill('0') << min;

}