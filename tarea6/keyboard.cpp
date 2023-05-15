
/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************

La complejidad computacional de este programa es O(n), donde n es la longitud de la línea de entrada.
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    string in;

    while (getline(cin, in)) {
        list<char> ans;
        list<char>::iterator it = ans.begin();

        for (int i = 0; i < in.length(); i++) {
            char c = in[i];
            
            if (c == '[') {
                it = ans.begin();
            } else if (c == ']') {
                it = ans.end();
            } else {
                ans.insert(it, c);
            }
        }

        for (list<char>::iterator it = ans.begin(); it != ans.end(); ++it) {
            char c = *it;
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
