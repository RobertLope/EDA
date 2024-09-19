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

//TODO
void estructuraDinamica::OmplirFinal(int n)
{
    //Afegeix diversos valors en ordre creixent al final de l'estrcutura (sigui buida o no)
    //Els valors afegits van del 1 fins a n
    cout<<"Omplir final"<<endl;

}
//TODO
int estructuraDinamica::nElements() const
{
    //Mira quants elements hi ha a la estructura

    int elements = 0;
    node *p = final;

    if (final != NULL)
    {
        p = final->seguent;
        while (p != final)
        {
            elements++;
            p = p->seguent;
        }
    } else {
        return elements;
    }

    return elements;
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




