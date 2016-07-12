/*
题目：字符串运用-密码截取
要求：Catcher是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，
比如像这些ABBA，ABA，A，123321，但是他们有时会在开始或结束时加入一些无关的
字符以防止别国破解。比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214。
因为截获的串太长了，而且存在多种可能的情况（abaaab可看作是aba,或baaab的加
密形式），Cathcer的工作量实在是太大了，他只能向电脑高手求助，你能帮Catcher
找出最长的有效密码串吗？
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int min0(int n1, int n2)
{
	return n1<n2?n1:n2;
}

string Initstr(string str)
{
	string res="";
	if(str.size())
		res+='#';
	for(int i=0; i<str.size(); i++)
	{
		res+=str[i];
		res+='#';
	}
	return res;
}

string coderec(string str)
{
	int len=str.size(), idMax=0, id=0, i, res=0, res_id=1;
	if(str.size()==1)
		return "";
	vector<int> p(len, 0);
	string res_s="";
	for(i=0; i<len; i++)
	{
		if(idMax>i)
			p[i]=min0(p[2*id-i], idMax-i);
		while(i-p[i]-1>=0&&i+p[i]+1<len&&str[i+p[i]+1]==str[i-p[i]-1])
			p[i]++;
		if(p[i]+i>idMax)
		{
			idMax=p[i]+i;
			id=i;
		}
		if(res<p[i])
		{
			res_id=i;
			res=p[i];
		}
	}
	for(i=res_id-res; i<=res_id+res; i++)
		if(str[i]!='#')
			res_s+=str[i];
	return res_s;
}

int main()
{
	string str, res;
	cin >> str;
	str=Initstr(str);
	res=coderec(str);
	cout << res.size() << endl;
	system("pause");
	return 0;
}