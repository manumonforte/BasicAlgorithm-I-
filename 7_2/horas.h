// Manuel Monforte Escobar
// E37
#ifndef horas_h
#define horas_h

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
	void printHora()const;
private:
	int seg;
	int hour;
	int minuto;
};

inline std::ostream & operator <<(std::ostream & out, horario const& h) {
	h.printHora();
	return out;
}

#endif;