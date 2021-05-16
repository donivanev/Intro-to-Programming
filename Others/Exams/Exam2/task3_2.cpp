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

void deleteMatrix(int** matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

int** allocateMatrix(int rows, int cols)
{
	int** matrix = new(nothrow) int* [rows];
	if (!matrix) return matrix;

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new(nothrow) int[cols];

		if (!matrix[i])
		{
			deleteMatrix(matrix, i);
			return nullptr;
		}
	}

	return matrix;
}

void readMatrix(int** matrix, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void showMatrix(int** matrix, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printFromTo(int* arr, int from, int to)
{
	for (size_t i = from; i < to; i++)
	{
		cout << arr[i] << " ";
	}
}

int* divisibleBy3(int** matrix, int rows, int cols, unsigned& indexI, int* resultArray)
{
	int startIndex = 0;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] % 3 == 0)
			{
				resultArray[indexI] = matrix[i][j];
				indexI++;
			}
		}
		printFromTo(resultArray, startIndex, indexI);
		cout << endl;
		startIndex = indexI;
	}

	return resultArray;
}

void showArray(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	unsigned r, c;
	cin >> r >> c;

	int** matrix = allocateMatrix(r, c);
	if (!matrix) cout << "Problem with memory";

	readMatrix(matrix, r, c);
	showMatrix(matrix, r, c);

	int k;
	cin >> k;
	unsigned indexI = 0;

	int* resultArray = new(nothrow) int[r * c];

	divisibleBy3(matrix, r, c, indexI, resultArray);

	showArray(resultArray, indexI);

	deleteMatrix(matrix, r);
	delete[] resultArray;

	return 0;
}