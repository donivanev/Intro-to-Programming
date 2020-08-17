#include <iostream>
using namespace std;

bool duplicates(long *pointers[])
{
	bool isDuplicate = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (pointers[i] == pointers[j])
			{
				isDuplicate = true;
			}
		}
	}

	return isDuplicate;
}

int main()
{
	long* pointers[10];
	long arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	//for (int i = 0; i < 10; i++) 
	//{
		//pointers[i] = &arr[i];
	//}

	for (int i = 0; i < 10; i++)
	{
		cout << pointers[i] << endl;
	}

	duplicates(pointers) == true ?
		cout << "There are at least 2 equal elements." : cout << "There aren't at least 2 equal elements.";

	return 0;
}