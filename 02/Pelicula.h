// Manuel Monforte Escobar
// E37
#ifndef Pelicula_h
#define Pelicula_h

#include "Horario.h"
#include <string>

class pelicula{
public:
	pelicula(horario ini, horario duracion,std::string nombre);//constructor
	pelicula();
	~pelicula();//destructor
	void pintar();
	bool operator<(pelicula &other);
private:
	horario horaIni;
	horario duracion;
	horario horaFin;
	std::string nombre;
};

#endif;