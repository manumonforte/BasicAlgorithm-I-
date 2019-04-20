#ifndef fecha_h
#define fecha_h

#include <iostream>
#include <iomanip>
#include <stdexcept>

class fecha{

public:
	fecha(int d, int h, int m);//constructor
	fecha();
	~fecha();//destructor
	bool operator<(fecha other)const;
	int getDia()const ;
	int getMin()const ;
	int getHora()const ;
	void pintarHora();

private:
	int dia;
	int hora;
	int min;
};
#endif