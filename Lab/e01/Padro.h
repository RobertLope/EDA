// Robert López Contreras
// u1990700
// Exercici 01



#ifndef PADRO_H
#define PADRO_H

#include <string>
#include <vector>
#include <list>


#include "Districte.h"
#include "Estudi.h"

class Padro
{
    public:

        //Contructor per defecte de Padro
        Padro();

        int afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
        //Pre: Cert
        //Post: retornar 1 si s'ha pogut afegir l'habitant o 0 si no s'ha pogut fer


        void obtenirNumHabitantsPerDistricte() const;
        //Pre: Cert
        //Post: Mostrar per pantalla una llistat del nombre d'habitants que hi ha per districte

        void resumEdat() const; //De manera temporal ho deixem amb un void pero pot cambiar
        //Pre: Cert
        //Post: Retorna un llistat del nombre d'habitants per districte

        list<Estudi> resumEstudis() const;
        //Pre: Cert
        //Post: Retorna un llistat dels estudis de Padro

        void edatNacioPerDistricte(int edat, int codiNacionalitat) const; //De manera temporal ho deixem amb un void pero pot cambiar
        //Pre: Una edat i un codiNacionalitat
        //Post: Retornar el nom de cada districte i el corresponent nombre d'habitants amb un edat i pais d'origen amb codi "codiNacionalitat"

        void diferentsNacionalitats(int districte1, int districte2) const; //De manera temporal ho deixem amb un void pero pot cambiars
        //Pre: Dos codis de districte
        //Post: Retorna els paisos d'origen dels habitants que no existeixen al districte1 i districte2

    private:

        vector<Districte> _d;//Utilitzem vector perque els districtes estan numerats, será més facil fer una cerca directa
        list<Estudi> _eLlista; //NO ES POT FER SERVIR necesito un operador < per fer servir el metode sort
        int _estudis=0; //El nombre d'estudis que tenim

        //int _nDistrictes=0; //El nombre de districtes que hi ha

        string _list_districtes[6] = {"Carme, Vila-roja","Eixample, Montilivi","Santa Eugenia, Mas Xirgu","Casc Antic","Montjuic, Pont major","Sant Ponc, Domeny, Taiala"};

        int _any=0;


};

#endif //PADRO_H
