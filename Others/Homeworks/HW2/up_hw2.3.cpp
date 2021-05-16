#include <iostream>
#include <cmath>
using namespace std;

int min(int firstNumber, int secondNumber)
{
	return firstNumber < secondNumber ? firstNumber : secondNumber;
}

int max(int firstNumber, int secondNumber)
{
	return firstNumber > secondNumber ? firstNumber : secondNumber;
}

void printArray(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
}

int lengthOfNumber(char number[])
{
	unsigned counter = 0;

	for (int i = 0; number[i] != '\0'; i++)
	{
		counter++;
	}

	return counter;
}

bool isBigger(char firstNumber[], char secondNumber[])
{
	bool isBigger = false;
	int counter = 0;

	for (int i = 0; i < lengthOfNumber(firstNumber); i++)
	{
		if (firstNumber[i] < secondNumber[i])
		{
			isBigger = true;
			break;
		}
	}

	return isBigger;
}

void equal(char firstNumber[], char secondNumber[])
{
	bool flag = true;
	int lengthOfFirst = lengthOfNumber(firstNumber);
	int lengthOfSecond = lengthOfNumber(secondNumber);
	int minLength = min(lengthOfFirst, lengthOfSecond);

	if (lengthOfFirst != lengthOfSecond)
	{
		cout << firstNumber << " != " << secondNumber;
		cout << endl;
		return;
	}

	for (int i = 0; i < minLength; i++)
	{
		if (firstNumber[i] != secondNumber[i])
		{
			flag = false;
		}
	}

	flag ? cout << firstNumber << " == " << secondNumber : cout << firstNumber << " != " << secondNumber;
	cout << endl;
}

