//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Име: Дони Иванов
// ФН: 81992
// Специалност: Компютърни науки
// Курс: 2
// Административна група: 2 
// Използван компилатор: Visual Studio
//

#include <iostream>
using namespace std;

const int MAX_COLS = 100;

void deleteMatrix(char** matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

char** allocateMatrix(int rows, int cols)
{
	char** matrix = new(nothrow) char* [rows];
	if (!matrix) return matrix;

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new(nothrow) char[cols];

		if (!matrix[i])
		{
			deleteMatrix(matrix, i);
			return nullptr;
		}
	}

	return matrix;
}

void readMatrix(char** matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		cin.getline(matrix[i], 100);
	}
}

void showMatrix(char** matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		cout << matrix[i] << endl;
	}
}

bool isLetter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
	{
		return true;
	}

	return false;
}

int countWords(const char* text)
{
	int counter = 0;

	while (*text)
	{
		while (*text && !isLetter(*text))
		{
			++text;
		}
		if (*text)
		{
			++counter;
		}
		while (isLetter(*text))
		{
			++text;
		}
	}

	return counter;
}

int extractWords(const char* text, char*** wordsPtr)
{
	int len = countWords(text);
	*wordsPtr = new(nothrow) char* [len];
	if (!*wordsPtr) return 0;

	for (size_t i = 0; i < len; i++)
	{
		while (*text && !isLetter(*text))
		{
			++text;
		}

		if (*text)
		{
			const char* start = text;
			while (isLetter(*text))
			{
				++text;
			}

			int len = text - start;
			*(wordsPtr)[i] = new(nothrow) char[len + 1];
			if (!*(wordsPtr)[i])
			{
				cout << "Memory problem with letter " << i;
				return i; 
			}

			for (size_t pos = 0; pos < len; pos++)
			{
				*(wordsPtr)[i][pos] = start[pos];
			}
			*(wordsPtr)[i][len] = '\0';
		}
	}

	return len;
}

int main()
{
	int n;
	cin >> n;

	char** words = allocateMatrix(n + 1, MAX_COLS);

	readMatrix(words, n + 1);
	showMatrix(words, n + 1);

	int m;
	cin >> m;
	char* text = new(nothrow) char[m + 1];

	cin.ignore();
	cin.getline(text, m + 1);
	cout << text;

	//char** wordsInText = allocateMatrix(n + 1, MAX_COLS);
	//int len = extractWords(text, &wordsInText);

	deleteMatrix(words, n + 1);
	delete[] text;

	return 0;
}