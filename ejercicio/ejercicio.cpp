#include<iostream>
#include "lista.hpp"
#include "lista.cpp"



void backtracking(Nodo<int> *begin, int &casos);
bool validar(int pasos, Nodo<int> *ptr);

int main(){
    Lista<int> elementos;
    int casos = 0;

    for(int i = 1; i <= 8; i++){
        elementos.insertar(i*2,i);
    }
    Nodo<int> *ptr = elementos.getHead();
    backtracking(ptr,casos);
    std::cout<<casos<<" casos encontrados";

    return 0;

}


void backtracking(Nodo<int> *begin, int &casos)
{
    int index =1;
    int opcionValida;
    Nodo<int> *ant;

    while(index <= 2)   // Dos opciones disponibles
    {
        if(validar(index,begin)){
            opcionValida = index;

            ant = begin;
            switch (opcionValida)
            {
            case 1:
                begin = begin->getNext();
                break;
            
            case 2:
                begin = begin->getNext()->getNext();
                break;
            }

            if((begin->getNext() == NULL)){

                casos = casos + 1;
            }else{
                backtracking(begin,casos);
            }
            begin = ant;
        }
        index++;
    }
}

bool validar(int pasos, Nodo<int> *ptr)
{
    switch (pasos)
    {
    case 1:
        if(ptr->getNext() == NULL){
            return false;
        }
        break;
    
    default:
        if(ptr->getNext()->getNext() == NULL){
            return false;
        }
        break;
    }
    return true;
}
