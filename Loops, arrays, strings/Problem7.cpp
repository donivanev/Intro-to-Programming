#include <iostream>
#include <cstring>
using namespace std;

void printDigitslowerCaseAndOthers(char* s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] > 47 && s[i] < 58)
        {
            cout << s[i];
        }
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] > 96 && s[i] < 123)
        {
            cout << s[i];
        }
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (!(s[i] > 47 && s[i] < 58) && !(s[i] > 96 && s[i] < 123))
        {
            cout << s[i];
        }
    }
}

int main()
{
    char s[255];
    cout << "Enter s: ";
    cin >> s;

    printDigitslowerCaseAndOthers(s);

    return 0;
}