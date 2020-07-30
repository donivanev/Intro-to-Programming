#include <iostream>
using namespace std;

int main()
{
	int year;
	cout << "Enter year: ";
	cin >> year;

    bool isLeap = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	
	isLeap ? cout << "Leap Year" : cout << "Not a Leap Year";

	return 0;
}