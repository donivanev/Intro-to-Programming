#include <iostream>
using namespace std;

double gcd(unsigned m, unsigned int n)
{
    if (n != 0)
    {
        return gcd(n, m % n);
    }
    
    return m;
}

int main()
{
    unsigned int m;
    unsigned int n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    cout << gcd(m, n);

    return 0;
}
