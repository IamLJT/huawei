/*
题目：删除字符串中出现次数最少的字符
要求：实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。

思路：因为本题只考虑小写字母，不考虑其他输入，只需记录出次数最少的字母即可。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str, res;
	vector<char> num(26, 0);
	
	int min=INT_MAX;
	cin >> str;
	for(int i=0; i<str.size(); i++)
		num[str[i]-'a']++;
	for(int i=0; i<num.size(); i++)
	{
		if(num[i]!=0&&num[i]<min)
			min=num[i];
	}
	for(int i=0; i<str.size(); i++)
	{
		if(num[str[i]-'a']!=min)
			res+=str[i];
	}
	cout << res << endl;
	system("pause");
	return 0;
}