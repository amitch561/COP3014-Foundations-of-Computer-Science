//Alexandra Sanzare
//04/15/2023
//Declarations for rational class and the functions of it
#ifndef RATIONALS_AS_H
#define RATIONALS_AS_H

#include <iostream>

namespace Sanzare {
    using namespace std;
    class Rational {
    private:
        int num, den;
        void reduce();

    public:
        Rational();
        Rational(int); //constructor taking 1 integer
        Rational(int, int); //constructor taking 2 integers
      //overloaded functions using different arithmetic operators
        friend istream& operator>>(istream&, Rational&);
        friend ostream& operator<<(ostream&, const Rational&);
        friend bool operator==(const Rational&, const Rational&);
        friend bool operator<(const Rational&, const Rational&);
        friend bool operator<=(const Rational&, const Rational&);
        friend bool operator>(const Rational&, const Rational&);
        friend bool operator>=(const Rational&, const Rational&);
        friend bool operator!=(const Rational&, const Rational&);
        friend Rational operator+(const Rational&, const Rational&);
        friend Rational operator-(const Rational&, const Rational&);
        friend Rational operator*(const Rational&, const Rational&);
        friend Rational operator/(const Rational&, const Rational&);
        Rational operator-() const;
    };
}

#endif
