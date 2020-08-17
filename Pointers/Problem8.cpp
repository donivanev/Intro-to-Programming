#include <iostream>
using namespace std;

long getmaxRecursion(long* pmax, size_t n)
{ 
	if (n == 0)
	{
		return *pmax;
	}

	long a;
	cin >> a;

	if (*pmax < a)
	{
		*pmax = a;
	}

	return getmaxRecursion(pmax, --n);
}

void getmax(long *pmax, size_t n)
{
	int a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (*pmax < a)
		{
			*pmax = a;
		}
	}

	cout << *pmax;
}

int main()
{
	long n, max;
	cout << "Enter n: ";
	cin >> n;

	//getmax(&max, n);
	cout << getmaxRecursion(&max, n);

	return 0;
}