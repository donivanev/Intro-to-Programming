//
// �� "��. ������� ��������"
// �������� �� ���������� � �����������
// ���� ���� � �������������� 2020/21
// ��������� 1
// 2020-11-29
//
// ������� ���: 9:00
// ���: ����
// ��: 81992
// �����������: �� 1
// ����: 2
// ��������������� �����: 2
// ��������� ����������: VS
//

bool isPrime(int number)
{
	if (number <= 1) return false;

	for (size_t i = 2; i < number; i++)
	{
		if (number % i == 0) return false;
	}

	return true;
}

int countOfDivisors(int number)
{
	unsigned counter = 0;

	for (size_t i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			counter++;
		}
	}

	return counter;
}

#include <iostream>
using namespace std;

int main()
{
	unsigned int a, b, counter = 0;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	for (size_t i = a; i < b; i++)
	{
		if (isPrime(countOfDivisors(i)))
		{
			counter++;
		}
	}

	cout << counter;

	return 0;
}


