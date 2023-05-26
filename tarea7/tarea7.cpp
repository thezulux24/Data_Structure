#include <iostream>
#include <queue>
#include <stack>

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
stack<int> filtrarNParesCola(queue<int> col, int N) {
    stack<int> ans;

    while (!col.empty() && N > 0) {
        int x = col.front();
        col.pop();

        if (x % 2 == 0) {
            ans.push(x);
            N--;
        }
    }

    return ans;
}
