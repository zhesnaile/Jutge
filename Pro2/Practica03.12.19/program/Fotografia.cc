/** @file Fotografia.cc
    @brief Implementación de la clase Foto
*/

#include "Fotografia.hh"

//Constructoras

Foto::Foto()
{
    Eti.clear();
}

Foto::Foto(const string& Id, const Fecha& f)
{
    Identificador=Id;
    dma=f;
    Eti.clear();
}

//Modificadoras

void Foto::crea_foto(const string& Id, const Fecha& f)
{
    Identificador=Id;
    dma=f;
    Eti.clear();
}

void Foto::agrega_etiqueta(const string& t)
{
    Eti.insert(t);
}

void Foto::elimina_etiqueta(const string& t)
{
    if (Eti.find(t)!=Eti.end()) Eti.erase(t);
}

//Consultoras

bool Foto::contiene_etiqueta(const string& t)
{
    return (Eti.find(t)!=Eti.end());
}

string Foto::id_foto() const
{
    return Identificador;
}

Fecha Foto::fecha_toma() const
{
    return dma;
}

int Foto::nr_etiquetas() const
{
    return Eti.size();
}

//Lectura

void Foto::lee_foto(istream& is)
{
    is>>Identificador;
    cin>>dma;
    int x;
    is>>x;
    Eti.clear();
    string t;
    while (x>0){    
        is>>t;
        agrega_etiqueta(t);
        --x;
    }
    is.clear();
}

//Escritura

void Foto::imprime_foto(ostream& os) const
{
    os << id_foto() << ' ';
    os<<fecha_toma();
    os << ' ' << nr_etiquetas();
    set<string>::iterator it=Eti.begin();
    while (it!=Eti.end())
    {
        os << ' ' << *it;
        ++it;
    }
    os << endl;
}

istream& operator>>(istream& is, Foto& f)
{
    f.lee_foto(is);
    return is;
}
    
ostream& operator<<(ostream& os, const Foto& f)
{
    f.imprime_foto(os);
    return os;
}
