#include <iostream>
#include <cstring>
using namespace std;

/*
Зад 1. Да се имплементира програма, която чете от входа char масив (с големина да 100 символа) и извежда всяка дума от този 
масив на нов ред.
    Примерeн вход. test Hello World
    Примерен изход. 
    test
    Hello
    World

Зад 2. Валидирайте (посредством функция) char* дали представлява валидна последователност от ходове на шахматен кон.  
Ход на коня се представя като двойка char символи симвори от вида <A-H,1-8>.
    Пример.
    A1B3 -> true
    A1B1 -> false

Зад 3. Напишете функция, която приема масив от 8 думи с по-малко от 20 символа всяка (т.е. приема матрица от символи) и 
сортира думите по дължина. Не е важно в какъв ред ще са думите с еднаква дължина след сортирането.
Ако долния пример работи почти по същия начин, но Ruby, Java и Perl са резместени, задачата е решена.

	Примерен вход:	C++  Python  Ruby  Java  Perl  JavaScript  Haskell  C#
	Изход:		C#  C++  Ruby  Java  Perl  Python  Haskell  JavaScript

Зад 4. Напишете функция, която проверява колко пъти се среща дадена дума (< 10 символа) в съответен низ.
    Примерен вход: C++TesttesTCC++C++JavaC++    и C++
    Изход: 4
*/

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

/*void readArray(int arr[][MAX_ROWS], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void printArray(int arr[][MAX_ROWS], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}*/

/*void readMatrix(char matrix[][20], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }
}

void sortMatrix(char matrix[][20], int n)
{
    for (size_t i = 0; i <= n - 1; i++)
    {
        bool swapped = false;

        for (size_t j = 1; j <= n - i - 1; j++)
        {
            if (strlen(matrix[j]) < strlen(matrix[j - 1]))
            {
                if (i != j)
                {
                    char helper[20];
                    strcpy(helper, matrix[j]);
                    strcpy(matrix[j], matrix[j - 1]);
                    strcpy(matrix[j - 1], helper);
                }

                swapped = true;
            }
        }

        if (!swapped) return;
    }
}

void printMatrix(char matrix[][20], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << matrix[i] << " ";
    }
}*/

/*void readMatrix(char** matrix, int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
}*/

/*void printMatrix(char** matrix, int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (matrix[i][j] == ' ')
            {
                cout << endl;
            }
            else
            {
                cout << matrix[i][j];
            }
        }
    }
}*/

void deleteMatrix(char** matrix, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    
    delete[] matrix;
}

char** allocateMatrix(int n, int m)
{
    char** matrix = new(nothrow) char*[n];
    if (!matrix) return matrix;

    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new(nothrow) char[m];
        if (!matrix[i])
        {
            deleteMatrix(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

void printSpiral(int arr[][MAX_ROWS], int n, int m)
{
    int i, startingRowIndex = 0, startingColumnIndex = 0; 
  
    while (startingRowIndex < m && startingColumnIndex < n) 
    { 
        for (i = startingColumnIndex; i < n; ++i) 
        { 
            cout << arr[startingRowIndex][i] << " "; 
        } 
        startingRowIndex++; 
  
        for (i = startingRowIndex; i < m; ++i) 
        { 
            cout << arr[i][n - 1] << " "; 
        } 
        n--; 
  
        if (startingRowIndex < m) 
        { 
            for (i = n - 1; i >= startingColumnIndex; --i) 
            { 
                cout << arr[m - 1][i] << " "; 
            } 
            m--; 
        } 
  
        if (startingColumnIndex < n) 
        { 
            for (i = m - 1; i >= startingRowIndex; --i) 
            { 
                cout << arr[i][startingColumnIndex] << " "; 
            } 
            startingColumnIndex++; 
        } 
    }
}

void multiply(int firstMatrix[][4], int secondMatrix[][4], int resultMatrix[][4])
{
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < 4; k++) resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
        }
    }
}

int formula()
{
    char c, op;
    int x, y;
    cin >> c;

    if (c >= '0' && c <= '9') return c - '0';

    else
    {
        x = formula();
        cin >> op;
        y = formula();
        cin >> c; 
        
        switch (op)
        {
            case '+': return x + y; break;
            case '-': return x - y; break;
            case '*': return x * y; break;
            default: return 111;
        }
    }
}

int main()
{
    int n, m;
    //cin >> n >> m;
    //int arr[MAX_ROWS][MAX_COLS];

    //readArray(arr, n, m);
    //printArray(arr, n, m);
    //printSpiral(arr, n, m);

    //char** matrix = nullptr;

    //matrix = allocateMatrix(n, m);
    //if (!matrix) return 1;
    //readMatrix(matrix, n, m);
    //printMatrix(matrix, n, m);
    //deleteMatrix(matrix, n);

    //char arr[100];
    //cin.getline(arr, 40);
    
    /*for (size_t i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == ' ')
        {
            cout << endl;
        }
        else
        {
            cout << arr[i];
        }
    }*/

    /*bool flag = true;

    for (size_t i = 0; i < strlen(arr); i++)
    {
        if (!((arr[i] >= 'A' && arr[i] <= 'H') || (arr[i] >= '1' && arr[i] <= '9')))
        {
            flag = false;
            break;  
        }
    }
    
    flag ? cout << "true" : cout << "false";*/

    //char matrix[8][20];

    //readMatrix(matrix, n, m);
    //sortMatrix(matrix, n);
    //printMatrix(matrix, n, m);

    char words[50];
    char wordSearch[50];

    //cin >> words;
    //cin >> wordSearch;

    int wordCounter = 0, counter = 0, index = 0, ind = 0;

    for (size_t i = 0; i < strlen(words); i++)
    {
        while (wordSearch[index] == words[i + ind])
        {
            if (index < strlen(wordSearch))
            {
                wordCounter++;
                index++;
                ind++;
            }
            else
            {
                break;
            }
        }

        if (wordCounter == strlen(wordSearch))
        {
            counter++;
        }

        wordCounter = 0;
        index = 0;
        ind = 1;
    }

    //cout << counter;
    
    //C++TesttesTCC++C++JavaC++

    /*int res[4][4]; 
    int mat1[4][4] = { { 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 },
                       { 4, 4, 4, 4 } };
 
    int mat2[4][4] = { { 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 },
                       { 4, 4, 4, 4 } };
 
    multiply(mat1, mat2, res);
 
    cout << "Result matrix is \n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }*/

    char* arr;
    cout << arr;
    
    cout << formula() << "\n";

    return 0;
}