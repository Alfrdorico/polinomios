#include <iostream>
#include <math.h>
#include "complex.h"
#include "poli.h"
using namespace std;

int main() {

    int grado, k=0;
    cout << "GRADO:" << '\n';
    cin >> grado;

    double coeficientes[grado+1];
    //double derivada[grado];

    for ( k = 0; k <= grado; k++) {
      cout << "a_" << k << "\n";
      cin>>coeficientes[k];
    }
/*
    double x=0;
    cout << "\nIngresa el valor de x" << '\n';
    cin>>x;
*/
    //cout<<"\nla derivada del polinomio en el valor "<<x<<" es: "<< dif_x0(grado,coeficientes,x);
    array rr = raices_racionales(grado,coeficientes);

    cout << "raíces racionales: \n";
    if(rr.longitud>0){
      for(k = 0; k < rr.longitud; k++)
      cout << rr.arreglo[k]<<"\t";
    cout << "\n";
    }
    else
      cout<<"NO se encontraron raíces racionales\n";



    return 0;
  }
