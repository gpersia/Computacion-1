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
        Persona(long , int, string, string);

        void setDni(long);
        long  getDni();
        void setApellido(string);
        string getApellido();
        void setNombre(string);
        string getNombre();
        int getid();
        void setid(int);

        void as(string);
        void inicio();
        void agregar();
        void listar();
        void prueba();
        void eliminar(string);
        void recibir(string,string,string,string);
        void modificar(string,string,string,string);
    protected:

    private:
        long  dni;
        string apellido;
        string nombre;
        int id;
};
#endif // PERSONA_H