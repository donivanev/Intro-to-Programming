#include <iostream>
#include <string>
using namespace std;

char compareStrings(char* s1, char* s2)
{
    if (s1[0] == '\0' && s2[0] == '\0')
    {   
        return '=';
    }
    else if (s1[0] < s2[0]) 
    {
        return '<';
    }
    else if (s1[0] > s2[0]) 
    {
        return '>';
    }
    else
    {
        return compareStrings(s1 + 1, s2 + 1);
    }
}

int main()
{
    char str1[50];
    char str2[50];
    cout << "Enter s1: ";
    cin >> str1;
    cout << "Enter s2: ";
    cin >> str2;

    cout << compareStrings(str1, str2);

    return 0;
}
