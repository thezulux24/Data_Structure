#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main() {
    int numPersonas, numComandos;
    int ciudadano;
    char comando;

    int numCaso = 1;

    while (cin >> numPersonas >> numComandos && (numPersonas != 0 && numComandos != 0)) {
        cout << "Case " << numCaso << ":" << endl;

        queue<int> colaCiudadanos;
        list<int> listaExpedidos;

        for (int i = 1; i <= numPersonas; i++) {
            colaCiudadanos.push(i);
        }

        for (int i = 0; i < numComandos; i++) {
            cin >> comando;

            if (comando == 'N') {
                int siguienteCiudadano = colaCiudadanos.front();
                colaCiudadanos.pop();
                cout << siguienteCiudadano << endl;
                colaCiudadanos.push(siguienteCiudadano);
            } else if (comando == 'E') {
                cin >> ciudadano;
                colaCiudadanos = queue<int>();  // Limpiar la cola actual
                colaCiudadanos.push(ciudadano);
                listaExpedidos.push_back(ciudadano);
            }
        }

        for (list<int>::iterator it = listaExpedidos.begin(); it != listaExpedidos.end(); ++it) {
            bool expedido = false;
            while (!colaCiudadanos.empty() && !expedido) {
                int ciudadanoActual = colaCiudadanos.front();
                colaCiudadanos.pop();
                if (ciudadanoActual != *it) {
                    colaCiudadanos.push(ciudadanoActual);
                } else {
                    expedido = true;
                }
            }
            if (!expedido) {
                colaCiudadanos.push(*it);
            }
        }

        numCaso++;
        cout << endl;
    }

    return 0;
}
