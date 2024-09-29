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

    node *p = new node;
    p->dada = n;

    bool inserit = false;

    if (final == NULL){
        p->seguent = p;
        final = p;
    } else {
        node *q = final;
        node *ant = q;
        q = q->seguent;
        //anterior es el primer valor de la cadena
        //q es el seguent de la cadena es com si fosim al inici


        //Si final es mes gran que n i q es mes petit que n
         if(ant->dada > n and q->dada < n){
            ant = q;
            q = q->seguent;
        }


        //if(ant->dada > n and q->dada < n){
            //ant = q;
            //q = q->seguent;
        //}


        /*if(ant->dada <= n){
            ant = q;
            p = q->seguent;
        }*/


        if(ant == q){
            if(ant->dada <= n){
                ant->seguent = p;
                p->seguent = ant;
                final = p;
            } else {
                p->seguent = q;
                q->seguent = p;
            }
            inserit = true;
        }
        // 3 4 2
        while(!inserit) { // q!= final && q->dada <= n ant->dada < n and q->dada > n)



            if(ant->dada <= n){ //Aixo va al davant de ant               ant->dada <= n
                if(final == ant){ // Hem de inserir al final de la cadena
                    //Aixo pot anar fora del if
                    p->seguent = ant->seguent;
                    ant->seguent = p;
                    final = p;
                    inserit = true;
                } else{
                    p->seguent = q; //Aixo pot anar fora del if
                    ant->seguent = p;
                    inserit = true;
                }

            } else if(ant->dada >= n and ant != final) { //el coloquem abans de ant
                p->seguent = ant;
                //final->seguent = p;
                inserit = true;
                if(final->seguent == ant){ //Si el anterior es el final hem de enllaçarlo amb p
                    final->seguent = p;
                }
            }
            ant = q;
            q = q->seguent;
        }
    }

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
