#include <iostream>
#include <vector>

using namespace std;

/*
СHi��СHo�����ĳ�����Ա����������һ�е�N��λ�ã���˳��ֱ���Ϊ1..N��ÿ��λ���϶����ҽ���һ���˿�����Ϣ��
ͬʱÿ��λ���϶���һЩ������Ҫ���������е�i��λ�õ���������ΪWi������Ա����ѡ������һЩλ�ý�������
����ֵ��ע����ǣ�һ���б��������M��λ�����г���Q����λ�ö�����һ�������б�ѡ�еĻ�������M��λ���ϵĳ˿�������Q+1���������ˣ���
�ͻᷢ�����˲����Ŀڽǡ�
��СHi��СHo�������ǣ�����ѡ����Щλ�ý��������ڲ������ڽǵ�����£���ɨ�����ܶ��������
*/

//��̬�滮 + ״̬ѹ��
//����ǰi��λ�õ�ѡ�񷽰��Ѿ�ȷ�������ڵ�i+1��λ����˵���Ƿ�ѡ������ȡ����i+1ǰ���M - 1��λ�õ�ѡ�������
//��ѡ��Ϊ1����ѡ��Ϊ0����ôǰM - 1��λ�õ�ѡ��״̬ʵ���Ͽ���ѹ����һ��M - 1λ�����֡�
//���ֻ������״̬���ɣ�f(i, s)��ʾǰi��λ�ӣ����Ҵ�i��ʼ��M - 1λ��ѡ��״̬Ϊs������Ӧ�����ֵ


int countOnes(int s)
{
	int cnt = 0;
	while (s)
	{
		cnt++;
		s &= s - 1;
	}
	return cnt;
}

int GetMax(vector<int>& w, int N, int M, int Q)
{
	vector<vector<int> > dp(N + 1, vector<int>(1 << M - 1));
	for (int i = 1; i <= N; ++i)
	{
		for (int s = 0; s < (1 << M - 1); ++s)
		{
			int ones = countOnes(s);
			if (ones > Q)
			{
				dp[i][s] = 0;
				continue;
			}
			else if (ones == Q)
			{
				dp[i][s] = dp[i - 1][s >> 1];
			}
			else
			{
				dp[i][s] = max(dp[i - 1][s >> 1], dp[i - 1][(s >> 1) | (1 << M - 2)]);
			}

			if (s & (1 << M - 2))
			{
				dp[i][s] += w[i - 1];
			}
		}
	}

	int max = 0;
	for (int i = 0; i < (1 << M - 1); ++i)
	{
		max = max < dp[N][i] ? dp[N][i] : max;
	}
	return max;
}


int main()
{
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<int> w(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> w[i];
	}

	cout << GetMax(w, N, M, Q) << endl;

	int aa;
	cin >> aa;
}