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

void print(int* arr, int size)
{
	if (size == 0)
	{
		return;
	}

	cout << *arr << endl;
	return print(arr + 1, --size);
}

bool isSorted(int* arr, int index, int size)
{
	if (index == size)
	{
		return true;
	}

	return (*arr < *(arr + 1)) && isSorted(arr + 1, index + 1, size);
}

void copyArray(int* arr, int size, int* helperArr)
{
	if (size == 0)
	{
		return;
	}

	*helperArr = *arr;
	copyArray(arr + 1, --size, helperArr + 1);
}

void expandArray(int* arr, int& size)
{
	int* resize_arr = new(nothrow) int[size + 1];

	int s = size;
	copyArray(arr, s, resize_arr);

	++size;
	arr = resize_arr;
	delete[] resize_arr;
}

void insertInArray(int* arr, int size, int index, int x)
{
	if (size == index)
	{
		arr[index] = x;
		return;
	}

	*(arr + size) = *(arr + size - 1);
	insertInArray(arr + 1, --size, index, x);
}

void insertInSorted(int* arr, int size, int s, int index, int x)
{
	if (s == 0)
	{
		return;
	}
	if (x < *arr)
	{
		expandArray(arr, size);
		insertInArray(arr, size, x, index);
		return;
	}

	insertInSorted(arr + 1, size, --s, index + 1, x);
}

int main()
{
	int n;
	cin >> n;

	int* arr = new(nothrow) int[n]; 

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	print(arr, n);
	cout << "Is array sorted: " << isSorted(arr, 1, n);

	int* resize_arr = new(nothrow) int[n + 1];

	//copyArray(arr, n, resize_arr);
	//expandArray(arr, n);
	//insertInArray(arr, n, 3, 5);
	insertInSorted(arr, n, n, 3, 5);

	print(arr, n);

	delete[] resize_arr;
	delete[] arr;

    return 0;
}
