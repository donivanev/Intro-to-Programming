#include <iostream>
using namespace std;

void perfectNumber(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }

        cout << sum << " " << i << endl;
        if (sum == i) cout << i << endl;
        sum = 0;
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    perfectNumber(n);

    return 0;
}