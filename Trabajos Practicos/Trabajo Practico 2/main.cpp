#include <iostream>
#include <string>
// Formularios html
#include "getpost.h"
#include <typeinfo>
#include "persona.h"
#include "myconnection.h"

using namespace std;

int main (int argc, char* const argv[]) {
  // Para formularios
  // map<string,string> Post;
  // initializePost(Post);

  MyConnection myconnection;
  myconnection.connect();
  sql::ResultSet* personas = myconnection.query("SELECT persona.nombre, persona.apellido, persona.dni FROM persona");
  sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.nombre as nombre_persona,persona.apellido as apellido_persona,organizacion.nombre  as organizacion_nombre FROM computacion.persona INNER JOIN organizacion ON persona.idorganizacion = organizacion.id Where organizacion.nombre = 'Google'");

  Persona persona;

  map<string,string> Post;
  initializePost(Post);

    if (Post.find("nombre")==Post.end() )
    {
        cout<<"Content-type: text/html"<<endl<<endl;
        cout<<"<html><head>"<<endl;
        cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
        cout << "</head>" <<endl;
        cout << "<body>   <div class='container'>"<<endl;
        cout<<"<div class='centrar'><h2>Personas Cargadas</h2></div>"<<endl;

        cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
        cout << "<thead><tr>" << endl;
        cout << "<th >DNI</th>"<< endl;
        cout << "<th >Apellido</th>"<< endl;
        cout << "<th >Nombre</th>"<< endl;
        cout << "</tr></thead>" << endl;
        cout << "<tbody><tr>" << endl;
         while (personas->next()) {
          cout << "<td> " << personas->getString("dni") << "</td><td>" << personas->getString("nombre") << "</td><td>" << personas->getString("apellido") << "<td><a href='eliminar?10000000'" << endl;
          cout << ">Eliminar</a></td><td><span class='glyphicon glyphicon-pencil' aria-hidden='true'></span></td></tr><tr>" << endl;
        }
        cout << "</tr>" << endl;
        cout << "</tr></tbody>" << endl;
        cout << "</table>" << endl;
        cout<<"<div class='centrar'><h2>Agregar Persona</h2></div>"<<endl;
        cout<<"<form class='form-signin'  method='post'>"<<endl;
        cout<<"<label for='nombre' class='sr-only'>Nombre</label>"<<endl;
        cout<<"<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>"<<endl;
        cout<<"<label for='apellido' class='sr-only'>Apellido</label>"<<endl;
        cout<<"<input type='text' id='apellido' name='apellido' class='form-control' placeholder='Apellido' required>"<<endl;
        cout<<"<label for='dni' class='sr-only'>Dni</label>"<<endl;
        cout<<"<input type='text' id='dni' name='dni' class='form-control' placeholder='Dni' required>"<<endl;
        cout<<"<br>"<<endl;

        cout<<"<br>"<<endl;
        cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Enviar</button>"<<endl;
        cout<<"</form>"<<endl;
        cout<<"</div></body></html>"<<endl;

    }

  if (Post.find("nombre")!=Post.end() && Post.find("apellido")!=Post.end()) {
        cout<<"Content-type: text/html"<<endl<<endl;
        cout<<"<html><head>"<<endl;
        cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
        cout << "</head>" <<endl;
        cout << "<body>   <div class='container'>"<<endl;
        cout<<"<div class='centrar'><div class='datos'>"<<endl;

    //cout<<"<p class='centrar pad-top'><h1> Hola "<<Post["nombre"]<<" "<<Post["apellido"]<<"</h1></p>"<<endl;
        persona.setNombre(Post["nombre"]);
        persona.setApellido(Post["apellido"]);
        persona.setDni(atol(Post["dni"].c_str()));
        persona.ingresar();


        cout<<"</div></div></div></body></html>"<<endl;
  }



  return 0;
}
