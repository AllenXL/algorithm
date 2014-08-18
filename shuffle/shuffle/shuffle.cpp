// shuffle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

//int cnt=0;
//
//void swap(int* a,int* b)
//{
//	int temp=*a;
//	*a=*b;
//	*b=temp;
//}
//void Perm(int* a,int n)
//{
//	if(n==1)
//	{
//		cout<<sum<<": ";
//		for(int i=0;i<n;i++)
//			cout<<a[i]<<" ";
//		sum++;
//	}
//	else
//	{
//		for(int i=0;i<n;i++)
//		{
//			swap(a+i,a+n-1);
//			Perm(a,n-1);
//		}
//	}
//
//}
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	//srand((int)time(0));
//	//for(int i=0;i<10;i++)
//	//	cout<<rand()%10<<endl;
//	return 0;
//}


int n = 0;

void swap(char *a ,char *b)  
{  
    int m ;  
    m = *a;  
    *a = *b;  
    *b = m;  
}   
   
void perm(char list[],int begin, int end )  
{  
    int i;  
    if(begin >= end)  
    {  
        for(i = 0 ; i <= end ; i++)  
        {  
            cout<<"r"<<list[i];  
               
        }  
        cout<<endl;  
		n++;
        return; 
    }  
    else  
    {  
        for(i = begin ; i <= end;i++)  
        {  
            swap(&list[begin],&list[i]); 			
            perm(list,begin + 1,end);  
            swap(&list[begin],&list[i]);  
        }  
    }  
}  


string countAndSay(int n) {
        if (n <= 0)
        {
            return string("");
        }
        
        if (n == 1)
        {
            return string("1");
        }
        string str_prev = countAndSay(n-1);
		cout<<str_prev<<endl;
        string str_res;
        int j=0;
        int cnt=1;
        char temp = str_prev[0];
        char cnt_str[10];
        for(int i=1; i<str_prev.size(); i++)
        {
            if (str_prev[i] == temp)
            {
                cnt++;
            }
            else
            {
                sprintf(cnt_str, "%d%c", cnt, temp);
                str_res += string(cnt_str);
                cnt = 1;
                temp = str_prev[i];
            }
        }
        
        if (cnt != 0)
        {
            sprintf(cnt_str, "%d%c", cnt, temp);
            str_res += string(cnt_str);
        }
        
        return str_res;
    }
  
int main()  
{  
   /* char list[] ="123";  
    perm(list,0,2);  
    cout<<"total:"<<n<<endl;*/ 

	string res = countAndSay(5);
	cout<<res<<endl;


    return 0;  
}  

