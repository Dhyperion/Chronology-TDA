#include "fechahistorica.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  FechaHistorica f1; 
  FechaHistorica f2;
  FechaHistorica f4;
  FechaHistorica f5;

  ifstream f ("../datos/fh1.txt");
  if (!f){
    cout<<"No puedo abrir el fichero ../datos/fh1.txt"<<endl;
    return 0;
  }
   
  f>>f1; //Leemos la fecha histórica del fichero.
  FechaHistorica f3(f1); //utilizamos el constructor copia
  f2 = f1; //probamos la sobrecarga del operador de asignación

  f5 = f1 + f2; //sobrecarga del operador +

  cout<<f1;
  cout<<f2; //comprobamos sobrecarga del operador <<
  cout<<f3;
  cout<<f5;

  if(f4<f1){cout<<"f4 menor que f1"<<endl;} // utilizamos la sobrecarga del operador <

  if(f1.buscarAcontecimiento("The Enchanted Drawing", f4)){cout<<"encontrado!"<<endl;} //comprobamos la función buscarAcontecimiento()

   

   /* Exhibir aquí la funcionalidad programada para el TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener el año de una FechaHistorica
   // - Obtener los eventos de una FechaHistorica
   // - Comparar dos FechaHistorica (operator<)
   // - "Unir" o "sumar" dos FechaHistorica (operator+) -- sólo si tienen el mismo año.
   // - Cualquier otra funcionalidad que consideréis de interés
}
