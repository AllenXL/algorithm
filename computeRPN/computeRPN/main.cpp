#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int compute_expr(int num1, int num2, char op)
    {
        switch(op)
        {
            case '+':
            return num1+num2;
            case '-':
            return num1-num2;
            case '*':
            return num1*num2;
            case '/':
            return num1/num2;
        }
    }
    int evalRPN(vector<string> &tokens) {
        //后缀表达式计算
        stack<int> expr;
        
        for (vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); ++iter)
        {
			
            char temp = (*iter).front();
			if ((*iter).size() == 1 && (temp < '0' || temp > '9'))
			{
				int num1 = expr.top(); 
				expr.pop();
                int num2 = expr.top();
				expr.pop();
				int res = compute_expr(num2, num1, temp);
                expr.push(res);
			}
			else
            {
				istringstream iss(*iter);
				int num;
				iss >> num;
                expr.push(num);
            }
        }
        return expr.top();
    }

void main()
{
	vector<string> strVec;
	strVec.push_back(string("-1"));
	strVec.push_back(string("1"));
	strVec.push_back(string("*"));
	strVec.push_back(string("-1"));
	strVec.push_back(string("+"));
	cout << evalRPN(strVec)<<endl;
	int a;
	cin >> a;
	return;
}