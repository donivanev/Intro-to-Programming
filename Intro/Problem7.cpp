#include <iostream>
using namespace std;

int main()
{
	int x, k, counter = 0;
	cout << "Enter x and k: ";
	cin >> x >> k;

	while (x != 0)
	{
		int remainder = x % 10;
		x /= 10;
		counter++;

		if (counter == k)
		{
			cout << remainder << endl;
			break;
		}
	}

	return 0;
}