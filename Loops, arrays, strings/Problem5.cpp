#include <iostream>
using namespace std;

void isSequenceMonotonous(int n)
{
    int a, b, counter = 0;
    bool isMonotonous = false;

    cout << "Now enter n numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (i != 0) if (a >= b) counter++;

        b = a;
    }

    counter == n - 1 ? isMonotonous = true : isMonotonous = false;

    isMonotonous ? cout << "The sequence is monotonously growing." 
        : cout << "The sequence is not monotonously growing.";
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    isSequenceMonotonous(n);

    return 0;
}
