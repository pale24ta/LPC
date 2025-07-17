#include<iostream>
#include "lista.hpp"


template <class Element>
inline Lista<Element>::Lista()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class Element>
inline Lista<Element>::Lista(const Lista<Element> &c)
{
    if(c.length != 0){
        Nodo<Element> *p1 = c.head, *p2 = nullptr;

        Nodo<Element> *add = new Nodo<Element>(p1->getDato());
        head = add;
        p1 = p1->getNext();

        for(; p1 != nullptr; p1 = p1->getNext()){
            add->setNext(new Nodo<Element>(p1->getDato()));
            p2 = add->getNext();
            add = add->getNext();
        }
        tail = p2;
        length = c.length;
    }
}

template <class Element>
inline Nodo<Element> *Lista<Element>::getHead()
{
    return head;
}

template <class Element>
inline Nodo<Element> *Lista<Element>::getTail()
{
    return tail;
}

template <class Element>
inline int Lista<Element>::getLength()
{
    return length;
}

template <class Element>
inline void Lista<Element>::setHead(Nodo<Element> *h)
{
    head = h;
}

template <class Element>
inline void Lista<Element>::setTail(Nodo<Element> *t)
{
    tail = t;
}

template <class Element>
inline void Lista<Element>::setLength(int l)
{
    length = l;
}

template <class Element>
inline void Lista<Element>::insertar(Element dato, int pos)
{
    Nodo<Element> *ant = nullptr, *act = head;

    Nodo<Element> *nuevo = new Nodo<Element>(dato);

    for(int i=1; i < pos && act != nullptr; i++){
        ant = act;
        act = act->getNext();
    }

    if(ant == NULL){
        if(act == NULL){
            head = nuevo;
            tail = nuevo;
        }else{
            nuevo->setNext(head);
            head = nuevo;
        }
    }else if(act == NULL){
        tail->setNext(nuevo);
        tail = nuevo;
    }else{
        ant->setNext(nuevo);
        nuevo->setNext(act);
    }
    length += 1;
}

template <class Element>
inline void Lista<Element>::remover(int pos)
{
    Nodo<Element> *ant = nullptr, *act = head, *del = nullptr;

    for(int i=1; i < pos && act != nullptr; i++)
    {
        ant = act;
        act = act->getNext();
    }

    del = act;  // Dato a eliminar

    if(ant == nullptr){
        head = act->getNext();
    }else if(act->getNext() == nullptr){
        tail = ant;
    }else{
        ant->setNext(act->getNext());
    }
    delete del;
    length -= 1;

}

template <class Element>
inline void Lista<Element>::insertarAlPrin(Element dato)
{
    Nodo<Element> *nuevo = new Nodo<Element>(dato);

    nuevo->setNext(head);

    if(nuevo->getNext() == nullptr){
        tail = nuevo;
    }

    head = nuevo;

    length += 1;
}

template <class Element>
inline void Lista<Element>::insertarAlFinal(Element dato)
{
    Nodo<Element> *nuevo = new Nodo<Element>(dato);

    tail->setNext(nuevo);

    tail = nuevo;
    length += 1;
}

template <class Element>
Element Lista<Element>::llamar(int pos)
{
    Nodo<Element> *ptr = head;

    for(int i=1; i < pos && ptr != nullptr; i++){
        ptr = ptr->getNext();
    }
    return ptr->getDato();
}

template <class Element>
void Lista<Element>::vaciar()
{
    Nodo<Element> *ptr = head, *del= nullptr;

    for(; ptr != head; ptr = ptr->getNext()){
        del = ptr;
        ptr = ptr->getNext();
        delete del;
    }

    head = nullptr;
    tail = nullptr;
    length  = 0;
}

template <class Element>
void Lista<Element>::copiar(const Lista<Element> &c)
{
    vaciar();

    if(c.length != 0){
        Nodo<Element> *p1 = c.head, *p2 = nullptr;

        Nodo<Element> *add = new Nodo<Element>(p1->getDato());
        head = add;
        p1 = p1->getNext();

        for(; p1 != nullptr; p1 = p1->getNext()){
            add->setNext(new Nodo<Element>(p1->getDato()));
            p2 = add->getNext();
            add = add->getNext();
        }
        tail = p2;
        length = c.length;
    }
}

template <class Element>
void Lista<Element>::bubbleSort()
{
    
}

template <class Element>
Lista<Element> Lista<Element>::subLista(int left, int right)
{
    Lista<Element> nuevaLista;
    Nodo<Element> *add;

    Nodo<Element> *p1 = head,*p2 = nullptr;      // 2 pivotes
    int i;
    
    for(i = 1; i < left && p1 != nullptr; i++){
        p1 = p1->getNext();
    }

    // Una vez encontrada la posicion deseada

    add = new Nodo<Element>(p1->getDato());
    nuevaLista.head = add;
    p1 = p1->getNext();

    for(; i< right && p1 != nullptr; i++){
        add->setNext(new Nodo<Element>(p1->getDato()));
        p2 = add->setNext();
        add = add->getNext();
        p1 = p1->getNext();
    }

    nuevaLista.setTail(p2);
    nuevaLista.setLength(right - left + 1);
    return nuevaLista;
}

template <class Element>
Lista<Element> Lista<Element>::concat(const Lista<Element> &l)
{
    Lista<Element> nueva(l);

    Nodo<Element> *p1 = head;
    Nodo<Element> *add = new Nodo(p1->getDato());

    Nodo<Element> *phead = add;
    Nodo<Element> *pfinal =nullptr;

    for(p1 = p1->getNext(); p1 != nullptr; p1 = p1->getNext()){
        add->setNext(new Nodo(p1->getDato()));
        pfinal = add->getNext();
        add = add->getNext();
    }

    pfinal->setNext(nueva.head);
    nueva.head = phead;
    nueva.length = nueva.length + l.length;
    return nueva;

}
