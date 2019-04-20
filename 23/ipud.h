//Manuel Monforte Escobar
//E37


#ifndef ipud_h
#define ipud_h

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <list>
#include <iterator>
#include <stdexcept>
#include <stack>

using artista = std::string;
using cancion = std::string;

struct tCancion{
	int duracion;
	artista cantante;
};

class ipud{
private:
	std::unordered_map<cancion, tCancion> tablaCanciones;
	int time=0;
	//playList
	std::unordered_map<cancion, std::list<cancion>::iterator>tablaIteradoresplayList;
	std::list<cancion>listaReproduccion;
	//reproducidas
	std::list<cancion> reproducidas;
	std::unordered_map<cancion, std::list<cancion>::iterator>tablaIteradoresReproducidas;
public:
	void addSong(cancion s, artista a, int d){
		if (tablaCanciones.find(s) != tablaCanciones.end()) throw std::domain_error("addSong");
		else {
			tCancion aux;
			aux.cantante = a;
			aux.duracion = d;
			tablaCanciones.insert({ s, aux });
		}
	}

	void addToPlayList(cancion s){
		auto itC = tablaCanciones.find(s);
		//si la cancion no existe error
		if (itC == tablaCanciones.end()) throw std::domain_error("addToPlayList");
		else{// si la cancion existe
			auto itI = tablaIteradoresplayList.find(s);
			// si la cancion no estaba en la lista
			if (itI == tablaIteradoresplayList.end()) {
				//anadimos a la lista
				listaReproduccion.push_back(s);
				//actualizamos mapaIterador
				auto it = listaReproduccion.end();
				it--;
				tablaIteradoresplayList[s] = it;
				time += tablaCanciones[s].duracion;
			}
		}
	}

	cancion current(){
		if (listaReproduccion.empty()) throw std::domain_error("current");
		else return listaReproduccion.front();
	}

	cancion play(){
		cancion aux;

		if (!listaReproduccion.empty()) { // si no es vacia
			aux  = listaReproduccion.front();
			listaReproduccion.pop_front();
			tablaIteradoresplayList.erase(aux);
			time -= tablaCanciones[aux].duracion;

			auto itR = tablaIteradoresReproducidas.find(aux);
			if (itR != tablaIteradoresReproducidas.end()) { 
				reproducidas.erase(itR->second);
			}
			reproducidas.push_back(aux);

			auto itLRP = reproducidas.end();
			itLRP--;
			tablaIteradoresReproducidas[aux] = itLRP;
		}
		return aux;
	}

	int totalTime(){
		if (!listaReproduccion.empty()) return time;
		else return 0;
	}

	std::list<cancion> recent(int N){
		std::list<cancion>sol;
		int i = 1;

		if (!reproducidas.empty()) {

			auto itRep = reproducidas.end();
			itRep--;

			while (itRep != reproducidas.begin() && i < N) {
				sol.push_back(*itRep);
				itRep--;
				i++;
			}
			sol.push_back(*itRep);
		}
		//restauramos reproducidas
		return sol;
	}

	void deleteSong(cancion s){
		auto itIpud = tablaCanciones.find(s);

		if (itIpud != tablaCanciones.end()) { 
			auto itLP = tablaIteradoresplayList.find(s);
			if (itLP != tablaIteradoresplayList.end()) { 
				listaReproduccion.erase(itLP->second);
				tablaIteradoresplayList.erase(s);
				time -= tablaCanciones[s].duracion;
			}
			auto itR = tablaIteradoresReproducidas.find(s);
			if (itR != tablaIteradoresReproducidas.end()) { // Esta en la lista de reproducidas
				reproducidas.erase(itR->second);
				tablaIteradoresReproducidas.erase(s);
			}
			tablaCanciones.erase(s);
		}
	}
};


#endif