#include "queue_eda.h"
#include <iostream>
template <class T>

class ListaElimina : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * aux = this->prim;
		for (int i = 0; i < this->nelems; i++){
			o << aux->elem<< " ";
			aux = aux->sig;
		}
	}



	// Duplicar los nodos de una lista enlazada simple

	void eliminaPares() {
		Nodo * aux = this->prim;
		int x = this->nelems;
		for (int i = 0; i < x/2; i++){
			Nodo * next = aux->sig;
			aux->sig = aux->sig->sig;
			delete next;
			aux = aux->sig;
			this->nelems--;
		}
	}

};