/** @file Coleccion.cc
    @brief Implementación de la clase Coleccion
*/

#include "Coleccion.hh"

Coleccion::Coleccion()
{
    Todas=Album("ALL");
    set<string> s;
    ColAF.insert(pair<string, set<string>> ("ALL", s));
}
//Modificadoras

void Coleccion::agrega_album(Album& alb)
{
    if (not contiene_album(alb.identif_alb()))
    {
        Todas.combina_album(alb);
        set<string> s;
        pair<string, set<string>> pareja (alb.identif_alb(), s) ;
        pareja.first=alb.identif_alb();
        album_to_stringset(pareja.second, alb);
        ColAF.insert(pareja);
    }
}

void Coleccion::agrega_foto(const Foto& ph)
{
    Todas.agrega_foto(ph);
}

void Coleccion::elimina_album(const string& idf)
{
    ColAF.erase(idf);
}

void Coleccion::elimina_foto(const string& idf)
{
    Todas.elimina_foto(idf);
    map<string, set<string>>::iterator it=ColAF.begin();
    while (it != ColAF.end())
    {
        pair<string, set<string>> s1=*it;
        set<string>::iterator itset;
        itset=(s1.second).find(idf);
        if (itset!=(s1.second).end())
        {
            (s1.second).erase(itset);
            ColAF.erase(it);
            ColAF.insert(s1);
            it=ColAF.find(s1.first);
        }
        ++it;
    }
}

void Coleccion::modifica_foto(const string& idf, const Foto& ph)
{
    if(this->contiene_foto(idf))
    {
        Todas.elimina_foto(idf);
        Todas.agrega_foto(ph);
    }
}

void Coleccion::album_to_stringset(set<string>& s, Album& alb) const
{
    int x=alb.nr_fotos();
    s.clear();
    for (int i=0; i<x; ++i)
    {
        if (i==0) s.insert(alb.primer_id());
        else s.insert(alb.siguiente_id());
    }
}

//Consultoras

bool Coleccion::contiene_album(const string& idf) const
{
    return( ColAF.find(idf) != ColAF.end() );
}
bool Coleccion::contiene_foto(const string& idf) const
{
    return Todas.contiene_foto(idf);
}

void Coleccion::stringset_to_album(const set<string>& s, Album& alb) const
{
    set<string>::const_iterator it_set=s.begin();
    while (it_set!=s.end()){
        Foto ph;
        bool a;
        ph=Todas.obten_foto(*it_set, a);
        if (a==true) alb.agrega_foto(ph);
        ++it_set;
    }
}

Album Coleccion::obten_album(const string& idf, bool& alb) const
{
    Album a (idf);
    map<string, set<string>>::const_iterator it= ColAF.find(idf);
    alb=(it!= ColAF.end());
    if (alb==true) stringset_to_album(it->second, a);
    return a;
}

int Coleccion::nr_albumes() const
{
    return ColAF.size();
}

int Coleccion::nr_albumes_foto(const string& idf) const
{
    map<string, set<string>>::const_iterator it = ColAF.begin();
    int contador=0;
    while(it!=ColAF.end())
    {
        if ((it->second).find(idf) != (it->second).end()) ++contador;
        ++it;
    }
    return contador;        
}

Album Coleccion::busca_por_fecha(const Fecha& fmin, const Fecha& fmax,const string& idf, const string& idres)
{
    Album alb (idres);
    map<string, set<string>>::const_iterator it = ColAF.find(idf);
    if (it!=ColAF.end())
    {
        if (it->first=="ALL")
        {
            int x=Todas.nr_fotos();
            for (int i=0; i<x; ++i)
            {
                Foto ph;
                if (i==0) ph=Todas.primera_foto();
                else ph=Todas.siguiente_foto();
                if ((fmin <= ph.fecha_toma()) and (ph.fecha_toma() <= fmax)) alb.agrega_foto(ph);
            }
        }
        else{
            set<string>::const_iterator it_set = it->second.begin();
            while(it_set!=it->second.end())
            {
                bool a;
                Foto ph;
                ph=Todas.obten_foto(*it_set, a);
                if ((fmin <= ph.fecha_toma()) and (ph.fecha_toma() <= fmax)) alb.agrega_foto(ph);
                ++it_set;
            }
        }
    }
    return alb;
}

Album Coleccion::busca_por_etiqueta(const string& t, const string& idf, const string& idres)
{
    Album alb (idres);
    map<string, set<string>>::const_iterator it = ColAF.find(idf);
    if (it!=ColAF.end())
    {
        if (it->first=="ALL")
        {
            int x=Todas.nr_fotos();
            for (int i=0; i<x; ++i)
            {
                Foto ph;
                if (i==0) ph=Todas.primera_foto();
                else ph=Todas.siguiente_foto();
                if (ph.contiene_etiqueta(t)) alb.agrega_foto(ph);
            }
        }
        set<string>::const_iterator it_set = (it->second).begin();
        while(it_set!=(it->second).end())
        {
            bool a;
            Foto ph;
            ph=Todas.obten_foto(*it_set, a);
            if (ph.contiene_etiqueta(t)) alb.agrega_foto(ph);
            ++it_set;
        }
    }
    return alb;
}

void Coleccion::lista_albumes()
{
    map<string, set<string>>::iterator it = ColAF.begin();
    while (it!=ColAF.end())
    {
        if (it!=ColAF.begin())  cout << ' ';
        cout << it->first;
        ++it;
    }
    cout << endl;
}

void Coleccion::lista_albumes_foto(const string& idf) const
{
    map<string, set<string>>::const_iterator it = ColAF.begin();
    while(it!=ColAF.end())
    {
        if ((it->first=="ALL") or ((it->second).find(idf) != (it->second).end())  )
        {
            if (it!=ColAF.begin()) cout << ' ';
            cout << it->first;
        }
        ++it;
    }
    cout << endl;
}

void Coleccion::imprime_coleccion(ostream& os) const
{
    map<string, set<string>>::const_iterator it = ColAF.begin();
    while (it!=ColAF.end())
    {
        if (it->first=="ALL") os<<Todas;
        else 
        {
            bool b;
            os<<(obten_album(it->first, b));
        }
    ++it;
    }
}

ostream& operator<<(ostream& os, const Coleccion& col)
{
    col.imprime_coleccion(os);
    return os;
}
