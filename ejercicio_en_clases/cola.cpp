

#include "cola.h"

Cola::Cola(){
}
//esta implementacion tiene una complejidad temporal de O(n), donde n es el tamano del vector, donde está dada por el ciclo while, ya que este recorre
//hasta dejar el vector copia vacio, las implementaciones del vector son O(1) así que no afectan tanto a la complejidad
Elemento Cola::front(){
  //Elemento ans = vec[0]; 
  vector <Elemento> temp;
  Elemento max = 0;
  while(!vec.empty()){
    if (vec[vec.size() - 1] > max ){
      max = vec[vec.size() - 1];
    }
   temp.insert(temp.begin(), vec[vec.size() - 1]);
   vec.pop_back();
  }
  while(!temp.empty()){
    vec.insert(vec.begin(), temp[temp.size()-1]);
    temp.pop_back();
  }
   return max;
}

void Cola::enqueue(Elemento e){
  //vec.push_back(e);
  vec.insert(vec.begin(), e);
}

//la complejidad es O(n) donde n es el tamaño del vector, es muy parecida a la implementación anterior, solo que guardo el indice del maximo y después lo borro
void Cola::deque(){
  //vec.erase(vec.begin());
  vector<Elemento> temp = vec;
  Elemento index = 0;
  Elemento max = 0;
  int i = temp.size()-1;
  while(!temp.empty()){
    if (temp[temp.size() - 1] > max){
      max = temp[temp.size() - 1];
      index = i;
    }
   temp.pop_back();
   i = temp.size()-1;
  }
  vec.erase(vec.begin() + index);
}

bool Cola::vaciaCola(){
  bool ans;
  if(vec.empty())
     ans = true;
  else
     ans = false;
  return ans;
}
