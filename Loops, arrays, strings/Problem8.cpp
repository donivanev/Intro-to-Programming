#include <iostream>
#include <cstring>
using namespace std;

bool isSymmetric(char* s)
{
    bool isSymmetric = false;
    int counter = 0;

    for (int i = 0; i < strlen(s) / 2 + 1; i++)
    {
        if (s[i] == s[strlen(s) - i - 1])
        {
            counter++;
        }
    }

    counter == strlen(s) / 2 + 1 ? isSymmetric = true : isSymmetric = false;
    return isSymmetric;
}

int main()
{
    char s[255];
    cout << "Enter s: ";
    cin >> s;

    isSymmetric(s) ? cout << "The string is symmetric." : cout << "The string is not symmetric.";

    return 0;
}