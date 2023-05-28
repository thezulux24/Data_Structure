#include "big.h"

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

void BigInteger::add(BigInteger& big) {
    int aux = 0;
    if (negativo == big.negativo){
        for (int i = 0; i < vec.size() || i < big.vec.size() || aux != 0; i++) {
            if (i < vec.size())
                aux += vec[i];
            if (i < big.vec.size())
                aux += big.vec[i];
            if (i >= vec.size())
                vec.push_back(0);
            vec[i] = aux % 10;
            aux /= 10;
        }
    }
    else{
        BigInteger temp = big;
        substract(temp);
    }
}

void BigInteger::substract(BigInteger& big) {
    
    if (negativo != big.negativo) {
        BigInteger temp(big);
        add(temp);
        return;
    }

    bool signo = false;
    if (operator<(big)) {
        swap(*this, big);
        signo = !negativo;
    }

    int aux = 0;
    for (int i = 0; i < vec.size(); i++) {
        int sub = vec[i] - aux;
        if (i < big.vec.size())
            sub -= big.vec[i];

        if (sub < 0) {
            aux = 1;
            sub += 10;
        } else {
            aux = 0;
        }

        vec[i] = sub;
    }

    // Eliminar los ceros no significativos
    while (vec.size() > 1 && vec.back() == 0) {
        vec.pop_back();
    }

    negativo = signo;
}

void BigInteger::product(BigInteger& big) {
    int n = vec.size();
    int m = big.vec.size();
    vector<int> ans(n + m, 0);

    for (int i = 0; i < n; i++) {
        int aux = 0;
        for (int j = 0; j < m; j++) {
            int tmp = vec[i] * big.vec[j] + aux + ans[i+j];
            aux = tmp / 10;
            ans[i+j] = tmp % 10;
        }
        if (aux > 0)
            ans[i+m] += aux;
    }

    while (ans.size() > 1 && ans.back() == 0)
        ans.pop_back();

    vec = ans;

    if (negativo == big.negativo )
        negativo = false;
    else    
        negativo = true;
}

void BigInteger::pow(int e) {
    bool par = (e % 2 == 0);
    if (e == 0) {
        vec.clear();
        vec.push_back(1);
    }
    else{
        BigInteger ans(*this); 
        BigInteger base(*this); 

        for (int i = 1; i < e; i++) {
            ans.product(base);
        }

        vec = ans.vec; 
        if (par && negativo)
            negativo = false;
    }

}

void BigInteger::quotient(BigInteger& big) {
    bool signo;
    BigInteger cero("0");
    BigInteger uno("1");

    if (big == cero) {
    }
    else{
        if (negativo == big.negativo)
            signo = false;
        else
            signo = true;

        BigInteger dividido(*this); 
        BigInteger ans;
        big.negativo = false;
        dividido.negativo = false;
        while (big <= dividido) {
            dividido.substract(big);
            ans.add(uno);
        }
        vec = ans.vec;
        negativo = signo;
    }
}

void BigInteger::remainder(BigInteger& big) {
    bool signo;
    BigInteger cero("0");
    if (big == cero) {
    }
    else{
        if (negativo == big.negativo)
            signo = false;
        else
            signo = true;

        BigInteger dividido(*this); 
        big.negativo = false;
        dividido.negativo = false;
        while (big <= dividido) {
            dividido.substract(big);
        }
        vec = dividido.vec;
        negativo = signo;
    }
}

string BigInteger::toString() {
    string ans;
    if (negativo)
        ans += '-';
    for (int i = vec.size() - 1; i >= 0; i--) {
        ans += to_string(vec[i]);
    }
    return ans;
}

BigInteger BigInteger::operator+(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.add(big);
    return ans;
}

BigInteger BigInteger::operator-(BigInteger& big){
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.substract(big);
    return ans;

}

BigInteger BigInteger::operator*(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.product(big);
    return ans;
}

BigInteger BigInteger::operator/(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.quotient(big);
    return ans;
}

BigInteger BigInteger::operator%(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.remainder(big);
    return ans;
}

//analizadoras
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
bool BigInteger::operator<=(BigInteger& big) {
    return operator<(big) || operator==(big);
}


BigInteger BigInteger::sumarListaValores(list<BigInteger>& lista) {
    BigInteger suma;
    
    for (list<BigInteger>::iterator it = lista.begin(); it != lista.end(); ++it) {
        suma.add(*it);
    }
    
    return suma;
}

BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& lista) {
    BigInteger producto("1");
    for (list<BigInteger>::iterator it = lista.begin(); it != lista.end(); ++it) {
        producto.product(*it);
    }
    
    return producto;
}