void compare(char firstNumber[], char secondNumber[])
{
	if (lengthOfNumber(firstNumber) > lengthOfNumber(secondNumber))
	{
		if (firstNumber[0] == '-' && secondNumber[0] == '-')
		{
			cout << firstNumber << " < " << secondNumber;
		}
		else if (firstNumber[0] == '-')
		{
			cout << firstNumber << " < " << secondNumber;
		}
		else if (secondNumber[0] == '-')
		{
			cout << firstNumber << " < " << secondNumber;
		}
		else
		{
			cout << firstNumber << " > " << secondNumber;
		}
	}
	else if (lengthOfNumber(firstNumber) < lengthOfNumber(secondNumber))
	{
		if (firstNumber[0] == '-' && secondNumber[0] == '-')
		{
			cout << firstNumber << " > " << secondNumber;
		}
		else if (firstNumber[0] == '-')
		{
			cout << firstNumber << " > " << secondNumber;
		}
		else if (secondNumber[0] == '-')
		{
			cout << firstNumber << " > " << secondNumber;
		}
		else
		{
			cout << firstNumber << " < " << secondNumber;
		}
	}
	else
	{
		bool flag = true;

		for (int i = 0; i < lengthOfNumber(firstNumber); i++)
		{
			if (firstNumber[i] != secondNumber[i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			cout << firstNumber << " == " << secondNumber << endl;
			return;
		}
		else if (!isBigger(firstNumber, secondNumber))
		{
			if (firstNumber[0] == '-' && secondNumber[0] == '-')
			{
				cout << firstNumber << " < " << secondNumber;
			}
			else if (firstNumber[0] == '-')
			{
				cout << firstNumber << " < " << secondNumber;
			}
			else if (secondNumber[0] == '-')
			{
				cout << firstNumber << " > " << secondNumber;
			}
			else
			{
				cout << firstNumber << " > " << secondNumber;
			}
		}
		else
		{
			if (firstNumber[0] == '-' && secondNumber[0] == '-')
			{
				cout << firstNumber << " > " << secondNumber;
			}
			else if (firstNumber[0] == '-')
			{
				cout << firstNumber << " < " << secondNumber;
			}
			else if (secondNumber[0] == '-')
			{
				cout << firstNumber << " > " << secondNumber;
			}
			else
			{
				cout << firstNumber << " < " << secondNumber;
			}
		}
	}

	cout << endl;
}

void addNums(char firstNumber[], char secondNumber[], char result[])
{
	int lengthOfFirst = lengthOfNumber(firstNumber), lengthOfSecond = lengthOfNumber(secondNumber);
	int minLength = min(lengthOfFirst, lengthOfSecond), maxLength = max(lengthOfFirst, lengthOfSecond);
	int index = maxLength, remainder = 0;
	int currLength = maxLength, currentSum = 0;
	bool flag = false;
	char sum[8194];

	if (lengthOfFirst > lengthOfSecond)
	{
		currentSum = (firstNumber[index - 1] - '0') + (secondNumber[minLength - 1] - '0');
	}
	else
	{
		currentSum = (firstNumber[minLength - 1] - '0') + (secondNumber[index - 1] - '0');
	}

	for (int i = minLength - 2; i >= 0; i--)
	{
		remainder = currentSum % 10;
		sum[index] = remainder + '0';
		index--;

		if (currentSum / 10 > 0)
		{
			flag = true;
		}

		if (lengthOfFirst > lengthOfSecond)
		{
			currentSum = (firstNumber[index - 1] - '0') + (secondNumber[i] - '0');
		}
		else
		{
			currentSum = (firstNumber[i] - '0') + (secondNumber[index - 1] - '0');
		}

		if (flag)
		{
			currentSum++;
			flag = false;
		}
	}

	remainder = currentSum % 10;
	sum[index] = remainder + '0';
	index--;

	for (int i = 0; i < maxLength - minLength; i++)
	{
		if (lengthOfFirst > lengthOfSecond)
		{
			sum[i + 1] = firstNumber[i];
		}
		else
		{
			sum[i + 1] = secondNumber[i];
		}
	}

	if (currentSum >= 10)
	{
		for (int i = maxLength - minLength; i > 0; i--)
		{
			if (sum[i] == '9')
			{
				sum[i] = '0';
			}
			else
			{
				sum[i]++;
				break;
			}
		}
	}

	if (currentSum / 10 > 0 && lengthOfNumber(firstNumber) < lengthOfNumber(secondNumber))
	{
		int index2 = maxLength + 1;
		result[index2] = '\0';
		index2--;
		int helperCounter = 0;

		for (int i = maxLength; i >= 0; i--)
		{
			if (!(sum[i] >= '0' && sum[i] <= '9'))
			{
				result[maxLength + 1] = '\0';
				for (int i = 0; i < helperCounter; i++)
				{
					result[i] = result[i + 1];
				}
				result[helperCounter] = '\0';
			}
			else
			{
				result[index2] = sum[i];
			}
			index2--;
			helperCounter++;
		}
	}
	else
	{
		if (!(sum[0] > '0' && sum[0] <= '9'))
		{
			sum[0] = '0';
		}

		sum[0] = ((sum[0] - '0') + (currentSum / 10)) + '0';

		int index2 = maxLength + 1;
		result[index2] = '\0';
		index2--;

		for (int i = maxLength; i >= 0; i--)
		{
			result[index2] = sum[i];
			index2--;
		}
	}

	int value = 0;

	while (result[0] == '0' && lengthOfNumber(result) > 1)
	{
		for (int i = 0; i < max(lengthOfFirst, lengthOfSecond); i++)
		{
			result[i] = result[i + 1];
		}

		value++;
	}

	result[maxLength + 1 - value] = '\0';
}

void subtractTwoNumbers(int minLength, int maxLength, int& index, char firstNumber[], char secondNumber[],
	char resultArray[], int& firstNumIndex, bool& getOneFromPrevious)
{
	int minIndex = minLength;

	for (int i = maxLength; i > 0; i--)
	{
		if (i <= maxLength - minLength)
		{
			if (getOneFromPrevious)
			{
				firstNumber[firstNumIndex - 1]--;
			}
			if (firstNumber[firstNumIndex - 1] < '0')
			{
				resultArray[index] = firstNumber[firstNumIndex - 1] + 10;
				firstNumIndex--;
				index--;
				minIndex--;
				getOneFromPrevious = true;
			}
			else
			{
				resultArray[index] = firstNumber[firstNumIndex - 1];
				firstNumIndex--;
				index--;
				minIndex--;
				getOneFromPrevious = false;
			}
		}
		else
		{
			if (getOneFromPrevious)
			{
				firstNumber[firstNumIndex - 1]--;
			}
			if (firstNumber[firstNumIndex - 1] >= secondNumber[minIndex - 1])
			{
				resultArray[index] = ((firstNumber[firstNumIndex - 1] - '0') - (secondNumber[minIndex - 1] - '0') + '0');
				firstNumIndex--;
				index--;
				minIndex--;
				getOneFromPrevious = false;
			}
			else
			{
				resultArray[index] = (((firstNumber[firstNumIndex - 1] - '0') + 10) - (secondNumber[minIndex - 1] - '0') + '0');
				firstNumIndex--;
				index--;
				minIndex--;
				getOneFromPrevious = true;
			}
		}
	}
}

void add(char firstNumber[], char secondNumber[], bool& hasFirstMinus, bool& hasSecondMinus)
{
	int lengthOfFirst = lengthOfNumber(firstNumber), lengthOfSecond = lengthOfNumber(secondNumber);
	int minLength = min(lengthOfFirst, lengthOfSecond), maxLength = max(lengthOfFirst, lengthOfSecond);
	int index = maxLength, remainder = 0, currentSum = 0;
	bool flag = false;
	char sum[8193];

	if (firstNumber[0] == '-' && secondNumber[0] == '-')
	{
		hasFirstMinus = true;
		hasSecondMinus = true;
	}
	else if (firstNumber[0] == '-')
	{
		hasFirstMinus = true;
	}
	else if (secondNumber[0] == '-')
	{
		hasSecondMinus = true;
	}

	//When the two numbers differ 

	if (hasFirstMinus && !hasSecondMinus)
	{
		maxLength--;

		for (int i = 0; i < lengthOfFirst; i++)
		{
			firstNumber[i] = firstNumber[i + 1];
		}

		char copyNumber[8193];

		if (lengthOfFirst - 1 == lengthOfSecond)
		{
			int firstNumIndex = maxLength;
			bool getOneFromPrevious = false;
			index = maxLength - 1;

			for (int i = 0; i <= lengthOfNumber(firstNumber); i++)
			{
				copyNumber[i] = firstNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, secondNumber, copyNumber, sum,
				firstNumIndex, getOneFromPrevious);

			int value = 0;

			while (sum[0] == '0' && lengthOfNumber(sum) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					sum[i] = sum[i + 1];
				}

				value++;
			}

			sum[maxLength - value] = '\0';
			cout << "-" << firstNumber << " + " << secondNumber << " = " << sum;
			cout << endl;
			return;
		}
		else if (lengthOfFirst > lengthOfSecond)
		{
			int firstNumIndex = maxLength;
			bool getOneFromPrevious = false;
			index = maxLength - 1;

			for (int i = 0; i <= lengthOfNumber(firstNumber); i++)
			{
				copyNumber[i] = firstNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, copyNumber, secondNumber, sum,
				firstNumIndex, getOneFromPrevious);

			int value = 0;

			while (sum[0] == '0' && lengthOfNumber(sum) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					sum[i] = sum[i + 1];
				}

				value++;
			}

			sum[maxLength - value] = '\0';
			cout << "-" << firstNumber << " + " << secondNumber << " = -" << sum;
		}
		else
		{
			maxLength++;
			minLength--;
			int firstNumIndex = maxLength;
			bool getOneFromPrevious = false;
			index = maxLength - 1;

			for (int i = 0; i <= lengthOfNumber(firstNumber); i++)
			{
				copyNumber[i] = firstNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, secondNumber, copyNumber, sum,
				firstNumIndex, getOneFromPrevious);

			int value = 0;

			while (sum[0] == '0' && lengthOfNumber(sum) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					sum[i] = sum[i + 1];
				}

				value++;
			}

			sum[maxLength - value] = '\0';
			cout << "-" << firstNumber << " + " << secondNumber << " = " << sum;
		}
	}
	else if (!hasFirstMinus && hasSecondMinus)
	{
		maxLength--;

		for (int i = 0; i < lengthOfSecond; i++)
		{
			secondNumber[i] = secondNumber[i + 1];
		}

		char copyNumber[8193];

		if (lengthOfFirst - 1 == lengthOfSecond)
		{
			int firstNumIndex = maxLength;
			bool getOneFromPrevious = false;
			index = maxLength - 1;

			for (int i = 0; i <= lengthOfNumber(secondNumber); i++)
			{
				copyNumber[i] = secondNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, firstNumber, copyNumber, sum,
				firstNumIndex, getOneFromPrevious);

			int value = 0;

			while (sum[0] == '0' && lengthOfNumber(sum) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					sum[i] = sum[i + 1];
				}

				value++;
			}

			sum[maxLength - value] = '\0';
			cout << "-" << firstNumber << " + " << secondNumber << " = -" << sum;
			cout << endl;
			return;
		}

		if (lengthOfSecond > lengthOfFirst)
		{
			int firstNumIndex = maxLength;
			bool getOneFromPrevious = false;
			index = maxLength - 1;

			for (int i = 0; i <= lengthOfNumber(firstNumber); i++)
			{
				copyNumber[i] = firstNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, secondNumber, copyNumber, sum,
				firstNumIndex, getOneFromPrevious);

			sum[maxLength] = '\0';

			int value = 0;

			while (sum[0] == '0' && lengthOfNumber(sum) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					sum[i] = sum[i + 1];
				}

				value++;
			}

			sum[maxLength - value] = '\0';

			cout << firstNumber << " + -" << secondNumber << " = -" << sum;
		}
		else
		{
			maxLength++;
			minLength--;
			int firstNumIndex = maxLength;
			bool getOneFromPrevious = false;
			index = maxLength - 1;

			for (int i = 0; i <= lengthOfNumber(firstNumber); i++)
			{
				copyNumber[i] = firstNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, copyNumber, secondNumber, sum,
				firstNumIndex, getOneFromPrevious);

			int value = 0;

			while (sum[0] == '0' && lengthOfNumber(sum) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					sum[i] = sum[i + 1];
				}

				value++;
			}

			sum[maxLength - value] = '\0';
			cout << firstNumber << " + -" << secondNumber << " = " << sum;
		}
	}
	else
	{
		//When the two numbers are either positive or negative
		if (hasFirstMinus)
		{
			for (int i = 0; i < lengthOfFirst; i++)
			{
				firstNumber[i] = firstNumber[i + 1];
			}
		}

		if (hasSecondMinus)
		{
			for (int i = 0; i < lengthOfSecond; i++)
			{
				secondNumber[i] = secondNumber[i + 1];
			}
		}

		if (lengthOfFirst > lengthOfSecond)
		{
			currentSum = (firstNumber[index - 1] - '0') + (secondNumber[minLength - 1] - '0');
		}
		else
		{
			currentSum = (firstNumber[minLength - 1] - '0') + (secondNumber[index - 1] - '0');
		}

		for (int i = minLength - 2; i >= 0; i--)
		{
			remainder = currentSum % 10;
			sum[index] = remainder + '0';
			index--;

			if (currentSum / 10 > 0)
			{
				flag = true;
			}

			if (lengthOfFirst > lengthOfSecond)
			{
				currentSum = (firstNumber[index - 1] - '0') + (secondNumber[i] - '0');
			}
			else
			{
				currentSum = (firstNumber[i] - '0') + (secondNumber[index - 1] - '0');
			}

			if (flag)
			{
				currentSum++;
				flag = false;
			}
		}

		remainder = currentSum % 10;
		sum[index] = remainder + '0';
		index--;

		for (int i = 0; i < maxLength - minLength; i++)
		{
			if (lengthOfFirst > lengthOfSecond)
			{
				sum[i + 1] = firstNumber[i];
			}
			else
			{
				sum[i + 1] = secondNumber[i];
			}
		}

		if (currentSum >= 10)
		{
			for (int i = maxLength - minLength; i > 0; i--)
			{
				if (sum[i] == '9')
				{
					sum[i] = '0';
				}
				else
				{
					sum[i]++;
					break;
				}
			}
		}

		if (sum[1] == '0')
		{
			sum[0] = '1';
		}
		else if (currentSum / 10 > 0 && lengthOfNumber(firstNumber) == lengthOfNumber(secondNumber))
		{
			sum[0] = (currentSum / 10) + '0';
		}

		if (hasFirstMinus && hasSecondMinus)
		{
			cout << "-" << firstNumber << " + " << "-" << secondNumber << " = -";
			printArray(sum + 1, maxLength - 1);
		}
		else
		{
			if (sum[0] > '0' && sum[0] <= '9')
			{
				cout << firstNumber << " + " << secondNumber << " = ";
				printArray(sum, maxLength + 1);
			}
			else
			{
				cout << firstNumber << " + " << secondNumber << " = ";
				printArray(sum + 1, maxLength);
			}
		}
	}

	cout << endl;
}

