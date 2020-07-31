#include <iostream>
using namespace std;

int printNinKbasedSystem(int n, int k)
{
    int s = 0, power = 0;

    while (n != 0)
    {
        int remainder = n % k;
        n /= k;
        s += remainder * pow(10, power);
        power++;
    }

    return s;
}

int main()
{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << printNinKbasedSystem(n, k) << endl;

    return 0;
}