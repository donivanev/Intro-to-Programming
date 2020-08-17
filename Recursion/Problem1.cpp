#include <iostream>
using namespace std;

double ermit(double x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 2 * x;
    }

    return 2 * x * ermit(x, n - 1) + 2 * (n - 1) * ermit(x, n - 2);
}

int main()
{
    unsigned int n;
    double x;

    cout << ermit(5, 5);

    return 0;
}
