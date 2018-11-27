#include "organizacion.h"
#include <iostream>
#include "myconnection.h"

using namespace std;
Organizacion::Organizacion()
{
    nombre="";
    id=0;

}

Organizacion::Organizacion(string nombre,int id)
{
    this->setNombre(nombre);
    this->setid(id);
}


void Organizacion::agregar()
{
    string stringSQL;
    stringstream values;
    values << this->getNombre();
    stringSQL = "INSERT INTO organizacion (nombre) VALUES ('"+values.str()+"');";
    MyConnection::instance()->execute(stringSQL);
}

void Organizacion::inicio(){
    cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout << "<body>   <div class='container'>"<<endl;
    cout << "</table>" << endl;
    cout<<"<div><h2>Agregar Organizacion</h2></div>"<<endl;
    cout<<"<form  method='post'>"<<endl;
    cout<<"<label for='organizacion'>Organizacion</label>"<<endl;
    cout<<"<input type='text' id='organizacion' name='organizacion' placeholder='organizacion' required autofocus>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button name='button_agregar_organizacion' type='submit'>Enviar</button>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;

}

void Organizacion::asignar(string id_persona){

  MyConnection myconnection;
  myconnection.connect();
  sql::ResultSet* organizaciones = myconnection.query("SELECT * FROM organizacion");

  cout<<"<html><head>"<<endl;
  cout << "</head>" <<endl;
  cout << "<body>   <div class='container'>"<<endl;
  cout<<"<form method='post'>"<<endl;
  cout << "<input type='hidden' name='id_persona' value=" + id_persona + ">"<<endl;
  cout <<"Organizacion: " << endl;
  cout << "<select name='sel_idorganizacion'>" << endl;
  while(organizaciones->next())
  {
    cout << "<option value="+organizaciones->getString("id")+">"+organizaciones->getString("nombre")+"</option>" << endl;
  }
  cout << "</select>" << endl;
  cout<<"<button name='button_asignar_organizacion' type='submit'>Asignar y Volver</button>"<<endl;
  cout<<"</form>"<<endl;
  cout<<"</div></body></html>"<<endl;

}

void Organizacion::cambiar(string id_persona, string id_organizacion)
{
  string stringSQL;
  stringSQL = "UPDATE persona SET idorganizacion='"+id_organizacion+"' WHERE id='"+id_persona+"'";
  MyConnection::instance()->execute(stringSQL);
}


void Organizacion::listar()
{

}

void Organizacion::eliminar(int x){

}

void Organizacion::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Organizacion::getNombre()
{
    return this->nombre;
}

void Organizacion::setid(int id)
{
  this->id=id;
}
int Organizacion::getid()
{
  return this->id;
}
