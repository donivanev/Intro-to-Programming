#include <iostream>
using namespace std;

bool isFromFibonacci(unsigned int n, int twoPrevious = 0, int previous = 1)
{
    if (n == twoPrevious || n == previous)
    {
        return true;
    }

    int currentFibonacciNumber = twoPrevious + previous;

    if (currentFibonacciNumber == n) return true;
    else return false;
    
    return isFromFibonacci(n, previous, currentFibonacciNumber);
}

int main()
{
    unsigned int n;
    cout << "Enter n: ";
    cin >> n;

    cout << isFromFibonacci(n);

    return 0;
}
