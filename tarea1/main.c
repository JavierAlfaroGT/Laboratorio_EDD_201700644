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
#include "ListaC.c"
#include "NodoC.c"

int main(){
    NodoA* a=newNodoC(10);
    NodoA* b=newNodoC(3);
    NodoC* c=newNodoC(25);
    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    //imprimir(l);

    buscarIndex(l,2);//metodo implementado por 201700644
    eliminarIndex(l,1);//metodo implementado por 201700644

    imprimir(l);

    generar(l);
    Liberar(l);
    free(l);
    return 0;
    
    
    
}
