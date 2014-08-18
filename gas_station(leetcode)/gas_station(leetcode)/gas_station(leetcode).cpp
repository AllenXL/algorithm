// gas_station(leetcode).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;


int canCompleteCircuit1(vector<int> &gas, vector<int> &cost) {
 
 // 问题转化为求以最后一个gas结尾的最大和子序列，如果total >= 0,必有解，且解即为上述最大和子序列的开头节点

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

//任意选择一个加油站作为开始，一直往下走，如果到达某一站加的油减去耗费的油为负值，
//则选择截至的那个加油站的下一站作为起始站，继续计算 ; 直到计算完所有加油站为止。
//最后需要检测一下选择的起始站，能否跑完全程。
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

