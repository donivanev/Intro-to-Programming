#include <iostream>
using namespace std;

int getMax(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int max(int n, int *a)
{
	if (n == 1)
	{
		return a[0];
	}

	return getMax(max(n - 1, a), a[n - 1]);
}

/*int main()
{
    unsigned int n;
    cout << "Enter n: ";
    cin >> n;
	int a[50];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

    cout << max(n, a);

    return 0;
}*/
