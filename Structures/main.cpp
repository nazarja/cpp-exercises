#include <iostream>

using namespace std;

struct Date 
{
    int day;
    int month;
    int year;
};

int main()
{
	Date date;

	date.day = 19;
	date.month = 4;
	date.year = 1984;

	cout << date.day << "/" << date.month << "/" << date.year << endl;	
}