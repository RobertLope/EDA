#include "pilaDinamica.h"

pilaDinamica::pilaDinamica()
{
    //pre: cert
    //post: la pila es buida

    inici = NULL;
}

pilaDinamica::~pilaDinamica()
{
    // pre: cert
    // post: s'allibera la mem�ria ocupada per la pila

    allibera();
}


bool pilaDinamica::Buida() const{
    //pre: cert
    //post: retorna cert si la pila no t� elements

        return(inici == NULL);
}


void pilaDinamica::Empila(element e){
    //pre: cert
    //post: es posa el nou element al cim de la pila

    node * p = new node;

    p->dada = e;
    p->seguent = inici;
    inici = p;
}

void pilaDinamica::Desempila(){
    //pre: cert
    //post: es treu el cim de la pila

    if(Buida())
        throw("La pila es buida"); // excepcio
    else {
        node * p = inici;
        inici = inici->seguent;
        delete p;
    }
}

element pilaDinamica::Cim() const {
    //pre: cert
    //post: es retorna una c�pia del cim de la pila

    element res;

    if (Buida())
        throw("La pila es buida");
    else
        res = inici->dada;

    return (res);

}

void pilaDinamica::allibera(){
    //pre: cert
    //post: ha alliberat tota la mem�ria de la pila

    while(inici != NULL){
        node *p = inici;

        inici = inici->seguent;
        delete p;
    }
}