void subtract(char firstNumber[], char secondNumber[], bool& hasFirstMinus, bool& hasSecondMinus)
{
	int lengthOfFirst = lengthOfNumber(firstNumber), lengthOfSecond = lengthOfNumber(secondNumber);
	int minLength = min(lengthOfFirst, lengthOfSecond), maxLength = max(lengthOfFirst, lengthOfSecond);
	char resultArray[8193];
	char copyNumber[8193];
	int index = maxLength - 1, firstNumIndex = maxLength;
	bool getOneFromPrevious = false, greater = false;

	//Redundant if-else cases if we come from add function, otherwise not
	if (firstNumber[0] == '-' && secondNumber[0] == '-')
	{
		hasFirstMinus = true;
		hasSecondMinus = true;
	}
	else if (firstNumber[0] == '-')
	{
		hasFirstMinus = true;
	}
	else if (secondNumber[0] == '-')
	{
		hasSecondMinus = true;
	}

	if (hasFirstMinus && !hasSecondMinus)
	{
		if (lengthOfNumber(firstNumber) >= lengthOfNumber(secondNumber))
		{
			addNums(firstNumber, secondNumber, resultArray);

			int value = 0;

			while (resultArray[0] == '0' && lengthOfNumber(resultArray) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					resultArray[i] = resultArray[i + 1];
				}

				value++;
			}

			resultArray[maxLength + 1 - value] = '\0';
			cout << "-" << firstNumber << " - " << secondNumber << " = -" << resultArray;
		}
		else if (lengthOfNumber(firstNumber) < lengthOfNumber(secondNumber))
		{
			addNums(firstNumber, secondNumber, resultArray);

			int value = 0;

			while (resultArray[0] == '0' && lengthOfNumber(resultArray) > 1)
			{
				for (int i = 0; i < lengthOfSecond; i++)
				{
					resultArray[i] = resultArray[i + 1];
				}

				value++;
			}

			resultArray[maxLength + 1 - value] = '\0';
			cout << firstNumber << " - -" << secondNumber << " = -" << resultArray;
		}
	}
	else if (!hasFirstMinus && hasSecondMinus)
	{
		if (lengthOfNumber(firstNumber) >= lengthOfNumber(secondNumber))
		{
			addNums(firstNumber, secondNumber, resultArray);

			int value = 0;

			while (resultArray[0] == '0' && lengthOfNumber(resultArray) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					resultArray[i] = resultArray[i + 1];
				}

				value++;
			}

			resultArray[maxLength + 1 - value] = '\0';
			cout << firstNumber << " - -" << secondNumber << " = " << resultArray;
		}
		else if (lengthOfNumber(firstNumber) < lengthOfNumber(secondNumber))
		{
			addNums(firstNumber, secondNumber, resultArray);

			int value = 0;

			while (resultArray[0] == '0' && lengthOfNumber(resultArray) > 1)
			{
				for (int i = 0; i < lengthOfSecond; i++)
				{
					resultArray[i] = resultArray[i + 1];
				}

				value++;
			}

			resultArray[maxLength + 1 - value] = '\0';
			cout << firstNumber << " - -" << secondNumber << " = " << resultArray;
		}
	}
	else
	{
		if (lengthOfNumber(firstNumber) > lengthOfNumber(secondNumber))
		{
			for (int i = 0; i <= lengthOfNumber(firstNumber); i++)
			{
				copyNumber[i] = firstNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, copyNumber, secondNumber, resultArray,
				firstNumIndex, getOneFromPrevious);

			int value = 0;

			while (resultArray[0] == '0' && lengthOfNumber(resultArray) > 1)
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					resultArray[i] = resultArray[i + 1];
				}

				value++;
			}

			resultArray[maxLength - value] = '\0';
			if (hasFirstMinus && hasSecondMinus)
			{
				cout << "-" << firstNumber << " - " << "-" << secondNumber << " = -" << resultArray;
			}
			else
			{
				cout << firstNumber << " - " << secondNumber << " = " << resultArray;
			}
		}
		else if (lengthOfNumber(firstNumber) <= lengthOfNumber(secondNumber))
		{
			for (int i = 0; i <= lengthOfNumber(secondNumber); i++)
			{
				copyNumber[i] = secondNumber[i];
			}
			copyNumber[maxLength] = '\0';

			subtractTwoNumbers(minLength, maxLength, index, copyNumber, firstNumber, resultArray,
				firstNumIndex, getOneFromPrevious);

			//resultArray[maxLength + 1] = '\0';

			int value = 0;

			while (resultArray[0] == '0' && (resultArray[1] >= '0' && resultArray[1] <= '9'))
			{
				for (int i = 0; i < lengthOfFirst; i++)
				{
					resultArray[i] = resultArray[i + 1];
				}

				value++;
			}

			resultArray[maxLength - value] = '\0';
			if (hasFirstMinus && hasSecondMinus)
			{
				cout << "-" << firstNumber << " - " << "-" << secondNumber << " = " << resultArray;
			}
			else
			{
				cout << firstNumber << " - " << secondNumber << " = -" << resultArray;
			}
		}
	}

	cout << endl;
}

