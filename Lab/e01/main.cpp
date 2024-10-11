// Robert López Contreras
// u1990700
// Exercici 01



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  // Para std::istringstream
#include <list>
#include <vector>
#include <iomanip>
#include <stdlib.h>


#include "Persona.h"
#include "Padro.h"
#include "Estudi.h"


// Pros de vect: el cost per accedir a qualsevol element es constant
// Contres: Inserir te un coste constant amortitzat i un cost lineal per afegir a qualsevol posicio

// Pros de list: inserir te un cost constant
// Contres: Accedir a qualsevol posicio te un Cost lineal


using namespace std;

int stringToInt ( string s ) { //Evitar llegir directament les dades numeriques
    if ( s . length ()==0) return -1;
    for( char c : s ) {
        if (c <'0' || c >'9') return -1;
    }
    return stoi ( s );
}




Padro llegirDades(){ //La llista que ha de retornar no son de Persona, segurament sera de Padro

    cout<<"*******************"<<endl;
    cout<<"* 1: Llegir dades *"<<endl;
    cout<<"*******************"<<endl;

    string ruta;

    cin>>ruta;
    ifstream fitxer(ruta);

    Padro p;

    //vector<Padro> vp;


    if(!fitxer.is_open()){
        throw("Error al obrir el fitxer");
    }

    //Variables de la clase persona
    int codiNivellEstudis;
    string nivellEstudis;
    int anyNaixement;
    int codiPaisNaixement;
    string paisNaixement;

    //Variables del districte
    int numDistricte;
    int anyDistricte;

    //Utilitats
    string convertidor; //Farem servir aquesta variable auxiliar per a fer el stringToInt()
    string linea;

    //Controlem si s'ha afegit o no
    int afegit = 0;

    int cont = 0;

    //Fem un salt de linia
    getline(fitxer,linea);



    while(getline(fitxer, linea)){

        istringstream stream(linea);//Procesem la linea

        //Tractem primer el districte

        stream >> convertidor;
        anyDistricte = stringToInt(convertidor);

        stream >> convertidor;
        numDistricte = stringToInt(convertidor);

        //Tractem les dades de la persona
        stream >> convertidor;
        codiNivellEstudis = stringToInt(convertidor);

        stream >> nivellEstudis;

        stream >> convertidor;
        anyNaixement = stringToInt(convertidor);

        stream >> convertidor;
        codiPaisNaixement = stringToInt(convertidor);

        stream >> paisNaixement;

        //Afegim l'habitant
        afegit = p.afegir(anyDistricte,numDistricte,codiNivellEstudis,nivellEstudis,anyNaixement,codiPaisNaixement,paisNaixement);

        if(afegit == 0) cerr<< "Error al afegir el habitant";
        else cont++;
    }

    //De moment sol traballarem com si hagues un padro així que afegirem l'any al final



    cout<<"Numero de linies: "<<cont<<endl;
    return p;
}


void ObtenirNumHabitants(Padro const &p){

    //Pre:
    //Post:
    cout<<"***************************************"<<endl;
    cout<<"* 2: Nombre d'habitants per districte *"<<endl;
    cout<<"***************************************"<<endl;

    p.obtenirNumHabitantsPerDistricte();



}

void llistaEstudis(Padro const &p) {

    //Imprimim una llista d'Estudis ordenada amb el metode reverse

    cout<<"**************"<<endl;
    cout<<"* 3: Estudis *"<<endl;
    cout<<"**************"<<endl;
    list<Estudi> eLlista = p.resumEstudis();

    eLlista.sort();

    list<Estudi>:: reverse_iterator rit = eLlista.rbegin();
    while(rit != eLlista.rend()){
            cout<<" - "<<(*rit).obtenirNom()<<endl;
            rit++;
    }
}

void mostrarEdadMitjana(Padro const &p){

    //Pre:
    //Post:

    cout<<"*********************"<<endl;
    cout<<"* 4: Edats mitjanes *"<<endl;
    cout<<"*********************"<<endl;

    p.resumEdat();
}

void mostrarNacionalitatsExclusives(Padro const &p){

    //Pre:Padro amb habitants
    //Post: retorna un llista dels 2 districtes que tenen diferents nacionalitats

    cout<<"*******************************"<<endl;
    cout<<"* 5: Nacionalitats exclusives *"<<endl;
    cout<<"*******************************"<<endl;

    int dis1=0;
    int dis2=0;
    cin>>dis1;
    cin>>dis2;
    p.diferentsNacionalitats(dis1,dis2);
}

void mostrarEdatNacio(Padro const &p){

    //Pre: Padro amb habitants
    //Post: retorna el nombre d'habitants de cada distrite que compleixi l'edat i el codi de nacionalitat pasades per paraemtre

    cout<<"****************************************"<<endl;
    cout<<"* 6: Compta edat i nació per districte *"<<endl;
    cout<<"****************************************"<<endl;

    int edat=0;
    int nac;
    cin>>edat;
    cin>>nac;

    p.edatNacioPerDistricte(edat,nac);
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
            //llegir el fitxer amb ifstream cal saltar la primera liniea que es la capçelera
            p = llegirDades();
            break;

        case 2:
            //retornar el nombre d'habitants per districte

            ObtenirNumHabitants(p);
            break;

        case 3:
            //estudis: mostrar el llistat dels diferents tipus d'estudis que ha completat la població empadronada, ordre alfabètic invers (revisar lo del reverse)


            llistaEstudis(p);
            break;

        case 4:
            //mostrar el llistat de l'edat mitjana per districte

            mostrarEdadMitjana(p);

            break;
        case 5:
            //mostrar donat el valor de l'edat un codi de nacionalitat, el nombre d'habitants de cada districte que compleixi aquests requisits

            mostrarNacionalitatsExclusives(p);

            break;

        case 6:
            //mostar, donat un valor d'edat i un codi de nacionalitat, el nombre d'habitants de cada dsitricte que compleixi aquests requisits.

            mostrarEdatNacio(p);

            break;


        case 0:

            break;
        }
         cin>>opcio;
    }
    return 0;
}


