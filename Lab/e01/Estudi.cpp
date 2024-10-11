// Robert López Contreras
// u1990700
// Exercici 01



#include "Estudi.h"

Estudi::Estudi(int id, string nom)
{
    _id = id;
    _nom = nom;
}

int Estudi::obtenirId() const{
    return _id;
}

string Estudi::obtenirNom() const {
    return _nom;
}


bool Estudi::operator== (const Estudi &e1) const{
    return(obtenirId() == e1.obtenirId());
}

bool Estudi::operator< (const Estudi &e1) const{
    return obtenirNom() < e1.obtenirNom();
}


