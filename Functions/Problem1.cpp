#include <iostream>
using namespace std;

bool isLeap(int y)
{
    bool leap = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
    return leap;
}

bool isGregorian(int d, int m, int y)
{
    bool isDayCorrect = true, isMonthCorrect = true, isYearCorrect = true;

    if (d <= 1 || d >= 31) isDayCorrect = false;
    if (m <= 1 || m >= 12) isMonthCorrect = false;

    if (m == 2)
    {
        if (isLeap(y))
        {
            if (d > 29) isDayCorrect = false;
        }
        else
        {
            if (d > 28) isDayCorrect = false;
        }
    }

    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d > 30) isDayCorrect = false;
    }

    return isDayCorrect && isMonthCorrect && isYearCorrect;
}

/*int main()
{
    int day, month, year;

    cout << "Enter a date: ";
    cin >> day >> month >> year;

    if (isGregorian(day, month, year))
    {
        cout << "Valid date.";
    }
    else
    {
        cout << "Not a valid date.";
    }

    return 0;
}*/