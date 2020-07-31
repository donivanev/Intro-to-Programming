#include <iostream>
using namespace std;

bool isSumDivisibleBy3(int n)
{
    int sum = 0;

    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    if (sum % 3 == 0) return true;
    
    return false;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << isSumDivisibleBy3(n) << endl;

    return 0;
}