/*
*********************
Brayan David Zuluaga
ID:8972631
*********************

la operacion concatenarListas tiene una complejidad O(n^2) en el peor de los casos, ya que el ciclo for recorre la longitud de
lista 2 lo cual tiene una complejidad O(n) sumandole a esto que dentro de este ciclo se llaman dos métodos que tienen una complejidad O(n) en el peor de los casos
n es el tamaño de la lista

*/


#include "lista.h"
#include <iostream>


void concatenarListas (Lista& l, Lista& l2){
  int i;
  for (i = 1 ; i <= l2.longLista(); i++ )
    l.anxLista(l2.infoLista(i));

}


int main(){
  int numeros [5] = {1,1,1,1,1} ;
  int numeros2 [5] = {2,2,2,2,2};
  int i;
  Lista l;
  Lista l2;
  for (i=0; i < 5; i++)
    l.anxLista(numeros[i]);
  for (i=0; i < 5; i++)
    l2.anxLista(numeros2[i]);
    
  concatenarListas (l, l2);
  for (i=1; i <= l.longLista(); i++)
    cout << l.infoLista(i)<< " ";

  return 0;
}
