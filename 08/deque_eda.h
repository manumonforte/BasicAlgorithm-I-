#ifndef deque_eda_h
#define deque_eda_h

#include <stdexcept>
#include <cassert>
#include <iostream>
template <class T>
class deque {
protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y dos punteros, uno al nodo anterior y otro al nodo siguiente.
	*/
	struct Nodo {
		Nodo() : ant(nullptr), sig(nullptr) {}
		Nodo(T const& elem, Nodo * ant, Nodo * sig) : elem(elem), ant(ant), sig(sig) {}
		T elem;
		Nodo * ant;
		Nodo * sig;
	};

	// puntero al nodo fantasma
	Nodo * fantasma;

	// n�mero de elementos
	size_t nelems;

public:

	// constructor: cola doble vac�a
	deque() : fantasma(new Nodo()), nelems(0) {
		fantasma->sig = fantasma->ant = fantasma; // circular
	}

	// destructor
	~deque() {
		libera();
	}

	// constructor por copia
	deque(deque<T> const& other) {
		copia(other);
	}

	// operador de asignaci�n
	deque<T> & operator=(deque<T> const& that) {
		if (this != &that) {
			libera();
			copia(that);
		}
		return *this;
	}

	// a�adir un elemento por el principio
	void push_front(T const& e) {
		inserta_elem(e, fantasma, fantasma->sig);
		++nelems;
	}

	// a�adir un elemento por el final
	void push_back(T const& e) {
		inserta_elem(e, fantasma->ant, fantasma);
		++nelems;
	}

	// consultar el primer elemento de la dcola
	T const& front() const {
		if (empty())
			throw std::domain_error("la dcola vacia no tiene primero");
		return fantasma->sig->elem;
	}

	// consultar el �ltimo elemento de la dcola
	T const& back() const {
		if (empty())
			throw std::domain_error("la dcola vacia no tiene ultimo");
		return fantasma->ant->elem;
	}

	// eliminar el primer elemento
	void pop_front() {
		if (empty())
			throw std::domain_error("eliminando el primero de una dcola vacia");
		borra_elem(fantasma->sig);
		--nelems;
	}

	// elminar el �ltimo elemento
	void pop_back() {
		if (empty())
			throw std::domain_error("eliminando el ultimo de una dcola vacia");
		borra_elem(fantasma->ant);
		--nelems;
	}

	// consultar si la dcola est� vac�a
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tama�o de la cola doble
	size_t size() const {
		return nelems;
	}

protected:

	void libera() {
		// primero rompemos la circularidad
		fantasma->ant->sig = nullptr;
		fantasma->ant = nullptr;
		while (fantasma != nullptr) {
			Nodo * a_borrar = fantasma;
			fantasma = fantasma->sig;
			delete a_borrar;
		}
		fantasma = nullptr;
	}

	void copia(deque<T> const& other) {
		fantasma = new Nodo();
		fantasma->sig = fantasma;
		fantasma->ant = fantasma;
		nelems = 0;

		// act recorre la cola que estamos copiando
		Nodo * act = other.fantasma->sig;
		while (act != other.fantasma) {
			push_back(act->elem);
			act = act->sig;
		}
	}

	// insertar un nuevo nodo entre anterior y siguiente
	static Nodo * inserta_elem(T const& e, Nodo * anterior, Nodo * siguiente) {
		Nodo * nuevo = new Nodo(e, anterior, siguiente);
		anterior->sig = nuevo;
		siguiente->ant = nuevo;
		return nuevo;
	}

	// eliminar el nodo n
	static void borra_elem(Nodo * n) {
		assert(n != nullptr);
		n->ant->sig = n->sig;
		n->sig->ant = n->ant;
		delete n;
	}
};

#endif // deque_eda_h