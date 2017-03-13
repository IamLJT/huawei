/*****************************************
Name: 称砝码
Data: 2017/03/12
Func: 现有一组砝码，重量互不相等，分别为m1、m2
……mn；他们可取的最大数量分别为x1、x2……xn。
现在要用这些砝码去称物体的重量，问能称出多少中
不同的重量。
******************************************/

#include <iostream>
#include <vector>

using namespace std;

int fama(int n, vector<int> weight, vector<int> nums)
{
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; ++i) 
		sum += weight[i] * nums[i];
	vector<bool> dic(sum+1, false);
	dic[0] = true;
	//for (int j = 0; j < n; ++j)
	//	for (int i = 0; i <= sum; i++)
	//		for (int k = 0; k <= nums[j]; ++k)
	//			if (i + k*weight[j] <= sum && dic[i] == true  // 会重复添加
	//				&& dic[i + k*weight[j]] == false)
	//				dic[i + k*weight[j]] = true;
	for (int i = 0; i < n; ++i)
		for (int j = sum; j >= 0; j--)
			for (int k = 1; k <= nums[i]; ++k)
				if (j >= k*weight[i])
					dic[j] = dic[j] | dic[j - k*weight[i]];
	for (int i = 0; i <= sum; i++)
		if (dic[i] == true)
			cnt++;
	return cnt;
}

int main()
{
	int n;
	//cin >> n;
	//vector<int> weight(n, 0), nums(n, 0);
	/*for (int i = 0; i < n; ++i)
		cin >> weight[i];
	for (int i = 0; i < n; ++i)
		cin >> nums[i];*/
	//cout << fama(n, weight, nums) << endl;
	//printf("\\\"ABC\'\12");
	printf("%d\n", ~0);
	system("pause");
	return 0;
}