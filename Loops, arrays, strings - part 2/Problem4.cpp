#include <iostream>
using namespace std;

/*int main()
{
    int n, m;
    bool hasPoints = false;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int arr[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int minRow = arr[i][0], colIndex = 0;

        for (int j = 1; j < m; j++)
        {
            if (minRow > arr[i][j])
            {
                minRow = arr[i][j];
                colIndex = j;
            }
        }

        int k;
        for (k = 0; k < n; k++)
        {
            if (minRow < arr[k][colIndex]) break;
        }

        if (k == n)
        {
            hasPoints = true;
            cout << "Saddle Point: " << minRow;
        }
    }

    if (hasPoints != true) cout << "No saddle points.";

    return 0;
}*/