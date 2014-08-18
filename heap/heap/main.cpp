#include <iostream>

using namespace std;

//堆排序比选择排序的优点在于，每次挑选最小值时，选择排序需要i-1次比较，而堆排序由于有了堆结构，记录了节点的大小信息，能更快地搜索出最小值
//时间复杂度是O(lgn)

//最小堆的创建: 利用数组存储

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//将idx节点向下调整到合适的位置，假设其子树已是最小堆
void shiftDown(int arr[], int idx, int len)
{
	int min = 2 * idx + 1;  //left child

	while (min < len)
	{
		if (min + 1 < len && arr[min] > arr[min + 1]) //找到左右孩子节点中最小的那个
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
//将长度为n的数组，转换成堆结构
void createMinHead(int arr[], int len)
{
	int idx = (len - 2) / 2;  // 先找到最后一个非叶子节点，从最后一个非叶子节点开始调整

	while (idx >= 0)
	{
		shiftDown(arr, idx, len);
		--idx;
	}
}

//同理，构造最大堆
void shiftUp(int arr[], int idx, int len)
{
	int max = 2 * idx + 1;  //left child

	while (max < len)
	{
		if (max + 1 < len && arr[max] < arr[max + 1]) //找到左右孩子节点中最小的那个
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
	int idx = (len - 2) / 2;  // 先找到最后一个非叶子节点，从最后一个非叶子节点开始调整

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