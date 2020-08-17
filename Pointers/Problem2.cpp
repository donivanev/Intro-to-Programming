#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//void swap(int &x, int &y) 
//{ 
    //int temp = x; 
    //x = y; 
    //y = temp; 
//}

int main()
{
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    swap(&a, &b);
    //swap(a, b); 

    cout << "Swapping..." << endl;
    cout << "a = " << a << " b = " << b;

    return 0;
}