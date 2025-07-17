#include "nodos.hpp"

template<class Element>
Nodo<Element>::Nodo(Element dato, Nodo<Element> *n)
{
	info = dato;
	next = n;
}
template<class Element>
Nodo<Element>::Nodo(Element dato): Nodo(dato,nullptr)
{}
template<class Element>
Nodo<Element>::~Nodo()
{}

template<class Element>
Element Nodo<Element>::getDato()
{
	return info;
}
template<class Element>
Nodo<Element>* Nodo<Element>::getNext()
{
	return next;
}
template<class Element>
void Nodo<Element>::setDato(Element d)
{
	info = d;
}
template<class Element>
void Nodo<Element>::setNext(Nodo<Element> *n)
{
	next = n;
}

// Nodo Doble enlace

template<class Element>
NodoD<Element>::NodoD(Element dato, Nodo<Element> *b, Nodo<Element> *n)
{
	Nodo<Element>(dato,n);
	before = b;

}
template<class Element>
NodoD<Element>::NodoD(Element dato): NodoD(dato,nullptr,nullptr)
{}

template<class Element>
Nodo<Element>* NodoD<Element>::getBefore()
{
	return before;
}
template<class Element>
void NodoD<Element>::setBefore(Nodo<Element>* b)
{
	before = b;
}

