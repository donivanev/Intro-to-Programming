#include <iostream>
using namespace std;

int sumDigits(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + sumDigits(n / 10);
}

int toNumericalSystem(unsigned int n, unsigned int k)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % k + 10 * toNumericalSystem(n / k, k));
}

int main()
{
    unsigned int n;
    cout << "Enter n: ";
    cin >> n;

    cout << sumDigits(toNumericalSystem(n, 2));

    return 0;
}
