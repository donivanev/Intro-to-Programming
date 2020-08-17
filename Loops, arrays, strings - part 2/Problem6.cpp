#include <iostream>
using namespace std;

/*int main()
{
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int a[50][50];
    int b[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }

    int resultArray[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            resultArray[i][j] = 0;

            for (int k = 0; k < m; k++)
            {
                resultArray[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Result matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << resultArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/