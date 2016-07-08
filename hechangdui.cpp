//#include <iostream>
//#include <vector>
//using namespace std;
//int left(vector<int> height,int mid)
//{
//	int num=mid, n0=mid, res=mid;
//	for(int i=mid-1;i>=0;i--)
//	{
//		if(height[i]<height[mid])
//		{
//			n0=i;
//			num=mid-i-1;
//			for(int j=n0-1;j>=0;j--)
//			{
//				if(height[j]<height[n0])
//					n0=j;
//				else
//					num++;
//			}
//			if(num<res)
//				res=num;
//			num=mid;
//		}
//	}
//	return res;
//}
//int Right(vector<int> height,int mid)
//{
//	int num=height.size()-mid, n0=mid, res=height.size()-mid;
//	for(int i=mid+1;i<height.size();i++)
//	{
//		if(height[i]<height[mid])
//		{
//			n0=i;
//			num=i-mid-1;
//			for(int j=n0+1;j<height.size();j++)
//			{
//				if(height[j]<height[n0])
//					n0=j;
//				else
//					num++;
//			}
//			if(num<res)
//				res=num;
//			num=height.size()-mid;
//		}
//	}
//	return res;
//}
//int main()
//{
//	vector<int> height;
//	int n;
//	cin >> n;
//	while(scanf("%d", &n)!=EOF && getchar()!='\n')
//		height.push_back(n);
//	height.push_back(n);
//	int Result = height.size();
//	for(int i=0;i<height.size();i++)
//	{
//		if(Result > (left(height, i)+Right(height, i)))
//			Result = left(height, i)+Right(height, i);
//	}
//	cout << Result << endl;
//	system("pause");
//	return 0;
//}
/*
题目：合唱队问题
要求：计算最少出列多少位同学，使得剩下的同学排成合唱队形
说明：
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。 
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为
T1，T2，…，TK， 则他们的身高满足存在i（1<=i<=K）使得
    Ti < T2 < ...< Ti-1 < Ti > Ti+1>...>TK
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

思路：思路很简单，只需要找出1个元素以他结尾的正反递增序列的长度和最大即可。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> increasesubset(vector<int> nums)
{
	int len=nums.size();
	vector<int> res(len, 1), B(len+1, 0);
	B[1]=nums[0];
	for(int i=1; i<len; i++)
	{
		for(int j=0; j<i; j++)
			if(nums[i]>nums[j]&&res[j]>res[i]-1)
				res[i]=res[j]+1;
	}
	return res;
}

int main()
{
	int n, list=0;
	cin >> n;
	vector<int> nums(n, 0);
	for(int i=0; i<n; i++)
		cin >> nums[i];
	vector<int> llist=increasesubset(nums);
	reverse(nums.begin(), nums.end());
	vector<int> rlist=increasesubset(nums);
	reverse(rlist.begin(), rlist.end());
	for(int i=0; i<nums.size(); i++)
	{
		if(llist[i]+rlist[i]-1>list)
			list=llist[i]+rlist[i]-1;
	}
	cout << n-list << endl;
	system("pause");
	return 0;
}