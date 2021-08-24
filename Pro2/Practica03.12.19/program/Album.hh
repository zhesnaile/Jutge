/** @file Album.hh
    @brief Especificación de la clase Album
*/

#ifndef _ALBUM_HH_
#define _ALBUM_HH_

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "Fotografia.hh"

/** @class Album
    @brief Representa un conjunto de fotos
*/

class Album
{
public:
    //Constructoras

    /** @brief Creadora por defecto;
        \pre <em>cierto</em>
        \post El resultado es un álbum vacío
    */
    Album();

    /** @brief Creadora con valores concretos.
        \pre <em>cierto</em>
        \post El resultado es un álbum de identificador "Id"
    */
    Album(const string& Id);
    
    /** @brief Creadora por copia
        \pre "Al1" es un álbum con Identificador
        \post El resultado es un álbum con p.i. identicos a "Al1"
    */
    Album(const Album& Al1);

    //Modificadoras
    
    /** @brief Agrega una foto al álbum.
        \pre <em>cierto<em>
        \post: Retorna si la foto ha sido agregada al p.i. (falla si el identificador de la foto ya forma parte del p.i)
    */
    bool agrega_foto(const Foto& f1);

    void combina_album(Album& alb);
    
    /** @brief Elimina una foto al álbum
        \pre <em>cierto</em>
        \post El p.i. pasa a contener sus fotos originales menos una foto cuyo identificador es el mismo que el dado (si esta formaba parte de el)
    */
    void elimina_foto(const string& idf);
    
    /** @brief Vacía el diccionario de fotos del Album
        \pre <em>cierto</em>
        \post El p.i. pasa a estar vacío salvo por el Identificador
    */
    void clear_album();

    //Consultoras

    /** @brief Retorna si hay una foto en el album a partir de un idf dado
        \pre <em> cierto</em>
        \post Devuelvo Cierto si hay una foto de idenficador "idf" en el album.
    */
    bool contiene_foto(const string& idf) const;

    /** @brief Retorna una foto de identificador "idf" si está en el album
        \pre <em>cierto</em>
        \post Retorna una foto del p.i. a partir del identificador dado o devuelve una foto vacía
    */
    Foto obten_foto(const string& idf, bool& a) const;

    Foto primera_foto();
    
    Foto siguiente_foto();
    
    /** @brief Devuelve el número de fotos que contiene el álbum.
        \pre <em>cierto</em>
        \post Retorna el numero de fotos en el p.i.
    */
    int nr_fotos() const;
    
    /** @brief Devuelve el identificador del álbum
        \pre <em>cierto</em>
        \post Retorna el identificador del p.i.
    */
    string identif_alb() const;
    
    string primer_id();
    
    string siguiente_id();
    
    //Lectura
    
    /** @brief Crea un álbum a partir de valores concretos leidos por el canal estandar
        \pre Todo Int leido en el canal de entrada debe ser positivo o nulo.
        \post El resultado es un álbum 
    */
    void lee_album(istream& is);
    
    //Escritura

    /** @brief Escribe el identificador y los contenidos del álbum.  
        \pre <em>cierto</em>
        \post Escribe el identificador del p.i seguido de la secuencia de fotos en orden ascendente de identificador.
    */
    void imprime_album(ostream& os) const;

private:
    string IdAlb;
    map<string, Foto> MapFotos;
    map<string, Foto>::const_iterator it_pri;
    //private temporal, susceptible a canvis
};
istream& operator>>(istream& is, Album& f);

ostream& operator<<(ostream& os, const Album& f);
#endif
