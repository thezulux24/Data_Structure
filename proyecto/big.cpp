

#include "big.h"

BigInteger::BigInteger(Elemento e){
    for (int i = e.size() - 1; i >= 0; i--) {
            vec.push_back(e[i] - '0');
    }
}
BigInteger::BigInteger(const BigInteger& other) {
    vec = other.vec;
}
void BigInteger::add(BigInteger big) {
    int aux = 0;
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
void BigInteger::substract(BigInteger big) {
    int aux = 0;
    int i;
    for (i = 0; i < vec.size() && i < big.vec.size(); i++) {
        aux = vec[i] - big.vec[i] - aux;
        vec[i] = (aux + 10) % 10;
        if (aux < 0) {
            aux = 1;
        } else {
            aux = 0;
        }
    }
    while (i < vec.size() && aux) {
        aux = vec[i] - aux;
        vec[i] = (aux + 10) % 10;
        if (aux < 0) {
            aux = 1;
        } else {
            aux = 0;
        }
        i++;
    }
    while (vec.size() > 1 && vec.back() == 0) {
        vec.pop_back();
    }
}

void BigInteger::product(BigInteger big) {
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

    // Elimina los ceros al frente del ansado
    while (ans.size() > 1 && ans.back() == 0)
        ans.pop_back();

    vec = ans;
}


string BigInteger::toString() {
    string ans;
    for (int i = vec.size() - 1; i >= 0; i--) {
        ans += to_string(vec[i]);
    }
    return ans;
}


//analizadoras
bool BigInteger::operator==(const BigInteger& big) const {
    bool ans = true;
    if (vec.size() != big.vec.size())
        ans = false;
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] != big.vec[i])
            ans = false;
    }
    return ans;
}
