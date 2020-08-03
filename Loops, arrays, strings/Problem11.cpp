#include <iostream>
#include <cstring>
using namespace std;

char* reverse(char* s)
{
    for (int i = 0; i < strlen(s) / 2; i++)
    {
        char helper = s[i];
        s[i] = s[strlen(s) - i - 1];
        s[strlen(s) - i - 1] = helper;
    }

    return s;
}

int main()
{
    char s[255];
    cout << "Enter s: ";
    cin >> s;

    cout << reverse(s);

    return 0;
}