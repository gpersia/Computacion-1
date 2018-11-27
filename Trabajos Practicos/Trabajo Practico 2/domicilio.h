#ifndef DOMICILIO_H
#define DOMICILIO_H
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Domicilio
{
    public:
        Domicilio();
        Domicilio(string,long);

        void setNumero(long);
        long  getNumero();
        void setCalle(string);
        string getCalle();
        void setid(int);
        int getid();


        void inicio();
        void agregar();
        void asignar(string);
        void cambiar(string,string);
        void listar();
        void prueba();
        void eliminar(string);
        void recibir(string,string,string,string);
        void modificar(string,string,string,string);

    protected:

    private:
        long  numero;
        string calle;
        int id;
};
#endif // DOMICILIO_H
