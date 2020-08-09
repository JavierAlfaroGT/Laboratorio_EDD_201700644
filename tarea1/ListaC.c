#include "ListaC.h"

    void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                    NodoC* ant=aux->izquierda;
                    ant->derecha=nuevo;
                    nuevo->izquierda=ant;
                    nuevo->derecha=aux;
                    aux->izquierda=nuevo;
                    return;
                }else if(nuevo->val<=aux->derecha->val){
                    NodoC *siguiente=aux->derecha;
                    aux->derecha=nuevo;
                    nuevo->derecha=aux;
                    nuevo->derecha=siguiente;
                    siguiente->izquierda=nuevo;
                    return;
                }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
}

void Liberar(ListaC* l){//borra toda la lista a partir de los nodos
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        printf("se borro %d \n",aux->val);
        free(aux);
        aux=tmp;
    }
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);
        aux=aux->derecha;
    }
}
ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    return nueva;
}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void generar(ListaC* l){//graphviz
    FILE * fp;
    fp=fopen("./cadigo.txt","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{ \n node[shape=\"ellipse\",color = cyan,fontcolor=slateblue2,style=filled];\nedge[arrowhead=vee,color=blue];\n");//personalizacion
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){   
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p;\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------
//metodo implementado por 201700644
//-----------------------------------------------------------------------------------------------------------------------
void buscarIndex(ListaC* l,int index){
	if(l->head!=NULL){
        NodoC* aux  = l->head;//aux nodo
        int encontrado=0;
		for (int i = 0; i < index; i++) {	
            if(aux->derecha!=NULL){//si el de la derecha es no null nos movemos
			    aux = aux->derecha;
            }else{printf("\n fin lista\n\n");encontrado=1; break;}//llegamos hasta el ultimo nodo existenete
		}
		if(encontrado == 0){//si llegamos al indice que queriamos
			printf("\nValor en indice: %d\n\n",aux->val);
		}else{
            printf("\nindice NO EXISTE!\n\n");
        }

	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void eliminarIndex(ListaC* l,int index){
    if (index == 0) {//borro la cabeza
        NodoC* aux  = l->head;
        l->head = l->head->derecha;
        l->head->izquierda = NULL;
        free(aux);
        //pero falta borrar el espacio del antiguo (aux) cabeza queda en LIMBO
    } else {
        NodoC* aux  = l->head;
        int F=0;//para saber si sale del array o no XD

        for (int i = 0; i < index - 1; i++) {
            if(aux->derecha!=NULL){
                aux = aux->derecha;
            }else{F=1;break;}
        }
        if(F==0){
            if(aux->derecha->derecha==NULL){//si borro el ultimo
                NodoC* auxBorrar = aux->derecha;
                aux->derecha=NULL;
                //borrar el q le sigue a aux
                free(auxBorrar);       
            }else if(aux->derecha->derecha!=NULL){//si borro un intermedio
                //printf("FFFFFF %d",aux->derecha->derecha->val); 
                NodoC* auxBorrar1 = aux->derecha;
                aux->derecha->derecha->izquierda=aux;
                aux->derecha=aux->derecha->derecha;//enlazo
                
                //auxBorrar ;//borrar este nodo para q todo quede bien
                free(auxBorrar1);
                }
            }else{printf("error indice > q la lista\n");}
        }
    }

//-----------------------------------------------------------------------------------------------------------------------
//metodo implementado por 201700644
//-----------------------------------------------------------------------------------------------------------------------