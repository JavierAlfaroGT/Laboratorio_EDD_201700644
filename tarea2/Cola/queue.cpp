#include "queue.h"

template<class T>
Queue<T>::Queue()
{
    this->top=NULL;
    this->bottom=NULL;
}

template<class T>
Queue<T>::~Queue(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp=NULL;
    while(aux!=NULL){
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}


template<class T>//encolar
void Queue<T>::enqueue(T valor){
    if(this->top==NULL){
        NodoGenerico<T> *nuevo=new NodoGenerico<T>(valor);
        this->top=nuevo;
        this->bottom=nuevo;
    }else{
        NodoGenerico<T>*nuevo=new NodoGenerico<T>(valor);
        NodoGenerico<T>*aux=this->bottom;
        aux->setSiguiente(nuevo);
        this->bottom=nuevo;
    }
}

template <class T>//descolar
NodoGenerico<T>* Queue<T>::dequeue(){
    if(top==NULL){return NULL;}
    NodoGenerico<T>*aux=top;
    top=top->getSiguiente();
    return aux;
}

template<class T>
void Queue<T>::vaciar(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp;
    while(aux!=NULL){
        //cout<<aux->getValue()<<"\n";
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}

//-----------------------------------------------------------------------------------------------------
//                                       201700644
//-----------------------------------------------------------------------------------------------------
template<class T>
void Queue<T>::insertar(T persona){//cola prioridad
        int prioridad = persona.edad;

        if (this->top==NULL){//si la cola esta vacia
            NodoGenerico<T> *persona1=new NodoGenerico<T>(persona);  
            this->top=persona1;
            this->bottom=persona1;
            cout<<"se ingreso de primero a:"<<persona.nombre<<endl;
        }else {//significa q hay alguien mas en la cola ya

            if (prioridad > 65){//el del inicio se corre y el nuevo inicio se vuelve el abuelo
                NodoGenerico<T>*nuevo=new NodoGenerico<T>(persona);
                NodoGenerico<T>*aux=this->top;
                nuevo->setSiguiente(aux);
                this->top=nuevo;
                cout<<"se ingreso por prioridad a:"<<persona.nombre<<endl;  

            }else {//prioridad es baja se agrega normal aprovechare el metodo del auxiliar XD
                //this.enqueue(persona);
                NodoGenerico<T>*nuevo=new NodoGenerico<T>(persona);
                NodoGenerico<T>*aux=this->bottom;
                aux->setSiguiente(nuevo);
                this->bottom=nuevo;
                cout<<"se ingreso NORMAL a:"<<persona.nombre<<endl;
            }
        }//fin si la cola no esta vacia
    }//fin de metodo de agregar a cola



