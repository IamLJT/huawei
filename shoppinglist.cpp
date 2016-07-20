#include <iostream>
#include <vector>
using namespace std;

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

int maxValue(int N, int m, vector<int> v, vector<int> w, vector<int> q)
{
	vector<int> dp(N+1, 0),attach(N+1, 0);
	for(int i=0; i<m; i++)
	{
		for(int j=N; j>=v[i]; j--)
		{
			if(q[i]==0)
				dp[j]=max0(dp[j], dp[j-v[i]]+v[i]*w[i]);
			else
			{
				if(j>=v[i]+v[q[i]-1])
				{
					if((attach[j]==0||attach[j]!=q[i])&&dp[j-v[i]-v[q[i]-1]]+v[i]*w[i]+v[q[i]-1]*w[q[i]-1]>dp[j])
					{
						attach[j]=q[i];
						dp[j]=dp[j-v[i]-v[q[i]-1]]+v[i]*w[i]+v[q[i]-1]*w[q[i]-1];
					}
					else if(attach[j]==q[i]&&attach[j-v[i]]==q[i])
					{
						if(dp[j-v[i]]+v[i]*w[i]>dp[j])
							dp[j]=dp[j-v[i]]+v[i]*w[i];
					}
				}
			}
		}
	}
	return dp.back();
}

int main()
{
	int N, m;
	cin >> N >> m;
	vector<int> v(m, 0), w(m, 0), q(m, 0);
	for(int i=0; i<m; i++)
	{
		cin >> v[i] >> w[i] >> q[i];
		v[i]/=10;
	}
	cout << 10*maxValue(N/10, m, v, w, q) << endl;
	system("pause");
	return 0;
}