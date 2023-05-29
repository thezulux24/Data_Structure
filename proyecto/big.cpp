#include "big.h"

/*
ENTRADA: Ninguna
SALIDA:
DESCRIPCION:
*/
BigInteger::BigInteger() {
    vec.push_back(0);
}
/*
ENTRADA:
SALIDA: Ninguna
DESCRIPCION:
*/
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
/*
ENTRADA
SALIDA
DESCRIPCION:
*/
BigInteger::BigInteger(const BigInteger& other) {
    vec = other.vec;
}


/*
función add
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: Ninguna
DESCRIPCION:Esta función suma el valor representado por el objeto BigInteger pasado como parámetro al objeto actual
*/
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
        if (negativo && !big.negativo){
            negativo = !negativo;
            substract(temp);
            negativo = !negativo;
        }
        else{
            substract(temp);
        }
    }
}
/*
función substract
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: Ninguna
DESCRIPCION:Esta función resta el valor representado por el objeto BigInteger pasado como parámetro al objeto actual
*/
void BigInteger::substract(BigInteger& big) {
    
    if (negativo != big.negativo) {
        BigInteger temp(big);
        if (!negativo && big.negativo ){
            temp.negativo = false;
            add(temp);
        
        }
        else{
            add(temp);
        }
    }
    if (negativo && big.negativo){
        BigInteger temp(big);
        temp.negativo = false;
        add(temp);
        negativo = true;
        }

    else{
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
}

/*
función Product
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: Ninguna
DESCRIPCION:Esta función  multiplica el valor representado por el objeto BigInteger pasado como parámetro al objeto actual
*/
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
/*
función pow
ENTRADA: un elemento entero 'e'
SALIDA: Ninguna
DESCRIPCION:Esta función  calcula la potencia 'e'del valor representado por el objeto actual BigInteger
*/
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
/*
función quotient
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: 
DESCRIPCION:Esta función divide el valor representado por el objeto BigInteger pasado como parámetro al objeto actual
*/
void BigInteger::quotient(BigInteger& big) {
    BigInteger cero("0");
    BigInteger uno("1");

    if (big == cero) {
    }
    else{
        BigInteger dividido(*this); 
        BigInteger ans("0");
        while (big <= dividido) {
            dividido.substract(big);
            ans.add(uno);
        }
        vec = ans.vec;
    }
}
/*
función remainder
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: 
DESCRIPCION:Esta función calcula el residuo de la division de el valor representado por el objeto BigInteger pasado como parámetro al objeto actual
*/
void BigInteger::remainder(BigInteger& big) {
    BigInteger cero("0");
    if (big == cero) {
    }
    else{
        BigInteger dividido(*this); 
        while (big <= dividido) {
            dividido.substract(big);
        }
        vec = dividido.vec;
    }
}
/*
función toString
ENTRADA: Ninguna
SALIDA: Una cadena de texto que representa al objeto BigInteger
DESCRIPCION:Esta función transforma el objeto BigInteger actual a una cadena de texto 
*/
string BigInteger::toString() {
    string ans;
    if (negativo)
        ans += '-';
    for (int i = vec.size() - 1; i >= 0; i--) {
        ans += to_string(vec[i]);
    }
    return ans;
}
/*
Función operator+
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: un objeto BigInteger que representa la suma del objeto BigInteger actual y 'big'.
DESCRIPCIÓN: Esta función realiza la suma del valor representado por el objeto BigInteger pasado como parámetro ('big') al objeto BigInteger actual.
*/
BigInteger BigInteger::operator+(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.add(big);
    return ans;
}

/*
Función operator-
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: un objeto BigInteger que representa la resta del objeto BigInteger actual y 'big'.
DESCRIPCIÓN: Esta función realiza la resta del valor representado por el objeto BigInteger pasado como parámetro ('big') al objeto BigInteger actual.
*/
BigInteger BigInteger::operator-(BigInteger& big){
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.substract(big);
    return ans;

}
/*
Función operator*
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: un objeto BigInteger que representa el producto del objeto BigInteger actual y 'big'.
DESCRIPCIÓN: Esta función realiza la multiplicacion del valor representado por el objeto BigInteger pasado como parámetro ('big') al objeto BigInteger actual.
*/
BigInteger BigInteger::operator*(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.product(big);
    return ans;
}
/*
Función operator/
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: un objeto BigInteger que representa la division del objeto BigInteger actual y 'big'.
DESCRIPCIÓN: Esta función realiza la division del valor representado por el objeto BigInteger pasado como parámetro ('big') al objeto BigInteger actual.
*/
BigInteger BigInteger::operator/(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.quotient(big);
    return ans;
}
/*
Función operator%
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA: un objeto BigInteger que representa el residuo del objeto BigInteger actual y 'big'.
DESCRIPCIÓN: Esta función calcula el residuo del valor representado por el objeto BigInteger pasado como parámetro ('big') al objeto BigInteger actual.
*/

BigInteger BigInteger::operator%(BigInteger& big) {
    BigInteger ans(*this);
    ans.negativo = negativo;
    ans.remainder(big);
    return ans;
}

//analizadoras

/*
función operator==
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA:  un valor booleano que indica si el objeto BigInteger actual es igual al objeto 'big'
DESCRIPCION: Esta función compara si el objeto BigInteger actual es igual al objeto 'big'.
*/
bool BigInteger::operator==( BigInteger& big){
    bool ans = true;
    if(negativo != big.negativo)
        ans = false;
    if (vec.size() != big.vec.size()&& ans)
        ans = false;
    for (int i = vec.size() - 1 && ans; i >= 0; i--) {
        if (vec[i] != big.vec[i])
            ans = false;
    }
    return ans;
}
/*
función operator<
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA:  un valor booleano que indica si el objeto BigInteger actual es menor al objeto 'big'
DESCRIPCION: Esta función compara si el objeto BigInteger actual es menor al objeto 'big'.
*/
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
    if(!negativo && !big.negativo &&flag ){
        if (vec.size() < big.vec.size() && flag) {
            ans = true;
            flag = false;
        }
        if (vec.size() > big.vec.size() && flag) {
            ans = false;
            flag = false;
        }
    
    }
    if(negativo && big.negativo && flag ){
        if (vec.size() < big.vec.size() && flag) {
            ans = false;
            flag = false;
        }
        if (vec.size() > big.vec.size() && flag) {
            ans = true;
            flag = false;
        }
    
    }
    else if (negativo && big.negativo){
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
/*
función operator<=
ENTRADA: un objeto BigInteger pasado por referencia
SALIDA:  un valor booleano que indica si el objeto BigInteger actual es menor o igual al objeto 'big'
DESCRIPCION: Esta función compara si el objeto BigInteger actual es menor o igual al objeto 'big'.
*/
bool BigInteger::operator<=(BigInteger& big) {
    return operator<(big) || operator==(big);
}

/*
función add
ENTRADA: una lista pasada por referencia
SALIDA: un objeto que representa la suma de todos los objetos BigInteger en la lista
DESCRIPCION: Esta función suma todos lo elementos dentro de la lista.
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger>& lista) {
    BigInteger suma;
    
    for (list<BigInteger>::iterator it = lista.begin(); it != lista.end(); ++it) {
        suma.add(*it);
    }
    
    return suma;
}
/*
función add
ENTRADA: una lista pasada por referencia
SALIDA: un objeto que representa el producto de todos los objetos BigInteger en la lista
DESCRIPCION: Esta función multiplica todos lo elementos dentro de la lista.
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& lista) {
    BigInteger producto("1");
    for (list<BigInteger>::iterator it = lista.begin(); it != lista.end(); ++it) {
        producto.product(*it);
    }
    
    return producto;
}



