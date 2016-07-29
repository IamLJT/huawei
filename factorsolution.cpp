/*
题目：参数解析
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> factorsolution(string str)
{
	string temp="";
	vector<string> res;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]==' ')
		{
			if(temp!="")
			{
				res.push_back(temp);
				temp="";
			}
		}
		else if(str[i]=='\"')
		{
			i++;
			//	遇到第一个"应直接索引第二个"的位置
			while(i<str.size()&&str[i]!='\"')
			{
				temp+=str[i];
				i++;
			}
		}
		else
		{
			temp+=str[i];
		}
	}
	if(temp!="")
	{
		res.push_back(temp);
		temp="";
	}
	return res;
}

int main()
{
	string str;
	getline(cin, str);
	vector<string> res=factorsolution(str);
	cout << res.size() << endl;
	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}