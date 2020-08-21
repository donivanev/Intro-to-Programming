#include <iostream>
using namespace std;

const size_t maxPower = 50;
struct Poly
{
    double coefs[maxPower];
    size_t power;
};

void initializePolynom(Poly &x, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> x.coefs[i];
    }
    cin >> x.power;
}

void diff(Poly x, int n)
{
    size_t pow = x.power;

    for (int i = 0; i < n; i++)
    {
        x.coefs[i] *= x.power;
        x.power--;
    }

    cout << "First derivative: ";
    for (int i = 0; i < n; i++)
    {
        if (x.coefs[i] == 0)
        {
            break;
        }
        if (x.coefs[i] < 0)
        {
            cout << x.coefs[i] << "x^" << --pow;
        }
        else
        {
            if (i != 0)
            {
                cout << "+" << x.coefs[i] << "x^" << --pow;
            }
            else
            {
                cout << x.coefs[i] << "x^" << --pow;
            }
        }
    }
}

int main()
{
    Poly x;
    int n;
    cout << "Enter n: ";
    cin >> n;

    initializePolynom(x, n);
    diff(x, n);
}
