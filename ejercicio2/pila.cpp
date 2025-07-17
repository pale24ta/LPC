#include<iostream>
#include "pila.hpp"



template <class Element>
inline Pila<Element>::Pila()
{
    top = nullptr;
    length = 0;
}

template <class Element>
inline Pila<Element>::~Pila()
{
}

template <class Element>
inline Nodo<Element> *Pila<Element>::getTop()
{
    return top;
}

template <class Element>
inline int Pila<Element>::getLength()
{
    return length;
}

template <class Element>
inline void Pila<Element>::setTop(Nodo<Element> *t)
{
    top = t;
}

template <class Element>
inline void Pila<Element>::setLength(int l)
{
    length = l;
}

template <class Element>
inline void Pila<Element>::apilar(Nodo<Element> *nodo)
{
    nodo->setNext(top);
    top = nodo;

    length += 1;
    
}

template <class Element>
inline void Pila<Element>::apilar(Element dato)
{
    apilar(new Nodo<Element>(dato));
}
template<class Element>
void Pila<Element>::vaciar(){
    Nodo<Element> *p = top, *del = NULL;

    for(; p != NULL; p = p->getNext()){
        del = p;
        p = p->getNext();
        delete del;
    }
    length = 0;
}