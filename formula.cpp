/*
*********************
Brayan David Zuluaga
ID: 8972631
*********************
la complejidad computacional de este programa es: O(n*p*q) donde n es la cantidad de casos, q es la cantidad de carreas y q la cantidad de sistemas 
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int pilot, races, systems, aux, i, j, q, key;
    vector<int> result;
    while (cin >> races >> pilot  && races != 0 && pilot != 0){
        result.clear();
        for (i = 0; i < races*pilot; i++){
            cin >> aux;
            result.push_back(aux);
        }
        cin >> systems;
        for (i = 0; i < systems; i++ ){
            vector<int> score(pilot, 0);
            cin >> q;
            vector<int> points(q);
            for(j = 0 ; j < q ; j++){
                cin >> aux;
                points[j] = aux;
            }

            for (j = 0 ;j < races; j++){
                vector<int> racePoints(pilot, 0);
                for (int k = 0; k < pilot; k++) {
                    key = result[j*pilot + k]-1;
                    if (key < q)
                        racePoints[k] = points[key];
                }
                for (int k = 0; k < pilot; k++) {
                    score[k] += racePoints[k];
                }
            }
            auto it = max_element(score.begin(), score.end());
            int maxScore = *it;
            for (int i = 0; i < score.size(); i++){
                if (score[i] == maxScore){                    
                    cout << i+1 << " ";
                }                
            }  
            cout << endl;
        }
    }
    return 0;
}
