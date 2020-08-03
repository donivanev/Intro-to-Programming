#include <iostream>
using namespace std;

void areThere2EqualElementsInRow(int n)
{
    int a, b;
    bool equal = false;

    cout << "Now enter n numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (i != 0) if (a == b) equal = true;

        b = a;
    }

    equal ? cout << "There are at least 2 equal elements in a row."
        : cout << "There aren't at least 2 equal elements in a row.";
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    areThere2EqualElementsInRow(n);

    return 0;
}
