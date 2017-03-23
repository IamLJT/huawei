/********************************************************
Name: 完全数计算
Data: 2017/03/21
Func: 完全数（Perfect number），又称完美数或完备数，是一些特
殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好
等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个
数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围,
0 < n <= 500000
返回n以内完全数的个数。异常情况返回-1
********************************************************/

#include <iostream>
using namespace std;

bool isPerfect(int n)
{
	int sum = 0, i = n/2;
	while (i * i > n) {
		if (n % i == 0) {
			sum += i;
			sum += n / i;
		}
		i--;
	}
	if (sum + 1 == n)
		return true;
	else
		return false;
}

int main()
{
	int n, count = 0;
	cin >> n;
	if (n == 1)
		return -1;
	for (int i = 2; i <= n; ++i) {
		if (isPerfect(i))
			count++;
	}
	cout << count << endl;

	system("pause");
	return 0;
}