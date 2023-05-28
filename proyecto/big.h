
#include <vector>
#include <string>
#include <list>

#ifndef BIG_H
#define BIG_H

using namespace std;

class BigInteger{
    vector<int> vec;
    bool negativo;
    public:
        BigInteger();
        BigInteger(const string e);
        BigInteger(const BigInteger& big);
        void add(BigInteger& big);
        void product(BigInteger& big);
        void substract(BigInteger& big);
        void quotient(BigInteger& big);
        void remainder(BigInteger& big);
        void pow(int e);
        string toString();
        //sobrecarga
        BigInteger operator+(BigInteger& big);
        BigInteger operator-(BigInteger& big);
        BigInteger operator*(BigInteger& big);
        BigInteger operator/(BigInteger& big);
        BigInteger operator%(BigInteger& big);
        bool operator==( BigInteger& big) ;
        bool operator<(BigInteger& big) ;
        bool operator<=( BigInteger& big);

        //estaticas
        static BigInteger sumarListaValores(list<BigInteger>& lista);
        static BigInteger multiplicarListaValores(list<BigInteger>& lista);
};

#endif
