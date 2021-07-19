#include <iostream>
#include <sstream>
#include <string>

#include "cronologia.h"

using namespace std;


Cronologia::Cronologia(){
  this->num_eventos = 0;
  this->eventos = NULL;
}

Cronologia::Cronologia(const Cronologia& c){
  this->num_eventos = c.getNumEventos();
  this->eventos = new FechaHistorica[this->num_eventos];

  for(int i=0; i<this->num_eventos; i++){
    this->eventos[i] = c.getFechaHistorica(i);
  }

}

Cronologia& Cronologia::operator=(const Cronologia &c){
  if(this != &c){
    this->num_eventos = c.getNumEventos();
    this->eventos = new FechaHistorica[this->num_eventos];

    for(int i=0; i<this->num_eventos; i++){
      this->eventos[i] = c.getFechaHistorica(i);
    }
  }
  return *this;
}

// Completar la implementación...

void Cronologia::insertFechaHistorica(FechaHistorica &f){

  if(this->eventos == NULL){
    this->num_eventos = 1;
    this->eventos = new FechaHistorica[this->num_eventos];
    this->eventos[0] = f;
  }

  else{
    this->num_eventos += 1;
    FechaHistorica *aux = new FechaHistorica[this->num_eventos];

    for(int i=0; i<this->num_eventos-1; i++){
      aux[i] = this->eventos[i];
    }
    delete [] this->eventos;

    this->eventos = new FechaHistorica[num_eventos];

    for(int i=0; i<this->num_eventos-1; i++){
      this->eventos[i] = aux[i];
    }

    this->eventos[num_eventos-1] = f;
    delete [] aux;
    ordenar();
  }

}

void Cronologia::ordenar(){
  for(int i=0; i<num_eventos; i++){
    for(int j=0; j<num_eventos-1; j++){
      if(eventos[j+1]<eventos[j]){
        FechaHistorica aux;
        aux = eventos[j];
        eventos[j] = eventos[j+1];
        eventos[j+1] = aux;
      }
    }
  }
}

void Cronologia::buscarPorFecha(int anio){
  for(int i=0; i<this->num_eventos; i++){
    if(eventos[i].getFecha() == anio){
      cout<<eventos[i];
    }
  }
}

Cronologia Cronologia::buscarPorPalabra(string palabra){
  Cronologia sublista;
  for(int i=0; i<this->num_eventos; i++){
    FechaHistorica aux;
    if(eventos[i].buscarAcontecimiento(palabra, aux)){
      sublista.insertFechaHistorica(aux);
    }
  }
  sublista.ordenar();
  return sublista;
}

Cronologia Cronologia::buscarEntreFechas(int fInicio, int fFinal){
  assert(fInicio<fFinal);

  Cronologia sublista;

  for(int i=0; i<this->num_eventos; i++){
    if((eventos[i].getFecha()>=fInicio) && (eventos[i].getFecha()<=fFinal)){
      sublista.insertFechaHistorica(eventos[i]);
    }
  }

  return sublista;
}

int Cronologia::getNumEventos()const {return this->num_eventos;}
FechaHistorica Cronologia::getFechaHistorica(int pos)const {return this->eventos[pos];}

Cronologia::~Cronologia(){
  delete [] eventos;
}


// Este método se proporciona a medio hacer para facilitar la lectura de una Cronologia a partir de un fichero
istream& operator>>(istream &flujo, Cronologia &c){

  cout << "Leyendo cronología ..."<<endl;

  int fh_leidas =0; 

  string s;
  getline(flujo, s, '\n');

  while(flujo.eof() == 0){
    istringstream ss(s);
    FechaHistorica aux;
    cout << "Leyendo FechaHistorica número: "<<fh_leidas<<endl;
    ss >> aux;
    //Aquí aux es una FechaHistorica que ya contiene la información de esa linea del fichero
    c.insertFechaHistorica(aux);
    fh_leidas ++;
    s = "";
    getline(flujo, s, '\n');
  }

  return flujo;
}

ostream& operator<<(std::ostream &flujo, const Cronologia &c){
  for(int i=0; i<c.getNumEventos(); i++){
    flujo << c.eventos[i];
  }
  return flujo;
}


