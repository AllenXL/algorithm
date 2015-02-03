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
    int N, enleft=1000000 , enright=0;//N是farmer的数量 ,enleft是第一个farmer开始的时间，enright是最后一个farmer结束的时间
    int longest_milked = 0 , longest_interval = 0 ;
    int i=0 , j=0 ;
    int tmp=0 , interval=0;

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    fin>>N;
    int * left = new int[N];//记录每个farmer开始时间
    int *right = new int[N];//记录每个farmer结束时间

    for(i=0;i<N;++i)
    {
        fin>>left[i];
        if(left[i]<enleft) enleft=left[i];
        fin>>right[i];
        if(right[i]>enright) enright=right[i];
    }
   // cout<<enleft<<' '<<enright<<endl;
    interval = enright - enleft;//从第一个开始到最后一个结束的间隔
    bool *flag = new bool[interval];//将所有有人挤奶的时间标记为1
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
