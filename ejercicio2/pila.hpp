#ifndef PILA_HPP
#define PILA_HPP


#include "nodos.hpp"
#include<iostream>
#include "nodos.cpp"

template<class Element>
class Pila{

    private:
        Nodo<Element> *top;
        int length;
    
    public:
        
        Pila();
        ~Pila();

        Nodo<Element>* getTop();
        int getLength();

        void setTop(Nodo<Element> *t);
        void setLength(int l);

        void apilar(Nodo<Element> *nodo);
        void apilar(Element dato);
        void vaciar();
        
        friend std::ostream& operator<<(std::ostream& os, const Pila<Element> &p){
            os<<"[";
            for(Nodo<Element> *ptr = p.top; ptr != nullptr; ptr = ptr->getNext()){
                os<<ptr->getDato();
                if(ptr->getNext() != nullptr){
                    os<<",";
                }
            }
            os<<"]\n";
            return os;
        }
};

#endif
