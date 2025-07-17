#include<iostream>
#include "lista.hpp"
#include "lista.cpp"

int main(int argc, char const *argv[])
{
    Lista<int> lista,otraLista;
    Lista<Lista<int>> macro;


    for(int i=1;i<=10;i++){
        lista.insertar(i*2,i);
        otraLista.insertar(i*3,i);

    }

    macro.insertar(lista,1);
    macro.insertar(otraLista,2);


    std::cout<<macro;
    return 0;
}
