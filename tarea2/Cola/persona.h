#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using namespace std;


class Persona
{
public:
    
    Persona();
    Persona(string nombre, int edad);
    int edad;
    string nombre;
    ~Persona();
};

#endif // PERSONA_H
