/*Name: Albert Mitchell, 
*Class: COP3014,
Project: Assignment 4, 
Date: 03/30/2023 */


#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<chrono>
using namespace std;
int DaysinMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
class DayOfYear
{
public:
    DayOfYear();    //initializes day and month to 01/01
    DayOfYear(int the_month, int the_day);
    void input();
    void output();
    void set_date(int new_month, int new_day);  //setter function or mutator function
    void set_month(int new_month);
    void set_day(int new_day);
    //Precondition: new_month and new_day form a possible date.
    //Postcondition: The date is reset according to the arguments.
    int get_month();   //getter function or accessor function
    //Returns the month, 1 for January, 2 for February, etc.
    int get_day();
    //Returns the day of the month.
    friend bool equal(DayOfYear date1, DayOfYear date2);
    //checks for equality of two dates
    friend bool after(DayOfYear date1, DayOfYear date2);
    //checks to see if date1 occurs after date2

private:
    void check_date();
    int month;
    int day;
};

class DateYear :public DayOfYear
{
    friend bool DateCompare(DateYear year_one, DateYear year_two);

private:
    int year;

public:
    DateYear();
    DateYear(int new_year);
    DateYear(int new_month, int new_day);
    DateYear(int new_month, int new_day, int new_year);
    int get_year();
    void set_year(int new_year);
    void input();
    void output(ostream& outs);
    void BDCountdown(DateYear Birthday);
    bool isLeapYear(int new_year);

 };

int main()
{
    
    DateYear testyear(11,9,2023),test2(2024), test3(4,5), year, Birthday(10, 12, 2023);
    
    testyear.output(cout);
    test2.output(cout);
    test3.output(cout);
    year.input();
    year.output(cout);
    DateYear year_one(1988), Year_two(1989);
    Birthday.BDCountdown(Birthday);
    
    
    cout << "\nPrints true(1) if year one is equal to year two or false(0) if it is not:\n" << DateCompare(test2, test3);
    return 0;
}

//Base class
DayOfYear::DayOfYear()
{
    month = 1;
    day = 1;
}
DayOfYear::DayOfYear(int the_month, int the_day)
{
    month = the_month;
    day = the_day;
}
void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> oct >> month;
    cout << "Enter the day of the month: ";
    cin >> oct >> day;
    check_date();
}
void DayOfYear::output()
{
    cout << "month = " << month << ", day = " << day << endl;
         check_date();
}
void DayOfYear::set_date(int new_month, int new_day)
{
    month = new_month;
    day = new_day;
    
    check_date();
}
void DayOfYear::set_month(int new_month)
{
    month = new_month;
}
void DayOfYear::set_day(int new_day)
{
    day = new_day;

}
void DayOfYear::check_date()
{
    if ((month < 1) || (month > 12))
    {   
        cout << "Illegal Month entered. Month cannot be less than 1 or greater than 12. Aborting program.\n";
        exit(1);
    }
    else if ((day < 1) || (day > 31))
    {
        cout << "Illegal day entered. Day cannot be less than 1 or greater than 31. Aborting program.\n";
        exit(1);

    }
}
int DayOfYear::get_month()
{
    return month;
}
int DayOfYear::get_day()
{
    return day;
}
bool equal(DayOfYear date1, DayOfYear date2)
{
    return (date1.day == date2.day && date1.month == date2.month);
}
bool after(DayOfYear date1, DayOfYear date2)
{
    return(date1.month > date2.month) || (date1.month == date2.month && date1.day > date2.day);
}

//Derived Class
DateYear::DateYear()
{
    year = 2023;
    set_date(1,1);
}
DateYear::DateYear(int new_year)
{
    set_year(new_year);
}
DateYear::DateYear(int new_month, int new_day, int new_year)
{
    set_year(new_year);
    set_date(new_month, new_day);
}
DateYear::DateYear(int new_month, int new_day)
{
    year = 2023;
    set_date(new_month, new_day);
}
int DateYear::get_year()
{
    return year;
}
void DateYear::set_year(int new_year)
{
    year = new_year;
    if (year < 1582)
    {
        cout << "Illegal operation detected, Year cannot be less than 1582. Gregorian Calender was first enacted in 1582";
        exit(1);
    }
}
void DateYear::input()
{
   int new_month;
   int new_day;
    cout << "Enter the month as a number: ";
    cin >> new_month;
    cout << "Enter the day of the month: ";
    cin >> new_day;
    cout << "Enter the year: ";
    cin >> year;
    set_date(new_month, new_day);
 }
void DateYear::BDCountdown(DateYear Birthday)
{
    time_t now = time(NULL);
    tm currentDate = {};
    localtime_s(&currentDate, &now);

    int currentYear = currentDate.tm_year + 1900;
    int currentMonth = currentDate.tm_mon + 1;
    int currentDay = currentDate.tm_mday;
    int days_left = 0;

    cout << "This is the current date " << currentMonth << "/" << currentDay << "/" << currentYear << "\n";

    if (currentMonth < Birthday.get_month() || (currentMonth == Birthday.get_month() && currentDay < Birthday.get_day()))
    {
        for (int i = currentMonth; i < Birthday.get_month(); i++)
        {
            days_left += DaysinMonth[i - 1];

            if (i == 2 && isLeapYear(currentYear))
            {
                days_left++;
            }
        }
        days_left += Birthday.get_day() - currentDay;
        cout << "There are " << days_left << " day(s) left to your birthday";
    }
    else
    {
        cout << "Birthday has already occured";
    }
}
void DateYear::output(ostream& outs)
{
    outs << setfill('0') <<setw(2) << get_month() << "/" << setw(2) << get_day() << "/" << year << endl;
   
}
//friend function
bool DateCompare(DateYear year_one, DateYear year_two)
{    
    return(year_one.year == year_two.year);
}
bool DateYear::isLeapYear(int new_year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
        return false;
}


//References
//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm#:~:text=To%20access%20date%20and%20time,as%20some%20sort%20of%20integer.