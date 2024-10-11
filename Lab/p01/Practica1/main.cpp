// Robert López Contreras
// u1990700
// Practica 01

#include <iostream>
#include <string>
#include <vector>

#include "Padro.h"


using namespace std;

void llegirDades(){
//Pre: --
//Post: Llegir les dades csv

cout<<"********************"<<endl;
cout<<"* 01: Llegir dades *"<<endl;
cout<<"********************"<<endl;


}


void existeixAny(){
//Pre:
//Post: retornar si existeix el any

cout<<"********************"<<endl;
cout<<"* 02: Existeix any *"<<endl;
cout<<"********************"<<endl;



}

void obtenirNombreHabitants(){
//Pre:
//Post:

cout<<"**********************************"<<endl;
cout<<"* 03: Obtenir nombre d'habitants *"<<endl;
cout<<"**********************************"<<endl;


}

void obtenirNombreHabitantsAny(){
//Pre:
//Post:

cout<<"********************************************"<<endl;
cout<<"* 04 : Obtenir nombre d'habitants d'un any *"<<endl;
cout<<"********************************************"<<endl;

}

void obtenirNombreHabitantsAnyDistricte(){


cout<<"********************************************************"<<endl;
cout<<"* 05 : Obtenir nombre d'habitants d'un any i districte *"<<endl;
cout<<"********************************************************"<<endl;


}

void resumPerEstudis(){


cout<<"**************************"<<endl;
cout<<"* 06 : Resum per estudis *"<<endl;
cout<<"**************************"<<endl;


}


void estudisPerDistricte(){


cout<<"**************************************"<<endl;
cout<<"* 07: Nombre d'estudis per districte *"<<endl;
cout<<"*************************************"<<endl;

}

void resumNivellEstudis(){

cout<<"**************************************"<<endl;
cout<<"* 08: Nombre d'estudis per districte *"<<endl;
cout<<"**************************************"<<endl;

}


void resumNacionalitats(){


cout<<"*******************************"<<endl;
cout<<"* 09: Nombre de nacionalitats *"<<endl;
cout<<"*******************************"<<endl;


}

void movimentsComunitat(){

cout<<"*********************************"<<endl;
cout<<"* 10: Moviments d'una comunitat *"<<endl;
cout<<"*********************************"<<endl;

}


void resumEdats(){

cout<<"*********************"<<endl;
cout<<"* 11: Resum d'edats *"<<endl;
cout<<"*********************"<<endl;


}


void movimentsDelsVells(){


cout<<"*********************"<<endl;
cout<<"* 12: Resum d'edats *"<<endl;
cout<<"*********************"<<endl;


}


void mesJoves(){


cout<<"*********************"<<endl;
cout<<"* 13: Resum d'edats *"<<endl;
cout<<"*********************"<<endl;



}


void estudisAnyDistricteEdatNacio(){


cout<<"*********************"<<endl;
cout<<"* 14: Resum d'edats *"<<endl;
cout<<"*********************"<<endl;



}


int main()
{

    int opcio = 0;
    vector<Padro> vP;

    cin>>opcio;
    while(opcio!= 0){

    switch (opcio){

        case 1:
            //demanar la ruta de fitxers al usuari
            //llegirDades(); Es posible que hagi de retornar un vector de Padrons
            llegirDades(); //TODO
            break;

        case 2:
            //indicar si l'any pasat esta inserit

            ObtenirNumHabitants(p);
            break;

        case 3:
            //estudis: mostrar el llistat dels diferents tipus d'estudis que ha completat la població empadronada, ordre alfabètic invers (revisar lo del reverse)

            obtenirNombreHabitants();
            //obtenirNombreHabitants(pv);
            break;

        case 4:
            //mostrar el llistat de l'edat mitjana per districte

            obtenirNombreHabitantsAny();

            break;
        case 5:
            //mostrar donat el valor de l'edat un codi de nacionalitat, el nombre d'habitants de cada districte que compleixi aquests requisits

            obtenirNombreHabitantsAnyDistricte();

            break;

        case 6:
            //mostar, donat un valor d'edat i un codi de nacionalitat, el nombre d'habitants de cada dsitricte que compleixi aquests requisits.

            resumPerEstudis();

            break;

        case 7:

            estudisPerDistricte();

            break;

        case 8:

            resumNivellEstudis();

            break;

        case 9:

            resumNacionalitats();

            break;

        case 10:

            movimentsComunitat();

            break;

        case 11:

            resumEdats();

            break;

        case 12:

            movimentsDelsVells();

            break;

        case 13:

            mesJoves();

            break;

        case 14:

            estudisAnyDistricteEdatNacio();

            break;

        case 0:

            break;
        }
         cin>>opcio;
    }

    return 0;
}
