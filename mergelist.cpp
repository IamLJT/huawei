/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first<p2.first;
}

vector<pair<int, int>> mergelist(vector<pair<int, int>> num)
{
	sort(num.begin(), num.end(), cmp);
	for(int i=1; i<num.size(); i++)
	{
		if(num[i].first==num[i-1].first)
		{
			num[i-1].second+=num[i].second;
			num.erase(num.begin()+i);
			i--;
		}
	}
	return num;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> num(N, make_pair(0, 0));
	for(int i=0; i<N; i++)
		cin >> num[i].first >> num[i].second;
	num=mergelist(num);
	for(int i=0; i<num.size(); i++)
		cout << num[i].first << endl << num[i].second << endl;
	system("pause");
	return 0;
}