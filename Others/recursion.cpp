#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int fibonacciNumber(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    return (n % 10) + sumOfDigits(n / 10);
}

int reverseNumber(int n, int power)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 * pow(10, power) + reverseNumber(n / 10, --power);
}

int reverse(int n, int reversed) 
{
    if (n == 0)
    {
        return reversed;
    }

    return reverse(n / 10, reversed * 10 + n % 10);
}

bool isPalindrome(int start, int end, const char* str)
{
    if (start >= end) return 1;

    if (str[start] != str[end]) return 0;

    return isPalindrome(++start, --end, str);  
}

/*Зад. 5 По зададени N и M, да се изведат всички възможни N-торки от цифри, чиято сума е равна на M.
Пример N = 3 M = 4
0 0 4 
0 1 3
0 2 2
0 3 1
0 4 0
1 0 3
1 1 2
1 2 1
1 3 0
2 0 2
2 1 1
2 2 0
3 0 1
3 1 0
4 0 0*/

void allPairsHelper(int n, int m, char* arr, int index) 
{ 
    // Base case 
    if (index > n || m < 0) return; 
  
    // If number becomes N-digit 
    if (index == n) 
    { 
        // if sum of its digits is equal to given sum, print it 
        if(m == 0) 
        { 
            arr[index] = '\0'; 
            cout << arr << " "; 
        } 
        return; 
    } 
  
    // Traverse through every digit. Note that here we're considering leading 0's as digits 
    for (int i = 0; i <= 9; i++) 
    { 
        // append current digit to number 
        arr[index] = i + '0'; 
  
        // recurse for next digit with reduced sum 
        allPairsHelper(n, m - i, arr, index + 1); 
    } 
} 

void allPairs(int n, int m) 
{ 
    // output array to store N-digit numbers 
    //char arr[n + 1];
    char arr[10]; 
  
   // fill 1st position by every digit from 1 to 9 and calls findNDigitNumsUtil() for remaining positions 
    for (int i = 1; i <= 9; i++) 
    { 
        arr[0] = i + '0'; 
        allPairsHelper(n, m - i, arr, 1); 
    } 
} 

int lengthOfNumber(int n)
{
    int counter = 0;

    while (n != 0)
    {
        counter++;
        n /= 10;
    }

    return counter;
}

bool isKInNumber(int n, int k)
{
    if (n % 10 == k)
    {
        return true;
    }

    if (n == 0)
    {
        return false;
    }
    
    return isKInNumber(n / 10, k);
}

bool isMonotonousDecreasing(int* arr, int size, int index, int counter)
{
    if (counter == size)
    {
        return true;
    }

    if (index == size)
    {
        return false;
    }

    if (*arr >= *(arr + 1))
    {
        return isMonotonousDecreasing(arr + 1, size, index + 1, counter + 1);
    }

    return isMonotonousDecreasing(arr + 1, size, index + 1, 1);   
}

bool isFromEqualElements(int* arr, int size, int index, int counter)
{
    if (counter == size)
    {
        return true;
    }

    if (index == size)
    {
        return false;
    }

    if (*arr == *(arr + 1))
    {
        return isFromEqualElements(arr + 1, size, index + 1, counter + 1);
    }
    
    return isFromEqualElements(arr + 1, size, index + 1, 1);
}

bool isKFromArray(int* arr, int size, int index, int n)
{
    if (*arr == n)
    {
        return true;
    }

    if (index == size)
    {
        return false;
    }
    
    return isKFromArray(arr + 1, size, index + 1, n);
}

void printArray(int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
}

void resize(int* arr, int &size)
{
   int* resize_arr = new int[size + 1];

   for(int i = 0; i < size; i++)
   {
       *(resize_arr + i) = *(arr + i);
   }

   size++;
   arr = resize_arr;
   delete[] resize_arr;
}

