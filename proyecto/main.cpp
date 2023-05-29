#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class BigInteger {
    vector<int> vec;
    bool negativo;

public:
    BigInteger();
    BigInteger(const string e);
    BigInteger(const BigInteger& big);
    bool operator<(BigInteger& big);
    bool operator==(BigInteger& big);
    string toString();


};

BigInteger::BigInteger() {
    vec.push_back(0);
}

BigInteger::BigInteger(const string e){
{
        if (e[0] == '-') {
            negativo = true;
            for (int i = e.size() - 1; i >= 1; i--) {
                vec.push_back(e[i] - '0');
            }
        } else {
            negativo = false;
            for (int i = e.size() - 1; i >= 0; i--) {
                vec.push_back(e[i] - '0');
            }
        }
    
    }
}

BigInteger::BigInteger(const BigInteger& other) {
    vec = other.vec;
}
bool BigInteger::operator==( BigInteger& big){
    bool ans = true;
    if (vec.size() != big.vec.size()&& ans)
        ans = false;
    for (int i = vec.size() - 1 && ans; i >= 0; i--) {
        if (vec[i] != big.vec[i])
            ans = false;
    }
    return ans;
}

bool BigInteger::operator<(BigInteger& big) {

    bool ans;
    bool flag = true;
    if (negativo && !big.negativo && flag) {
        ans = true;
        flag = false;
    }
    if (!negativo && big.negativo && flag) {
        ans = false; 
        flag = false;
    }
    if (vec.size() < big.vec.size() && flag) {
        ans = true;
        flag = false;
    }
    if (vec.size() > big.vec.size() && flag) {
        ans = false;
        flag = false;
    }
    if (negativo && big.negativo){
        for (int i = vec.size() - 1 ; i >= 0 && flag; i--) {
            if (vec[i] < big.vec[i]) {
                ans = false;
                flag = false;
            }
             if (vec[i] > big.vec[i]){
                
                ans = true;
                flag = false;
             }
        }


    }
    else {
        for (int i = vec.size() - 1 ; i >= 0 && flag; i--) {
            if (vec[i] < big.vec[i]) {
                ans = true;
                flag = false;
            }
             if (vec[i] > big.vec[i]){
                
                ans = false;
                flag = false;
             }
        }


    }
    return ans;
}
void removerCeros(std::string& str) {
    int length = str.length();
    int i = length - 1;
    while (i >= 0 && str[i] == '0') {
        str.pop_back();
        i--;
    }
}
int main() {
    int caso = 1;
    string num1, num2;
    while (cin >> num1 >> num2 && !std::cin.eof()) {
        string intPart1, decPart1;
        string intPart2, decPart2;

    string::iterator it = find(num1.begin(), num1.end(), '.');
        if (it != num1.end()) {
            int pos = distance(num1.begin(), it);
            intPart1 = num1.substr(0, pos);
            decPart1 = num1.substr(pos + 1);
        } else {
            intPart1 = num1;
            decPart1 = "0";
        }
        removerCeros(decPart1);
        it = find(num2.begin(), num2.end(), '.');
        if (it != num2.end()) {
            int pos = distance(num2.begin(), it);
            intPart2 = num2.substr(0, pos);
            decPart2 = num2.substr(pos + 1);
        } else {
            intPart2 = num2;
            decPart2 = "0";
        }
        removerCeros(decPart2);

        BigInteger int1(intPart1);
        BigInteger int2(intPart2);
        BigInteger dec1(decPart1);
        BigInteger dec2(decPart2);



        if (int1 < int2){
            cout << "Case " << caso << ": Smaller" << endl;
        }
        else if (int1 == int2){
            if(dec1 < dec2)
                cout << "Case " << caso << ": Smaller" << endl;
            else if (dec1 == dec2)
                cout << "Case " << caso << ": Same" << endl;
            else
                cout << "Case " << caso << ": Bigger" << endl;
        }
        else 
            cout << "Case " << caso << ": Bigger" << endl;

        caso++;
    }

    return 0;
}

