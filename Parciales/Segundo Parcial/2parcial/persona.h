#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Persona
{
    public:
        Persona();
        Persona(long , string, string);

        void agregar();
        void listar();
        void eliminar(string);
        void inicio();
        void setDni(long );
        long  getDni();
        void setApellido(string);
        string getApellido();
        void setNombre(string);
        string getNombre();
    protected:

    private:
        long  dni;
        string apellido;
        string nombre;
};
#endif // PERSONA_H
