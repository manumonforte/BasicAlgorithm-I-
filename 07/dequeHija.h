//Manuel Monforte Escobar
//E37
#include "deque_eda.h"

template <class T>

class ListaDuplica : public deque<T> {

	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * aux = this->fantasma->sig;
		for (int i = 0; i < this->nelems; i++){
			o << aux->elem << " ";
			aux = aux->sig;
		}
	}



	// Duplicar los nodos de una lista enlazada simple

	void invierte() {
		this->fantasma->sig = this->fantasma->ant;
		Nodo *aux = this->fantasma->sig;
		for (int i = 0; i < this->nelems; i++){
			aux->sig = aux->ant;
			aux = aux->sig;
		}
	}

};