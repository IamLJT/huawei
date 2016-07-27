#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//int commonstr(string str1, string str2)
string commonstr(string str1, string str2)
{
	int m=str1.size(), n=str2.size(), max0=0, end=0;
	string res="";
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for(int i=1; i<=m; i++)
	{
		//if(str1[i-1]<='Z'&&str1[i-1]>='A')
		//	str1[i-1]+=32;
		for(int j=1; j<=n; j++)
		{
		//	if(str2[j-1]<='Z'&&str2[j-1]>='A')
		//		str2[j-1]+=32;
			if(str1[i-1]==str2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
		//		dp[i][j]=dp[i-1][j-1]+1;
		//	else
		//		dp[i][j]=max(dp[i][j-1], max0);
		//	max0=max(dp[i][j], max0);
			if(dp[i][j]>max0)
			{
				max0=dp[i][j];
				end=i;
			}
		}
	}
	//return dp.back().back();
	//return max0;
	for(int i=0; i<max0; i++)
	{
		res=str1[end-1]+res;
		end--;
	}
	return res;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	cout << commonstr(str1, str2) << endl;
	system("pause");
	return 0;
}