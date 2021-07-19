#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * @class FechaHistorica
 *
 * @brief T.D.A. de un conjuto de acontecimientos en una fecha
 *
 * una instancia @e c del tipo de datos abstracto ©c FechaHistorica es un objeto de los acontecimientos realizados en una fecha,
 * compuesto por un array de strings que almacenará los acontecimientos sucedidos y un valor entero que representa la fecha que sucedierón
 * los acontecimientos.
 *
 * @author Manuel Jesús Alcaraz Cortizo
*/


using namespace std;


class FechaHistorica{

private:
  int fecha;
  int num_acon;
  string *acontecimientos;

public:
/**
  * @brief Constructor por defecto.
  */
FechaHistorica();


/**
  * @brief Constructor de copia
  * 
  * @param fh un objeto de FechaHistorica
  * @param f.Fecha fecha del objeto FechaHistorica a construir
  * @param f.num_acon numeros de acontecimientos del objeto FechaHistorica a construir
  * @param f.acontecimientos[] conjunto de acontecimientos del objeto FechaHistorica a construir
  */
FechaHistorica(const FechaHistorica &f);


/**
  * @brief Sobrecarga del operador =
  * 
  * @param fh un objeto de FechaHistorica
  *
  * @return Devuelve el propio objeto con los valores del objeto f
  */
FechaHistorica& operator=(const FechaHistorica &f);


/**
  * @brief Sobrecarga del operador <
  *
  * @param f un objeto de FechaHistorica
  *
  * @return devuelve 1 si este objeto es mayor a f y 0 si es menor
  */
bool operator<(const FechaHistorica &f);

/**
  * @brief asignación de una fecha para el objeto
  *
  * @param fecha, fecha de los acontecimientos a asignar
  *
  */
void setFecha(int fecha);

/**
  * @brief inserción de un acontecimiento histórico en el array acontecimientos
  *
  * @param acon, acontecimiento que se asignará en una nueva posición del array
  *
  * @return vector acontecimientos redimensionado con una nueva posición y con el parametro acon insertado en el
  */
void insertAcontecimiento(string acon);

/**
  * @brief Numero de acontecimientos
  * @return devuelve el numero de acontecimientos del objeto
  */
int getNumAcon() const;

/**
  * @brief Fecha
  * @return devuelve la Fecha historica en la que transcurren los acontecimientos
  */
int getFecha() const;

/**
  * @brief Acontecimiento
  * @param pos, posición del vector que se quiere consultar
  * @return devuelve un acontecimientomnbv  s del array acontecimientos
  */
string getAcontecimiento(int pos) const;

/**
  * @brief busca un acontecimiento especifico en el array
  *
  * @param s, palabra clave utilizada para buscar el acontecimiento
  * @param f, objeto utilizado para pasar el acontecimiento si es encontrado
  *
  * @return devuelve 0 si se encuentra la palabra clave y 1 si no
  */
bool buscarAcontecimiento(string s, FechaHistorica &f);

/**
  * @brief Destructor de la clase FechaHistorica
  */
~FechaHistorica();

};

/**
  * @brief Sobrecarga del operador <<
  *
  * @param os stream de salida
  * @param f, objeto FechaHistorica a escribir
  *
  */


ostream& operator<<(std::ostream &os, const FechaHistorica &f);

/**
  * @brief Sobrecarga del operador >>
  *
  * @param is stream de entrada
  * @param f objeto FechaHistorica que recibe el valor
  * 
  * @retval la FechaHistorica leida en f
  *
  */
istream& operator>>(std::istream &is, FechaHistorica &f);

/**
  * @brief Sobrecarga del operador <<
  *
  * @param f1 FechaHistorica a sumar
  * @param f2 FechaHistorica a sumar
  *
  * @pre los dos objetos deben de tener la misma fecha
  *
  * @return devuelve un objeto nuevo con los acontecimiento de los otros dos objetos
  *
  */

FechaHistorica operator+(const FechaHistorica &f1, const FechaHistorica &f2);





#endif
