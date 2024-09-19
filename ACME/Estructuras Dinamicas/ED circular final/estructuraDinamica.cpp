/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell on Wed Oct 06 2004.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 *
 * JSS - 2022
 *    es obligatori implementar el destructor
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;


estructuraDinamica::estructuraDinamica( )
{
// aquest constructor es dona fet i no es pot canviar
	final = NULL;
}



void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
    node *p;

    if (final != NULL)
    {
        p = final->seguent;
        while (p != final)
            p = p->seguent;
    }
    cout << endl;
}

estructuraDinamica::~estructuraDinamica(){ //Destructor
    allibera(); // crida a mètode privat
}


//CAL MODIFICAR AQUEST METODE PER A QUE TINGUI UN PUNTER AL FINAL NO AL INICI
void estructuraDinamica::AfegirInici(int n)
{
    //Pre: cert
    //post: posa x com a primer element de l'estructura

    node *p = new node;//Creem un node

    p->dada = n; //El node guardara on esta la nostra dada n

    if(final == NULL){ //cas particular AQUESTA PART ES POT REUTILITZAR
        p->seguent = p; //El primer node apunta a si mateix
        final = p;
    } else { //CAL MODIFICAR EL ELSE PRINCIPALMENT
        node *q = final; //El ultim node
        //q = q->seguent;
        /*
        while(q->seguent != inici){
            q = q->seguent;
        }
        */

        //CADENA CIRCULAR FINAL
        p->seguent = q->seguent; //El node seguent (del nou node) apuntara cap a inici
        q->seguent = p; // L'ultim node apunta al nou inici

        //Potser es pot llurar de memoria p i q
    }

}
//FUNCIO FETA
bool estructuraDinamica::Existeix(int x) const {
// pre: cert
// post: retorna cert si x és un element de l’estructura.
    node *p = final;
    bool trobat = false;


    if(x == p->dada){ //Comprobem si la dada que busquem es al final
        trobat = true;
    }

    p = final->seguent; //Apuntem cap al inici de la nostra estructura


    while (p != final and not trobat)
    {
        if (x == p->dada)
            trobat = true;
        else
            p = p->seguent;
    }
    return(trobat);
}



/*
//Si es vol incerir al final cal fer el mateix i fer avançar el punter una posició
void estructuraDinamica::AfegirFinal(int n)
{
    //pre: cert
    //post: posa n com a darrer element de l'estructura

    node *p = new node;
    p->dada = n;
    //p->seguent = inici; //Fem que el nou node apunti a inici perque es circular
    //p->seguent = NULL; //D'aquesta manera es una estructura normal

    if(inici == NULL) //primer node
    {
        p->seguent = p; // El primer node apunta a si mateix
        inici = p;
    }
    else {
        node *q = inici; //Guardem el inici del node
        while(q->seguent != inici){ // (quasi)MAI hauria de ser aixi
            q = q->seguent;
        }
        p->seguent = inici; //El nou node (que es troba al final) apunta al inici
        q->seguent = p; //L'últim node apunta al nou node
    }
}
*/
void estructuraDinamica::allibera(){
    //PENDENT DE ALLIBERAR MEMORIA

    node *p = final;
    while (p != final) { //Eliminar fins arribar al inici
        node *aux = p;
        p = p->seguent;
        delete aux;
    }
    final = NULL; //Com que hem eliminat fins arribar al inici el deixem com a null

}
