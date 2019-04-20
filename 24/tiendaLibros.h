#ifndef tiendaLibros_h
#define tiendaLibros_h

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <list>

using libro = std::string;

const int TOP = 10;
struct tInfo{
	int vendidos = 0;
	int unidades = 0;
};

class tiendaLibros{
private:
	std::unordered_map<libro, tInfo>tablaLibros;
	std::map<int, std::list<libro>>tablaVentas;//numVentas,libro
	std::unordered_map<libro, std::list<libro>::const_iterator>tablaIteradores;
public:

	void nuevoLibro(int n, libro x){//0(1)
		// anadimos nuevo libros con unidades
		tablaLibros[x].unidades += n;
	}

	void comprar(libro x){//O(1)
		auto itL = tablaLibros.find(x);
		//comprobamos si existe el libro
		if (itL == tablaLibros.end()) throw std::invalid_argument("Libro no existente");
		else{	
			//comrpobamos que hay unidades
			if (itL->second.unidades == 0) throw std::out_of_range("No hay ejemplares");
			else{
				//primera venta
				if (itL->second.vendidos == 0){
					tablaVentas[1].push_front(x);
					//guardamos iterador
					tablaIteradores[x] = tablaVentas[1].begin();
				}
				else{
					//borramos libro de ventas
					tablaVentas[itL->second.vendidos].erase(tablaIteradores[x]);
					//anadimos en la sig tupla de ventas
					tablaVentas[itL->second.vendidos + 1].push_front(x);
					//actualizamos el iterador
					tablaIteradores[x] = tablaVentas[itL->second.vendidos + 1].begin();
				}
				itL->second.unidades--;
				itL->second.vendidos++;
			}
		}
	}

	bool estaLibro(libro x){//O(1)
		auto itL = tablaLibros.find(x);
		if (itL == tablaLibros.end()) return false;
		else return true;
	}
	
	void elimLibro(libro x){//O(1)
		auto itL = tablaLibros.find(x);
		if (itL != tablaLibros.end()){
			if (itL->second.vendidos > 0){
				//eliminamos de historial de ventas
				tablaVentas[itL->second.vendidos].erase(tablaIteradores[x]);
				//eliminamos de historial de iteradores
				tablaIteradores.erase(x);
			}
			//eliminamos de historial de libros
			tablaLibros.erase(x);
			
		}
	}

	int numEjemplares(libro x){//O(1)
		auto itL = tablaLibros.find(x);
		if (itL == tablaLibros.end()) throw std::invalid_argument("Libro no existente");
		else return itL->second.unidades;
	}

	std::vector<libro> top10(){//O(10) -->O(1)
		std::vector<libro>top10;
		int contador = 0;
		auto it = tablaVentas.rbegin();
		while (it != tablaVentas.rend() && contador < TOP){
			auto itCola = it->second.begin();
			while (contador < TOP && itCola != it->second.end()){
				top10.push_back(*itCola);
				itCola++;
				contador++;
			}
			it++;
		}
		return top10;
	}
};




#endif