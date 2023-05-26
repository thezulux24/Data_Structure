#include <iostream>
#include <queue>

using namespace std;
// paso sin referencia para que no me altere la cola original
bool verificarRepetidosCola(queue<int> cola) {
bool ans = false;
bool flag = true;
    while (!cola.empty() && flag) {
        int frente = cola.front();
        cola.pop();

        queue<int> colaRestante = cola;
        while (!colaRestante.empty() && flag) {
            if (frente == colaRestante.front()) {

                ans = true; 
                flag = false;
            } 
            colaRestante.pop();         
        }
    }
     return ans;
}
