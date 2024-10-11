#include "ArbreBinari.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;
ArbreBinari::ArbreBinari() { }

ArbreBinari::ArbreBinari(const char t[]){

    //Ens pasen un array de lletres per omplir un arbre binari

    int i = 0;
    arrel = iArbreBinari(t,i);

}


ArbreBinari ArbreBinari::FillDret() const {

    ArbreBinari res;
    if (esBuit())
        throw("L'arbre es buit");
    else
        res.arrel = arrel->fd;
    return res;

}



ArbreBinari ArbreBinari::FillEsquerre() const {

    ArbreBinari res;
    if (esBuit())
        throw("L'arbre es buit");
    else
        res.arrel = arrel->fe;
    return res;

}

bool ArbreBinari::esBuit() const {
    return (arrel == NULL);
}

char ArbreBinari::Contingut() const {

    char res;
    if(esBuit())
        throw("L'arbre es buit");
    else
        res = arrel->dada;

    return res;
}


shared_ptr<ArbreBinari::node> ArbreBinari::iArbreBinari(const char t[], int &i){

    //Cal avançar per el array per anar emplenan el arbre, primer esquerra despres dret

    if (t[i] == '\0') //si arribem al final del array
        return nullptr;

    //Crear un nou node amb el valor actual
    shared_ptr<node> n = make_shared<node>();

    shared_ptr<node> aux1, aux2;

    if(t[i] != '('){
            aux1 = aux2 = NULL;
    } else {
        i++;
        aux1 = iArbreBinari(t,i); //fill esquerra

    }

    //shared_ptr<node> n;
    n->dada = t[i];
    cout<<"Valor"<<n->dada<<endl;

    i++;
    n->fe = iArbreBinari(t,i); //Fill esquerra
    i++;
    n->fd = iArbreBinari(t,i); //fill dret

    return n;

}
