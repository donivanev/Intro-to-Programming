#include <iostream>
using namespace std;

int main()
{
	int years;
	cout << "Enter age: ";
	cin >> years;

    int days = 0.5 + (years * 365.25);
    int hours = days * 24;
    int minutes = hours * 60;
    int seconds = minutes * 60;

    cout << days << " days" << endl;
    cout << hours << " hours" << endl;
    cout << minutes << " minutes" << endl;
    cout << seconds << " seconds" << endl;

	return 0;
}