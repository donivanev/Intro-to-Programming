#include <iostream>
using namespace std;

void sortRows(int n, int m, int a[][50])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = j + 1; k < m; ++k)
            {
                if (a[i][j] > a[i][k])
                {
                    int helper = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = helper;
                }
            }
        }
    }
}

void sortCols(int n, int m, int a[][50])
{
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int k = i + 1; k < m; ++k)
            {
                if (a[i][j] > a[k][j])
                {
                    int helper = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = helper;
                }
            }
        }
    }
}

void printMatrix(int n, int m, int a[][50])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

/*int main()
{
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int a[50][50];
    int a2[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a2[i][j] = a[i][j];
        }
    }

    sortRows(n, m, a);
    cout << "Sorted by rows: " << endl;
    printMatrix(n, m, a);

    sortCols(n, m, a2);
    cout << "Sorted by columns: " << endl;
    printMatrix(n, m, a2);

    return 0;
}*/