/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************
la complejidad computacional de este programa es:  O(n log n + nk). donde n es el numero de nombres y k su longitud
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n,  i, medio;
    string nombre, a ,b, palabra = "";
    vector<string> nombres; 
    while (cin >> n && n) {
        nombres.clear();
        for (i = 0; i < n; i++) {
            cin >> nombre;
            nombres.push_back(nombre);
        }
        sort(nombres.begin(), nombres.end());
        medio = n / 2;
        a = nombres[medio - 1];
        b = nombres[medio];
        palabra += 65;
        i = 0;
        bool key = true;
        while(i< a.size() && key == true){
            for (; palabra[i] <= 90 && palabra < a && key == true; palabra[i]++) {
                }
            if(palabra[i] <= 90 && palabra >= a && palabra < b && key == true) 
                key = false;
            if(a[i] != palabra[i] && key == true){
                palabra[i] -= 1;
                palabra += 65 ;
            }
            ++i;
            }
        cout << palabra << endl;
        palabra = "";
    }
    return 0;
}
