#include <iostream>
#include <string>
using namespace std;

char* strduplicate(char* str)
{
    char* copyStr = new char[strlen(str) + 1];
    strcpy_s(copyStr, strlen(str) + 1, str);
    
    //strcpy_s(copyStr, 50, str); ??
    //copyStr[strlen(str)] = '\0'; ?? 

    return copyStr;
    delete[] copyStr;
}

/*int main()
{
    char str[50];
    cout << "Enter a string: ";
    cin >> str;

    cout << strduplicate(str);

    return 0;
}*/