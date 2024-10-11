// Robert López Contreras
// u1990700
// Exercici 01

#ifndef DISTRICTE_H
#define DISTRICTE_H

#include <string>
#include <list>
#include "Persona.h"

using namespace std;

class Districte
{
    public:

        //Constructor per defecte que inicialitza tot sense cap inforamcio extra
        Districte() {};

        void afegir(int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
        //Pre: tots els valors pasats per parametre han de ser els corresponents
        //Post: afegir un habitant(Persona) a les estructures de dades amb les caraceteristiques indicades pels parametres.

        long obtenirNumHabitants() const;
        //Pre: Cert
        //Post: retorna el numero d'habitants

        double obtenirEdatMitjana() const;
        //Pre: cert
        //Post: retornar l'edat mitjana de les persones

        void resumEstudis() const;
        //Pre: cert
        //Post: retorna un llistat amb el resum dels estudis

        list<Nacionalitat> resumNacionalitats() const;
        //Pre: Cert
        //Post: Retornem una llista de nacions, sense ordenar

        long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;
        //Pre: cert
        //Post: retorna el nombre de persones que cumpleixin l'any de naixment i el codi


    private:
        list<Persona> _lista; //Llista on es guardaran totes les persones que es vagin afegin

        //Lista nacionalitats per districte
        list<Nacionalitat> _llistaNacions;

        double _numPersones = 0;
        int _any = 0;
        //int _numDistricte;

        //Fer un metode privat per a obtenir el any actual

};

#endif // DISTRICTE_H
