#ifndef NODOS_HPP
#define NODOS_HPP

template <class Element>
class Nodo{

	// Atributos
	private:
		Element info;
		Nodo<Element> *next;

	public:

		Nodo(Element dato, Nodo<Element> *n);
		Nodo(Element dato);
		~Nodo();

		Element getDato();
		Nodo<Element>* getNext();
		void setDato(Element d);
		void setNext(Nodo<Element> *n);
};

template<class Element>
class NodoD: public Nodo<Element>{

	private:
		Nodo<Element> *before;

	public:
		NodoD(Element dato, Nodo<Element> *b, Nodo<Element> *n);
		NodoD(Element dato);

		Nodo<Element>* getBefore();
		void setBefore(Nodo<Element>* b);
};


#endif