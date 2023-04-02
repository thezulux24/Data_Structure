/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************
la complejidad compuacional de este programa es: O(nklog(k)) donde n es el numero de casos y k la cantidad de caracteres
es logaritmica ya que la funcion find tiene esta complejidad y es la operacion ams costosa del programa

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int n = 0, i = 0, espacios = 0;
    int* pos;
    string line;
    string s1 [] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};
    string s2 [] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9",".",",","?","'","!","/","(",")","&",":",";","=","+","-","_", "\"" ,"@"};
    int size = sizeof(s1)/sizeof(*s1);
    vector <string> morse (s1, s1 + size);
    vector <string> digitos(s2, s2 + size);
    string palabra;
    cin >> n;
    cin.ignore();
    while (i < n){
        cout << "Message #"<< i+1 <<endl;
        getline(cin, line);
        for (int i = 0; i < line.length(); i++) {
            char c = line[i];
            if (c == ' '){
                espacios ++;
                if (espacios == 2){
                    cout << " ";
                    espacios = 0;     
                }
                else{
                    vector <string>:: iterator it = find(morse.begin(), morse.end(), palabra);
                    int pos = it - morse.begin();
                    cout << digitos[pos];
                    palabra = "";
                }
            }
            else{
               palabra += c;
               espacios = 0;
            }
        }
        vector <string>:: iterator it  = find(morse.begin(), morse.end(), palabra);
        int pos = it - morse.begin();
        cout << digitos[pos] << endl;
        palabra = "";

        if (i+1 < n){
            cout << endl;
        }
        i++;
    }
    return 0;
}
