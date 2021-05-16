#include <iostream>
#include <climits>

int main()
{
    unsigned int a, b, c;
    std::cin >> a >> b >> c;

    if (a > UCHAR_MAX || b > UCHAR_MAX || c > UCHAR_MAX)
    {
        std::cout << "Enter a valid input"; 
        return 1;
    }
    
    a = (a << 2) | (a >> 6);
    std::cout << (char)a << (char)b << (char)c;

    b = (b << 7) | (b >> 7) | (b&0b0111'1110);
    std::cout << (char)a << (char)b << (char)c;

    c ^= 0b0011'1100;

    unsigned int a, b;
    std::cin >> a >> b;

    std::cout << (a + b) / 2 << std::endl;

    return 0;
}