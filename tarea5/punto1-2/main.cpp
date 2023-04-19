/*
*********************
Brayan David Zuluaga
ID:8972631
*********************
La complejidad computacional de este programa es O(n^2), donde n es la longitud de la lista. Esto se debe a que para cada elemento en la lista,
estamos llamando al método infoLista que es O(n), lo que significa que para una lista de longitud n, llamamos a este método n veces,
resultando en una complejidad de O(n^2) en el peor caso. Además, la función longLista también tiene complejidad O(n), y como estamos llamando a esta función una vez, esto no afecta la complejidad total del programa.
esto aplica en ambas funciones

*/


#include "lista.h"
#include <iostream>




int contarOcurrencias(Lista& l, int v) {
  int ans = 0;
  for (int i = 1; i <= l.longLista(); i++) {
    if (l.infoLista(i) == v) {
      ans++;
    }
  }
  return ans;
}

Lista obtenerMenores(Lista& l, int v) {
  Lista m;
  for (int i = 1; i <= l.longLista(); i++) {
    int num = l.infoLista(i);
    if (num < v) {
      m.anxLista(num);
    }
  }
  return m;
}

int main(){
  int numeros [16] = {1, 1 ,1 ,3 ,4 ,6 ,7 ,8, 5 ,6 ,4 ,5 ,6 ,3 ,2, 1} ;
  int i;
  Lista l;
  for (i=0; i < 16; i++)
    l.anxLista(numeros[i]);
  cout << contarOcurrencias(l, 1);
  cout << endl;
  Lista m = obtenerMenores(l,3);
  for (int i = 1; i <= m.longLista(); i++) 
    cout << <<m.infoLista(i) << " ";
  
  cout << endl;


  return 0;
}
