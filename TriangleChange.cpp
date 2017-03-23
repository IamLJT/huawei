/***********************************************
Name: 杨辉三角的变形
Data: 2017/03/21
Func:       1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4 10 16 19 16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，
是恰好是它上面的数，左上角数到右上角的数，3个数之和
（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。
例如输入3,则输出2，输入4则输出3。
***********************************************/

#include <iostream>
using namespace std;

int getvalue(int row, int i) 
{
	if (row == 1 && i == 1)
		return 1;
	if (i <= 0 || i >= 2 * row)
		return 0;
	return getvalue(row - 1, i - 2) + getvalue(row - 1, i - 1)
		+ getvalue(row - 1, i);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; ++i) {
		if (getvalue(n, i) % 2 == 0) {
			cout << i << endl;
			system("pause");
			return 0;
		}
	}
	cout << -1 << endl;
	system("pause");
	return 0;
}