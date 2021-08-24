/** @file ConsBooleana.hh
    @brief Especificación de la clase ConsBooleana
*/

#ifndef _CONSBOOL_HH_
#define _CONSBOOL_HH_

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

#include"Fecha.hh"
#include"Fotografia.hh"
#include"Album.hh"
#include"Coleccion.hh"

/** @class ConsBooleana
    @brief Representa una expresión que combina operadores lógicos y consultas básicas bajo forma de árbol binario.

    Operadores lógicos (<b>not</b>, <b>and</b>, <b>or</b>).

    Varios tipos de consultas (Por fecha: <b>DATE</b>, Por etiqueta: <b>TAG</b>, Booleanas: <b>BOOL</b>). 
*/

class ConsBooleana
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto.
        \pre <em>cierto<em>.
        \post El resultado es una Consulta Booleana vacía. 
     */
    ConsBooleana();
    
    /** @brief Creadora a partir de dos Consultas booleanas.
        \pre a y b no están vacías
        \post El resultado es una Consulta Booleana con a y b como subárboles. 
     */
    ConsBooleana(const string& operacion, const ConsBooleana& a, const ConsBooleana& b);

    //Modificadoras
    
    /** @brief  Crea una consulta booleana que será el "and" de otras dos.
        \pre El p.i. está vacío.
        \post El resultado es una consulta booleana de tipo "and" con subárbol izquierdo "a" y subárbol derecho "b".
    */
    void and_booleana(const ConsBooleana& a, const ConsBooleana& b);

    /** @brief  Crea una consulta booleana que será el "or" de otras dos.
        \pre El p.i. está vacío.
        \post El resultado es una consulta booleana de tipo "or" con subárbol izquierdo "a" y subárbol derecho "b".
    */
    void or_booleana(const ConsBooleana& a, const ConsBooleana& b);

    /** @brief  Crea una consulta booleana que será la negación de otra.
        \pre El p.i. está vacío.
        \post El resultado es una consulta booleana de tipo "not" con subárbol izquierdo "a".
    */
    void not_booleana(const ConsBooleana& a);
    
    //Consultoras

    /** @brief Retorna si l'expresió representada per la consulta booleana es certa per a una fotografia "f" 
        \pre <em>cierto</em>
        \post El resultado indica si la expresión representada por el p.i. es cierta para una fotografía "f"
    */
    bool check_inordre(const Foto& f);

    /** @brief Retorna un álbum con todas las fotos que satisfacen la expresión lógica
        \pre "colh" está inicializada y tiene un album de identificador "idf"
        \post El resultado es un álbum que contiene las fotos del álbum de identificador "idf" de la colección "colh" que satisfacen la expresión lógica representada en el p.i.
    */
    Album evalua_consulta(const string& idf, const Coleccion& colh);

    //Lectura

    /** @brief Crea una Consulta Booleana a partir de una serie de valores leídos por el cánal estándar. 
        \pre <em>cierto</em> 
        \post  El resultado es una ConsBooleana
    */
    void lee_consulta();
private:
    //Susceptible a cambios
};
#endif