#include <iostream>
#include <string>
#pragma warning (disable:4996)
using namespace std;

char* unite(char* str1, char* str2)
{  
    char* str = new char[strlen(str1) + strlen(str2) + 1];
    //char* str = strcat(str1, str2);
    int index = 0;

    str[0] = '\0';

    for (int i = 0; i < strlen(str1); i++)
    {
        bool isThereCurrentSymbol = false;

        for (int j = 0; j < strlen(str); j++)
        {
            if (str1[i] == str[j])
            {
                isThereCurrentSymbol = true;
            }
        }

        if (!isThereCurrentSymbol)
        {
            str[index] = str1[i];
            index++;
            str[index] = '\0';
        }
    }

    for (int i = 0; i < strlen(str2); i++)
    {
        bool isThereCurrentSymbol = false;

        for (int j = 0; j < strlen(str); j++)
        {
            if (str2[i] == str[j])
            {
                isThereCurrentSymbol = true;
            }
        }

        if (!isThereCurrentSymbol)
        {
            str[index] = str2[i];
            index++;
            str[index] = '\0';
        }
    }

    return str;
    delete[] str;
}

int main()
{
    char str1[50];
    char str2[50];
    cout << "Enter a string: ";
    cin >> str1;
    cout << "Enter another string: ";
    cin >> str2;

    cout << unite(str1, str2);

    return 0;
}