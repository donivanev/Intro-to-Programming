#include <iostream>
#include <cmath>
using namespace std;

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}

	return false;
}

void errorMessage()
{
	cout << "Invalid date/time";
}

void catchInvalidCases(int day, int month, int year, int hours, int minutes, int seconds, 
						int day2, int month2, int year2, int hours2, int minutes2, int seconds2, bool& flag)
{
	if (year > 9999 || month > 12)
	{
		flag = true;
		errorMessage();
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
		{
			flag = true;
			errorMessage();
		}
	}
	else if (month == 2)
	{
		if (!isLeapYear(year))
		{
			if (day > 28)
			{
				flag = true;
				errorMessage();
			}
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			flag = true;
			errorMessage();
		}
	}

	if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 12)
	{
		if (day2 > 31)
		{
			flag = true;
			errorMessage();
		}
	}
	else if (month2 == 2)
	{
		if (!isLeapYear(year))
		{
			if (day2 > 28)
			{
				flag = true;
				errorMessage();
			}
		}
	}
	else if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11)
	{
		if (day2 > 30)
		{
			flag = true;
			errorMessage();
		}
	}

	if (hours > 24 || hours2 > 24 || minutes > 60 || minutes2 > 60 || seconds > 60 || seconds2 > 60)
	{
		flag = true;
		errorMessage();
	}
}

void addDays(int month, int& yearsToDays)
{
	switch (month)
	{
		case 2: yearsToDays += 31; break;
		case 3: yearsToDays += 28 + 31; break;
		case 4: yearsToDays += 28 + 2 * 31; break;
		case 5: yearsToDays += 28 + 30 + 2 * 31; break;
		case 6: yearsToDays += 28 + 30 + 3 * 31; break;
		case 7: yearsToDays += 28 + 2 * 30 + 3 * 31; break;
		case 8: yearsToDays += 28 + 2 * 30 + 4 * 31; break;
		case 9: yearsToDays += 28 + 2 * 30 + 5 * 31; break;
		case 10: yearsToDays += 28 + 3 * 30 + 5 * 31; break;
		case 11: yearsToDays += 28 + 3 * 30 + 6 * 31; break;
		case 12: yearsToDays += 28 + 4 * 30 + 6 * 31; break;

		default: break;
	}
}

int leapYears(int year)
{
	if (isLeapYear(year)) year--;

	return year / 4 - year / 100 + year / 400;
}

int main()
{
	unsigned int day, month, year, hours, minutes, seconds;
	unsigned int day2, month2, year2, hours2, minutes2, seconds2;
	char dot, colon;
	cin >> day >> dot >> month >> dot >> year >> hours >> colon >> minutes >> colon >> seconds;
	cin >> day2 >> dot >> month2 >> dot >> year2 >> hours2 >> colon >> minutes2 >> colon >> seconds2;

	bool flag = false;
	catchInvalidCases(day, month, year, hours, minutes, seconds, 
					  day2, month2, year2, hours2, minutes2, seconds2, flag);

	if (!flag)
	{
		int numberOfSecondsOfDate1 = seconds;

		int firstLeapYears = leapYears(year);
		int yearsToDays = ((year - 1) * 365) + firstLeapYears + day;

		addDays(month, yearsToDays);

		if (month > 2 && isLeapYear(year))
		{
			yearsToDays++;
		}

		int hoursToSeconds = hours * 3600, minutesToSeconds = minutes * 60;
		numberOfSecondsOfDate1 += hoursToSeconds + minutesToSeconds;

		int numberOfSecondsOfDate2 = seconds2, secondsLeapYears = leapYears(year2), 
		yearsToDays2 = ((year2 - 1) * 365) + secondsLeapYears + day2;

		addDays(month2, yearsToDays2);

		if (month2 > 2 && isLeapYear(year2))
		{
			yearsToDays2++;
		}

		int hoursToSeconds2 = hours2 * 3600, minutesToSeconds2 = minutes2 * 60;
		numberOfSecondsOfDate2 += hoursToSeconds2 + minutesToSeconds2;

		int difference = abs(numberOfSecondsOfDate1 - numberOfSecondsOfDate2);
		int differenceCopy = difference;

		int returnSecondsFromHours = difference / 3600;

		if (returnSecondsFromHours > 0)
		{
			difference -= returnSecondsFromHours * 3600;
		}

		int returnSecondsFromMinutes = difference / 60;

		if (returnSecondsFromMinutes > 0)
		{
			difference -= returnSecondsFromMinutes * 60;
		}

		if (day > day2 && returnSecondsFromHours == 0)
		{
			//Substract from 24 (86 400 seconds)
			differenceCopy = 86400 - differenceCopy;

			int returnSecondsFromHours = differenceCopy / 3600;

			if (returnSecondsFromHours > 0)
			{
				differenceCopy -= returnSecondsFromHours * 3600;
			}

			int returnSecondsFromMinutes = differenceCopy / 60;

			if (returnSecondsFromMinutes > 0)
			{
				differenceCopy -= returnSecondsFromMinutes * 60;
			}

			(returnSecondsFromHours < 10) ? cout << "0" << returnSecondsFromHours :
				                            cout << returnSecondsFromHours;

			(returnSecondsFromMinutes < 10) ? cout << ":0" << returnSecondsFromMinutes :
				                              cout << ":" << returnSecondsFromMinutes;

			differenceCopy < 10 ? cout << ":0" << differenceCopy : 
				                  cout << ":" << differenceCopy;
		}
		else
		{
			cout << abs(yearsToDays2 - yearsToDays);

			(returnSecondsFromHours < 10) ? cout << "-0" << returnSecondsFromHours :
										    cout << "-" << returnSecondsFromHours;

			(returnSecondsFromMinutes < 10) ? cout << ":0" << returnSecondsFromMinutes :
											  cout << ":" << returnSecondsFromMinutes;

			difference < 10 ? cout << ":0" << difference : cout << ":" << difference;
		}
	}	

	return 0;
}