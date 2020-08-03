#include <iostream>
#include <cstring>
using namespace std;

void lowerToUpperOrTheOpposite(char* s)
{
    int latinSymbolsCount[26];

    for (int i = 0; i < 26; i++)
    {
        latinSymbolsCount[i] = 0;
    }
 
    for (int i = 0; i < strlen(s); i++)
    {
        latinSymbolsCount[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(s); i++) {

        if (latinSymbolsCount[s[i] - 'a'] != 0)
        {
            cout << s[i] << " " << latinSymbolsCount[s[i] - 'a'] << endl;
            latinSymbolsCount[s[i] - 'a'] = 0;
        }
    }
}

int main()
{
    char s[255];
    cout << "Enter s: ";
    cin >> s;

    lowerToUpperOrTheOpposite(s);

    return 0;
}