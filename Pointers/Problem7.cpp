#include <iostream>
using namespace std;

double reverse(size_t n)
{
	int a;
	cin >> a;

	if (n > 1) 
	{
		reverse(n - 1);
	}

	cout << a << " ";

	return n;
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	reverse(n);

	return 0;
}