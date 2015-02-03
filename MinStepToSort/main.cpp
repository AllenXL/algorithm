#include <iostream>
#include <limits.h>

using namespace std;
/*
 �����һ������ʼ��Ѱ�ҵݼ����У���Ϊa, �������е�ֵ���Բ��ƶ�;
 ʣ�µ�����֮�����ЩԪ���������b, ��������Ҫ��b�е�Ԫ��swap�����
 ��Ҫ�ҳ�b��Ԫ�ص���Сֵm, �ٴδ��ҵ������a���ҵ���һ��С��m��Ԫ��ai����ai�ұߵ���ЩԪ��ҲҪ����swap;
*/
int GetMiniStep(int* a, int n)
{
    if (a == NULL || n <= 1)
    {
        return 0;
    }

    int step = 0;

    int i = n -1;
    int pivot = a[n - 1];
    int pivot_cnt = 0;

    int m = INT_MAX;
    while (i >= 0)
    {
        if (a[i] <= pivot)
        {
            pivot = a[i];
            ++pivot_cnt;
        }
        else
        {
            if (a[i] < m)
            {
                m = a[i];
            }
        }
        --i;
    }

    step += n - pivot_cnt;  //����Ҫ�������������ֵ�Ƶ�����

    i = n - 1;
    pivot = a[i];
    pivot_cnt = 0;

    while (i >= 0)   //
    {
        if (a[i] <= pivot)
        {
            pivot = a[i];
            if (m > pivot)
            {
                break;
            }
            ++pivot_cnt;
        }
        --i;
    }

    step += pivot_cnt;

    return step;
}
int main()
{
    int a[] = {1, 2, 1, 1, 3};
    cout << GetMiniStep(a, sizeof(a) / sizeof(int)) << endl;
}
