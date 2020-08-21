#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};

void enterElements(Point p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x;
		cin >> p[i].y;
	}
}

void sortPoints(Point p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].x >= p[j + 1].x && p[j].y > p[j + 1].y)
			{
				double helper = p[j].x;
				p[j].x = p[j + 1].x;
				p[j + 1].x = helper;

				double helper2 = p[j].y;
				p[j].y = p[j + 1].y;
				p[j + 1].y = helper2;
			}
		}
	}
}

void printPoints(Point p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << p[i].x << " " << p[i].y << endl;
	}
}

int main()
{
	Point p[5];
	int n;
	cout << "Enter n: ";
	cin >> n;

	enterElements(p, n);
	sortPoints(p, n);
	printPoints(p, n);

	return 0;
}