#include <iostream>
#include <string>
using namespace std;

char car(const char* x)
{
	return x[0];
}

char* cdr(char* remainingPiece, char* x)
{
	for (int i = 1; i < strlen(x); i++)
	{
		remainingPiece[i - 1] = x[i];
	}

	remainingPiece[strlen(x) - 1] = '\0';

	return remainingPiece;
}

char* cons(char* &concatenation, char x, const char* y)
{
	int index = 1;

	concatenation[0] = x;

	for (int i = 0; i < strlen(y); i++)
	{
		concatenation[index] = y[i];
		index++;
	}

	concatenation[index] = '\0';

	return concatenation;
}

bool eq(const char* x, const char* y)
{
	if (strcmp(x, y) == 0)
	{
		return true;
	}

	return false;
}

char* reverse(const char* x, char* reversed)
{
	int index = 0;

	for (int i = strlen(x) - 1; i >= 0; i--)
	{
		reversed[index] = x[i];
		index++;
	}

	reversed[index] = '\0';

	return reversed;
}

char* copy(const char* x, char* copyStr)
{
	strcpy_s(copyStr, strlen(x) + 1, x);

	return copyStr;
}

char* car_n(const char* x, int n, char* firstN)
{
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		firstN[index] = x[i];
		index++;
	}

	firstN[index] = '\0';

	return firstN;
}

char* crd_n(const char* x, int n, char* lastPiece)
{
	int index = 0;

	for (int i = n; i < strlen(x); i++)
	{
		lastPiece[index] = x[i];
		index++;
	}

	lastPiece[index] = '\0';

	return lastPiece;
}

int number_of_char(const char* x, char ch)
{
	int counter = 0;

	for (int i = 0; i < strlen(x); i++)
	{
		if (x[i] == ch)
		{
			counter++;
		}
	}

	return counter;
}

int number_of_substr(const char* x, const char* y)
{
	int counter = 0, sequence = 0;

	for (int i = 0; i < strlen(x); i++)
	{
		for (int j = 0; j < strlen(x); j++)
		{
			if (x[i] == y[j])
			{
				sequence++;
				if (sequence == strlen(y))
				{
					counter++;
					sequence = 0;
				}
			}
		}
	}

	return counter;
}

char* delete_susbtr(const char* x, const char* y, char* finalArray)
{
	int sequence = 0, index = 0;
	bool isSubstr = false;

	for (int i = 0; i < strlen(x); i++)
	{
		for (int j = 0; j < strlen(x); j++)
		{
			if (x[i] == y[j])
			{
				sequence++;
				if (sequence == strlen(y))
				{
					isSubstr = true;
					sequence = 0;
				}
			}
		}

		if (!isSubstr)
		{
			finalArray[index] = x[i];
			index++;
		}

		isSubstr = false;
	}

	finalArray[index] = '\0';

	return finalArray;
}

/*int main()
{
	int n;
	char word[50];
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter word: ";
	cin >> word;

	char* x = new char[n];
	strcpy_s(x, n, word);

	char* remainingPiece = new char[strlen(x)];
	char* concatenation = new char[5 + 2];
	char* reversed = new char[13];
	char* copyStr = new char[13];
	char* firstN = new char[13];
	char* lastPiece = new char[13];
	char* finalArray = new char[13];

	cout << car(x) << endl;
	cout << cdr(remainingPiece, x) << endl;
	cout << cons(concatenation, 'a', "idebe") << endl;
	cout << eq("burger", "chef") << endl;
	cout << reverse("lazarlazarov", reversed) << endl;
	cout << copy("hegel", copyStr) << endl;
	cout << car_n("rezil", 4, firstN) << endl;
	cout << crd_n("avtokasko", 4, lastPiece) << endl;
	cout << number_of_char("azschezuazsche", 'a') << endl;
	cout << number_of_substr("askingaskedask", "ask") << endl;
	cout << number_of_substr("hahahahaah", "ha") << endl;
	cout << delete_susbtr("abccbabba", "cc", finalArray) << endl;
	cout << delete_susbtr("kakviraboti", "ak", finalArray);

	delete[] concatenation;
	delete[] remainingPiece;
	delete[] reversed;
	delete[] copyStr; 
	delete[] firstN;
	delete[] lastPiece;
	delete[] finalArray;
	delete[] x;

	return 0;
}*/