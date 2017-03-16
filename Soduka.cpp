/***************************************************
Name: Sudoku
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

vector<int> FindLose(vector<vector<int>> Sudoku, int row, int col)
{
	vector<int> res;
	vector<bool> r(9, 1), l(9, 1), m(9, 1);
	for (int i = 0; i < 9; ++i) {
		if (Sudoku[row][i] != 0)
			r[Sudoku[row][i] - 1] = 0;
		if (Sudoku[i][col] != 0)
			l[Sudoku[i][col] - 1] = 0;
		if (Sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != 0)
			m[Sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] - 1] = 0;
	}
	for (int i = 0; i < 9; ++i) {
		if (r[i] == 1 && r[i] == m[i] && m[i] == l[i])
			res.push_back(i + 1);
	}
	return res;
}

void FillSudoku(vector<vector<int>>& Sudoku)
{
	vector<vector<int>> temp = Sudoku;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (Sudoku[i][j] != 0)
				continue;
			vector<int> res = FindLose(Sudoku, i, j);
			if (res.size() == 1)
				Sudoku[i][j] = res[0];
		}
	}
	if (Sudoku == temp)
		return;
	FillSudoku(Sudoku);
}

int main(void)
{
	vector<vector<int>> Sudoku(9, vector<int>(9, 0));
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> Sudoku[i][j];
	FillSudoku(Sudoku);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j == 8)
				cout << Sudoku[i][j];
			else
				cout << Sudoku[i][j] << " ";
		}
			
		cout << endl;
	}
	system("pause");
	return 0;
}