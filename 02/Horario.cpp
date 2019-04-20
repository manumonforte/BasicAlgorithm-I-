// Manuel Monforte Escobar
// E37
#include "Horario.h"
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
bool horario::operator>(horario const &other){
	if (other.hour<hour)return true;
	else if (other.hour > hour)return false;
	else{
		if (other.minuto<minuto)return true;
		else if (other.minuto > minuto)return false;
		else{
			if (other.seg < seg)return true;
			else return false;
		}
	}
}
bool horario:: operator==(horario const &other){
	if (hour == other.hour && minuto == other.minuto && seg == other.seg)return true;
	else return false;
}
horario horario:: operator+ (horario const &other){
	minuto += other.minuto+((seg + other.seg) / 60);
	seg = (seg + other.seg) % 60;
	hour += other.hour +(minuto / 60);
	minuto %= 60;
	return horario(seg, minuto, hour%24);
}

void horario::printHora(){
	std::cout << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minuto << ":" << std::setw(2) << std::setfill('0') << seg;
}