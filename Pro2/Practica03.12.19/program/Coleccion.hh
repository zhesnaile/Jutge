/** @file Coleccion.hh
    @brief Especificación de la clase Coleccion
*/

#ifndef _COLECCION_HH_
#define _COLECCION_HH_

#include "Fotografia.hh"
#include "Album.hh"
#include "Fecha.hh"
//#include "ConsBooleana.hh"
/** @class Coleccion
    @brief Representa un conjunto de fotos
*/

class Coleccion
{
public:
    //Constructoras

    /** @brief Creadora por Defecto.
        \pre <em>cierto</em>
        \post El resultado es una colección vacía.
    */
    Coleccion();

    //Modificadoras
    
    /** @brief Añade un álbum a la colección.
        \pre Identificador del álbum != Id. de <em>ALL<!em>.
        \post Si no hay ningún album de mismo identificador que "alb" en el p.i., "alb" pasa a formar parte del p.i. y se sincronizan las fotos en el p.i.
    */
    void agrega_album(Album& alb);
    
    /** @brief Añade una foto a la colección.
        \pre <em>cierto</em>
        \post Si la foto no forma parte del p.i. esta es añadida al p.i. (pero fuera de todo álbum del p.i.)
    */
    void agrega_foto(const Foto& ph);
    
    /** @brief Elimina un álbum de la colección.
        \pre <em>cierto</em>
        \post Elimina un álbum de identificador "idf" del p.i. si dicho album existe. Las fotos de dicho álbum siguen formando parte del p.i. 
    */
    void elimina_album(const string& idf);
        
    /** @brief Elimina una foto de la colección.
        \pre <em>cierto</em>
        \post El p.i. pasa a contener sus datos originales salvo la foto de identificador "idf" (esto incluye eliminarla de todos los álbumes en los que esté presente).
    */
    void elimina_foto(const string& idf);
    
    /** @brief Reemplaza una foto de la colección
        \pre "ph" tiene "idf" como identificador
        \post Si el p.i. contiene una foto de identificador "idf", dicha foto es remplazada por "ph" (el cambio se realiza a través de todos los álbumes del p.i.)  
    */
    void modifica_foto(const string& idf, const Foto& ph);
    
    void album_to_stringset(set<string>& s, Album& alb) const;
    
    //Consultoras
    
    void stringset_to_album(const set<string>& s, Album& alb) const;
    
    /** @brief Retorna si un álbum concreto pertenece a la colección.  
        \pre <em>cierto</em>
        \post El resultado indica si el p.i. contiene un álbum de identificador "idf"
    */
    bool contiene_album(const string& idf) const;
    
    /** @brief Retorna si una foto pertenece a la colección
        \pre <em> cierto<em>
        \post Devuelve cierto si el p.i. contiene una foto de identificador "idf"
    */
    bool contiene_foto(const string& idf) const;
    
    /** @brief Retorna una copia de un álbum de la colección
        \pre <em>cierto</em>
        \post Devuelve una copia de un álbum de identificador "idf" si este forma parte del p.i. devuelve "alb"=0 en caso contrario.
    */
    Album obten_album(const string& idf, bool& alb) const;
    
    /** @brief Devuelve el número de álbumes de la colección. (Incluye ALL)
        \pre <em>cierto</em>
        \post El resultado es el número de álbumes incluidos en el p.i.
    */
    int nr_albumes() const;
    
    /** @brief Devuelve el número de álbumes de la colección (excluido ALL) a los que pertence una foto.
        \pre <em>cierto</em>
        \post El resultado es el numero de álbumes del p.i. que contienen una foto de identificador "idf" 
    */
    int nr_albumes_foto(const string& idf) const;
    
    /** @brief Crea un álbum a que contiene las fotos realizadas entre dos fechas especificas de un álbum concreto en la colección (el albúm de búsqueda puede ser ALL).
        \pre El p.i. contiene un álbum con identificador "idf".
        \post El resultado es un álbum de identificador "idres" que contiene las fotos del álbum "idf" que tienen una fecha que pertenezca a ["fmin";"fmax"].
    */
    Album busca_por_fecha(const Fecha& fmin, const Fecha& fmax,const string& idf, const string& idres);
    
    /** @brief Crea un álbum a que contiene las fotos con una etiqueta especifica de un álbum concreto en la colección (el albúm de búsqueda puede ser ALL).
        \pre El p.i. contiene un álbum con identificador "idf".
        \post El resultado es un álbum de identificador "idres" que contiene las fotos del álbum "idf" que tienen la etiqueta t. 
    */
    Album busca_por_etiqueta(const string& t, const string& idf, const string& idres);
    
    //Escritura
    
    /** @brief Escribe la lista de los identificadores de los álbumes de la colección (incluído ALL), en orden lexicográfico ascendente.
        \pre El p.i. no está vacío.
        \post Escribe los identificadores de los álbumes del p.i. en orden lexicográfico ascendente.
    */
    void lista_albumes();

    /** @brief Escribe la lista de los identificadores de los álbumes de la colección (excluído ALL) que contienen una foto concreta, en orden lexicográfico ascendente.
        \pre El p.i. no está vacío.
        \post Escribe los identificadores de los álbumes del p.i. que contienen una foto de identificador "idf" (en orden lexicográfico ascendente).
    */
    void lista_albumes_foto(const string& idf) const;

    /** @brief Escribe el contenido de todos los álbumes de la colección (<b>ALL</b> incluido)
        \pre <em>cierto<em>
        \post Escribe el contenido de todoes los álbumes del p.i.
    */
    void imprime_coleccion(ostream& os) const;
private:
    map<string, set<string> > ColAF;
    Album Todas;
    //private temporal, susceptible a canvis
};

ostream& operator<<(ostream& os, const Coleccion& col);
#endif
