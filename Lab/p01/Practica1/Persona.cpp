// Robert López Contreras
// u1990700
// Exercici 01

#include "Persona.h"
#include <string>

Persona::Persona(int cNE, const string &Ne, int An, int cPN, const string &pN)
{
    _codiNivellEstudis = cNE;
    _nivellEstudis = Ne;
    _anyNaixement = An;
    _codiPaisNaixement = cPN;
    _paisNaixement = pN;
}


int Persona::obtenirAnyNaixement() const {
    return _anyNaixement;
}

string Persona::obtenirNivellEstudis() const {
    return _nivellEstudis;
}

int Persona::obtenirCodiPaisNaixement() const {
    return _codiPaisNaixement;
}
