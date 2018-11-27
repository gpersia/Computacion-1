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
        Organizacion(string,int);

        void agregar();
        void listar();
        void asignar(string);
        void cambiar(string,string);
        void eliminar(int);
        void inicio();
        void setNombre(string);
        string getNombre();
        void setid(int);
        int getid();

    protected:

    private:
        string nombre;
        int id;
};
#endif // ORGANIZACION_H
