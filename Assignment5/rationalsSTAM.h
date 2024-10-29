/*Albert Mitchell, 
*04/8/2023, 
*Assignment 5 - Header File*/

#pragma once
#ifndef RATIONALSSTAM_h
#define RATIONALSSTAM_h
#include<fstream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;


namespace rationalnumberMitchell
{
	class RationalNumber
	{
		friend RationalNumber operator+ (const RationalNumber& r1, const RationalNumber& r2);
		friend RationalNumber operator* (const RationalNumber r1, const RationalNumber r2);
		friend RationalNumber operator- (const RationalNumber r1, const RationalNumber r2);
		friend RationalNumber operator/ (const RationalNumber r1, const RationalNumber r2);
		friend RationalNumber operator- (const RationalNumber r1);
		friend bool operator < (const RationalNumber r1, const RationalNumber r2);
		friend bool operator <= (const RationalNumber r1, const RationalNumber r2);
		friend bool operator > (const RationalNumber r1, const RationalNumber r2);
		friend bool operator >= (const RationalNumber r1, const RationalNumber r2);
		friend bool operator == (const RationalNumber r1, const RationalNumber r2);
		friend bool operator != (const RationalNumber r1, const RationalNumber r2);
		friend ostream& operator <<(ostream& outs, const RationalNumber r1);
		friend istream& operator >>(istream& ins, RationalNumber& r1);

	private:
		int numerator, denominator;
		
	public:
		RationalNumber();
		RationalNumber(int new_numerator);
		RationalNumber(int new_numerator, int new_denominator);

		void SetNumerator(int new_numerator);
		void SetDenominator(int new_denominator);

		int GetNumerator();
		int GetDenominator();
		void simplify();

	};
}
#endif