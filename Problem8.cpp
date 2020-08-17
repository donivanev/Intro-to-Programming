#include <iostream>
using namespace std;

bool isFromFibonacci(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }

    //if ()
    //{

    //}

    return isFromFibonacci(n - 1) + isFromFibonacci(n - 2);
}

/*int main()
{
    unsigned int n;
    cout << "Enter n: ";
    cin >> n;

    cout << isFromFibonacci(n);

    return 0;
}*/
