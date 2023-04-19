/*
*********************
Brayan David Zuluaga
ID:8972631
*********************
La complejidad computacional de la operación insListaOrdenada es O(n^2), donde n es el número de elementos en la lista.
 Esto se debe a que, en el peor de los casos, se debe recorrer toda la lista además que el procedimiento de longLista e infolista en el peor de los casos es O(n) 
*/


#include "lista.h"
#include <iostream>
void insertarEnListaOrdenada(Lista& l, int v) {
int i = 1;
while (i <= l.longLista() && l.infoLista(i) < v) {
i++;
}
if (i < l.longLista())
  l.insLista(v, i);
else
  l.anxLista(v);
}

int main(){
  int numeros [10] = {1,2,3,4,5,7,8,9,10,11} ;
  int i;
  Lista l;
  for (i=0; i < 10 ; i++)
  l.anxLista(numeros[i]);
  insertarEnListaOrdenada(l, 6)
  for (int i = 1; i <= l.longLista(); i++) 
    cout << l.infoLista(i) << " ";
  
    cout << endl;


  return 0;
}
