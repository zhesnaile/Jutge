/** @file Fecha.cc
    @brief Implementación de la clase Fecha
*/

#include "Fecha.hh"

//Constructoras
Fecha::Fecha(){}

//Consultoras
bool Fecha::operator<=(const Fecha& d) const
{
    if(any!= d.any) return any < d.any;
    else if (mes!= d.mes) return mes < d.mes;
    else return dia <= d.dia;
}

bool Fecha::operator<(const Fecha& d) const
{
    if(any!= d.any) return any < d.any;
    else if (mes!= d.mes) return mes < d.mes;
    else return dia < d.dia;
}

//Lectura
void Fecha::lee_fecha(istream& is)
{
    is>> dia >> mes >> any; 
}

//Escritura
void Fecha::escribe_fecha(ostream& os) const
{
    os << dia << '/' << mes << '/' << any; 
}

istream& operator>>(istream& is, Fecha& f)
{
    f.lee_fecha(is);
    return is;
}
    
ostream& operator<<(ostream& os, const Fecha& f)
{
    f.escribe_fecha(os);
    return os;
}
