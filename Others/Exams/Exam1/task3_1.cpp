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
    const int MAX_SIZE = 100;
    unsigned n;
    
    do
    {
        cout << "Enter n: ";
        cin >> n;
    } while (n < 0 || n > 1000000);

    double arr[MAX_SIZE];

    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "] = ";
        cin >> arr[i];
    }

    unsigned k = 1, m = 0, kMax = 0, mMax = 0;
    bool flag = true;

    while(k < n)
    {
        for (size_t i = 0; i < n; i += k)
        {
            if (i == 0)
            {
                m = abs(arr[i] - arr[i + k]);
            }
            else
            {
                if (i + k <= n)
                {
                    if (abs(arr[i] - arr[i + k]) != m)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        flag = true;
                    }
                }
            }
        }
        if (flag)
        {
            if (k > kMax)
            {
                kMax = k;
            }
            if (m > mMax)
            {
                mMax = m;
            }
            flag = false;
        }
        k++;
    }

    cout << kMax << " " << mMax;

    return 0;
}

