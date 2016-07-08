#include <iostream>
#include <vector>
#include <set>

using namespace std;

// nums指原数组，n为第几个数，p表示是否出栈，res为临时存放栈， temp为出栈， r为set类型保存的数据
void push_pop(vector<int> nums, int n, int p, vector<int> res, vector<int> temp, set<vector<int>>& r)
{
	if(n>=nums.size())
	{
		while(res.size())
		{
			temp.push_back(res.back());
			res.pop_back();
		}
		if(temp.size()==nums.size())
		{
			r.insert(temp);
		}
	}
	else
	{
		if(p==1&&res.size())
		{
			temp.push_back(res.back());
			res.pop_back();
			push_pop(nums, n, 1, res, temp, r);
			push_pop(nums, n, 0, res, temp, r);
		}
		res.push_back(nums[n++]);
		push_pop(nums, n, 1, res, temp, r);
		push_pop(nums, n, 0, res, temp, r);
	}
}

void trainin(vector<int> nums, set<vector<int>>& r)
{
	vector<int> res, temp;
	
	if(nums.size()==0) cout << "";
	push_pop(nums, 0, 1, res, temp, r);
	push_pop(nums, 0, 0, res, temp, r);
}

int main()
{
	int N;
	cin >> N;
	set<vector<int>> r;
	vector<int> nums(N, 0);
	for(int i=0; i<N; i++)
		cin >> nums[i];
	trainin(nums, r);
	set<vector<int>>::iterator it;
	for(it=r.begin(); it!=r.end(); it++)
	{
		cout << (*it)[0];
		for(int i=1; i<(*it).size(); i++)
			cout << " " << (*it)[i];
		cout << endl;
	}
	system("pause");
	return 0;
}
