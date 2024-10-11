// Robert López Contreras
// u1990700
// Exercici 01




#include <iostream>
#include "Districte.h"
#include <list>
#include "Persona.h"
#include <string>
#include <ctime> //Per a poder obtenir el any actual



void Districte::afegir(int any,int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat)
{
    _any = any;

    Persona p(codiNivellEstudis,nivellEstudis,anyNaixement,codiNacionalitat,nomNacionalitat);
    _lista.push_back(p);// Afegim una persona a la ultima posicio si volguesim fer a la primera seria un l.push_front(p)
    _numPersones++;

    //Aprofitem a afegir una nova nacionalitat si es que hi ha

    bool noExisteix = true;

    //Creem un estudi que sera el que insertem si fos necesari
    Nacionalitat n(codiNacionalitat,nomNacionalitat);
    list<Nacionalitat>::iterator it = _llistaNacions.begin();

    //Busquem si existeix la Nacionalitat al districte
    while(it != _llistaNacions.end() && noExisteix == true ){
        if(*it == n){
            noExisteix = false;
        }
        it++;
   }

   if(noExisteix)
    _llistaNacions.push_back(n);  //Afegim la Nacionalitat a la llista si no existeix


}


long Districte::obtenirNumHabitants() const
{
    return _numPersones;
}

double Districte::obtenirEdatMitjana() const
{

    double edat_total = 0;
    int edat;
    //list<Persona> _l(l1.begin(), l1.end());

    list<Persona> l2(_lista.begin(), _lista.end());//Preparem la llista per buscar
    list<Persona>::iterator it = l2.begin();//Creem un iterador

    for(int i = 0; i< _numPersones; i++){ //Busquem entre totes les persones

       edat = _any-(*it).obtenirAnyNaixement(); //amb (*it).metode accedim al metode || una alternativa es fer servir it->obtenirAnyNaixement
       edat_total += edat;
       it++;
    }
    return edat_total/_numPersones;
}

void Districte::resumEstudis() const {

    //FALTA IMPLEMENTAR

}

list<Nacionalitat> Districte::resumNacionalitats() const{

    return _llistaNacions;
}

long Districte::comptaEdatNacionalitat(int anyNaixement, int codiNac) const{

    list<Persona> l2(_lista.begin(), _lista.end());//Preparem la llista per buscar
    list<Persona>::iterator it = l2.begin();//Creem un iterador

    long nHabitants = 0;
    int anycomp=0;
    int codicomp=0;


    while(it != l2.end()){
        if((*it).obtenirCodiPaisNaixement() == codiNac && (*it).obtenirAnyNaixement() == anyNaixement)
            nHabitants++;
        it++;
   }


    return nHabitants;

}



