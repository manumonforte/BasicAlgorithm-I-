// Manuel Monforte Escobar
// E37
#ifndef Horario_h
#define Horario_h

#include <stdexcept>

int const MAX = 60;
int const MAX2 = 24;
int const MIN = 0;
class horario{
public:
	horario(int s, int m, int h);//constructor
	horario();
	~horario();//destructor
	bool operator<(horario const &other);
	bool operator>(horario const &other);
	bool operator==(horario const &other);

	horario operator+ (horario const &other);
	void printHora();
private:
	int seg;
	int hour;
	int minuto;
};

#endif;