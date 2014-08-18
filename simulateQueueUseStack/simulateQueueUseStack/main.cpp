#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class MyQueue
{
public:
	void push(T value);
	void pop();
	T front();
	T back();
	bool empty();
private:
	stack<T> stackPush;
	stack<T> stackPop;
};

template <typename T>
void MyQueue<T>::push(T value)
{
	stackPush.push(value);
}

template <typename T>
void MyQueue<T>::pop()
{
	if (stackPop.empty())
	{
		while (!stackPush.empty())
		{
			stackPop.push(stackPush.top());
			stackPush.pop();
		}
	}

	if (!stackPop.empty())
	{
		stackPop.pop();
	}
}

template <typename T>
T MyQueue<T>::front()
{
	if (stackPop.empty())
	{
		while (!stackPush.empty())
		{
			stackPop.push(stackPush.top());
			stackPush.pop();
		}
	}

	if (!stackPop.empty())
	{
		return stackPop.top();
	}
}

template <typename T>
T MyQueue<T>::back()
{
	if (!stackPush.empty())
	{
		return stackPush.top();
	}
	else if (!stackPop.empty())
	{
		stack<T> stackTmp;
		while (!stackPop.empty())
		{
			stackTmp.push(stackPop.top());
			stackPop.pop();
		}
		int res = stackTmp.top();
		while (!stackTmp.empty())
		{
			stackPop.push(stackTmp.top());
			stackTmp.pop();
		}
		return res;
	}
	else
	{
		T a;
		return a;
	}
}

template <typename T>
bool MyQueue<T>::empty()
{
	if (stackPush.empty() && stackPop.empty())
		return true;
	return false;
}


int main()
{
	MyQueue<int> q;
	q.push(1);
	q.push(2);
	q.pop();
	cout << q.front() << endl;
	int aa;
	cin >> aa;
}