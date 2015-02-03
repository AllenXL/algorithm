#include <iostream>
#include <limits.h>

using namespace std;
/*
 从最后一个数开始，寻找递减序列，记为a, 该序列中的值可以不移动;
 剩下的序列之外的那些元素组成序列b, 则至少需要将b中的元素swap到最后；
 还要找出b中元素的最小值m, 再次从右到左遍历a，找到第一个小于m的元素ai，则ai右边的那些元素也要参与swap;
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

    step += n - pivot_cnt;  //至少要将单调序列外的值移到后面

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
