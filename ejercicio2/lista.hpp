#ifndef LISTA_HPP
#define LISTA_HPP

#include<iostream>
#include"nodos.hpp"
#include"nodos.cpp"


template<class Element>
class Lista{
    
    private:
        Nodo<Element> *head,*tail;
        int length;

    public:

        Lista();
        //Lista(const Lista<Element> &c);

        Nodo<Element>* getHead();
        Nodo<Element>* getTail();
        int getLength();

        void setHead(Nodo<Element>* h);
        void setTail(Nodo<Element>* t);
        void setLength(int l);

        void insertar(Element dato, int pos);
        void remover(int pos);
        void insertarAlPrin(Element dato);
        void insertarAlFinal(Element dato);
        Element llamar(int pos);

        void vaciar();
        void copiar(const Lista<Element> &c);

        void bubbleSort();

        Lista<Element> subLista(int left, int right);
        Lista<Element> concat(const Lista<Element> &l);

        friend std::ostream& operator<<(std::ostream& os, const Lista<Element> &l){
            os<<"[";
            for(Nodo<Element> *p = l.head; p != nullptr; p = p->getNext())
            {
                os<<p->getDato();
                if(p->getNext() != nullptr)
                {
                    os<<",";
                }
            }
            os<<"]\n";

            return os;
        }
        
};
#endif
