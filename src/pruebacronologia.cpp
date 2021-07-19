#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
  int ini, final;

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Cronologia mi_cronologia;
   f>>mi_cronologia; //Cargamos en memoria la cronología.
   
   cout<<mi_cronologia;

   mi_cronologia.buscarPorFecha(1941); //obtenemos los eventos acecidos en un año dado

   cout<<"insertar dos años para buscar entre la cronologia : "<<endl;
   cin>>ini>>final;

   cout<< mi_cronologia.buscarEntreFechas(ini, final); //subcronologia de eventos acaecidos entre dos años
   Cronologia nueva = mi_cronologia; //probando la sobrecarga del operador =

   Cronologia copia = nueva.buscarPorPalabra("Einstein"); //utilizo la sobrecarga de =, junto con la función de crear una subcronología de eventos históricos asociados a una palabra

   cout<< copia;

   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés


}
