// Robert López Contreras
// u1990700
// Exercici 01



#ifndef ESTUDI_H
#define ESTUDI_H

#include <string>

using namespace std;

class Estudi
{
    public:


        Estudi(int id, string nom);
        //Contructor que rep el codi i el nom que defineix el tipus d'Estudi

        int obtenirId() const;
        //Pre: Cert
        //Post: retorna el id del estudi

        string obtenirNom() const;
        //Pre: Cert
        //Post: retorna el nom del estudi

        // Sobrecarrega el operador d'iugaldat. Dos estudis són iguals si tenen el mateix codi.
        bool operator==(const Estudi &estudi) const;
        //Pre: Cert
        //Post: retorna si true si dos estudis son iguals

        //Sobrecarregar el operador d'igualtat < per a fer servir el sort. Un estudi es mes petit que un altre per el nom
        bool operator <(const Estudi &estudi) const;
        //Pre: Cert
        //Post: retorna true si el primer estudi es més petit que el que pasem per parametre, en cas contrari false

    private:

        int _id;
        string _nom;

};

#endif // ESTUDI_H
