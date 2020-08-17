#include <iostream>
using namespace std;

void swappable(int n, int* a)
{
    int counter = 0, max = INT32_MIN, index = 0;
    int previousArray[50];

    for (int i = 0; i < n; i++)
    {
        previousArray[i] = a[i];
    } 

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }

    if (n % 2 == 0) index++;

    for (int i = 0; i < index; i++)
    {
        int temp = previousArray[n - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            previousArray[j + 1] = previousArray[j];
        }
        previousArray[0] = temp;
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
        if (previousArray[i] == a[i])
        {
            counter++;
        }
    }

    counter == n ? cout << "This array is swappable." : cout << "This array is not swappable.";
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a[50];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    swappable(n, a);

    return 0;
}