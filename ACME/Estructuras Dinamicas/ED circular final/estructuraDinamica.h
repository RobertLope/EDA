/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura circular
 * simplement encadenada. Cal implementar *nomes* els metodes que demana cada
 * enunciat.
 */

#ifndef ESTRUCTURA_CIRCULAR_H
#define ESTRUCTURA_CIRCULAR_H

#include <cstdlib>
#include <iostream>
using namespace std;


struct node
{
    int dada;
    node * seguent;
};

class estructuraDinamica // circular
{
public:
    estructuraDinamica();
    estructuraDinamica(const estructuraDinamica &e);

    //DESTRUCTOR
    ~estructuraDinamica();
    // Pre: --; Post: memoria alliberada (inclosa la dinˆmica)

     // CONSULTORS -------------------------------------------------
    bool buida() const;
    // Pre: -- ; Post: retorna cert si la la llista es buida; fals en c.c.



    void AfegirInici(int i); //CAL IMPLEMENTAR AQUEST METODE
    void AfegirFinal(int i);
    void AfegirDespres(int i, int j);
    void AfegirAbans(int i, int j);
    void InserirOrdenadament(int i);

    bool Existeix(int i) const; //CAL IMPLEMENTAR AQUEST METODE
    int TreureFinal();
    void Esborrar(int i);

    void OmplirInici(int n);
    void OmplirFinal(int n);
    int nElements() const;

    void Llistar() const;
private:
    node *final; //Es comportara com un node al final
    void allibera();
    // Pre: --; Post: memoria dinamica alliberada
};

#endif
