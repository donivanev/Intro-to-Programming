#include <iostream>
using namespace std;

int length(int n)
{
    int len = 0;

    while (n != 0)
    {
        n /= 10;
        len++;
    }

    return len;
}

int toBin(int date)
{
    int bin = 0, power = 0;

    while (date != 0) 
    {
        int remainder = date % 2;
        date /= 2;
        bin += remainder * pow(10, power);
        power++;
    }

    return bin;
}

int toOct(int date)
{
    int oct = 0, power = 0;

    while (date != 0)
    {
        int remainder = date % 8;
        date /= 8;
        oct += remainder * pow(10, power);
        power++;
    }

    return oct;
}

int toHex(int date)
{
    int hex = 0, power = 0;

    while (date != 0)
    {
        int remainder = date % 16;
        date /= 16;
        hex += remainder * pow(10, power);
        power++;
    }

    return hex;
}

int main()
{
    //17.12.2000

    int date = 17122000;

    //cout << toBin(7) << endl;
    //cout << toOct(4) << endl;
    //cout << toHex(22) << endl;

    cout << toBin(date) << endl;
    cout << toOct(date) << endl;
    cout << toHex(date) << endl;
}