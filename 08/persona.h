// Manuel Monforte Escobar
// E37
#ifndef persona_h
#define persona_h

#include <stdexcept>
#include <string>
class persona{
public:
	persona(int e, std::string n);//constructor
	persona();
	~persona();//destructor
	std::string consultarNombre()const;
	int consultarEdad()const ;
private:
	int edad;
	std::string nombre;
};

#endif;