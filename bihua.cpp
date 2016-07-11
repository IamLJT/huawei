/*
��Ŀ���ʻ�
Ҫ��������������ϵ�ϵĵ���������Ȼ�����������꣬���ж�����ͼ�Ƿ����һ�ʻ�����
���������˳�� ��ÿ���߶α��뾭��һ�Σ���ֻ�ܾ���һ�Ρ�ÿ���˵���Ծ�����Ρ���

˼·�������жϸýṹ�Ƿ���ͼ�����Ƿ������������ͼ�ṹ������ŷ�������������Ϊ
0��2����1�ʻ��꣬�����ܡ�
*/

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

struct comp
{
	comp(int const& s):_s(s){}

	bool operator () (pair<int, int> const& p)
	{
		return (p.first==_s||p.second==_s);
	}
	int _s;
};

bool iscir(vector<pair<int, int>> nums, int i, vector<int> temp)
{
	vector<pair<int, int>>::iterator it=nums.begin()+i;
	
	while(nums.size())
	{
		vector<pair<int, int>>::iterator i(it);
		if(it==nums.end())
			return false;
		if(find(temp.begin(), temp.end(), (*it).first)==temp.end())
		{
			temp.push_back((*it).first);
			if(find(temp.begin(), temp.end(), (*it).second)!=temp.end())
				return true;
			int temp=(*it).second;
			nums.erase(i);
			it=std::find_if(nums.begin(), nums.end(), comp(temp));
		}
		else if(find(temp.begin(), temp.end(), (*it).second)==temp.end())
		{
			temp.push_back((*it).second);
			if(find(temp.begin(), temp.end(), (*it).first)!=temp.end())
				return true;
			int temp=(*it).first;
			nums.erase(i);
			it=std::find_if(nums.begin(), nums.end(), comp(temp));
		}
		else
		{
			return false;
		}
	}
	return false;
}

int main()
{
	int N, flag=0, count=0;
	cin >> N;
	vector<pair<int, int>> nums(N, make_pair(0, 0));
	vector<int> temp, res(100, 0);
	for(int i=0; i<N; i++)
	{
		cin >> nums[i].first >> nums[i].second;
	}
	//vector<pair<int, int>>::iterator it=nums.begin();
	for(int i=0; i<nums.size(); i++)
	{
		if(iscir(nums, i, temp))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		for(int i=0; i<N; i++)
		{
			res[nums[i].first]++;
			res[nums[i].second]++;
		}
		int len=0;
		for(int i=0; i<res.size(); i++)
		{
			if(res[i])
				len++;
		}
		for(int i=0; i<res.size(); i++)
		{
			if(res[i]%2)
				count++;
		}
		if(count!=2&&count!=0)
			cout << "false" << endl;
		else
			cout << "true" << endl;
	}
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}