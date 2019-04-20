#ifndef consultorio_h
#define consultorio_h

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include "fecha.h"


using medico = std::string;
using paciente = std::string;

struct tElem{
	paciente p;
	fecha f;
};

class consultorio{
	private:
		std::unordered_map <medico, std::map<fecha, paciente>> tabla;
	public:
		void nuevoMedico(medico m);
		void pideConsulta(paciente p, medico m, fecha f);
		paciente siguientePaciente(medico m);
		void atiendeConsulta(medico m);
		std::vector<tElem> listaPacientes(medico m, int d);
};
#endif