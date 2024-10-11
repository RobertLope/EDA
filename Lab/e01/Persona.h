// Robert López Contreras
// u1990700
// Exercici 01



#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "Estudi.h"
#include "Nacionalitat.h"

using namespace std;

class Persona
{
    public:
        // Constructor que rep els tres elements que defineixen una Persona, amb codi i nom en el cas de nacionalitat i estudis (cal guardar-ho tot en els atributs corresponents).
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);

        int obtenirAnyNaixement() const;
        //Pre: Cert
        //Post: Retornar el any de naixement de la persona

        string obtenirNivellEstudis() const;
        //Pre: Cert
        //Post: retorna el NivellEstudis en format string

        int obtenirCodiPaisNaixement() const;
        //Pre: Cert
        //Post: retorna el codi de pais de naixament

    private:

        int _codiNivellEstudis;
        string _nivellEstudis;
        int _anyNaixement;
        int _codiPaisNaixement;
        string _paisNaixement;
};

#endif // PERSONA_H
