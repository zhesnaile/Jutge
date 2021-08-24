/** @mainpage Practica Quadrimestre Tardor 2019
  
    El objetivo de la práctica es desarrollar un conjunto de módulos que serían componentes esenciales de un programa de gestión de fotografías y álbumes digitales
    
    Se introducen las clases <em>Fecha</em>, <em>Foto</em>, <em>Album</em>, <em>ConsBooleana</em> y <em>Coleccion</em>.

    En esta etapa sólo documentamos los elementos públicos de la especificación de las clases y el main del programa principal.
*/

#include "Fecha.hh"
#include "Fotografia.hh"
#include "Album.hh"
//#include "ConsBooleana.hh"
#include "Coleccion.hh"


/** @file program.cc
    @brief Programa principal de la práctica.

    El programa realiza una serie de operaciones a partir de una serie de "comandos" que leera a través del canal de entrada.

    Realiza una serie de modificaciones a un album y/o colección en curso.
*/

int main()
{
    string entrada;
    Coleccion colhelp;
    Album albhelp;
    while(cin>>entrada && entrada!="acabar")
    {
        /** @brief <b>lee_album</b>: Modifica el álbum en curso a partir de valores leídos por el canal de entrada
        */
        if(entrada=="lee_album")
        {
            cin>>albhelp;
            cout << "# " << entrada << ' ' << albhelp.identif_alb() << " ..." << endl;
            cout << "Album " << albhelp.identif_alb() << " leido." << endl;
        }
        
        /** @brief <b>agrega_foto</b>: Lee los datos de una foto y la agrega al álbum en curso
        */        
        else if(entrada=="agrega_foto")
        {
            Foto ph;
            cin>>ph;
            cout << "# " << entrada << ' ' <<  ph.id_foto() << " ..." << endl;
            if(albhelp.contiene_foto(ph.id_foto()))
            {
                cout << "El album en curso ya contiene una foto con el identificador " << ph.id_foto() << endl;
            }
            else 
            {
                albhelp.agrega_foto(ph);
                cout << "Foto " << ph.id_foto() << " agregada al album en curso." << endl;
            }
        }
        
        /** @brief <b>elimina_foto</b>: Lee un identificador de foto y la elimina del álbum en curso
        */
        else if(entrada=="elimina_foto")
        {
            string Id;
            cin>>Id;
            cout << "# " << entrada << ' ' <<  Id << endl;
            if (albhelp.contiene_foto(Id)) 
            {
                albhelp.elimina_foto(Id);
                cout << "Foto " << Id << " eliminada del album en curso." << endl;
            }
            else cout << "El album en curso no contiene una foto con el identificador " << Id <<  endl;
        }
        
        /** @brief <b>obten_foto</b>: Lee un identificador, lo busca en el álbum en curso y devuelve una foto si está  
        */
        else if(entrada=="obten_foto")
        {
            string id;
            bool a;
            cin>>id;
            cout << "# " << entrada << ' ' <<  id << endl;
            Foto ph;
            ph=albhelp.obten_foto(id, a);
            if (a==1) cout<<ph;
            else cout << "El album en curso no contiene una foto con el identificador " << id << endl;
        }
        
        /** @brief <b>nr_fotos</b>: Escribe el número de fotos en el album en curso
        */
        else if(entrada=="nr_fotos")
        {
            cout << "# " << entrada << endl;;
            cout << albhelp.nr_fotos() << endl;
        }
        
        /** @brief <b>agrega_album</b>: Agrega el álbum en curso a la coleccón siempre que no haya otro álbum de mismo id.
        */
        else if(entrada=="agrega_album")
        {
            cout << "# " << entrada << endl;;
            bool b=colhelp.contiene_album(albhelp.identif_alb());
            if (b) cout << "Identificador de album incorrecto. No se puede agregar." << endl;
            else {
                colhelp.agrega_album(albhelp);
                cout << "Album en curso agregado a la coleccion." << endl;
                cout << "Album en curso, despues de agregar:" << endl;
                cout << albhelp;
            }
        }
        
        /** @brief <b>elimina_album</b>: Lee un id. de álbum y lo elimina de la colección.
        */
        else if(entrada=="elimina_album")
        {
            string idf;
            cin>>idf;
            cout << "# " << entrada << ' ' <<  idf << endl;
            bool b = colhelp.contiene_album(idf);
            if (b)
            {
                colhelp.elimina_album(idf);
                cout << "Album eliminado de la coleccion." << endl;
            }
            else  cout << "Identificador de album incorrecto. No se puede eliminar." << endl;
        }
        
        /** @brief <b>obten_album</b>: Lee un identificador de álbum y si pertence a la colección, lo escribe y copia dicho álbum al álbum en curso.
        */
        else if(entrada=="obten_album")
        {
            string idf;
            bool a;
            cin>>idf;
            cout << "# " << entrada << ' ' <<  idf << endl;
            Album arb;
            arb = (colhelp.obten_album(idf, a));
            if (a==1)
            {
                cout<<arb;
                albhelp.clear_album();
                albhelp=arb;
            }
            else cout << "No existe un album con el id dado." << endl;
        }
        
        /** @brief <b>nr_albumes</b>: Escribe el numero de álbumes de la colección.
        */
        else if(entrada=="nr_albums")
        {
            cout << "# " << entrada << endl;;
            cout << colhelp.nr_albumes() << endl;
        }
        
        /** @brief <b>lista_albumes</b>: Escribe los id. de los álbumes de lacoleccion en orden lexicográfico ascendente.
        */
        else if(entrada=="lista_albumes")
        {
            cout << "# " << entrada << endl;;
            colhelp.lista_albumes();
        }
        
        /** @brief <b>agrega_foto_coleccion</b>: Lee la información de una fota y agrega dicha foto a la colección si no forma parte de ella.
        */
        else if(entrada=="agrega_foto_coleccion")
        {
            Foto ph;
            cin>>ph;
            cout << "# " << entrada << ' ' <<  ph.id_foto() << " ..." << endl;
            bool b = colhelp.contiene_foto(ph.id_foto());
            if (not b)
            {
                colhelp.agrega_foto(ph);
                cout << "Foto " << ph.id_foto() << " agregada a la coleccion." << endl;
            }
            else cout << "Ya existe una foto con el mismo id. No se puede agregar." << endl;
        }
        
        /** @brief <b>elimina_foto_coleccion</b>: Lee un id. de una foto y elimina la foto de la colección (en todos los álbumes y ALL)
        */
        else if(entrada=="elimina_foto_coleccion")
        {
            string id;
            cin>>id;
            cout << "# " << entrada << ' ' <<  id << endl;
            bool b = colhelp.contiene_foto(id);
            if (b)
            { 
                colhelp.elimina_foto(id);
                cout << "Foto " << id << " eliminada de la coleccion." << endl;
            }
            else cout << "No existe una foto con el id dado. No se puede eliminar." << endl;
        }
        
        /** @brief <b>modifica_foto coleccion</b>: Lee la informacion de una foto y remplaza todas las foto con su mismo id. en la colección por ella. 
        */
        else if(entrada=="modifica_foto_coleccion")
        {
            Foto ph;
            cin>>ph;
            cout << "# " << entrada << ' ' <<  ph.id_foto() << " ..." << endl;
            bool b = colhelp.contiene_foto(ph.id_foto());
            if (b)
            {
                colhelp.modifica_foto(ph.id_foto(), ph);
                cout << "Foto " << ph.id_foto() << " modificada en la coleccion." << endl;
            }
            else cout << "No existe una foto con el id dado. No se puede modificar." << endl;
        }
        
        /** @brief <b>albumes_foto</b>: lee un id. de foto y escribe los id. de los álbumes de la coleccón a los que pertenezca.
        */
        else if(entrada=="albumes_foto")
        {
            string idf;
            cin >> idf;
            cout << "# " << entrada << ' ' <<  idf << endl;
            if (colhelp.contiene_foto(idf))
                colhelp.lista_albumes_foto(idf);
            else cout << "No existe una foto con el id dado." << endl;
        }
        
        /** @brief <b>busca_por_fecha</b>: Lee dos fechas y dos identificadores. Escribe la información de un álbum que contiene las fotos del album de primer identificador que hayan sido tomadas entre las dos fechas leidas y copia ese álbum al álbum en curso.
        */
        else if(entrada=="busca_por_fecha")
        {
            Fecha min, max;
            cin>>min;
            cin>>max;
            string idf, idres;
            cin>>idf>>idres;
            cout << "# busca_por_fecha " << min << '-' << max << ' ' << idf << ' ' << idres << endl;
            if (colhelp.contiene_album(idf)){
                albhelp=colhelp.busca_por_fecha(min, max, idf, idres);
                cout<<albhelp;
            }
            else cout << "No existe un album con el id dado." << endl;
        }
        
        /** @brief <b>busca_por_etiqueta</b>: Lee una etiqueta, dos id. de album. Escribe la información de un álbum que contiene las fotos del album de primer identificador que contengan la etiqueta leída y copia ese álbum al álbum en curso.
        */
        else if(entrada=="busca_por_etiqueta")
        {
            string t, idf, idres;
            cin>>t>>idf>>idres;
            cout << "# busca_por_etiqueta " << t << ' ' << idf << ' ' << idres << endl;
            if (colhelp.contiene_album(idf)){
                albhelp=colhelp.busca_por_etiqueta(t, idf, idres);
                cout<<albhelp;
            }
            else cout << "No existe un album con el id dado." << endl;
        }
        
        /** @brief <b>evalua_consulta_booleana</b>: Lee dos identificadores, una expresión booleana, realiza una busqueda en el álbum del primer identificador y crea uno con el segundo identificador y con las fotos del primer álbum que satisfacen la expresión. Escribe el álbum resultado y lo copia al álbum en curso.
        */
        else if(entrada=="evalua_consulta_booleana")
        {
            //
        }
        
        /** @brief <b>imprime_album_en_curso</b>: Escribe el contenido del álbum en curso.
        */
        else if(entrada=="imprime_album_en_curso") 
        {
            cout << "# " << entrada << endl;;
            cout << albhelp;
        }
        
        /** @brief <b>imprime_coleccion</b>: Escribe el contenido de todos los álbumes de la colección (incluido ALL).
        */
        else if(entrada=="imprime_coleccion") 
        {
            cout << "# " << entrada << endl;;
            cout<<colhelp;
        }
    }
}