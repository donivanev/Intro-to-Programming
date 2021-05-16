#include "BullsAndCows.h"

//9 * 8 * 7 * 6
const int POSSIBLE_VALUES = 3024;

int numberLength(unsigned number)
{
	unsigned counter = 0;

	while (number != 0)
	{
		counter++;
		number /= 10;
	}

	return counter;
}

int reverseNumber(int number)
{
	int reversedNumber = 0;

	while (number != 0)
	{
		reversedNumber = reversedNumber * 10 + number % 10;
		number /= 10;
	}

	return reversedNumber;
}

int* numberToArray(int number)
{
	int* numbersArr = new(nothrow) int[numberLength(number)];
	int index = 0;
	number = reverseNumber(number);

	while (number != 0)
	{
		numbersArr[index] = number % 10;
		number /= 10;
		index++;
	}

	return numbersArr;
}

bool isNegative(int number)
{
	return number < 0;
}

bool hasRepeatingDigits(int number)
{
	int* numbersArr = nullptr;
	int size = numberLength(number);
	bool flag = false;

	numbersArr = numberToArray(number);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size; j++)
		{
			if (i != j && numbersArr[i] == numbersArr[j])
			{
				flag = true;
			}
		}
	}

	delete[] numbersArr;

	return flag;
}

bool hasZeroDigit(int number)
{
	while (number != 0)
	{
		if (number % 10 == 0)
		{
			return true;
		}
		number /= 10;
	}

	return false;
}

bool isInputValid(int number)
{
	return !isNegative(number) && numberLength(number) == 4
		&& !hasRepeatingDigits(number) && !hasZeroDigit(number);
}

int searchForBulls(int numberToGuess, int attemptingNumber)
{
	int bulls = 0;
	int* numberToGuessArr = numberToArray(numberToGuess);
	int* attemptingNumberArr = numberToArray(attemptingNumber);

	for (size_t i = 0; i < numberLength(numberToGuess); i++)
	{
		for (size_t j = 0; j < numberLength(numberToGuess); j++)
		{
			if (i == j && numberToGuessArr[i] == attemptingNumberArr[j])
			{
				bulls++;
			}
		}
	}

	delete[] numberToGuessArr;
	delete[] attemptingNumberArr;

	return bulls;
}

int searchForCows(int numberToGuess, int attemptingNumber)
{
	int cows = 0;
	int* numberToGuessArr = numberToArray(numberToGuess);
	int* attemptingNumberArr = numberToArray(attemptingNumber);

	for (size_t i = 0; i < numberLength(numberToGuess); i++)
	{
		for (size_t j = 0; j < numberLength(numberToGuess); j++)
		{
			if (i != j && numberToGuessArr[i] == attemptingNumberArr[j])
			{
				cows++;
			}
		}
	}

	delete[] numberToGuessArr;
	delete[] attemptingNumberArr;

	return cows;
}

int* loadValidNumbers()
{
	int index = 0;
	int* validNumbers = new(nothrow) int[POSSIBLE_VALUES];

	for (size_t i = 1234; i < 10000; i++)
	{
		if (isInputValid(i))
		{
			validNumbers[index] = i;
			index++;
		}
	}

	return validNumbers;
}

bool* loadPossibleNumbers()
{
	bool* isPossible = new(nothrow) bool[POSSIBLE_VALUES];

	for (size_t i = 0; i < POSSIBLE_VALUES; i++)
	{
		isPossible[i] = true;
	}

	return isPossible;
}

int chooseAPossibleNumber(int* validNumbers, bool* isPossible)
{
	for (size_t i = 0; i < POSSIBLE_VALUES; i++)
	{
		if (isPossible[i])
		{
			return validNumbers[i];
		}
	}

	return -1;
}

void filterPossibleNumbers(int bulls, int cows, int guess, int* validNumbers, bool* isPossible)
{
	for (size_t i = 0; i < POSSIBLE_VALUES; i++)
	{
		if (isPossible[i])
		{
			int validNumber = validNumbers[i];
			int validCows = searchForCows(validNumber, guess);
			int validBulls = searchForBulls(validNumber, guess);

			if (validBulls != bulls || validCows != cows)
			{
				isPossible[i] = false;
			}
		}
	}
}

const int* tryGuess(int number)
{
	int bulls, cows;
	cin >> bulls >> cows;

	const int* result = new(nothrow) int[2]{ bulls, cows };
	return result;
}

void play()
{
	int* validNumbers = loadValidNumbers();
	bool* possibleNumbers = loadPossibleNumbers();
	const int* result = nullptr;

	while (true)
	{
		int guess = chooseAPossibleNumber(validNumbers, possibleNumbers);
		cout << "My guess is: " << guess << endl;

		//in order to work the user should uncomment the function "tryGuess" or to put a new one
		result = tryGuess(guess);

		if (result[0] == 4 && result[1] == 0)
		{
			cout << "Your number is: " << guess << endl;
			break;
		}

		filterPossibleNumbers(result[0], result[1], guess, validNumbers, possibleNumbers);
	}

	delete[] validNumbers;
	delete[] possibleNumbers;
	delete[] result;
}