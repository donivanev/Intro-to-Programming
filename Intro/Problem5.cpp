#include <iostream>
#include <cmath>
using namespace std;

void isDivisible()
{
	int p;
	bool boolCondition;
	cout << "Enter p: ";
	cin >> p;

	boolCondition = (p % 4 == 0) || (p % 7 == 0);

	if (boolCondition) cout << "p can be divided by 4 or 7.";
	else cout << "p cannot be divided by 4 or 7.";
	cout << endl;
}

void hasRoots()
{
	int a, b, c, determinant;
	cout << "Enter a, b, c: ";
	cin >> a >> b >> c;

	determinant = b * b - 4 * a * c;
	if (determinant < 0) cout << "This equation has no real roots.";
	else cout << "This equation has real roots.";
	cout << endl;
}

void isInCircle()
{
	int x, y;
	cout << "Enter x and y: ";
	cin >> x >> y;

	if (sqrt(x * x + y * y) <= 5) cout << "The point is in the circle in third quadrant.";
	else cout << "The point is not in the circle in third quadrant.";
	cout << endl;
}

void is7InNumber()
{
	int number;
	cout << "Enter third digit number: ";
	cin >> number;

	int fDigit = number % 10;
	int sDigit = number / 10 % 10;
	int tDigit = number / 100;

	if (fDigit == 7 || sDigit == 7 || tDigit == 7) cout << "The number has 7 in its digits";
	else cout << "The number hasn't got 7 in its digits";
	cout << endl;
}

void digitsSequence()
{
	int number;
	cout << "Enter third digit number: ";
	cin >> number;

	int fDigit = number % 10;
	int sDigit = number / 10 % 10;
	int tDigit = number / 100;

	if (fDigit < sDigit && sDigit < tDigit && fDigit < tDigit) cout << "The digits of the number form regression.";
	else if (fDigit > sDigit && sDigit > tDigit && fDigit > tDigit) cout << "The digits of the number form progression.";
	else cout << "The digits of the number are not in a sequence.";
	cout << endl;
}

int main()
{
	isDivisible();
	hasRoots();
	isInCircle();
	is7InNumber();
	digitsSequence();
}