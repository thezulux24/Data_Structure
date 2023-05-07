
#include <vector>
#include <string>

#ifndef BIG_H
#define BIG_H

using namespace std;
typedef string Elemento;

class BigInteger{
    vector<int> vec;
  
    public:
        BigInteger(Elemento e);
        BigInteger(const BigInteger &big);
        void add(BigInteger big);
        void product(BigInteger big);
        void substract(BigInteger big);
        void quotient(BigInteger big);
        void remainder(BigInteger big);
        void pow(BigInteger big);
        string toString();
        //sobrecarga
        BigInteger operator+(BigInteger big);
        BigInteger operator-(BigInteger big);
        BigInteger operator*(BigInteger big);
        BigInteger operator/(BigInteger big);
        BigInteger operator%(BigInteger big);
        bool operator==(const BigInteger& big) const;
        bool operator<(const BigInteger& big) const;
        bool operator<=(const BigInteger& big) const;
};

#endif
