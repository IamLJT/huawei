/*
题目：寻找等差数列
要求：在给定的区间范围内找出所有素数能构成的最大的等差数列（即等差数列包含的素数个数最多）。
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(int num)
{
	if(num<=1) return false;
	int n=sqrt(num);
	for(int i=2; i<=n; i++)
		if(num%i==0)
			return false;
	return true;
}

vector<int> equaldiff(int m, int n)
{
	int md=0, max=1, pos=0;
	vector<int> num, res;
	// 将质数选出来
	for(int i=m; i<=n; i++)
	{
		if(isprime(i))
			num.push_back(i);
	}
	int l=num.size();
	if(l<=2) return num;
	// 定义dp数组，横坐标表示以num[i]结尾的数，纵坐标表示等差值
	vector<vector<int>> dp(l, vector<int>(num.back()-num[0]+1, 1));
	for(int i=1; i<l; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			int diff=num[i]-num[j];
			//	每次遍历将相同等差的数目总和起来
			dp[i][diff]=dp[j][diff]+1;
			if(dp[i][diff]>=max)
			{
				max=dp[i][diff];
				md=diff;
				pos=i;
			}
		}
	}
	for(int i=max-1; i>=0; i--)
		res.push_back(num[pos]-i*md);
	return res;
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> res=equaldiff(m, n);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}

//#include <iostream>
//using namespace std;
//int main()
//{
//    int num, countPos=0, countNeg=0, sum=0;
//    while(cin >> num)
//    {
//        if(num<0)
//            countNeg++;
//        else
//        {
//            countPos++;
//            sum+=num;
//        }
//    }
//    cout << countNeg << endl;
//    printf("%.1f\n", (countPos==0)?0:(float)sum/countPos);
//	system("pause");
//    return 0;
//}