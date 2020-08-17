#include <iostream>
using namespace std;

void unsortedness(int n, int *a)
{
    int counter = 0;
    int previousArray[50];

    for (int i = 0; i < n; i++)
    {
        previousArray[i] = a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                int helper = a[j + 1];
                a[j + 1] = a[j];
                a[j] = helper;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (previousArray[i] != a[i])
        {
            counter++;
        }
    }

    cout << "There are " << counter << " unsorted elements.";
}

/*int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a[50];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unsortedness(n, a);

    return 0;
}*/