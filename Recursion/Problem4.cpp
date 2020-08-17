#include <iostream>
using namespace std;

double mult1toN(unsigned n, unsigned int k)
{
    if (n == 1)
    {
        return 1;
    }

    return n + mult1toN(n - 1, k);
}

int main()
{
    unsigned int n;
    unsigned int k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    cout << mult1toN(n, k);

    return 0;
}
