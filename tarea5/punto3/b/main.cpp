/*
*********************
Brayan David Zuluaga
ID:8972631
*********************
La complejidad computacional de la operación insListaOrdenada es O(n), donde n es el número de elementos en la lista.
 Esto se debe a que, en el peor de los casos, se debe recorrer toda la lista para encontrar la posición adecuada para insertar el nuevo nodo. 
*/


#include "lista.h"
#include <iostream>

int main(){
  int numeros [10] = {1,2,3,4,5,7,8,9,10,11} ;
  int i;
  Lista l;
  for (i=0; i < 10 ; i++)
  l.anxLista(numeros[i]);
  l.insListaOrdenada(7);
  for (int i = 1; i <= l.longLista(); i++) 
    cout << l.infoLista(i) << " ";
  
    cout << endl;


  return 0;
}
