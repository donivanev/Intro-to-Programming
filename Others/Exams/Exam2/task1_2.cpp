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

#include <iostream>
using namespace std;

int main()
{
    unsigned a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	bool a4 = (a | 0);
	bool a3 = (a | 1);
	bool a2 = (a & 100);
	bool a1 = (a & 1000);
	//cout << !a1 << " " << !a2 << " " << !a3 << " " << !a4 << endl;

	bool b4 = (a | 0);
	bool b3 = (a | 1);
	bool b2 = (a & 100);
	bool b1 = (a & 1000);
	//cout << b1 << " " << b2 << " " << b3 << " " << b4 << endl;

	//cout << (a1 | b1) << " " << (a2 | b2) << " " << (a3 | b3) << " " << (a4 | b4);
	bool sumBit = 0;

	while (a != 0)
	{
		bool aRemainder = a % 10;
		bool bRemainder = b % 10;
		sumBit = aRemainder | bRemainder;
		cout << sumBit;
		a /= 10;
		b /= 10;
	}

    return 0;
}


