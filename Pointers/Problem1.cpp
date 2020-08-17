#include <iostream>
using namespace std;

void swapElements(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapArrays(int *a, int *b)
{
    for (int i = 0; i < 10; i++)
    {
        swapElements(&a[i], &b[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
}

int main()
{
    int a[10];
    int b[10];

    cout << "Enter 10 integers for the first array: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    cout << "Enter 10 integers for the second array: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }

    swapArrays(a, b);

    return 0;
}