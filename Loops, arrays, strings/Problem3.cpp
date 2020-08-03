#include <iostream>
using namespace std;

void sumOfPositivesAndMultOfNegatives(int n)
{
    int a, sum = 0, mult = 1;

    cout << "Now enter n numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (a > 0) sum += a;
        if (a < 0) mult *= a;
    }

    cout << "The sum of the positive numbers is: " << sum << endl;
    cout << "The multiplication of the negative numbers is: " << mult;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    sumOfPositivesAndMultOfNegatives(n);

    return 0;
}
