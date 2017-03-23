/************************************************
Name: 寻找等差数列
Data: 2017/03/19
Func: 在给定的区间范围内找出所有素数能构成的最大的等
差数列（即等差数列包含的素数个数最多）
************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> SameDiff(vector<bool> prime, int diff, int s)
{
	vector<vector<int>> res(diff, vector<int>(prime.size(), 0));
	vector<int> out;
	int max = 0, e = -1, d = 0;
	for (int i = 0; i < prime.size(); ++i) {
		if (prime[i]) {
			res[0][i] = 1;
			e = i;
		}
	}
	for (int i = 1; i < diff; ++i) {
		for (int j = s; j < prime.size(); ++j) {
			if (j < i) continue;
			if (prime[j] && prime[j - i]) {
				res[i][j] = res[i][j - i] + 1;
				if (max < res[i][j]) {
					max = res[i][j];
					e = j;
					d = i;
				}
			}
		}
	}
	for (int i = e; i >= s && prime[i]; i -= d) {
		out.push_back(i);
		if (d == 0)
			break;
	}
		
	return out;
}

vector<int> FindPrime(int i, int j)
{
	vector<bool> num(j + 1, 0);
	for (int k = 2; k <= j; ++k)
		num[k] = 1;
	for (int k = 0; k <= j; ++k) {
		if (num[k] == true) {
			int n = k + k;
			// 如果为真，就去掉它的倍数
			while (n <= j) {
				num[n] = 0;
				n += k;
			}
		}
	}
	for (int k = 2; k < i; ++k)
		num[k] = 0;
	return SameDiff(num, j - i, i);
}

int main()
{
	int s, e;
	cin >> s >> e;
	vector<int> res = FindPrime(s, e);
	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i];
		if (i != 0) cout << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}