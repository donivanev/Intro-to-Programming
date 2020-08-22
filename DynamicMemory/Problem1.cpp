#include <iostream>
#include <string>
using namespace std;

char* strduplicate(char* copyStr, char* str)
{
    strcpy_s(copyStr, strlen(str) + 1, str);
    
    //strcpy_s(copyStr, 50, str); ??
    //copyStr[strlen(str)] = '\0'; ?? 

    return copyStr;
}

/*int main()
{
    char str[50];
    cout << "Enter a string: ";
    cin >> str;

    char* copyStr = new char[strlen(str) + 1];

    cout << strduplicate(copyStr, str);

    delete[] copyStr;

    return 0;
}*/