#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    char a[30][30][6];

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

    char mainDiagonal[50];
    char reverseDiagonal[50];
    int index = 0, index2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == j)
                {
                    mainDiagonal[index] = a[i][j][k];
                    index++;
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            for (int k = 0; k <= n - 1; k++)
            {
                if (i == n - j - 1)
                {
                    reverseDiagonal[index2] = a[i][j][k];
                    index2++;
                }
            }
        }
    }

    mainDiagonal[index] = '\0';
    reverseDiagonal[index2] = '\0';

    cout << mainDiagonal << endl;
    cout << reverseDiagonal << endl;

    int counter = 0;

    for (int i = 0; i < strlen(mainDiagonal); i++)
    {
        if (mainDiagonal[i] == reverseDiagonal[i])
        {
            counter++;
        }
    }

    //strcmp also works!

    if (counter == strlen(mainDiagonal))
        cout << "The sentence at the main diagonal is the same as the sentence at the reversed diagonal.";
    else
        cout << "The sentence at the main diagonal is not the same as the sentence at the reversed diagonal."; 

    return 0;
}