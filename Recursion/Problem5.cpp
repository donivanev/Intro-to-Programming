#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
       return 0;
    }

    return n + sum(n - 1);
}

int mult1toN(unsigned n, unsigned int k, int c)
{
    if (c > n)
    {
        return 1;
    }

    return c * mult1toN(n, k, c + k);
}

int main()
{
    unsigned int n;
    unsigned int k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    cout << mult1toN(n, k, 1);

    return 0;
}
