#include <iostream>
#include <cstring>
using namespace std;

char* lowerToUppercase(char* s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] > 96 && s[i] < 123)
        {
            s[i] -= 32;
        }
    }

    return s;
}

int main()
{
    char s[255];
    cout << "Enter s: ";
    cin >> s;

    cout << lowerToUppercase(s);

    return 0;
}