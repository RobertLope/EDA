// Robert López Contreras
// u1990700
// Exercici 01



#ifndef NACIONALITAT_H
#define NACIONALITAT_H

#include <string>

using namespace std;

class Nacionalitat
{
    public:
        //Constructor que rep el codi i el nom que defineixen una Nacionalitat
        Nacionalitat(int id, string nom);

        int obtenirId() const;
        //Pre: Cert
        //Post: retorna el id del pais

        string obtenirNom() const;
        //Pre: Cert
        //Post: retorna el nom del pais

        bool operator==(const Nacionalitat &nacio) const;
        //Pre: Cert
        //Post: Sobrecarrega el operador de igualdat. Dos paisos son iguals si tenen el mateix codi.

        //IMPLEMENTACIO EXTRA, he implementat aquest operador per a poder fer servir el sort al llistar
        bool operator<(const Nacionalitat &nacio) const;
        //Pre: Cert
        //Post: Sobrecarregar el operador de es menor que. Un país es mes petit que un altre per el seu nom

    private:

        int _id;
        string _nom;

};

#endif // NACIONALITAT_H
