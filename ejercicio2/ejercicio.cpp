#include<iostream>
#include "lista.hpp"
#include "lista.cpp"




Lista<Lista<int>> compac(Lista<int> lista);

int main(){
    Lista<int> lista;
    Lista<Lista<int>> resultado;
    
    lista.insertar(1,1);
    lista.insertar(1,2);
    lista.insertar(1,3);
    lista.insertar(2,4);

    lista.shiftleft(4);
    std::cout<<lista;
    return 0;
}

Lista<Lista<int>> compac(Lista<int> lista)
{
    Lista<int> subLista;
    Lista<Lista<int>> nueva;

    int count =1, j=1;

    for(int i = 1; i <= lista.getLength(); i++){
        if(lista.llamar(i+1) == lista.llamar(i)){
            count++;
        }else{
            subLista.insertar(lista.llamar(i),1);
            subLista.insertar(count,2);
            nueva.insertar(subLista,j);
            j++;
            count = 1;
            subLista.vaciar();
        }
    }

    return nueva;
}
