#include <iostream>
#include <cstring>
using namespace std;

bool isSubstring(char* s1, char* s2)
{
    bool flag = false;

    for (int i = 0; i <= strlen(s1) - strlen(s2); i++)
    {
        for (int j = i; j < i + strlen(s2); j++)
        {
            flag = true;

            if (s1[j] != s2[j - i])
            {
                flag = false;
                break;
            }
        }

        if (flag == 1) break;
    }

    return flag;
}

int main()
{
    char s1[255];
    char s2[255];
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    cout << isSubstring(s1, s2) << endl;

    if (isSubstring(s1, s2)) cout << "S2 is a substring of S1.";
    else cout << "S2 is not a substring of S1.";

    return 0;
}