/*
题目：计算字符串的相似度
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int simstr(string str1, string str2)
{
	int m=str1.size(), n=str2.size();
	vector<vector<int>> num(m+1, vector<int>(n+1, 0));
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(str2[j-1]==str1[i-1])
				num[i][j]=num[i-1][j-1]+1;
			else
				num[i][j]=max(num[i-1][j], num[i][j-1]);
		}
	}
	return num.back().back();
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int len=max(str1.size(), str2.size());
	cout << "1/" << len-simstr(str1, str2)+1 << endl;
	system("pause");
	return 0;
}