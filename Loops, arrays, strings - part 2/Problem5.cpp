#include <iostream>
using namespace std;

/*int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[50];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int firstElement = 0, p = 0, index = 0, counter = 0;
    int resultArray[50];

    for (int i = 0; i < n; i++)
    {
        resultArray[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            firstElement = arr[i];
        }
        if (arr[i] == firstElement)
        {
            if (i != 0)
            {
                index++;
                p = 0;
            }
        }

        resultArray[index] += arr[i] * pow(10, p);
        p++;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            firstElement = resultArray[i];
        }
        if (resultArray[i] == firstElement)
        {
            counter++;
        }
    }

    cout << "The period is: " << counter;

    return 0;
}*/