#include <iostream>
using namespace std;

int findMin(int n)
{
    int a, min = INT_MAX;

    cout << "Now enter n numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (min > a) min = a;
    }

    cout << "The minimal number is: ";
    return min;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << findMin(n);

    return 0;
}
