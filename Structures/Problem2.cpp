#include <iostream>
#include <cmath>
using namespace std;

const size_t maxPower = 50;
struct Poly
{
    double coefs[maxPower];
    size_t power;
};

struct NewPoly
{
    double coefs[maxPower];
    size_t power[maxPower];
};

void initializePolynoms(Poly &x1, Poly &x2, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cin >> x1.coefs[i];
    }
    cin >> x1.power;

    for (int i = 0; i < m; i++)
    {
        cin >> x2.coefs[i];
    }
    cin >> x2.power;
}

NewPoly prod(NewPoly &x, Poly x1, Poly x2, int n, int m, int *max)
{
    int min, index = 0;

    if (n >= m)
    {
        *max = n;
        min = m;
    }
    else
    {
        *max = m;
        min = n;
    }

    int pow1 = x1.power;
    int pow2 = x2.power;

    for (int i = 0; i < *max; i++)
    {
        for (int j = 0; j < min; j++)
        {
            x.coefs[index] = x1.coefs[i] * x2.coefs[j];
            x.power[index] = pow1 + pow2;
            pow2--;
            index++;
        }
        pow1--;
        pow2 = x2.power;
    }

    return x;
}

void printPolynomial(NewPoly x, int n, int m)
{

    for (int i = 0; i < n * m; i++)
    {
        if (x.coefs[i] == 0)
        {
            break;
        }
        if (x.coefs[i] < 0)
        {
            cout << x.coefs[i] << "x^" << --x.power[i] + 1;
        }
        else
        {
            if (i != 0)
            {
                cout << "+" << x.coefs[i] << "x^" << --x.power[i] + 1;
            }
            else
            {
                cout << x.coefs[i] << "x^" << --x.power[i] + 1;
            }
        }
    }
}

int main()
{
    Poly x1;
    Poly x2;
    NewPoly x;

    int n, m, max = INT32_MIN;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    initializePolynoms(x1, x2, n, m);
    prod(x, x1, x2, n, m, &max);
    printPolynomial(x, n, m);

	return 0;
}