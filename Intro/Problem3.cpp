#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, h;
	cout << "Enter side and height: ";
	cin >> a >> h;

	cout << "Triangle area: " << (a * h) / 2 << endl;

	cout << "Now enter three sides: ";
	cin >> a >> b >> c;

	int p = (a + b + c) / 2;
	cout << "Triangle area: " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;

	return 0;
}