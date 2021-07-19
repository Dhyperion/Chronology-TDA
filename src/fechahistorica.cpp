#include <iostream>
#include <string>
#include <cstring>

#include "fechahistorica.h"

using namespace std;

FechaHistorica::FechaHistorica(){
  this->fecha = 0;
  this->num_acon = 0;
  acontecimientos = NULL;
} 


FechaHistorica::FechaHistorica(const FechaHistorica &f){
    this->fecha = f.getFecha();
    this->num_acon = f.getNumAcon();
    this->acontecimientos = new string[this->num_acon];

    for(int i=0; i<this->num_acon; i++){
      this->acontecimientos[i] = f.getAcontecimiento(i);
    }
}

void FechaHistorica::setFecha(int fecha){
  this->fecha = fecha;
}

void FechaHistorica::insertAcontecimiento(string acon){

  if(this->acontecimientos == NULL){
    this->num_acon = 1;
    this->acontecimientos = new string [this->num_acon];
    this->acontecimientos[0] = acon;
  }

  else{

    this->num_acon += 1;
    string *aux_acon = new string [this->num_acon];


    for(int i=0; i<this->num_acon-1; i++){
      aux_acon[i] = this->acontecimientos[i];
    }

    delete [] this->acontecimientos;

    this->acontecimientos = new string[num_acon];

    for(int i=0; i<this->num_acon-1; i++){
      this->acontecimientos[i] = aux_acon[i];
    }

    this->acontecimientos[this->num_acon-1] = acon;

    delete [] aux_acon;

  }

}

bool FechaHistorica::buscarAcontecimiento(string s, FechaHistorica &f){
  bool encontrado = false;
  for(int i=0; i<this->num_acon; i++){
    if(acontecimientos[i].find(s) != -1){
      f.insertAcontecimiento(acontecimientos[i]);
      encontrado = true;
    }
  }
  if(encontrado){
    f.setFecha(this->fecha);
  }
  return encontrado;
}

int FechaHistorica::getNumAcon() const {return this->num_acon;}
int FechaHistorica::getFecha() const {return this->fecha;}
string FechaHistorica::getAcontecimiento(int pos) const {return this->acontecimientos[pos];}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &f){
    //To-do ...  
    this->fecha = f.getFecha();
    this->num_acon = f.getNumAcon();
    this->acontecimientos = new string[this->num_acon];

    for(int i=0; i<this->num_acon; i++){
      this->acontecimientos[i] = f.getAcontecimiento(i);
    }
    return *this;
}

bool FechaHistorica::operator<(const FechaHistorica &f){
  return (this->fecha < f.getFecha())? true: false;
}

// Implementar el resto de métodos ...

ostream& operator<<(std::ostream &os, const FechaHistorica &f){
    //Completar ... 
    os<<"fecha: "<<f.getFecha()<<endl;

    for(int i=0; i<f.getNumAcon(); i++){
      os<<"acontemiento: "<<f.getAcontecimiento(i)<<endl;
    }
    return os;
}

FechaHistorica::~FechaHistorica(){
  delete [] acontecimientos;
}



// Este método se proporciona a medio hacer para facilitar la lectura de una FechaHistorica a partir de un fichero
istream& operator>>(std::istream &is, FechaHistorica &f){
  
  string s;

  getline(is, s, '#');

  int anio = stoi(s);
  cout << "\tLeido año: "<<anio<<endl;
  f.setFecha(anio);

  while(!is.eof()){
    s = "";
    getline(is, s, '#');
    cout << "\t\tLeido evento: "<<s<<endl;
    f.insertAcontecimiento(s);
  }

  return is;

}

FechaHistorica operator+(const FechaHistorica &f1, const FechaHistorica &f2){
  if(f1.getFecha() == f2.getFecha()){
    FechaHistorica suma;
    suma.setFecha(f1.getFecha());

    for(int i=0; i<f1.getNumAcon(); i++){
      suma.insertAcontecimiento(f1.getAcontecimiento(i));
    }
    for(int j=0; j<f2.getNumAcon(); j++){
      suma.insertAcontecimiento(f2.getAcontecimiento(j));
    }
    return suma;
  }

}


