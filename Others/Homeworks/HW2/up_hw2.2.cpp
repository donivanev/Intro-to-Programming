#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void printArray(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
}

int lengthOfNumber(int number)
{
	int counter = 0;

	while (number != 0)
	{
		counter++;
		number /= 10;
	}

	return counter;
}

void loadBar(char arr[], int progress, int lengthOfBar, char leftPlugSymbol, char rightPlugSymbol, bool flag,
			 char emptySymbol)
{
	cout << leftPlugSymbol;

	for (int i = 0; i <= lengthOfBar; i++)
	{
		if (i == lengthOfBar / 2)
		{
			if (lengthOfNumber(progress) == 1)
			{
				arr[i] = progress;
			}
			else if (lengthOfNumber(progress) == 2)
			{
				if (flag)
				{
					arr[i] = (progress / 10) + '0';
					arr[i + 1] = (progress % 10) + '0';
					arr[i + 2] = '%';
					i++;
				}
				else
				{
					arr[i] = emptySymbol;
					i--;
				}
				i++;
			}
			else
			{
				if (flag)
				{
					arr[i] = '1';
					arr[i + 1] = '0';
					arr[i + 2] = '0';
					arr[i + 3] = '%';
					i += 3;
				}
				else
				{
					arr[i] = emptySymbol;
				}
			}
		}
		else
		{
			arr[i] = emptySymbol;
		}
	}
}

void animate(int progress, int lengthOfBar, char leftPlugSymbol, char rightPlugSymbol, bool flag,
	char fillSymbol, char emptySymbol)
{
	const unsigned MAX_NUMBER = 200;
	char arr[MAX_NUMBER];

	loadBar(arr, progress, lengthOfBar, leftPlugSymbol, rightPlugSymbol, flag, emptySymbol);

	int currentSymbols = lengthOfBar * progress / 100;

	for (int i = 0; i < currentSymbols; i++)
	{
		if (arr[i] == emptySymbol)
		{
			arr[i] = fillSymbol;
		}
	}

	printArray(arr, lengthOfBar);
	cout << rightPlugSymbol;
}

int main()
{
	unsigned short progress, lengthOfBar;
	char leftPlugSymbol, rightPlugSymbol, fillSymbol, emptySymbol;
	bool flag = false;

	cout << "Enter progress: ";
	cin >> progress;
	cout << "Enter length of bar: ";
	cin >> lengthOfBar;
	cin.ignore();
	cout << "Enter leftPlugSymbol: ";
	cin.get(leftPlugSymbol);
	cin.ignore();
	cout << "Enter rightPlugSymbol: ";
	cin.get(rightPlugSymbol);
	cout << "Enter 0(false)/1(true) if you want to see the procents: ";
	cin >> flag;
	cin.ignore();
	cout << "Enter fillSymbol: ";
	cin.get(fillSymbol);
	cin.ignore();
	cout << "Enter emptySymbol: ";
	cin.get(emptySymbol);

	unsigned int seconds;
	cout << "Enter seconds: ";
	cin >> seconds;

	while (progress < 101)
	{
		animate(progress, lengthOfBar, leftPlugSymbol, rightPlugSymbol, flag, fillSymbol, emptySymbol);
		std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
		if (progress != 100)
		{
			system("cls");
		}
		progress++;
	}

	return 0;
}