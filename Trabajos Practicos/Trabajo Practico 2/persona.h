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
        Persona(long , string, string, int);

        void ingresar();
        void mostrar();
        void crear();
        void eliminar();
        void modificar();

        void setDni(long );
        long  getDni();
        void setApellido(string);
        string getApellido();
        void setNombre(string);
        string getNombre();
        int getid();  //aca pongo primero el get y despues el set porque lo pide por pantalla
        void setid(int);

    protected:

    private:
        long  dni;
        string apellido;
        string nombre;
        int id;
};
#endif // PERSONA_H
