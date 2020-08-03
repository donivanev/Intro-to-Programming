#include <iostream>
#include <cstring>
using namespace std;

void findCommonPrefix(char* s1, char* s2)
{
    int maxLength = 0, index = 0, counter = 0;

    if (strlen(s1) >= strlen(s2)) maxLength = strlen(s1);
    else maxLength = strlen(s2);

    for (int i = 0; i < maxLength; i++)
    {
        if (s1[i] == s2[i])
        {
            counter++;
        }
    }

    char* resultS = new char[counter + 1];

    for (int i = 0; i < maxLength; i++)
    {
        if (s1[i] == s2[i])
        {
            resultS[index] = s1[i];
            index++;
        }
        else
        {
            resultS[index] = '\0';
            break;
        }
    }

    cout << resultS;
    delete[] resultS;
}

int main()
{
    char s1[255];
    char s2[255];
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    findCommonPrefix(s1, s2);

    return 0;
}