void multiplyOneNumber(int digit, char number[], char result[])
{
	int size = lengthOfNumber(number);
	int index = size, extraSum = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		int product = digit * (number[i] - '0');
		product += extraSum;

		if (product >= 10)
		{
			result[index] = (product % 10) + '0';
			extraSum = product / 10;
		}
		else
		{
			result[index] = product + '0';
			extraSum = 0;
		}
		index--;
	}

	if (extraSum > 0)
	{
		result[0] = extraSum + '0';
		result[size + 1] = '\0';
	}
	else
	{
		for (int i = 1; i <= size; i++)
		{
			result[i - 1] = result[i];
		}
		result[size] = '\0';
	}
}

char* appendZero(char arr[], int index)
{
	int len = lengthOfNumber(arr);
	int end = index;

	while (index != 0)
	{
		arr[len + index - 1] = '0';
		index--;
	}

	arr[len + end] = '\0';
	return arr;
}

void multiply(char firstNumber[], char secondNumber[], bool& hasFirstMinus, bool& hasSecondMinus)
{
	char result[8193 * 2];
	char currResult[8193];
	char sum[8193];
	int len = lengthOfNumber(firstNumber), size = lengthOfNumber(secondNumber), index = 1;
	result[size + 1] = '\0';

	if (firstNumber[0] == '-' && secondNumber[0] == '-')
	{
		hasFirstMinus = true;
		hasSecondMinus = true;
	}
	else if (firstNumber[0] == '-')
	{
		hasFirstMinus = true;
	}
	else if (secondNumber[0] == '-')
	{
		hasSecondMinus = true;
	}

	multiplyOneNumber(firstNumber[len - 1] - '0', secondNumber, result);

	for (int i = len - 2; i >= 0; i--)
	{
		char currentArray[8193];

		multiplyOneNumber(firstNumber[i] - '0', secondNumber, currResult);
		addNums(result, appendZero(currResult, index), currentArray);
		strcpy_s(result, currentArray);
		index++;
	}

	if (hasFirstMinus && !hasSecondMinus)
	{
		cout << "-" << firstNumber << " * " << secondNumber << " = -" << result << endl;
	}
	else if (!hasFirstMinus && hasSecondMinus)
	{
		cout << firstNumber << " * -" << secondNumber << " = -" << result << endl;
	}
	else
	{
		if (hasFirstMinus && hasSecondMinus)
		{
			cout << "-" << firstNumber << " * -" << secondNumber << " = " << result << endl;
		}
		else
		{
			cout << firstNumber << " * " << secondNumber << " = " << result << endl;
		}
	}
}

int main()
{
	char firstNumber[8193];
	char secondNumber[8193];
	bool hasFirst = false, hasSecond = false;

	cin >> firstNumber;
	cin >> secondNumber;

	equal(firstNumber, secondNumber);
	compare(firstNumber, secondNumber);
	add(firstNumber, secondNumber, hasFirst, hasSecond);
	subtract(firstNumber, secondNumber, hasFirst, hasSecond);
	multiply(firstNumber, secondNumber, hasFirst, hasSecond);

	return 0;
}