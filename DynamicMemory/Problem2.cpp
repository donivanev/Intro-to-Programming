#include <iostream>
#include <string>
using namespace std;

char* transformToString(char* copyStr, int n, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        copyStr[i] = '0' + (char)(n % 10);
        n /= 10; 
    }

    copyStr[counter] = '\0';

    for (int i = 0; i < strlen(copyStr) / 2; i++)
    {
        char helper = copyStr[i];
        copyStr[i] = copyStr[strlen(copyStr) - i - 1];
        copyStr[strlen(copyStr) - i - 1] = helper;
    }

    return copyStr;
}

/*int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int counter = 0, helper = n;

    while (helper != 0)
    {
        counter++;
        helper /= 10;
    }

    char* copyStr = new char[counter + 1];

    cout << transformToString(copyStr, n, counter);

    delete[] copyStr;

    return 0;
}*/