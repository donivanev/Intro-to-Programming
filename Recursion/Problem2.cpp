#include <iostream>
using namespace std;

double mult(unsigned m, unsigned int n)
{
    if (n == 1)
    {
        return m;
    }

    return m + mult(m, n - 1);
}

int main()
{
    unsigned int m;
    unsigned int n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    cout << mult(m, n);

    return 0;
}