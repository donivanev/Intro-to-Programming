#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 2; i < n; i += 3)
	{
		sum += i;
	}

	cout << sum;

	return 0;
}