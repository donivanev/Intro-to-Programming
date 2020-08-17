#include <iostream>
using namespace std;

int main()
{
    int n, counter = 0;
    bool flag = false;
    cout << "Enter n: ";
    cin >> n;
    int a[50];
    int b[50];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                counter++;
            }
        }
    }

    counter == n ? flag = true : flag = false;

    flag ? cout << "Similar sequences." : cout << "Not similar sequences.";

    return 0;
}