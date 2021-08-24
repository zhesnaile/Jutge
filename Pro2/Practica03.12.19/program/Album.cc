/** @file Album.cc
    @brief Implementación de la clase Album
*/

#include "Album.hh"

//Constructoras

Album::Album(){}

Album::Album(const string& Id)
{
    IdAlb=Id;
}

Album::Album(const Album& Al1)
{
    IdAlb=Al1.IdAlb;
    MapFotos=Al1.MapFotos;
}

//Modificadoras

bool Album::agrega_foto(const Foto&f1)
{
    string Idfoto = f1.id_foto();
    if (contiene_foto(Idfoto) == 1) return 0;
    else {
        MapFotos.insert(pair<string, Foto> (Idfoto, f1));
        return 1;
    }
}

void Album::combina_album(Album& alb)
{
    map<string, Foto>::iterator it1 = MapFotos.begin();
    map<string, Foto>::iterator it2 = (alb.MapFotos).begin();
    while (it2 != (alb.MapFotos).end())
    {
        it1=MapFotos.find(it2->first);
        if (it1!=MapFotos.end()) 
        {
            (alb.MapFotos).erase(it2);
            (alb.MapFotos).insert(*it1);
            it2=(alb.MapFotos).find((*it1).first);
        }
        else MapFotos.insert(*it2);
        ++it2;
    }
}
void Album::elimina_foto(const string& idf)
{
    map<string, Foto>::iterator it=MapFotos.find(idf);
    if (it!=MapFotos.end()) MapFotos.erase(it);
}

void Album::clear_album()
{
    MapFotos.clear();
}

//Consultoras

bool Album::contiene_foto(const string& idf) const
{
    return (MapFotos.find(idf) != MapFotos.end());
}

Foto Album::obten_foto(const string& idf, bool&a) const
{
    Foto ph;
    map<string, Foto>::const_iterator it=MapFotos.find(idf);
    if (it!=MapFotos.end())
    {
        a=1;
        ph=(*it).second;
    }
    else a=0;
    return ph;
}

Foto Album::primera_foto()
{
    it_pri=MapFotos.begin();
    return it_pri->second;
}
    
Foto Album::siguiente_foto()
{
    ++it_pri;
    return it_pri->second;
}

int Album::nr_fotos() const
{
    return MapFotos.size();
}

string Album::identif_alb() const
{
    return IdAlb;
}

string Album::primer_id()
{
    it_pri=MapFotos.begin();
    return it_pri->first;
}

string Album::siguiente_id()
{
    ++it_pri;
    return it_pri->first;
}

//Lectura

void Album::lee_album(istream& is)
{
    MapFotos.clear();
    is>>IdAlb;
    int x;
    is>>x;
    while(x>0) 
    {
        Foto ph;
        is>>ph;
        agrega_foto(ph);
        --x;
    }
}

//Escritura

void Album::imprime_album(ostream& os) const{
    os << IdAlb << endl;
    map<string, Foto>::const_iterator it=MapFotos.begin();
    while (it!=MapFotos.end()){
        os << "  ";
        os << (it->second);
        ++it;
    }
}

istream& operator>>(istream& is, Album& f)
{
    f.lee_album(is);
    return is;
}

ostream& operator<<(ostream& os, const Album& f)
{
    f.imprime_album(os);
    return os;
}
