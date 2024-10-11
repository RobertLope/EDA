// Robert López Contreras
// u1990700
// Practica 01

#ifndef PADRO_H
#define PADRO_H

#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class Padro {
public:

    //Constructor per defecte
    Padro() {}

    int llegirDades(const string &path);
    //Pre:
    //Post:

    bool existeixAny(int any) const;
    //Pre:
    //Post: Retorna un bool indicant si tenim dades d'aquest any

    map<int, long> obtenirNumHabitantsPerAny() const;
    //Pre:
    //Post: Retorna un map indicant, per cada any, el nombre d’habitants.

    vector<long> obtenirNumHabitantsPerDistricte(int any) const;
    //Pre:
    //Post: Retorna un vector amb els habitants de cada districte l’any indicat.

    map<int, long> obtenirNumHabitantsPerSeccio(int any, int districte) const;
    //Pre:
    //Post: Retorna un map<int, long> amb els habitants de cada secci´o de l’any i districte indicats.

    //TODO ResumEstudis resumEstudis() const;
    //Pre:
    //Post: Retorna un ResumEstudis que contindr`a, per cada any, tots els nivells d’estudis (identificats pel seu nom).

    map<int,int> nombreEstudisDistricte(int districte) const;
    //Pre:
    //Post:

    //TODO ResumNivellEstudis resumNivellEstudis() const;
    //Pre:
    //Post: Retorna un map<int,int> que contindr`a, per cada any, el nombre d’estudis diferents dels habitants del districte indicat.

    //TODO ResumNacionalitats resumNacionalitats() const;
    //Pre:
    //Post: Retorna un ResumNacionalitats que contindr`a, per cada any, totes les nacionalitats

    map<int,string> movimentsComunitat(int codiNacionalitat) const;
    //Pre:
    //Post: Retorna un Resum que contindr`a, per cada any, el nom del disctricte que concentra m´es habitats d’una determinada nacionalitat.

    //TODO ResumEdats resumEdat() const;
    //Pre:
    //Post: Retorna un ResumEdat que contindr`a, per cada any, tots els districtes (identificats pel seu nom) i l’edat promig dels seus habitants. Els districtes s’ordenaran pel promig, en ordre ascendent.

    map<int, string> movimentVells() const;
    //Pre:
    //Post: Retorna un map<int,string> que contindr`a, per cada any, el nom del districte m´es envellit.

    pair<string,long> mesJoves(int anyInicial, int anyFinal) const;
    //Pre:
    //Post: Retorna un pair<string,long> amb el nom del districte i l’increment d’habitants “joves” (entre 20 i 30 anys, ambd´os inclosos) del districte on el nombre d’habitants “joves” ha augmentat m´es entre els anys inicial i final.

    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;
    //Pre:
    //Post: Retorna un list<string> amb els diferents estudis (nom) dels habitants de l’any, districte, edat i codiNacionalitat indicats.


private:




};

#endif //PADRO_H
