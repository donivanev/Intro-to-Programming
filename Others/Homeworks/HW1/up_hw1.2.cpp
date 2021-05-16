#include <iostream>
#include <cmath>
using namespace std;

void processData(int number, int &maskM, int &maskH1, int &maskH2, int &maskFormat)
{
	maskM = maskM | (maskM << 1) | (maskM << 2) | (maskM << 3) | (maskM << 4) | (maskM << 5);
	maskM &= number;

	maskH1 = (maskH1 << 6) | (maskH1 << 7) | (maskH1 << 8) | (maskH1 << 9);
	maskH1 &= number;
	maskH1 >>= 6;

	maskH2 = (maskH2 << 10) | (maskH2 << 11);
	maskH2 &= number;
	maskH2 >>= 10;

	maskFormat <<= 12;
	maskFormat &= number;
	maskFormat >>= 12;
}

void calculateDifference(int xHours, int xMinutes, int yHours, int yMinutes)
{
	int diffM = abs(xMinutes - yMinutes);
	int diffH = abs(xHours - yHours);

	if (diffM == 0)
	{
		cout << "diff " << diffH << ":00";
	}
	else if (xHours == yHours)
	{
		cout << "diff " << diffM;
	}
	else if (xHours > yHours)
	{
		if (xMinutes > yMinutes)
		{
			cout << "diff " << diffH << ":" << diffM;
		}
		else if (xMinutes < yMinutes)
		{
			cout << "diff " << diffH - 1 << ":" << 60 - diffM;
		}
	}
	else if (xHours < yHours)
	{
		if (xMinutes > yMinutes)
		{
			cout << "diff " << diffH - 1 << ":" << 60 - diffM;
		}
		else if (xMinutes < yMinutes)
		{
			cout << "diff " << diffH << ":" << diffM;
		}
	}
}

int main()
{
	int x, y, xHours, xMinutes, yHours, yMinutes, maskM = 1, maskH1 = 1, maskH2 = 1, maskFormat = 1;
	cin >> x;
	cin >> y;

	processData(x, maskM, maskH1, maskH2, maskFormat);

	if(maskFormat == 0)
	{
		xHours = maskH2 * 10 + maskH1;
		xMinutes = maskM;

		if (xHours > 12 || xMinutes > 59)
		{
			cout << "invalid format" << endl;
			return 0;
		}

		cout << xHours << ":" << xMinutes;
		cout << endl;
	}
	else
	{ 
		xHours = maskH2 * 10 + maskH1;
		xMinutes = maskM;

		if (xHours > 24 || xMinutes > 59)
		{
			cout << "invalid format" << endl;
			return 0;
		}

		cout << xHours << ":" << xMinutes;
		cout << endl;
	}

	processData(y, maskM = 1, maskH1 = 1, maskH2 = 1, maskFormat = 1);

	if (maskFormat == 0)
	{
		yHours = maskH2 * 10 + maskH1;
		yMinutes = maskM;

		if (yHours > 12 || yMinutes > 59)
		{
			cout << "invalid format" << endl;
			return 0;
		}

		cout << yHours << ":" << yMinutes;
		cout << endl;
	}
	else
	{
		yHours = maskH2 * 10 + maskH1;
		yMinutes = maskM;

		if (yHours > 24 || yMinutes > 59)
		{
			cout << "invalid format" << endl;
			return 0;
		}

		cout << yHours << ":" << yMinutes;
		cout << endl;
	}

	calculateDifference(xHours, xMinutes, yHours, yMinutes);

	return 0;
}