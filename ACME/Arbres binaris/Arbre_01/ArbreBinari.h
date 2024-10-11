#ifndef ARBREBINARI_H
#define ARBREBINARI_H

#include <memory>
#include <string>

using namespace std;

class ArbreBinari { // Arbre Binari
  public:
    ArbreBinari();


    ArbreBinari(const char t[]);

    //Pre:
    //Post retorna un arbre binari que es construeix un array pasat per parametre

    bool esBuit() const;
    //Pre:
    //Post: retorna cert si l'arbre es buit


    ArbreBinari FillDret() const;
    //Pre:
    //Post: retorna un ArbreBinari que es el fill dret

    ArbreBinari FillEsquerre() const;
    //Pre:
    //Post: retorna un ArbreBinari que es el fill esquerra


    char Contingut() const;
    //Pre:
    //Post: retorna el contingut del arbre binari


    // no té destructor.

  private:
    struct node {
        char dada;
        shared_ptr<node> fe, fd;
    };

    shared_ptr<node> arrel;

    shared_ptr<ArbreBinari::node> iArbreBinari(const char t[], int &i); // mètode auxiliar del constructor

};

#endif
