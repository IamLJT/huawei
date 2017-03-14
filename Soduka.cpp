/***************************************************
Name: Soduka
Data: 2017/03/14
Func: 问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。
玩家需要根据9X9盘面上的已知数字，推算出所有剩余空格的数字，
并且满足每一行、每一列、每一个粗线宫内的数字均含1-9，并且不重复。
输入：
包含已知数字的9X9盘面数组[空缺位以数字0表示]
输出：
完整的9X9盘面数组
****************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindLose(vector<vector<int>> Soduka, int row, int col)
{
	vector<int> res;
	vector<bool> r(9, 1), l(9, 1), m(9, 1);
	for (int i = 0; i < 9; ++i) {
		if (Soduka[row][i] != 0)
			r[Soduka[row][i] - 1] = 0;
		if (Soduka[i][col] != 0)
			l[Soduka[i][col] - 1] = 0;
		if (Soduka[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != 0)
			m[Soduka[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] - 1] = 0;
	}
	for (int i = 0; i < 9; ++i) {
		if (r[i] == 1 && r[i] == m[i] && m[i] == l[i])
			res.push_back(i + 1);
	}
	return res;
}

void FillSoduka(vector<vector<int>>& Soduka)
{
	vector<vector<int>> temp = Soduka;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (Soduka[i][j] != 0)
				continue;
			vector<int> res = FindLose(Soduka, i, j);
			if (res.size() == 1)
				Soduka[i][j] = res[0];
		}
	}
	if (Soduka == temp)
		return;
	FillSoduka(Soduka);
}

int main(void)
{
	vector<vector<int>> Soduka(9, vector<int>(9, 0));
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> Soduka[i][j];
	FillSoduka(Soduka);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j == 8)
				cout << Soduka[i][j];
			else
				cout << Soduka[i][j] << " ";
		}
			
		cout << endl;
	}
	system("pause");
	return 0;
}