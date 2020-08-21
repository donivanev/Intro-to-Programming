#include <iostream>
#include <cmath>
using namespace std;

struct Polar
{
	double r;
	double fi;
};

struct Rect
{
	double x;
	double y;
};

void enterPolar(Polar p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].r;
		cin >> p[i].fi;
	}
}

void enterRect(Rect r[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> r[i].x;
		cin >> r[i].y;
	}
}

void polarToRect(Polar p[], Rect r[], int n)
{
	for (int i = 0; i < n; i++)
	{
		r[i].x = p[i].r * cos(p[i].fi);
		r[i].y = p[i].r * sin(p[i].fi);
	}
}

void rectToPolar(Rect r[], Polar p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		p[i].r = sqrt(pow(r[i].x, 2) + pow(r[i].y, 2));
		p[i].fi = atan(r[i].y / r[i].x);
	}
}

void printPolarPoints(Polar p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << p[i].r << " " << p[i].fi << endl;
	}
}

void printRectPoints(Rect r[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << r[i].x << " " << r[i].y << endl;
	}
}

int main()
{
	Rect r[5];
	Polar p[5];
	char choice;
	cout << "Enter r for cartesian coordinates or p for polar: ";
	cin >> choice;

	int n;
	cout << "Enter n: ";
	cin >> n;

	if (choice == 'r')
	{
		enterRect(r, n);
		rectToPolar(r, p, n);
		printPolarPoints(p, n);
	}
	else if (choice == 'p')
	{
		enterPolar(p, n);
		rectToPolar(r, p, n);
		printRectPoints(r, n);
	}

	return 0;
}