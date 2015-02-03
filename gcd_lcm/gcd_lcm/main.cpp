#include <iostream>
using namespace std;

//�����������Լ��--ŷ������㷨
int gcd(int a, int b)
{
 if (a < b)
  swap(a, b);

 if (b == 0)
  return a;
 else
  return gcd(b, a%b);
}

//n���������Լ���㷨
//˵��: 
//��n��������Ϊһ������
//����Ϊ�����ָ�������Ĵ�С(��Ҫ��������ĸ���)
//Ȼ�������gcd(a[0],a[1]), Ȼ�������gcd���������һ��Ԫ����Ϊgcd�Ĳ���������gcd
//�����Ͳ���һ���ݹ����ngcd���㷨
int ngcd(int *a, int n)
{
 if (n == 1)
  return *a;

 return gcd(a[n-1], ngcd(a, n-1));
}

//����������С������(lcm)�㷨
//lcm(a, b) = a*b/gcd(a, b)
int lcm(int a, int b)
{
 return a*b/gcd(a, b);
}

//n��������С�������㷨
//�㷨���̺�n���������Լ��������
//���ͷ��������С������,�ٽ��ۺʹ�����������С������ֱ������ĩβ
//��������һ���ݹ����nlcm���㷨
int nlcm(int *a, int n)
{
 if (n == 1)
  return *a;
 else
  return lcm(a[n-1], nlcm(a, n-1));
}

int main()
{
	int a = 14;
	int b = 12;
	cout << gcd(a, b) << endl;

	int aa;
	cin >> aa;
}