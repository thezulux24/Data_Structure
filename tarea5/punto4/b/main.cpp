/*
*********************
Brayan David Zuluaga
ID:8972631
*********************

la complejidad computacional de concatenar las dos lisatas mediante el uso de la sobrecarga del operador + es O(n) donde n es el tamaño de ambas listas
ya que se recorren ambas de manera secuencial, da como resultado esta complejidad
*/


#include "lista.h"
#include <iostream>

int main(){
  
  Lista l, l2, l3;
  int i;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);
  l2.anxLista(1);
  l2.anxLista(1);
  l2.anxLista(1);
  l2.anxLista(1);
  l3 = l+l2;

  for (i = 0; i <= l3.longLista(); i++)
    cout << l3.infoLista(i)<<endl;


  return 0;
}
