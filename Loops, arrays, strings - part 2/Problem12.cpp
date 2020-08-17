#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    char a[20][20][9];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> a[i][j][k];
            }
        }
    }

    int k = 0, l = 0;

    while (k < n && l < n) 
    {
        for (int i = l; i < n; ++i) 
        {
            for (int o = 0; o < n; o++)
            {
                cout << a[k][i][o];
            }
        }
        k++;

        for (int i = k; i < n; i++) 
        {
            for (int o = 0; o < n; o++)
            {
                cout << a[i][n - 1][o];
            }
        }
        n--;

        if (k < n) 
        {
            for (int i = n - 1; i >= l; --i) 
            {
                for (int o = 0; o < n; o++)
                {
                    cout << a[n - 1][i][o];
                }
            }
            n--;
        }

        if (l < n) 
        {
            for (int i = n - 1; i >= k; --i) 
            {
                for (int o = 0; o < n; o++)
                {
                    cout << a[i][l][o];
                }
            }
            l++;
        }
    }

    return 0;
}