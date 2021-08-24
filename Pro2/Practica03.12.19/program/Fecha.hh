/** @file Fecha.hh
    @brief Especificación de la clase Fecha
*/

#ifndef _DATA_HH_
#define _DATA_HH_


#ifndef NO_DIAGRAM
//#include "PRO2Excepcio.hh"
#include <iostream>
#include <string>
#endif

using namespace std;

/** @class Fecha
    @brief Representa un conjunto de tres enteros.
    
    Dia>0 y Dia<=31

    Mes>0 y Mes <=12
    
    Any>=1700 y Any<2299
*/

class Fecha
{
public:
    //Constructoras
    
    /** @brief Constructora por defecto
        \pre <em>cierto</em>
        \post El resultado es una Fecha vacía
    */
    Fecha();

    //Consultoras
    
    /** @brief Comprueba si la fecha es inferior o igual a una fecha d;
        \pre El p.i. esta inicializado.
        \post Devuelve cierto si el p.i. es inferior o igual que "d", falso en caso contrario.
    */
    bool operator<=(const Fecha& d) const;
    
    /** @brief Comprueba si la fecha es inferior a una fecha d;
        \pre El p.i. esta inicializado.
        \post Devuelve cierto si el p.i. es inferior que "d", falso en caso contrario.
    */
    bool operator<(const Fecha& d) const;

    //Lectura
    
    /** @brief Modifica la fecha a partir de valores obtenidos por el canal estándar 
        \pre El p.i. está inicializado
        \post El contenido del p.i. es modificado con los valores leidos si estos son validos 
    */
    void lee_fecha(istream& is);
    
    //Escritura
    
    /** @brief Escribe la fecha por el canal estándar (orden: dia, mes, any) 
        \pre El p.i. no está vacío.
        \post Escribe el contenido del p.i. en el canal de salida estándar.
    */
    void escribe_fecha(ostream& os) const;
    
private:
    int dia;
    int mes;
    int any;
};

istream& operator>>(istream& is, Fecha& f);
    
ostream& operator<<(ostream& os, const Fecha& f);

#endif
