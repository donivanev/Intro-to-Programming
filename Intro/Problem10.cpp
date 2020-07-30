#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k;
	cout << "Enter n and k: ";
	cin >> n >> k;
    int number = n;
    bool flag = false;

    while (number > 0) 
    {
        int digit = number % k; 
        if (digit > 1) cout << "No. ";
        if (digit == 1) 
        {
            if (flag) cout << "No. ";
            flag = true;
        }
        number /= k;
    }

    flag ? cout << n << " is power of " << k : cout << n << " is not power of " << k;

	return 0;
}