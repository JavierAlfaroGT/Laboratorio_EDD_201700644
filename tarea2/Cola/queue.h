#ifndef QUEUE_H
#define QUEUE_H
#include "nodogenerico.h"
#include "nodogenerico.cpp"
#include <iostream>
using namespace std;
template<class T>//---------------------ojo-------------------
class Queue
{
public:
    Queue();//constructor
    ~Queue();//hakai
    void enqueue(T valor);//encolar
    NodoGenerico<T>* dequeue();//descolar
    void vaciar();//borra los items de la cola
    void insertar(T persona);//cola prioridad mi tarea 

private:
    NodoGenerico<T> *top;//cabeza
    NodoGenerico<T> *bottom;//final
};

#endif // QUEUE_H
