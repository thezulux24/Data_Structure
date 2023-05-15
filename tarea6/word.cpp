/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************

La complejidad computacional de este programa es O(n*m), donde n es el número de palabras en el diccionario y
 m es la longitud maxima de una linea de emtrada.
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int contar(vector<string>& diccionario, string& puzzle) {
    vector<int> puzzleFreq(26, 0);
    for (int i = 0; i < puzzle.size(); i++) {
        char letra = puzzle[i];
        if (letra != ' ') {
            puzzleFreq[letra - 'a']++;
        }
    }

    int ans = 0;
    for (int i = 0; i < diccionario.size(); i++) {
        const string& palabra = diccionario[i];
        vector<int> palabraFreq(26, 0);
        bool posible = true;
        for (int j = 0; j < palabra.size() && posible; j++) {
            char letra = palabra[j];
            palabraFreq[letra - 'a']++;
            if (palabraFreq[letra - 'a'] > puzzleFreq[letra - 'a']) {
                posible = false;
            }
        }
        if (posible) {
            ans++;
        }
    }

    return ans;
}

int main() {
    vector<string> diccionario;
    string palabra;

    while (getline(cin, palabra) && palabra != "#") {
        diccionario.push_back(palabra);
    }

    string puzzle;
    while (getline(cin, puzzle) && puzzle != "#") {
        
        cout <<  contar(diccionario, puzzle) << endl;
    }

    return 0;
}
