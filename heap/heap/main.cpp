#include <iostream>

using namespace std;

//�������ѡ��������ŵ����ڣ�ÿ����ѡ��Сֵʱ��ѡ��������Ҫi-1�αȽϣ����������������˶ѽṹ����¼�˽ڵ�Ĵ�С��Ϣ���ܸ������������Сֵ
//ʱ�临�Ӷ���O(lgn)

//��С�ѵĴ���: ��������洢

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��idx�ڵ����µ��������ʵ�λ�ã�����������������С��
void shiftDown(int arr[], int idx, int len)
{
	int min = 2 * idx + 1;  //left child

	while (min < len)
	{
		if (min + 1 < len && arr[min] > arr[min + 1]) //�ҵ����Һ��ӽڵ�����С���Ǹ�
			min++;

		if (arr[min] < arr[idx])
		{
			swap(arr + idx, arr + min);
			idx = min;
			min = 2 * idx + 1;
		}
		else
			break;
	}
}
//������Ϊn�����飬ת���ɶѽṹ
void createMinHead(int arr[], int len)
{
	int idx = (len - 2) / 2;  // ���ҵ����һ����Ҷ�ӽڵ㣬�����һ����Ҷ�ӽڵ㿪ʼ����

	while (idx >= 0)
	{
		shiftDown(arr, idx, len);
		--idx;
	}
}

//ͬ����������
void shiftUp(int arr[], int idx, int len)
{
	int max = 2 * idx + 1;  //left child

	while (max < len)
	{
		if (max + 1 < len && arr[max] < arr[max + 1]) //�ҵ����Һ��ӽڵ�����С���Ǹ�
			max++;

		if (arr[max] > arr[idx])
		{
			swap(arr + idx, arr + max);
			idx = max;
			max = 2 * idx + 1;
		}
		else
			break;
	}
}

void createMaxHead(int arr[], int len)
{
	int idx = (len - 2) / 2;  // ���ҵ����һ����Ҷ�ӽڵ㣬�����һ����Ҷ�ӽڵ㿪ʼ����

	while (idx >= 0)
	{
		shiftUp(arr, idx, len);
		--idx;
	}
}

void show(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int heap[]={53,17,78,9,45,65,87,23};
	show(heap, 8);
	createMinHead(heap, 8);
	show(heap, 8);
	createMaxHead(heap, 8);
	show(heap, 8);
	int aa;
	cin >> aa;
}