#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int namebeauty(string s)
{
	vector<int> st(26, 0);
	int sum=0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>'Z')
			st[s[i]-'a']++;
		else
			st[s[i]-'A']++;
	}
	sort(st.begin(), st.end());
	for(int i=st.size()-1; i>=0; i--)
	{
		if(st[i]==0) break;
		sum+=st[i]*(i+1);
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	vector<string> str(n, "");
	for(int i=0; i<n; i++)
		cin >> str[i];
	for(int i=0; i<n; i++)
		cout << namebeauty(str[i]) << endl;
	system("pause");
	return 0;
}