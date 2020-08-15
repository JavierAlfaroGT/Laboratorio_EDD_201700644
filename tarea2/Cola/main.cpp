#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "persona.h"
#include "persona.cpp"
using namespace std;

int main()
{
    //cout<<"hello"<<endl;
    //enqueue encolar
    //dequeue descolar  
/*

    Queue<int>*cola=new Queue<int>();
    Queue<string>*cola2=new Queue<string>();
    cola->enqueue(10);
    cola->enqueue(20);
    cola->enqueue(30);

    cola2->enqueue("hola");
    cola2->enqueue("como");

    cout<<cola->dequeue()->getValue()<<endl;
    cout<<cola->dequeue()->getValue()<<endl;
    cout<<cola2->dequeue()->getValue()<<endl;
    
    cola->vaciar();
    cola2->vaciar();

    delete cola;
    delete cola2;
*/
    Queue<Persona>*cola3=new Queue<Persona>();
    Persona* persona = new Persona("Javier",66);
    Persona* persona1 = new Persona("Juan",25);
    Persona* persona3 = new Persona("Barry",65);
    Persona* persona2 = new Persona("Luis",15);
    

    cola3->insertar(*persona1);
    cola3->insertar(*persona3);
    cola3->insertar(*persona);
    cola3->insertar(*persona2);

    cout<<cola3->dequeue()->getValue().nombre<<endl;
    cout<<cola3->dequeue()->getValue().nombre<<endl;
    cout<<cola3->dequeue()->getValue().nombre<<endl;

    cola3->vaciar();
    delete cola3;

    return 0;
}
