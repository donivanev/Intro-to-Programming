#include <iostream>
using namespace std;

double sum(size_t n)
{
	if (n == 0) return 0;

	double a;
	cin >> a;

	return sum(--n) + a;
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	cout << sum(n);

	return 0;
}