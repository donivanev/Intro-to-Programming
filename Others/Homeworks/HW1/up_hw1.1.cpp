#include <iostream>
#include <cmath>
using namespace std;

bool isIn(double x1, double x2, double y1, double y2, 
		  double rightBotX1, double rightBotX2, double leftTopY1, double leftTopY2)
{
	if (x1 >= rightBotX2 || x2 >= rightBotX1)
	{
		return false;
	}
	else if (leftTopY1 <= y2 || leftTopY2 <= y1)
	{
		return false;
	}
	
	return true;
}

int main()
{
	double x1, y1, w1, h1, x2, y2, w2, h2, area = 0;

	cin >> x1 >> y1 >> w1 >> h1;
	cin >> x2 >> y2 >> w2 >> h2;

	double leftTopY1 = y1 + h1;
	double rightBotX1 = x1 + w1;
	double leftTopY2 = y2 + h2;
	double rightBotX2 = x2 + w2;

	if (isIn(x1, x2, y1, y2, rightBotX1, rightBotX2, leftTopY1, leftTopY2))
	{
		double areaTrivial = abs((w1 - x2)) * abs((h1 - y2));
		area = areaTrivial;
		cout << area;
	}
	else
	{
		cout << area;
	}

	return 0;
}