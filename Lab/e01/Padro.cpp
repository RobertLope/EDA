// Robert López Contreras
// u1990700
// Exercici 01



#include "Padro.h"
#include "Districte.h"
#include "Persona.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <list>

Padro::Padro()
{
    //ctor
}


int Padro::afegir(int any,int dis,int codiNivellE, const string &nivellEstudis, int anyN,int codiN,const string &nomN){

    //Sempre retorna 1 falta implementar si retorna 0
    bool noExisteix = true;

    for(int i = 1; i< _d.size(); i++){ //Busquem si existeix el Districte dins el vector
        if(i == dis) noExisteix = false;
    }

    if(noExisteix){
        //creem el vector a la posicio que li toca si NO EXISTEIX
        _d.push_back(Districte());
        //_nDistrictes++;
    }

    noExisteix = true;

    //Creem un estudi que sera el que insertem si fos necesari
    Estudi e(codiNivellE,nivellEstudis);
    list<Estudi>::iterator it = _eLlista.begin();

    //Busquem si existeix el estudi
    while(it != _eLlista.end()){
        if(*it == e){
            noExisteix = false;
        }
        it++;
   }


    if(noExisteix){
        //Afegim el estudi a la llista si no existeix
        _eLlista.push_back(e);
    }

    //_d.at(dis-1)
    _d[dis-1].afegir(any,codiNivellE,nivellEstudis,anyN,codiN,nomN);

    _any = any;
    return 1;

}

void Padro::obtenirNumHabitantsPerDistricte() const {

    long nHabitants = 0;
    long totalHabitants = 0;

    for(int i =0; i< _d.size()-1; i++){
        nHabitants = _d.at(i).obtenirNumHabitants();
        totalHabitants += nHabitants;
        cout<<"Districte "<< i+1 <<"   habitants:"<<setw(7)<<right<<nHabitants<<" "<<endl;
    }

    cout<<"TOTAL : "<<totalHabitants<<endl;
}

list<Estudi> Padro::resumEstudis() const {

    return _eLlista;

}

void Padro::resumEdat() const {
    //NOTA: Es probalbe que calgui retornar un llistat ordenat de les edats

    std::cout << std::fixed << std::setprecision(2);

    double edat_pr = 0;
    //PENDENT DE TABULAR I ORDENAR ELS DISTRICTES, PRIMER LA MITJANA MÉS PETITA DESPRÉS LA MES GRAN
    for(int i = 0; i<_d.size()-1; i++){

        edat_pr = _d.at(i).obtenirEdatMitjana();
        cout<<"\t"<<setw(31)<<left<< _list_districtes[i]<<" "<<"Promig Edat: "<<"\t"<<"   "<<edat_pr<<endl;
    }

}

void Padro::diferentsNacionalitats(int d1, int d2) const {


    if(d1< _d.size() && d2< _d.size() && d1>0 && d2>0){
        list<Nacionalitat> llista1 = _d.at(d1-1).resumNacionalitats();
        list<Nacionalitat> llista2 = _d.at(d2-1).resumNacionalitats();

        //Ordenem les dos llistes
        llista1.sort();
        llista2.sort();

        list<Nacionalitat>::iterator it = llista1.begin(), it2 = llista2.begin();

        //Fem un recorregut, si hi ha una nacionalitat igual a l'altra s'eliminaran de la llista,sino es continuara avançant

        it = llista1.begin();
        it2 = llista2.begin();

        while(it != llista1.end() && it2 != llista2.end()){
                if(*it == *it2){ //Si son igual els elminem
                    it = llista1.erase(it);//Fem servir el valor de retorn de erased per el seguent iterador
                    it2 = llista2.erase(it2);
                }
                ++it;
                ++it2;
        }
        //Mostrar les dues llistes del districte

        //Reiniciem els iteradors
        it = llista1.begin();
        it2 = llista2.begin();

        cout<<"Districte "<<d1<<":"<<endl;

        while(it != llista1.end()){
                cout<<" - "<<(*it).obtenirNom()<<endl;
                ++it;
        }
        cout<<"Districte "<<d2<<":"<<endl;

        while(it2 != llista2.end()){
            cout<<" - "<<(*it2).obtenirNom()<<endl;
            ++it2;
        }
    } else {
        cerr<<"El nombre del districte ha de ser superior a 0 e inferior als districtes que hi ha";

    }

}

void Padro::edatNacioPerDistricte(int edat, int codiNacionalitat) const {

    int nHabitants = 0;

    int any_nac = _any-edat;

    for(int i = 0; i< _d.size()-1; i++){
        nHabitants = _d.at(i).comptaEdatNacionalitat(any_nac,codiNacionalitat);
        if(nHabitants > 0)
            cout<<_list_districtes[i]<<": "<<nHabitants<<endl;
    }
}
