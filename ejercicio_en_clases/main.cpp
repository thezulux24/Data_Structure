
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include "cola.h"



void imprimirElementos(Cola &c){
  while(!c.vaciaCola()){
     printf("%d\n",  c.front());
     c.deque();
  }
}

void imprimirElementos(queue<int> &que){
  while(!que.empty()){
      printf("%d\n",  que.front());
      que.pop();
  }
}




int main(){
   Cola c;
   c.enqueue(1);
   c.enqueue(4);
   c.enqueue(6);
   c.enqueue(8);
   cout << c.front() << endl;
   
   c.deque();
   cout << c.front() << endl;
   return 0;
}
