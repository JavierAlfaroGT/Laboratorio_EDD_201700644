/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("hello world\njajajaja\nmortal kombat");
    return 0;
}
*/
//*/

//--------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"

int main() {
    NodoA* a=newNodoC(1);
    NodoA* b=newNodoC(2);
    NodoC* c=newNodoC(3);
    NodoC* d=newNodoC(4);
    NodoC* e=newNodoC(5);
    NodoC* f=newNodoC(6);
    NodoC* g=newNodoC(7);
    NodoC* h=newNodoC(8);
    NodoC* i=newNodoC(9);
    ListaC* l=nuevaLista();
    add(l, a);
    add(l, b);
    add(l, c);
    add(l, d);
    add(l, e);
    add(l, f);
    add(l, g);
    add(l, h);
    add(l, i);
    //imprimir(l);

    //buscarIndex(l,2);//metodo implementado por 201700644
    //eliminarIndex(l,1);//metodo implementado por 201700644
    eliminarIndex(l,0);
    eliminarIndex(l,1);
    eliminarIndex(l,6);

    buscarIndex(l,2);
    imprimir(l);

    generar(l);
    Liberar(l);
    free(l);
    return 0;



}
