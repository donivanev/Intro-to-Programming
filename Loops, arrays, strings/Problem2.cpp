#include <iostream>
using namespace std;

int findDoubledOddNums(int n)
{
    int a, sum = 0;

    cout << "Now enter n numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if ((a % 2 == 0) && (a / 2 % 2 != 0)) sum += a;
    }

    cout << "The sum of the doubled odd numbers is: ";
    return sum;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << findDoubledOddNums(n);

    return 0;
}
