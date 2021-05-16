#include <iostream>
using namespace std;

/*
Distance between two points
Three points on the same line
Sum of digits of a number
Reverse a number
Min/Max
Are digits ascending
Are digits unique
Increasing sequence
Extract numbers from string
Delete element
Frequency letters

Pass function to another function
Dynamic Allocation

Remove duplicates
Palindrome
Reverse a string
Subsequence


Basic algorithms
    - Greatest common divisor
    - Swap two variables
    - Prime number
    - Run-length encoding
    - Sorting algorithms (Bubble, Selection, Insertion, [Merge], [Heap], [Quick])
    - Binary-search
*/

//int (*f)(int, int*); 
//bool (*f)(int)

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b) a = a - b;
        else b = b - a; 
    }
 
    return a;
}

int swap(int* a, int* b)
{
    int helper = *a;
    *a = *b;
    *b = helper;
}

bool isPrime(int number)
{
	if (number <= 1) return false;

	for (int i = 2; i < number; i++)
	{
		if (number % i == 0) return false;
	}

	return true;
}

void printRLE(const char* str)
{
    int n = strlen(str);

    for (int i = 0; i < n; i++) 
    {
        int count = 1;

        while (i < n - 1 && str[i] == str[i + 1]) 
        {
            count++;
            i++;
        }
 
        cout << str[i] << count;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 1; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                if (i != j)
                {
                    int helper = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = helper;
                }
                swapped = true;
            }       
        }

        if (!swapped) return;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        
        if (minIndex != i)
        {
            int helper = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = helper;       
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i, key = arr[i];

        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }

        arr[j] = key;
    }
}

int search(int array[], int x, int size)
{
    for(int i = 0; i < size; ++i)
    {
        if (array[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int x, int n)
{
    unsigned left = 0, right = n;

    while (left < right)
    {
        int middle = (left + right) / 2;
 
        if (arr[middle] == x) 
        {
            return middle;
        }
        
        if (arr[middle] < x)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }
    
    return -1;
}

void findRange(int array[], int x, unsigned n)
{
    unsigned left = 0, right = n;

    while (left < right) 
    {
        unsigned middle = (left + right) / 2;
        if (array[middle] < x)
            left = middle + 1;
        else
            right = middle;
    }
    if (array[left] != x)
        return;

    int lb = left;

    right = n;
    while (left < right) 
    {
        unsigned middle = (left + right) / 2;
        if (array[middle] <= x)
            left = middle + 1;
        else
            right = middle;
    }
    int rb = left;

    cout << "[" << lb << ", " << rb << "]" << endl;
}

void readMatrix(int * const * const matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            cin >> matrix[i][j];
}

void printMatrix(const int * const * const matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; ++i) 
    {
        for (size_t j = 0; j < columns; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

int ** allocMatrixByRows(size_t rows, size_t columns)
{
    int ** matrix = new(nothrow) int*[rows];
    if (!matrix) return matrix;

    for (size_t i = 0; i < rows; ++i) 
    {
        matrix[i] = new(nothrow) int[columns];
        if (!matrix[i]) 
        {
            clearMatrixByRows(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

void clearMatrixByRows(int ** matrix, size_t rows)
{
    for (size_t i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = { 6, 3, 1, 7, 4, 8};

    //bubbleSort(arr, 6);
    //selectionSort(arr, 6);
    //insertionSort(arr, 6);
    //cout << binarySearch(arr, 7, 6);
    //findRange(arr, 3, 6);
    //print(arr, 6);

    /*int ** m = nullptr;

    m = allocMatrixByRows(3, 4);
    if (!m) return 1;
    readMatrix(m, 3, 4);
    printMatrix(m, 3, 4);
    clearMatrixByRows(m, 3);
    */

    return 0;
}