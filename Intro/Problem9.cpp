#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, counter = 0;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 0; i < 100; i++)
	{
		if ((int)(pow(i, 3) + 13 * i * n + pow(n, 3)) % 5 == 0 
			|| (int)(pow(i, 3) + 13 * i * n + pow(n, 3)) % 9 == 0)
		{
			counter++;
		}
	}

	cout << counter;

	return 0;
}