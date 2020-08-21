#include <iostream>
using namespace std;

void sort(long arr[], int n)
{
    if (n == 1) return;
    
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int helper = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = helper;
        }
    }
        
    sort(arr, n - 1);
}

void insertSorted(long x, long arr[], long n)
{
    arr[n] = x;
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    long x = 0, n;
    long arr[50]; 
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, n);
    insertSorted(x, arr, n);

    return 0;
}
