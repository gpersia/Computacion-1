#include "persona.h"
#include <iostream>
#include "myconnection.h"
#include "organizacion.h"

using namespace std;

Persona::Persona()
{
    dni=0;
    id=0;
    apellido="";
    nombre="";
}

Persona::Persona(long dni, int id, string apellido, string nombre)
{
    this->setDni(dni);
    this->setid(id);
    this->setApellido(apellido);
    this->setNombre(nombre);
}

void Persona::inicio(){
    cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout<<"<div class='centrar'><h3>Personas</h3></div>"<<endl;
    cout << "<thead><tr>" << endl;
    cout << "</tr></thead>" << endl;
    cout << "<tbody><tr>" << endl;
    this->listar();
    cout << "</tr>" << endl;
    cout << "</tr></tbody>" << endl;
    cout << "</table>" << endl;
    cout<<"<div class='centrar'><h3>Crear Persona</h3></div>"<<endl;
    cout<<"<form class='form-signin'  method='post'>"<<endl;
    cout<<"<label for='nombre' class='sr-only'>Nombre</label>"<<endl;
    cout<<"<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>"<<endl;
    cout<<"<label for='apellido' class='sr-only'>Apellido</label>"<<endl;
    cout<<"<input type='text' id='apellido' name='apellido' class='form-control' placeholder='Apellido' required>"<<endl;
    cout<<"<label for='dni' class='sr-only'>Dni</label>"<<endl;
    cout<<"<input type='text' id='dni' name='dni' class='form-control' placeholder='Dni' required>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button name='button_agregar_persona' type='submit'>Enviar</button>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;

}
void Persona::listar()
{
    MyConnection myconnection;
    myconnection.connect();
    sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.id as id_persona, persona.nombre as nombre_persona, persona.apellido as apellido_persona, persona.dni as dni_persona, persona.idorganizacion as idorganizacion_persona, persona.iddomicilio as iddomicilio_persona, organizacion.nombre as nombre_organizacion, domicilio.calle as calle_domicilio, domicilio.numero as numero_domicilio FROM computacion.persona LEFT JOIN organizacion ON persona.idorganizacion = organizacion.id LEFT JOIN domicilio ON persona.iddomicilio = domicilio.id ORDER BY apellido_persona");
    while (personas_organizaciones->next()) {
        cout << "<tr>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("dni_persona") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("apellido_persona") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("nombre_persona") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("nombre_organizacion") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("calle_domicilio") << endl;
        cout << "-" << endl;
        cout << personas_organizaciones->getString("numero_domicilio") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<form method='post'>" << endl;
        cout << "<input type='hidden' name='eliminar_id' value="+personas_organizaciones->getString("id_persona") +">" << endl;
        cout << "<button name='button_eliminar_form' type='submit'>Eliminar</button>"<<endl;
        cout << "</form>"<<endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<form method='post'>" << endl;
        cout << "<input type='hidden' name='modificar_id' value="+personas_organizaciones->getString("id_persona") +">" << endl;
        cout << "<input type='hidden' name='dni' value="+personas_organizaciones->getString("dni_persona") +">" << endl;
        cout << "<input type='hidden' name='nombre' value="+personas_organizaciones->getString("nombre_persona") +">" << endl;
        cout << "<input type='hidden' name='apellido' value="+personas_organizaciones->getString("apellido_persona")+">" << endl;
        cout << "<button name='button_modificar_form' type='submit'>Modificar</button>"<<endl;
        cout << "</form>"<<endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<form method='post'>" << endl;
        cout << "<input type='hidden' name='asignarorg_idpersona' value="+personas_organizaciones->getString("id_persona") +">" << endl;
        cout << "<input type='hidden' name='dni' value="+personas_organizaciones->getString("dni_persona") +">" << endl;
        cout << "<input type='hidden' name='nombre' value="+personas_organizaciones->getString("nombre_persona") +">" << endl;
        cout << "<input type='hidden' name='apellido' value="+personas_organizaciones->getString("apellido_persona")+">" << endl;
        cout << "<button name='button_asignar_organizacion_form' type='submit'>Asignar Organizacion</button>"<<endl;
        cout << "</form>"<<endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<form method='post'>" << endl;
        cout << "<input type='hidden' name='asignardom_idpersona' value="+personas_organizaciones->getString("id_persona") +">" << endl;
        cout << "<input type='hidden' name='dni' value="+personas_organizaciones->getString("dni_persona") +">" << endl;
        cout << "<input type='hidden' name='nombre' value="+personas_organizaciones->getString("nombre_persona") +">" << endl;
        cout << "<input type='hidden' name='apellido' value="+personas_organizaciones->getString("apellido_persona")+">" << endl;
        cout << "<button name='button_asignar_domicilio_form' type='submit'>Asignar Domicilio</button>"<<endl;
        cout << "</form>"<<endl;
        cout << "</td>" << endl;
    }

}

void Persona::recibir(string id, string dni, string nombre, string apellido){
  MyConnection myconnection;
  myconnection.connect();

  cout<<"<html><head>"<<endl;
  cout << "</head>" <<endl;
  cout << "<body>   <div class='container'>"<<endl;
  cout<<"<form method='post'>"<<endl;
  cout<<"<label for='dni2' >Dni</label>"<<endl;
  cout << "<input type='text' name='dni2' id='dni2' value="+dni+" >" << endl;
  cout << "<input type='hidden' name='id2' id='id2' value="+id+" >" << endl;
  cout<<"<label for='nombre2' >Nombre</label>"<<endl;
  cout << "<input type='text' name='nombre2' id='nombre2' value="+nombre+" >" << endl;
  cout<<"<label for='apellido2' >Apellido</label>"<<endl;
  cout << "<input type='text' name='apellido2' id='apellido2' value="+apellido+" >" << endl;
  cout<<"<button name='button_cambiar' type='submit'>Guardar y Volver</button>"<<endl;
  cout<<"</form>"<<endl;
  cout<<"</div></body></html>"<<endl;
}

void Persona::modificar(string i,string d, string n, string a)
{
    string stringSQL;
    stringSQL = "UPDATE persona SET dni='"+d+"', nombre='"+n+"',apellido='"+a+"' WHERE id='"+i+"'";

    MyConnection::instance()->execute(stringSQL);
}

void Persona::agregar()
{
    string stringSQL;
    stringstream values;
    values << this->getDni() << "','" << this->getNombre() << "','" << this->getApellido();
    stringSQL = "INSERT INTO persona (dni,nombre,apellido) VALUES ('"+values.str()+"');";
    MyConnection::instance()->execute(stringSQL);
}


void Persona::eliminar(string id){
    string stringSQL;
    stringSQL = "DELETE FROM persona WHERE id='"+id+"'";
    MyConnection::instance()->execute(stringSQL);
}




void Persona::setDni(long dni)
{
    this->dni = dni;
}

long Persona::getDni()
{
    return this->dni;
}

void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

string Persona::getApellido()
{
    return this->apellido;
}

void Persona::setNombre(string  nombre)
{
    this->nombre = nombre;
}

string Persona::getNombre()
{
    return this->nombre;
}
void Persona::setid(int id){
  this->id=id;
}
int Persona::getid(){
  return this->id;
}