void addElementInSortedArray(int* arr, int size, int index, int element, bool flag)
{
    if (flag)
    {
        return;
    }
    
    if (*arr > element)
    {
        for (size_t i = size; i >= index; i--)
        {
            *(arr + i + 1) = *(arr + i);   
        }

        arr[index] = element;
        flag = true;   
        printArray(arr, size);
        cout << endl;
    }
    
    addElementInSortedArray(arr + 1, size, index + 1, element, flag);
}

int binarySearch(int* arr, int size, int element)
{
    int left = 0, right = size;

    while (left < right)
    {
        int middle = (left + right) / 2;

        if (arr[middle] == element)
        {
            return middle;
        }
        
        if (arr[middle] < element)
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

void deleteElementRecursively(int* arr, int size, int index, int element)
{
    if (*arr == element)
    {
        for (int i = index; i < size - 1; i++) 
        {
            arr[i] = arr[i + 1];   
        }  

        return;
    }

    deleteElementRecursively(arr + 1, size, index + 1, element);   
}

bool areEqual(int num1, int num2)
{
    if (num1 % 10 == num2 % 10)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return areEqual(num1 / 10, num2 / 10);
}

int removeDigit(int num, int position)
{
    int newNumber = 0, length = lengthOfNumber(num), back = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (i != position)
        {
            newNumber += num % 10 * pow(10, i - back);
        }
        else
        {
            back++;
        }
        
        num /= 10;
    }
    
    return newNumber;
}

bool areEqualAfterRemoving(int num1, int num2, int counter)
{
    if (areEqual(removeDigit(num1, counter), num2))
    {
        return true;
    }
    
    if (counter == lengthOfNumber(max(num1, num2)))
    {
        return false;
    }

    return areEqualAfterRemoving(num1, num2, counter + 1);
}

void reverseArray(int arr[], int start, int end)
{
    if (start >= end) return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

bool exactMatch(char* text, char* pat)
{
    if (*text == '\0' && *pat != '\0')
        return false;

    if (*pat == '\0')
        return true;

    if (*text == *pat)
        return exactMatch(text + 1, pat + 1);

    return false;
}

bool contains(char* text, char* pat)
{
    if (*text == '\0')
        return false;

    if (*text == *pat)
        if (exactMatch(text, pat))
            return 1;
        else
            return contains(text + 1, pat);

    return contains(text + 1, pat);
}

int main()
{
    unsigned n;
    //cin >> n;

    //cout << factorial(n);
    //cout << endl;
    //cout << fibonacciNumber(n);
    //cout << endl;
    //cout << sumOfDigits(n);
    //cout << endl;
    //cout << reverseNumber(n, lengthOfNumber(n) - 1);
    //cout << endl;
    //cout << isPalindrome(0, 4, "abcba");
    //cout << isPalindrome(0, 5, "abccza");
    //cout << endl;
    //allPairs(3, 4);

    //cout << isKInNumber(1278, 7);
    int arr[6] = { 4, 5, 5, 7, 9, 10 };
    int size = 6;
    cout << isMonotonousDecreasing(arr, size, 0, 1);
    cout << isFromEqualElements(arr, size, 0, 1);
    cout << isKFromArray(arr, size, 0, 5);

    int* arr2 = new(nothrow) int[6];

    bool flag = false;

    //resize(arr, size);
    //for (int i = size - 1; i >= 0; i--)
    //{
        //*(arr + i) = *(arr + i - 1); 
    //} 
    //printArray(arr, size);
    //addElementInSortedArray(arr, size, 0, 8, flag);

    //resize(arr, size);
    //printArray(arr, size);

    int arr3[6] = { 4, 5, 5, 7, 9, 10 };

    //deleteElementRecursively(arr3, size, 0, 9);
    //printArray(arr3, size);

    cout << endl;
    cout << areEqualAfterRemoving(1025, 125, 0);
    cout << areEqualAfterRemoving(13, 125, 0);
    //cout << removeDigit(1456, 2);
    
    delete[] arr2;

    return 0;
}