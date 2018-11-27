#ifndef ORGANIZACION_H
#define ORGANIZACION_H
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Organizacion
{
    public:
        Organizacion();
        Organizacion(string);

        void agregar();
        void modificar(string);
        void listar();
        void eliminar(string);
        void inicio();
        void setNombre(string);
        string getNombre();

    protected:

    private:
        string nombre;
};
#endif // ORGANIZACION_H
