#include "persona.h"

using std::string;
using std::stringstream;
using namespace std;


//constructor
Persona::Persona(){

    this->nombre = "";
    this->edad = 1;
}
   

Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}

 
Persona::~Persona()
{

}