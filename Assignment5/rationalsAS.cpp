//Alexandra Sanzare
//04/15/2023
//has function definitions from rationalsAS.h
#include "rationalsAS.h"

namespace {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

namespace Sanzare {
   //default constructor setting the numerator to 0 and denominator to 1
    Rational::Rational() : num(0), den(1) {}

    Rational::Rational(int n) : num(n), den(1) {}

    Rational::Rational(int n, int d) : num(n), den(d) {
        reduce();
    }
   //reducing the fraction to simplest form
    void Rational::reduce() {
        if (den < 0) {
            num *= -1;
            den *= -1;
        }

        int div = gcd(abs(num), den);
        num /= div;
        den /= div;
    }
  //overloading the input operators
    istream& operator>>(istream& is, Rational& r) {
        char c;
        is >> r.num >> c >> r.den;
        r.reduce();
        return is;
    }
   //overloading the equal operator
    ostream& operator<<(ostream& os, const Rational& r) {
        os << r.num << "/" << r.den;
        return os;
    }
  //overloading the less than operator
    bool operator==(const Rational& r1, const Rational& r2) {
        return r1.num * r2.den == r2.num * r1.den;
    }
  //overloading the greater than operator
    bool operator<(const Rational& r1, const Rational& r2) {
        return r1.num * r2.den < r2.num * r1.den;
    }
  //overloading the less than or equal to operator
    bool operator<=(const Rational& r1, const Rational& r2) {
        return r1.num * r2.den <= r2.num * r1.den;
    }
  //overloading the greater than operator
    bool operator>(const Rational& r1, const Rational& r2) {
        return r1.num * r2.den > r2.num * r1.den;
    }
  //overloading the greater than or equal to operator
    bool operator>=(const Rational& r1, const Rational& r2) {
        return r1.num * r2.den >= r2.num * r1.den;
    }
  //overloading the not equal to operator
    bool operator!=(const Rational& r1, const Rational& r2) {
        return r1.num * r2.den != r2.num * r1.den;
    }
  //overloading the addtion operator
    Rational operator+(const Rational& r1, const Rational& r2) {
        int num = r1.num * r2.den + r2.num * r1.den;
        int den = r1.den * r2.den;
        return Rational(num, den);
    }
  //overloading the subtraction operator
    Rational operator-(const Rational& r1, const Rational& r2) {
        int num = r1.num * r2.den - r2.num * r1.den;
        int den = r1.den * r2.den;

return Rational(num, den);
}

Rational operator*(const Rational& r1, const Rational& r2) {
int num = r1.num * r2.num;
int den = r1.den * r2.den;
return Rational(num, den);
}

Rational operator/(const Rational& r1, const Rational& r2) {
int num = r1.num * r2.den;
int den = r1.den * r2.num;
return Rational(num, den);
}

Rational Rational::operator-() const {
return Rational(-num, den);
}
}

