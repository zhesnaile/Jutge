/** @file Fotografia.hh
    @brief Especificación de la clase Foto
*/

#ifndef _FOTO_HH_
#define _FOTO_HH_


#ifndef NO_DIAGRAM
#include <set>
#endif

#include "Fecha.hh"

/** @class Foto
    @brief Representa una imagen con atributos identificador, fecha y etiquetas.
*/

class Foto
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto
        \pre <em>cierto</em>
        \post Crea una foto vacía
    */
    Foto();

    /** @brief Creadora con valores concretos.
        \pre "f" sigue el formato {dd, mm, aaaa} y representa una fecha real.
        \post El resultado es una foto de identificador "Id" y fecha "f"
    */
    Foto(const string& Id, const Fecha& f);

    //Modificadoras

    /** @brief Crea una foto a partir de la string y fecha dadas
        \pre <em>cierto</em>
        \post El p.i. pasa a tener indentificador "idf" y fecha "f"
    */
    void crea_foto(const string& Id, const Fecha& f);

    /** @brief Añade una etiqueta a los atributos de la foto.
        \pre <em>cierto</em>
        \post El parámetro implícito pasa a contener sus etiquetas originales más t. 
    */
    void agrega_etiqueta(const string& t);
    
    /** @brief Elimina una etiqueta de los atributos de la foto.
        \pre t forma parte del p.i.
        \post  El parámetro implícito pasa a contener sus etiquetas originales menos t.
    */
    void elimina_etiqueta(const string& t);

    //Consultoras

    /** @brief Consultora de etiqueta.
        \pre <em>cierto</em>
        \post El resultado indica la presencia de la etiqueta en el p.i. 
    */
    bool contiene_etiqueta(const string& t);

    /** @brief Devuelve el identificador de la foto dada.
        \pre <em>cierto</em>
        \post El resultado es el identificador del p.i.
    */
    string id_foto() const;

    /** @brief Devuelve la fecha en la que se tomo la foto dada.
        \pre <em>cierto</em>
        \post El resultado es la fecha del p.i.
    */
    Fecha fecha_toma() const;

    /** @brief Devuelve el número de etiquetas asignadas a la foto dada.
        \pre <em>cierto</em>
        \post El resultado es el número de etiquetas del p.i.
    */
    int nr_etiquetas() const;

    //Lectura
    
    /** @brief Crea una fotografía a partir de valores leidos a traves del canal estándar (incluyendo etiquetas)
        \pre <em>cierto</em>
        \post Modifica el p.i. de una fotografía vacia. 
    */
    void lee_foto(istream& is);

    //Escritura de Foto

    /** @brief escribe toda la información de la foto.
        \pre <em>cierto</em>
        \post Escribe el contenido del parámetro implícito por el canal estándar de salida. (las etiquetas son escritas en orden lexicográfico ascendente)
    */
    void imprime_foto(ostream& os) const;
private:
    string Identificador;
    Fecha dma;
    set<string> Eti;
    //private temporal, susceptible a canvis
};

istream& operator>>(istream& is, Foto& f);
    
ostream& operator<<(ostream& os, const Foto& f);
    
#endif
