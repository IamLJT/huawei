/***************************************************
Name: Soduka
Data: 2017/03/14
Func: ����������������Sudoku����һ�����ϲ���������߼���Ϸ��
�����Ҫ����9X9�����ϵ���֪���֣����������ʣ��ո�����֣�
��������ÿһ�С�ÿһ�С�ÿһ�����߹��ڵ����־���1-9�����Ҳ��ظ���
���룺
������֪���ֵ�9X9��������[��ȱλ������0��ʾ]
�����
������9X9��������
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