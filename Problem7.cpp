#include <iostream>
using namespace std;

bool isThereK(unsigned int n, unsigned int k)
{
    if (n == 0)
    {
        return false;
    }

    if (n % 10 == k)
    {
        return true;
    }

    return isThereK(n / 10, k);
}

/*int main()
{
    unsigned int n;
    cout << "Enter n: ";
    cin >> n;

    cout << isThereK(n, 5);

    return 0;
}*/
