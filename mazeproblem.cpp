/*
题目：迷宫问题
*/

#include <iostream>
#include <vector>
using namespace std;

void mazepath(vector<vector<int>> num, int& flag, int row, int col, vector<pair<int, int>>& res, int& min0, vector<pair<int, int>> temp)
{
	int m=num.size();
	int n=(m==0)?0:num[0].size();
	if(flag==1) 
	{
		if(temp.size()<min0)
		{
			min0=temp.size();
			res.clear();
			res=temp;
		}
		flag=0;
		return;
	}
	if(row<m&&row>=0&&col<n&&col>=0&&num[row][col]!=1&&num[row][col]!=INT_MAX)
	{
		num[row][col]=INT_MAX;
		temp.push_back(make_pair(row, col));
		//	如果走到了右下方，则标记成功
		if(row==m-1&&col==n-1) flag=1;
		//	遍历改点的四个方向
		mazepath(num, flag, row-1, col, res, min0, temp);
		mazepath(num, flag, row+1, col, res, min0, temp);
		mazepath(num, flag, row, col-1, res, min0, temp);
		mazepath(num, flag, row, col+1, res, min0, temp);
		if(flag!=1)
		{
			temp.pop_back();
			num[row][col]=0;
		}
	}
}

vector<pair<int, int>> maze(vector<vector<int>> num)
{
	vector<pair<int, int>> res, temp;
	int flag=0, min0=INT_MAX;  //	访问到右下时为1
	mazepath(num, flag, 0, 0, res, min0, temp);
	return res;
}

int main()
{
	int m,n;
	cin >> m >> n;
	vector<vector<int>> num(m, vector<int>(n, 0));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> num[i][j];
	vector<pair<int, int>> res=maze(num);
	for(int i=0; i<res.size(); i++)
		cout << "(" << res[i].first << "," << res[i].second << ")" << endl;
	system("pause");
	return 0;
}