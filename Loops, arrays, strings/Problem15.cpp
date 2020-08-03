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

void bijectionString(char* s1, char* s2)
{
    bool bijection = false;

    if (isSymmetric(s1) && isSymmetric(s2)) cout << "The function f : char -> char (f(s1[i]) = f(s2[i])) exists.";
    else cout << "There function f : char -> char (f(s1[i]) = f(s2[i])) does not exist.";

}

int main()
{
    char s1[255];
    char s2[255];
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    bijectionString(s1, s2);

    return 0;
}