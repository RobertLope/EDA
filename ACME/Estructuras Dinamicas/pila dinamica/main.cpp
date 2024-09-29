
#include <iostream>
#include "pilaDinamica.h"

using namespace std;

int main() {
    pilaDinamica p;
    char c;

    cin >> c;
    while (c != '.') {
        if(c >= 'A' && c <= 'Z'){
            p.Empila(c);
            if(p.Buida())
                cout<<"* "; // mostrar valor o * (amb espai)
            else
                cout<<p.Cim()<<" ";
          }
        else if(c >= 'a' && c<= 'z'){
            if(!p.Buida()){
                p.Desempila(); // si la pila ha canviat
            }
            if(p.Buida())
                cout<<"* "; // mostrar valor o * (amb espai)
            else
                cout<<p.Cim()<<" ";
        }
        cin >> c;
    }

    // bucle per buidar la pila
    while(!p.Buida()){
        p.Desempila();
        if(p.Buida())
            cout<<"* "; // mostrar valor o * (amb espai)
        else
            cout<<p.Cim()<<" ";
    }
    // mostrant valor o * (després de treure cada element)
    cout << endl;

}
