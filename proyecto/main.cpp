

#include <cstdio>
#include <iostream>
#include "big.h"



int main(){
   BigInteger b1("153523432432523525223523");
   BigInteger b2("154523432432523525223523");

   if (b1 == b2)
      cout << "son iguales" <<endl;
   else
      cout << "no son iguales" << endl;
   cout << b1.toString() <<endl;

   b1.product(b2);
   cout << b1.toString() <<endl;
   return 0;
}
