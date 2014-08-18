// gas_station(leetcode).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;


int canCompleteCircuit1(vector<int> &gas, vector<int> &cost) {
 
 // ����ת��Ϊ�������һ��gas��β�����������У����total >= 0,���н⣬�ҽ⼴Ϊ�������������еĿ�ͷ�ڵ�

        int max_sum = gas[0] - cost[0];
        int start = 0;
        int total = gas[0] - cost[0];
        
        for (int i = 1; i < gas.size(); ++i)
        {
            total += gas[i] - cost[i];
            if (max_sum > 0)
            {
                max_sum += gas[i] - cost[i];
            }
            else
            {
                max_sum = gas[i] - cost[i];
                start = i;
            }
        }
        
        return total >= 0 ? start : -1;
    }

//����ѡ��һ������վ��Ϊ��ʼ��һֱ�����ߣ��������ĳһվ�ӵ��ͼ�ȥ�ķѵ���Ϊ��ֵ��
//��ѡ��������Ǹ�����վ����һվ��Ϊ��ʼվ���������� ; ֱ�����������м���վΪֹ��
//�����Ҫ���һ��ѡ�����ʼվ���ܷ�����ȫ�̡�
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
        
        if (gas.size() == 0 || cost.size() == 0)
        {
            return -1;
        }
        int num = gas.size();
        
        int i = 0;
        int j;
        while (i < num)
        {
			//cout << i << endl;
            int sum = 0;
            int j;
            for (j = 0; j < num; j++)
            {
                int idx = (i + j) % num;
				//cout << idx << endl;
                sum += gas[idx] - cost[idx];
                cout << sum << endl;
                if (sum < 0)
                {
					if ( (i + j) >= num)
					{
						return -1;
					}
					else
					{
						i = idx + 1;
						break;
					}
                }
            }
            if (j == num)
            {
                return i;
            }
            
        }
        
        return -1;
        
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> gas(2);
	vector<int> cost(2);
	gas[0] = 1;
	gas[1] = 2;
	cost[0] = 2;
	cost[1] = 1;

	cout << canCompleteCircuit1(gas, cost) << endl;
	return 0;
}

