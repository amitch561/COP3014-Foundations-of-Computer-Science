/*Albert Mitchell,
*04/9/2023,
*Assignment 5 - Application File*/

#include<iostream>
#include"rationalsSTAM.h"
#include "rationalsAS.h"
#include<iomanip>

using std::cout;
using std::cin;


int main()
{
	 {
		using namespace rationalnumberMitchell;
		int menuoption;
		{								
			RationalNumber r1, r2;
			RationalNumber Sum, Division, Multiplication, Subtraction;
			//sum = r1 + r2;
			cout << "\nPlease enter two fractions in the form (1/1) or two solid integers(1) or a combination of both: " << std::endl;
			cout << "Please enter the first fraction/integer: ";
			cin >> r1;
			cout << "You entered: " << (r1) << std::endl;
			cout << "Please enter the second fraction/integer: ";
			cin >> r2;
			cout << "You entered: " << (r2) << std::endl;
			
			cout << "\nSum: " << (r1 + r2) << std::endl;
			cout << "Division: " << (r1 / r2) << std::endl;
			cout << "Subtraction: " << r1 - r2 << std::endl;
			cout << "Multiplication: " << (r1 * r2) << std::endl;
			cout << r1 << " == " << r2 << " is " << std::boolalpha << (r1 == r2) << std::endl;
			cout << r1 << " < " << r2 << " is " << std::boolalpha << (r1 < r2) << std::endl;
			cout << r1 << " <= " << r2 << " is " << std::boolalpha << (r1 <= r2) << std::endl;
			cout << r1 << " > " << r2 << " is " << std::boolalpha << (r1 > r2) << std::endl;
			cout << r1 << " >= " << r2 << " is " << std::boolalpha << (r1 >= r2) << std::endl;
			cout << r1 << " != " << r2 << " is " << std::boolalpha << (r1 != r2) << std::endl;
			

		}
		/*cout << " Would you like to repeat test? Please enter 1 (Continue) or 2 (Exit)>";
		cin >> menuoption;
		if ((menuoption != 1) && (menuoption != 2))
			while ((menuoption != 1) && (menuoption != 2))
			{
				cout << "Invalid Selection. Please enter 1 or 2 >";
				cin >> menuoption;
			}
		if (menuoption == 1)
		{
			cout << "Continuing...\n";
		}
		else if (menuoption == 2)
		{
			cout << "Exiting...\n\n";
			break;
		}


	} while (menuoption == 1);*/
	}
	 
	{
		using namespace Sanzare;
		{
			Rational r1, r2;
			cout << "\nTest from new namespace";
			cout << "\nPlease enter two fractions in the form (1/1) or two solid integers(1) or a combination of both: " << std::endl;
			cout << "Please enter the first fraction/integer: ";
			cin >> r1;
			cout << "You entered: " << (r1) << std::endl;
			cout << "Please enter the second fraction/integer: ";
			cin >> r2;
			cout << "You entered: " << (r2) << std::endl;
			cout << "\nSum: " << (r1 + r2) << std::endl;
			cout << "Division: " << (r1 / r2) << std::endl;
			cout << "Subtraction: " << r1 - r2 << std::endl;
			cout << "Multiplication: " << (r1 * r2) << std::endl;
			cout << r1 << " == " << r2 << " is " << std::boolalpha << (r1 == r2) << std::endl;
			cout << r1 << " < " << r2 << " is " << std::boolalpha << (r1 < r2) << std::endl;
			cout << r1 << " <= " << r2 << " is " << std::boolalpha << (r1 <= r2) << std::endl;
			cout << r1 << " > " << r2 << " is " << std::boolalpha << (r1 > r2) << std::endl;
			cout << r1 << " >= " << r2 << " is " << std::boolalpha << (r1 >= r2) << std::endl;
			cout << r1 << " != " << r2 << " is " << std::boolalpha << (r1 != r2) << std::endl;
			
			
		}
	}

	return 0;
}