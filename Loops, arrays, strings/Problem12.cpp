#include <iostream>
#include <cstring>
using namespace std;

char* lowerToUpperOrTheOpposite(char* s)
{
    int lowerCounter = 0, upperCounter = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] > 64 && s[i] < 91)
        {
            upperCounter++;
        }
        else if (s[i] > 96 && s[i] < 123)
        {
            lowerCounter++;
        }
    }

    if (lowerCounter > upperCounter)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] > 64 && s[i] < 91)
            {
                s[i] += 32;
            }
        }
    }
    else
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] > 96 && s[i] < 123)
            {
                s[i] -= 32;
            }
        }
    }

    return s;
}

int main()
{
    char s[255];
    cout << "Enter s: ";
    cin >> s;

    cout << lowerToUpperOrTheOpposite(s);

    return 0;
}