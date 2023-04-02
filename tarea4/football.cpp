/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************
la complejidad compuacional de este programa es: O(Nlog(N)) donde N es el nUmero de equipos. la funcion sort es la que tiene mas costo compuacional
con nlogn
*/




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toUpper(const string& str) {
    string ans = str;
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] >= 'a' && ans[i] <= 'z') {
            ans[i] = ans[i] - 'a' + 'A';
        }
    }
    return ans;
}
class Futbol {
public:
    string nombre;
    int puntos, partidos, gol, golReci, diferencia;
    double porcentaje;

    Futbol(string nombre_) : nombre(nombre_), partidos(0), gol(0), golReci(0), diferencia(0), puntos(0), porcentaje(0.00) {}

    bool operator<(const Futbol& futbol) const {
        bool key = true;
        if (puntos != futbol.puntos) {
            key = puntos > futbol.puntos;
        } else if (diferencia != futbol.diferencia) {
            key = diferencia > futbol.diferencia;
        } else if (gol != futbol.gol) {
            key = gol > futbol.gol;
        } else {

            string may = toUpper(nombre);
            string may2 = toUpper(futbol.nombre);
            key = may < may2;
        }
        return key;
    }
};

int main() {
    int numEquipos=0, partidos=0, goles [2] , i, prev = 1;
    double completo = 100, tres = 3;
    vector<bool> igualados;
    string team;
    string jugado[2];
    vector <Futbol> juegos;


    while(cin >> numEquipos >> partidos && numEquipos != 0 && partidos != 0){

        for(int i = 0; i<numEquipos;i++){
        cin >> team;  
        juegos.push_back(Futbol(team));
        }
        i = 0;
        for(int i = 0; i < partidos; i++){
            cin >> jugado[0] >> goles[0] >> jugado[1] >> goles[1] >> jugado[1];
            if (goles[0] > goles[1]){
                for(auto it = juegos.begin(); it != juegos.end(); it++) {

                    if (it->nombre == jugado[0]) {
                        it->partidos += 1;
                        it->gol += goles[0];
                        it->golReci += goles[1];
                        it->diferencia = it->gol - it->golReci;
                        it->puntos += 3;
                        it->porcentaje =(it->puntos)*completo/(it->partidos*tres);
                    }
                    else if (it->nombre == jugado[1]) {
                        it->partidos += 1;
                        it->gol += goles[1];
                        it->golReci += goles[0];
                        it->diferencia = it->gol - it->golReci;
                        it->puntos += 0;
                        it->porcentaje =(it->puntos)*completo/(it->partidos*tres);
                    }
            
                }
            }
            else if (goles[0] < goles[1]) {
                for(auto it = juegos.begin(); it != juegos.end(); it++) {
                    if (it->nombre == jugado[0]) {
                        it->puntos += 0;
                        it->partidos += 1;
                        it->gol += goles[0];
                        it->golReci += goles[1];
                        it->diferencia = it->gol - it->golReci;
                        it->porcentaje =(it->puntos)*completo/(it->partidos*tres);
                    }
                    else if (it->nombre == jugado[1]) {
                        it->puntos += 3;
                        it->partidos += 1;
                        it->gol += goles[1];
                        it->golReci += goles[0];
                        it->diferencia = it->gol - it->golReci;
                        it->porcentaje =(it->puntos)*completo/(it->partidos*tres);
                    }
                }
            }
            else {
                for(auto it = juegos.begin(); it != juegos.end(); it++) {
                    if (it->nombre == jugado[0]) {
                        it->puntos += 1;
                        it->partidos += 1;
                        it->gol += goles[0];
                        it->golReci += goles[1];
                        it->diferencia = it->gol - it->golReci;
                        it->porcentaje =(it->puntos)*completo/(it->partidos*tres);
                    }
                    else if (it->nombre == jugado[1]) {
                        it->puntos += 1;
                        it->partidos += 1;
                        it->gol += goles[0];
                        it->golReci += goles[1];
                        it->diferencia = it->gol - it->golReci;
                        it->porcentaje =(it->puntos)*completo/(it->partidos*tres);
                    }
                    
                }
            }   
         }

        sort(juegos.begin(), juegos.end());

        for(auto it = juegos.begin(); it != juegos.end(); it++) {
            if (it->puntos== ((it-prev)->puntos) && it->diferencia==((it-prev)->diferencia) && it->gol==((it-prev)->gol)) 
                igualados.push_back(true);
            
            else
                igualados.push_back(false);
            
            }
        for(auto it = juegos.begin(); it != juegos.end(); it++) {
                if (igualados[i] == false) {
                    printf("%2d%s %15s %3d %3d %3d %3d %3d ", i+1, ".", juegos[i].nombre.c_str(), juegos[i].puntos, juegos[i].partidos, juegos[i].gol, juegos[i].golReci, juegos[i].diferencia);
                    if (it->partidos!=0)
                        printf("%6.2f\n", juegos[i].porcentaje);
                    
                    else
                        printf("%6s\n", "N/A");
                    
                }
                else {
                    printf("%19s %3d %3d %3d %3d %3d ", juegos[i].nombre.c_str(), juegos[i].puntos, juegos[i].partidos, juegos[i].gol, juegos[i].golReci, juegos[i].diferencia);
                    if (it->partidos != 0)
                        printf("%6.2f\n", juegos[i].porcentaje);
                    
                    else
                        printf("%6s\n", "N/A");
                    
                }    

            i++; 
        }
        juegos.clear();
        igualados.clear();           
        cout << endl;
        }
    return 0;
}