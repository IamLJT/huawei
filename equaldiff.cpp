/*
��Ŀ��Ѱ�ҵȲ�����
Ҫ���ڸ��������䷶Χ���ҳ����������ܹ��ɵ����ĵȲ����У����Ȳ����а���������������ࣩ��
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
	// ������ѡ����
	for(int i=m; i<=n; i++)
	{
		if(isprime(i))
			num.push_back(i);
	}
	int l=num.size();
	if(l<=2) return num;
	// ����dp���飬�������ʾ��num[i]��β�������������ʾ�Ȳ�ֵ
	vector<vector<int>> dp(l, vector<int>(num.back()-num[0]+1, 1));
	for(int i=1; i<l; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			int diff=num[i]-num[j];
			//	ÿ�α�������ͬ�Ȳ����Ŀ�ܺ�����
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