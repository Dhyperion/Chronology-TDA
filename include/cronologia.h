#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include "fechahistorica.h"

using namespace std;


/**
 * @class Cronologia
 *
 * @brief T.D.A. de un conjunto de FechaHistorica ordenadas por fechas
 *
 * una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto que agrupa acontecimientos ocasionados en distintas fechas,
 * compuesto por un array de FechaHistorica que almacenará en cada posicion los acontecimientos de un año especifico.
 *
 *
 * @author Manuel Jesús Alcaraz Cortizo
*/

class Cronologia{

private:
  int num_eventos; 
  FechaHistorica *eventos;

public:

/**
  * @brief Constructor por defecto
  */
Cronologia();

/**
  * @brief Constructor de copia
  * 
  * @param c un objeto de Cronologia
  */
Cronologia(const Cronologia& c);

/**
  * @brief Sobrecarga del operador =
  * 
  * @param c un objeto de Cronologia
  *
  * @return devuelve el propio objeto con los valores del objeto c
  */
Cronologia& operator=(const Cronologia &c);

/**
  * @brief ordena el array FechaHistorica por su fecha de mayor a menos
  * 
  */
void ordenar();

/**
  * @brief insertar un objeto FechaHistorica dentro del array eventos
  * 
  * @param f, objeto FechaHistorica que se asignará a la nueva posición del array
  *
  * @return vector eventos redimensionado  con una nueva posicion y con el parametro f ya insertado y ordenado
  *
  */
void insertFechaHistorica(FechaHistorica &f);

/**
  * @brief Número de eventos
  * @return devuelve el numero de eventos que tiene el vector eventos
  */
int getNumEventos()const;

/**
  * @brief Fecha Hsitorica
  * @param pos posición del vector que se quiere consultar
  * @return devuelve un objeto FechaHistorica dentro del array eventos
  */
FechaHistorica getFechaHistorica(int pos)const;

/**
  * @brief busca los acontecimientos sucedidos en un año especifico
  * 
  * @param anio, año de los acontecimientos que se quieren buscar
  */
void buscarPorFecha(int anio);

/**
  * @brief busca los acontecimientos sucedidos asociados a una palabra
  * 
  * @param palabra, palabra clave para buscar los acontecimientos asociados a esta
  *
  * @return retorna una subcronología con los eventos sucedidos de la palabra especificada
  */
Cronologia buscarPorPalabra(string palabra);

/**
  * @brief busca los acontecimientos sucedidos entre dos fechas
  * 
  * @param fInicio se creará la subcronología a partir de esta fecha
  * @param fFinal fecha que finaliza la creación de la subcronologría a partir de ella
  *
  * @pre fInicio tiene que ser menor a fFinal
  *
  * @return devuelve una subcronología con los eventos sucedidos entre las dos fechas especificadas
  * 
  */
Cronologia buscarEntreFechas(int fInicio, int fFinal);

/**
  * @brief Sobrecarga del operador <<
  *
  * @param flujo stream de salida
  * @param c, objeto Cronologia a escribir
  *
  */
friend ostream& operator<<(std::ostream &flujo, const Cronologia &c);

/**
  * @brief Destructor de la clase Cronologia
  */
~Cronologia();

};

/**
  * @brief Sobrecarga del operador >>
  *
  * @param flujo stream de entrada
  * @param c objeto Cronologia que recibe el valor
  * 
  * @retval la Cronologia leida en c
  *
  */

istream& operator>>(std::istream &flujo, Cronologia &c);

#endif
