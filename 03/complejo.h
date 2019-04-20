//Manuel Monforte Escobar
//E37
#ifndef complejo_h
#define complejo_h
#include <iostream>
#include <algorithm>

template <class T>
class complejo{

public:
	complejo(T r, T i);
	~complejo();
	complejo operator+(const complejo &other);
	complejo operator*(const complejo &other);
	T modulo() const ;

private:
	T real;
	T imaginaria;
};

template <class T>
complejo<T>::complejo(T r, T i){
	real = r;
	imaginaria = i;
}

template <class T>
complejo<T>::~complejo(){};

template <class T>
complejo complejo<T>:: operator+(const complejo &other){
	real += other.real;
	imaginaria += other.imaginaria;
	return complejo(real, imaginaria);
}

template <class T>
complejo complejo<T>::operator*(const complejo &other){
	T x = real;
	T y = other.real;
	T z = imaginaria;
	T w = other.imaginaria;
	real = (x*y) - (z *w);
	imaginaria = (x*w) + (y*z);
	return complejo(real, imaginaria);
}

template <class T>
T complejo<T>::modulo()const {
	T x = sqrt((real*real) + (imaginaria*imaginaria));
	return x;
}


#endif