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
	inici = NULL;
}

estructuraDinamica::~estructuraDinamica(){ //Destructor
    allibera(); // crida a m�tode privat
}



void estructuraDinamica::Llistar() const {
    if (inici != NULL) {
        node * p = inici->seguent;
        cout << inici->dada << " ";
        while (p != inici) {
            cout << p->dada << " ";
            p = p->seguent;
        }
    }
    cout << endl;
}

//Si es vol inserir al inici nom�s cal inserir un node despr�s de refer�ncia
void estructuraDinamica::AfegirInici(int n)
{
    //Pre: cert
    //post: posa x com a primer element de l'estructura

    node *p = new node;//Creem un node

    p->dada = n; //El node guardara on esta la nostra dada n

    if(inici == NULL){ //cas particular
        p->seguent = p; //El primer node apunta a si mateix
        inici = p;
    } else {
        node *q = inici; //El node que apuntara cap a inici
        while(q->seguent != inici){
            q = q->seguent;
        }
        p->seguent = inici; //El node seguent (del nou node) apuntara cap a inici
        q->seguent = p; // L'ultim node apunta al nou inici
        inici = p; //Inici pasara a ser el valor de p (que es el nou node)

        //Potser es pot llurar de memoria p i q
    }

}





//Si es vol incerir al final cal fer el mateix i fer avan�ar el punter una posici�
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
        q->seguent = p; //L'�ltim node apunta al nou node
    }
}

void estructuraDinamica::allibera(){
    //PENDENT DE ALLIBERAR MEMORIA

    node *p = inici;
    while (p != inici) { //Eliminar fins arribar al inici
        node *aux = p;
        p = p->seguent;
        delete aux;
    }
    inici = NULL; //Com que hem eliminat fins arribar al inici el deixem com a null

}




