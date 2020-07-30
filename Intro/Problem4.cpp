#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, y;
	cout << "Enter coordinates: ";
	cin >> x >> y;

	if (x > 0 && y > 0)
	{
		cout << "The point is in first quadrant." << endl;
	}
	else if (x < 0 && y > 0)
	{
		cout << "The point is in second quadrant." << endl;
	}
	else if (x < 0 && y < 0)
	{
		cout << "The point is in third quadrant." << endl;
	}
	else if (x > 0 && y < 0)
	{
		cout << "The point is in fourth quadrant." << endl;
	}
	else if (x == 0 && y == 0)
	{
		cout << "The point is on the origin." << endl;
	}
	else if (y == 0)
	{
		cout << "The point is on the x-axis." << endl;
	}
	else if (x == 0)
	{
		cout << "The point is on the y-axis." << endl;
	}

	return 0;
}