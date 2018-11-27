#include "persona.h"
#include <iostream>
#include "myconnection.h"
#include "organizacion.h"
#include "domicilio.h"

using namespace std;

Domicilio::Domicilio()
{
    calle="";
    numero=0;
}

Domicilio::Domicilio(string calle,long numero)
{
    this->setCalle(calle);
    this->setNumero(numero);
}

void Domicilio::agregar()
{
  string stringSQL;
  stringstream values;
  values << this->getCalle() << "','" << this->getNumero();
  stringSQL = "INSERT INTO domicilio (calle,numero) VALUES ('"+values.str()+"');";
  MyConnection::instance()->execute(stringSQL);
}

void Domicilio::inicio(){
    cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout << "<body>   <div class='container'>"<<endl;
    cout<<"<div class='centrar'><h3>Crear Domicilio</h3></div>"<<endl;
    cout<<"<form  method='post'>"<<endl;
    cout<<"<label for='calle'>Calle</label>"<<endl;
    cout<<"<input type='text' id='calle' name='calle' required>"<<endl;
    cout<<"<label for='numero'>Numero</label>"<<endl;
    cout<<"<input type='text' id='numero' name='numero' required>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button name='button_agregar_domicilio' type='submit'>Enviar</button>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;

}


void Domicilio::asignar(string id_persona){

  MyConnection myconnection;
  myconnection.connect();
  sql::ResultSet* domicilios = myconnection.query("SELECT * FROM domicilio");

  cout<<"<html><head>"<<endl;
  cout << "</head>" <<endl;
  cout << "<body>   <div class='container'>"<<endl;
  cout<<"<form method='post'>"<<endl;
  cout << "<input type='hidden' name='id_persona' value=" + id_persona + ">"<<endl;
  cout <<"Domicilio: " << endl;
  cout << "<select name='sel_id_domicilio'>" << endl;

  while(domicilios->next())
  {

    cout << "<option value="+domicilios->getString("id")+">"+domicilios->getString("calle")+"-"+domicilios->getString("numero")+"</option>" << endl;
  }
  cout << "</select>" << endl;

  cout<<"<button name='button_asignar_domicilio' type='submit'>Asignar y Volver</button>"<<endl;
  cout<<"</form>"<<endl;
  cout<<"</div></body></html>"<<endl;

}


void Domicilio::cambiar(string id_persona, string id_domicilio)
{
  string stringSQL;
  stringSQL = "UPDATE persona SET iddomicilio='"+id_domicilio+"' WHERE id='"+id_persona+"'";
  MyConnection::instance()->execute(stringSQL);
}





void Domicilio::setNumero(long numero)
{
    this->numero = numero;
}

long Domicilio::getNumero()
{
    return this->numero;
}

void Domicilio::setCalle(string calle)
{
    this->calle = calle;
}

string Domicilio::getCalle()
{
    return this->calle;
}

void Domicilio::setid(int id)
{
  this->id=id;
}
int Domicilio::getid()
{
  return this->id;
}