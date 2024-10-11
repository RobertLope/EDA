// Robert López Contreras
// u1990700
// Exercici 01



#include "Nacionalitat.h"

Nacionalitat::Nacionalitat(int id, string nom)
{
    _id = id;
    _nom = nom;
}

int Nacionalitat::obtenirId() const{
    return _id;
}

string Nacionalitat::obtenirNom() const {
    return _nom;
}


bool Nacionalitat::operator== (const Nacionalitat &n1) const{
    return(obtenirId() == n1.obtenirId());
}

bool Nacionalitat::operator< (const Nacionalitat &n1) const{
    return obtenirNom() < n1.obtenirNom();
}
