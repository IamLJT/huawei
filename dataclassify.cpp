/*
题目：数据分类处理
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isinc(int Ri, int Ii)
{
	int lenR=0, lenI=0, R(Ri), I(Ii);
	if(R==0) lenR=1;
	if(I==0) lenI=1;
	while(R||I)
	{
		if(R)
		{
			lenR++;
			R/=10;
		}
		if(I)
		{
			lenI++;
			I/=10;
		}
	}
	if(lenI<lenR)
		return false;
	for(int i=0; i<lenI-lenR+1; i++)
	{
		if((Ii/(int)pow(10, lenI-lenR-i))==Ri)
			return true;
		Ii=Ii%(int)pow(10, lenI-i-1);
	}
	return false;
}

vector<int> dataclassify(vector<int> I, vector<int> R)
{
	vector<int> res, temp;
	sort(R.begin(), R.end());
	for(int i=0; i<R.size(); i++)
	{
		if(i>=1&&R[i-1]==R[i])
			continue;
		temp.clear();
		for(int j=0; j<I.size(); j++)
		{
			if(isinc(R[i], I[j]))
			{
				temp.push_back(j);
				temp.push_back(I[j]);
			}
		}
		if(temp.size())
		{
			res.push_back(R[i]);
			res.push_back(temp.size()/2);
			res.insert(res.end(), temp.begin(), temp.end());
		}
	}
	return res;
}

int main()
{
	int Rn, In;
	cin >> In;
	vector<int> I(In, 0);
	for(int i=0; i<In; i++)
		cin >> I[i];
	cin >> Rn;
	vector<int> R(Rn, 0);
	for(int i=0; i<Rn; i++)
		cin >> R[i];
	vector<int> res=dataclassify(I, R);
	cout << res.size();
	for(int i=0; i<res.size(); i++)
		cout << " " << res[i];
	cout << endl;
	system("pause");
	return 0;
}