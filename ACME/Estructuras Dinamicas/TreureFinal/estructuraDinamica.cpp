/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Didac Barragan & Joan Surrell.
 *  Copyright (c) 2004-2021 IMAE-UdG.
 *
 */

#include <iostream>

#include "estructuraDinamica.h"

using namespace std;


estructuraDinamica::estructuraDinamica()
{
// aquest constructor es dona fet i no es pot canviar
	inici = final = NULL;
}


estructuraDinamica::~estructuraDinamica(){ //Destructor

    allibera(); // crida a mètode privat
}


void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
	node * p = inici;
	while (p != final) {
		cout << p->dada << " ";
		p = p-> seguent;
	}
	if (p != NULL)
		cout << p->dada << endl;
	else
		cout << endl;
}

//Si es vol inserir al inici només cal inserir un node després de referència
void estructuraDinamica::AfegirInici(int n)
{
    //Pre: cert
    //post: posa n com a primer element de l'estructura

    node *p = new node;//Creem un node

    p->dada = n; //El node guardara on esta la nostra dada n

    if(inici == NULL){ //cas particular
        p->seguent = NULL; //Apuntem al final
        inici = p; //Inici apunta al primer node
        final = p; //Final apunta al ultim node
    } else {
        p->seguent = inici;
        inici = p;
    }

}
int estructuraDinamica::TreureFinal(){
    //Pre: cert
    //post: retorna el ultim element de la llista i esborra el seu valor

    //Eliminem el ultim node i retornem el seu valor

    int n=0;
    node *p = inici;
    node *q = final;

    if(inici == NULL){
        return 0;
    }

    if(inici == final){
        n = q->dada;//Guardem la dada per retornar
        final = NULL;
        inici = NULL;
        delete q;
    } else {

        while(p->seguent != q){
           p = p->seguent;
        }
        n = q->dada;
        final = p;//p apunta al nou final
        p->seguent = NULL;
        delete q;
    }
    return n;
}





void estructuraDinamica::allibera(){

    node *p = inici;
    while (p != inici) { //Eliminar fins arribar al inici
        node *aux = p;
        p = p->seguent;
        delete aux;

    }
    inici = NULL; //Com que hem eliminat fins arribar al inici el deixem com a null
    final = NULL;

}
