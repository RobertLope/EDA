

#include "ArbreBinari.h"
#include <iostream>


const int MIDA = 1000;

void preordre_binari(const ArbreBinari & a);

using namespace std;

int main() {
    char entrada[MIDA];
    cin.getline(entrada, MIDA);
    ArbreBinari a(entrada);

    cout << "Preordre: ";
    preordre_binari(a);
    cout << endl;
}


void preordre_binari(const ArbreBinari & a){

    //Pre:
    //Post: Mostrar el arbre binari en forma de preordre

    if(!a.esBuit()){
        cout << a.Contingut() << " ";
        preordre_binari(a.FillEsquerre());
        preordre_binari(a.FillDret());
    }




}



