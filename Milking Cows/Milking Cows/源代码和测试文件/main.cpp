/*
ID:o6785431
PROG:milk2
LANG:C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int N, enleft=1000000 , enright=0;//N��farmer������ ,enleft�ǵ�һ��farmer��ʼ��ʱ�䣬enright�����һ��farmer������ʱ��
    int longest_milked = 0 , longest_interval = 0 ;
    int i=0 , j=0 ;
    int tmp=0 , interval=0;

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    fin>>N;
    int * left = new int[N];//��¼ÿ��farmer��ʼʱ��
    int *right = new int[N];//��¼ÿ��farmer����ʱ��

    for(i=0;i<N;++i)
    {
        fin>>left[i];
        if(left[i]<enleft) enleft=left[i];
        fin>>right[i];
        if(right[i]>enright) enright=right[i];
    }
   // cout<<enleft<<' '<<enright<<endl;
    interval = enright - enleft;//�ӵ�һ����ʼ�����һ�������ļ��
    bool *flag = new bool[interval];//���������˼��̵�ʱ����Ϊ1
    for (i = 0; i<interval; ++i) flag[i]=false;
    for (i=0;i<N;++i)
    {
        for (j=left[i];j<right[i];++j) flag[j-enleft]=true;
    }

     delete left;
     delete right;

    int k=enleft;
    while(k<enright)
    {

       tmp=0;
       while (k < enright && flag[k-enleft] == true) {tmp++; k++;}
       if(tmp>longest_milked) longest_milked = tmp;
       tmp=0;
       while (k < enright && !flag[k-enleft]) {tmp++; k++;}

       if(tmp>longest_interval) longest_interval = tmp;
       //cout<<"tmp:"<<tmp<<"enleft:"<<enleft<<endl;
    }

   fout<<longest_milked<<' '<<longest_interval<<endl;
    //cout<<longest_milked<<' '<<longest_interval<<endl;

   fin.close();
   fout.close();

   delete flag;

   return 0;

}
