/*Albert Mitchell,
*04/8/2023,
*Assignment 5 - Implementation File*/
#include<iostream>
#include"rationalsSTAM.h"
#include<algorithm>


using std::cout;
using std::cin;

namespace
{
	void read_rational(istream& ins, int& new_numerator, int& new_denominator);
	
}



namespace rationalnumberMitchell
{

	RationalNumber::RationalNumber()
	{
		numerator = 0;
		denominator = 1;
	}
	RationalNumber::RationalNumber(int new_numerator)
	{
		SetNumerator(new_numerator);
		denominator = 1;
	}
	RationalNumber::RationalNumber(int new_numerator, int new_denominator)
	{
		
		SetNumerator(new_numerator);
		SetDenominator(new_denominator);
	}
	void RationalNumber::simplify()
	{
		int a = numerator;
		int b = denominator;
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		int gcd = a;

		// simplify the numerator and denominator
		numerator /= gcd;
		denominator /= gcd;

		// handle negative signs
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}

	
	void RationalNumber::SetNumerator(int new_numerator)
	{
		numerator = new_numerator;

	}
	void RationalNumber::SetDenominator(int new_denominator)
	{
		if (new_denominator == 0)
		{
			cout << (" The fraction will be undefined whenever the denomimator is 0\n");
			std::exit(2);
		}
		else
		{

			denominator = new_denominator;
		}
	}

	int RationalNumber::GetNumerator()
	{
		return numerator;
	}
	int RationalNumber::GetDenominator()
	{
		return denominator;
	}

	//FRIEND FUNCTIONS - OVERLAD
	//ADDITION
	RationalNumber operator+ (const RationalNumber& r1, const RationalNumber& r2)
	{

		int num, den;
		RationalNumber new_rational;
		num = (r1.numerator * r2.denominator) + (r1.denominator * r2.numerator);
		den = r2.denominator * r1.denominator;
		
		RationalNumber r_result(num, den);
		r_result.simplify();
		return r_result;

	}
	//MULTIPLICATION
	RationalNumber operator*(const RationalNumber r1, const RationalNumber r2)
	{
		int num, den;
		num = (r1.numerator * r2.numerator);
		den = (r1.denominator * r2.denominator);
		if (den == 0)
		{
			cout << "\nError: Multiplication of fractions have caused denominator to be zero." << std::endl << " Solution is (undefined)." << " Default values returned > ";
			return RationalNumber();
		}
		else
		{
			RationalNumber r_result(num, den);
			r_result.simplify();
			return r_result;
		}
	}
	//SUBTRACTION
	RationalNumber operator- (const RationalNumber r1, const RationalNumber r2)
	{

		int num, den;
		num = ((r1.numerator * r2.denominator) - (r2.numerator * r1.denominator));
		den = (r1.denominator * r2.denominator);
		if (den == 0)
		{
			cout << "\nError: Subtraction of fractions have caused denominator to be zero." << std::endl << " Solution is (undefined)." << " Default values returned > ";
			return RationalNumber();
		}
		else
		{
			RationalNumber r_result(num, den);
			r_result.simplify();
			return r_result;
		}
		
	}
	//DIVISION
	RationalNumber operator/ (const RationalNumber r1, const RationalNumber r2)
	{

		int num, den;
		num = (r1.numerator * r2.denominator);
		den = (r2.numerator * r1.denominator);
		
		if (den == 0) 
		{
			cout << "\nError: Division of fractions have caused denominator to be zero." << std::endl << "Solution is (undefined)" << " Default values returned > ";
			return RationalNumber();
		}
		else
		{
			RationalNumber r_result(num, den);
			r_result.simplify();
			return r_result;
		}

	}
	//NEGATIVE FRACTION
	RationalNumber operator - (const RationalNumber r)
	{
		if ((r.numerator < 0) && (r.denominator < 0))
		{
			return RationalNumber((-r.numerator), r.denominator);
		}
		else if ((r.denominator < 0) || (r.numerator < 0))
		{
			return RationalNumber((-r.numerator), r.denominator);
		}
		
		else
			return RationalNumber(r.numerator, r.denominator);
	}
	//FRIEND BOOL - OVERLOAD
	bool operator < (const RationalNumber r1, const RationalNumber r2)
	{
		return ((r1.numerator * r2.denominator) < (r2.numerator * r1.denominator));

	}
	bool operator <= (const RationalNumber r1, const RationalNumber r2)
	{
		return ((r1.numerator * r2.denominator) <= (r2.numerator * r1.denominator));
	}
	bool operator > (const RationalNumber r1, const RationalNumber r2)
	{
		return ((r1.numerator * r2.denominator) > (r2.numerator * r1.denominator));

	}
	bool operator >= (const RationalNumber r1, const RationalNumber r2)
	{
		return ((r1.numerator * r2.denominator) >= (r2.numerator * r1.denominator));
	}
	bool operator == (const RationalNumber r1, const RationalNumber r2)
	{
		if ((r1.numerator * r2.denominator) == (r2.numerator * r1.denominator))
		{
			return true;
		}
		else return false;
	}
	bool operator != (const RationalNumber r1, const RationalNumber r2)
	{
		return ((r1.numerator * r2.denominator) != (r2.numerator * r1.denominator));

	}

	ostream& operator <<(ostream& outs, RationalNumber r)
	{
		outs << r.numerator << '/' << r.denominator;
		return outs;

	}
	istream& operator >>(istream& ins, RationalNumber& r)
	{
		
		read_rational(ins, r.numerator, r.denominator);
		return ins;
	}
}
namespace
{
	void read_rational(istream& ins, int& new_numerator, int& new_denominator)
	{
		char slash;
		
		ins >> new_numerator;
			if (ins.fail())
			{
				cout << "Illegal input to Numerator detected.";
				exit(1);								
			}
		if (ins.peek() == ' ' || ins.peek() == '\n')
			{
				return;
			}

		ins >> slash;
			if (slash == '/')
			{
			ins >> new_denominator;
				if (ins.fail())
				{
				cout << "Illegal input to Denominator detected.";
				exit(1);
				}
			}
			else if (slash != '/')
			{
			cout << "Expected '/' after numerator.";
			exit(1);
			}						
	}
}//Namespace