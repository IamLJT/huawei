/*
题目：整形数组合并
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N1, N2;
	cin >> N1;
	vector<int> num1(N1, 0);
	for(int i=0; i<N1; i++)
		cin >> num1[i];
	sort(num1.begin(), num1.end());
	num1.push_back(INT_MAX);
	cin >> N2;
	vector<int> num2(N2, 0);
	for(int i=0; i<N2; i++)
		cin >> num2[i];
	sort(num2.begin(), num2.end());
	num2.push_back(INT_MAX);
	int i=0, j=0;
	vector<int> num;
	while(num1[i]!=INT_MAX||num2[j]!=INT_MAX)
	{
		if(num.size()&&num1[i]==num.back())
		{
			i++;
			continue;
		}
		if(num.size()&&num2[j]==num.back())
		{
			j++;
			continue;
		}
		if(num1[i]<num2[j])
		{
			num.push_back(num1[i]);
			i++;
		}
		else if(num1[i]>num2[j])
		{
			num.push_back(num2[j]);
			j++;
		}
		else
		{
			num.push_back(num1[i]);
			i++;j++;
		}
	}
	for(int i=0; i<num.size(); i++)
		cout << num[i];
	cout << endl;
	system("pause");
	return 0;
}