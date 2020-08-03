#include <iostream>
using namespace std;

void scalarProduct(int n)
{
    int a, b;

    for (int i = 0; i < 2 * n; i++)
    {
        if (i == 0)
        cout << "Enter a vectors: ";
        if (i <= n - 1)
        cin >> a;

        if (i == n - 1)
        cout << "Enter b vectors: ";
        if (i > n - 1)
        cin >> b;
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    scalarProduct(n);

    return 0;
}
