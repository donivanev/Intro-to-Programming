#include <iostream>
using namespace std;

int* append(int* a, int* b, int n, int* result)
{
	int index = 0;

	for (int i = 0; i < 2 * n; i++)
	{
		if (i < n)
		{
			result[index] = a[i];
			index++;
		}
		else
		{
			result[index] = b[i - n];
			index++;
		}
	}

	return result;
}

int* mergeSorted(int* a, int* b, int n, int* result)
{
	int index = 0;

	for (int i = 0; i < 2 * n; i++)
	{
		if (i < n)
		{
			result[index] = a[i];
			index++;
		}
		else
		{
			result[index] = b[i - n];
			index++;
		}
	}
	
	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < 2 * n - i - 1; j++)
		{
			if (result[j] > result[j + 1])
			{
				int helper = result[j];
				result[j] = result[j + 1];
				result[j + 1] = result[j];
			}
		}
	}

	return result;
}

int* unionArray(int* a, int* b, int n, int* resultArray)
{
	return 0;
}

int* intersection(int* a, int* b, int n, int &index, int* resultArray)
{
	index = 0; 
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				resultArray[index] = a[i];
				index++;
			}
		}
	}

	return resultArray;
}

int* evens(int* a, int n, int &index, int* evenNumbers)
{
	index = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			evenNumbers[index] = a[i];
			index++;
		}
	}

	return evenNumbers;
}

void print(int n, int index, int* result)
{
	for (int i = 0; i < index; i++)
	{
		cout << result[i] << " ";
	}
}

void printArray(int n, int* result)
{
	for (int i = 0; i < 2 * n; i++)
	{
		cout << result[i] << " ";
	}
}

int main()
{
	int n, index = 0;
	cout << "Enter n: ";
	cin >> n;

	int* a = new int[n];
	int* b = new int[n];
	int* result = new int[2 * n];
	int* evenNumbers = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	append(a, b, n, result);
	printArray(n, result);
	cout << endl;

	mergeSorted(a, b, n, result);
	printArray(n, result);
	cout << endl;

	intersection(a, b, n, index, evenNumbers);
	print(n, index, evenNumbers);
	cout << endl;

	evens(a, n, index, evenNumbers);
	print(n, index, evenNumbers);

	delete[] result;
	delete[] evenNumbers;

	return 0;
}