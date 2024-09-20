/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * JSS - 2009
 *    cal afegir-hi els metodes a implementar
* JSS - 2022
 *    es obligatori implementar el destructor
 */

#include "estructuraDinamica.h"
#include <iostream>


estructuraDinamica::estructuraDinamica( )
{
// aquest constructor es dona fet i no es pot canviar
	final = NULL;
}

estructuraDinamica::~estructuraDinamica(){ //Destructor
    allibera(); // crida a mètode privat
}



void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
    node *p;

    if (final != NULL)
    {
        p = final->seguent;
        while (p != final)
        {
            cout << p->dada << " ";
            p = p->seguent;
        }
        cout << final->dada;
    }
    cout << endl;
}


void estructuraDinamica::InserirOrdenadament(int n){
//Inserir ordenadament no verifica si l'ordenació és correcta en invocar-lo: pressuposa que l'estructura ja està ordenada
//Cal inserirlo a la posicio que toca, es a dir el 2 per davant del 1, el 3 per davant del 2 etc etc.


}



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
