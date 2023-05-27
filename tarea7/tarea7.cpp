#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <map>
#include <list>

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


map<char, list<int> > obtenerPosicionesOcurrencias(string& cad) {
    map<char, list<int> > mapa;

    for (int i = 0; i < cad.length(); i++) {
        char c = cad[i];
        mapa[c].push_back(i);
    }

    return mapa;
}

void eliminarPosicionesPila(stack<int>& pil, list<int>& l) {
    stack <int> auxiliar;
    int posicion = 0;
    int contador = 0;

    while (!pil.empty()) {
        if (contador == l.front()) {
            pil.pop();
            l.pop_front();
        } else {
            auxiliar.push(pil.top());
            pil.pop();
        }

        contador++;
    }

    while (!auxiliar.empty()) {
        pil.push(auxiliar.top());
        auxiliar.pop();
    }
}

bool verificarOrdenadoCola(queue<int> &cola) {
    int valorAnterior = cola.front();
    queue<int> Aux = cola;
    bool ordenAscendente = true;
    bool ordenDescendente = true;
    while (!Aux.empty()) {
        int valorActual = Aux.front();
        Aux.pop();

        if (valorActual < valorAnterior) {
            ordenAscendente = false;
        }
        if (valorActual > valorAnterior) {
            ordenDescendente = false;
        }

        valorAnterior = valorActual;
    }

    return ordenAscendente || ordenDescendente;
}
