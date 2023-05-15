
/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************

este programa tiene una complejidad O(n), donde n es el número de vagones
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, key, i;

    while (cin >> n && n != 0) {
        while (cin >> key && key != 0) {
            vector<int> vagon(n);
            vagon[0] = key;
            
            for (i = 1; i < n ; i++) {
                cin >> vagon[i];
            }
            
            stack<int> estacion;
            int espera = 1 , i = 0;
            while (espera <=n){
                estacion.push(espera);

                while(!estacion.empty() && estacion.top()== vagon[i]){
                    estacion.pop();
                    i++;

                }
                espera++;
            }
            
            if (estacion.empty()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        
        cout << endl;
    }

    return 0;
}
