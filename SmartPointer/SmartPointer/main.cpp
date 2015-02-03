#include <iostream>

using namespace std;


//实际上用static变量来计数是不对的，因为引用计数并不是这个类的一般属性，应该用int*
template <class T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
	{
		ref = ptr;
		ref_cnt = 1;
	}
	SmartPointer(SmartPointer<T>& ptr)
	{
		ref = ptr.ref;
		++ptr.ref_cnt;
	}
	~SmartPointer()
	{
		--(ref_cnt);
		if (ref_cnt == 0)
		{
			delete ref;
			cout << "delete object" << endl;
		}
	}
	T GetVal()
	{
		return *ref;
	}
private:
	T* ref;
	static unsigned int ref_cnt;
};

template <typename T>
unsigned int SmartPointer<T>::ref_cnt = 0;
	
//template <class T>
//class SmartPointer
//{
//public:
//	SmartPointer(T* ptr)
//	{
//		ref = ptr;
//		ref_cnt = new unsigned int(1);
//	}
//	SmartPointer(SmartPointer<T>& ptr)
//	{
//		ref = ptr.ref;
//		ref_cnt = ptr.ref_cnt;
//		++(*ref_cnt);
//	}
//	~SmartPointer()
//	{
//		--(*ref_cnt);
//		if (*ref_cnt == 0)
//		{
//			delete ref;
//			delete ref_cnt;
//			cout << "delete object" << endl;
//		}
//	}
//
//	T GetVal()
//	{
//		return *ref;
//	}
//private:
//	T* ref;
//	unsigned int* ref_cnt;
//};

void UseSmartPointer()
{
	SmartPointer<int> sptr = SmartPointer<int>(new int(100));
	cout << sptr.GetVal() << endl;
}

int main()
{
	UseSmartPointer();
	int aa;
	cin >> aa;
}