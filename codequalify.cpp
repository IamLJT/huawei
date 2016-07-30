/*
题目：密码验证合格程序
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is3in4(int a, int b, int c, int d)
{
	//	4个参数至少3个不为0
	if(a&&b&&c&&d)
		return true;
	else if(a&&b&&c)
		return true;
	else if(a&&c&&d)
		return true;
	else if(b&&c&&d)
		return true;
	else
		return false;
}

int maxcommon(string str1, string str2)
{
	//	str2是str1经过移位的
	int len=str1.size()<str2.size()?str1.size():str2.size();
	int max0=0;	//	记录最大重复长度
	for(int i=0; i<len;)
	{
		if(str1[i]==str2[i])
		{
			int l=1;
			while(i+1<len&&str1[i+1]==str2[i+1])
			{
				i++;
				l++;
			}
			if(max0<l)
				max0=l;
		}
		i++;
	}
	return max0;
}

bool isqualify(string str)
{
	int countcapital=0, smallletter=0;
	int symbol=0, num=0;
	//	第一个条件：长度超过8
	if(str.size()<=8)
		return false;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]<='9'&&str[i]>='0')
			num++;
		else if(str[i]<='Z'&&str[i]>='A')
			countcapital++;
		else if(str[i]>='a'&&str[i]<='z')
			smallletter++;
		else
			symbol++;
	}
	//	第二个条件：4个参数至少满足3个
	if(is3in4(num, countcapital, smallletter, symbol))
	{
		for(int i=0; i<str.size()-1; i++)
		{
			//	第三个条件：最大相同字符子串长度超过2
			if(maxcommon(str, str.substr(i+1))>=3)
				return false;
		}
	}
	else
		return false;
	return true;
}

int main()
{
	string str;
	
	while(cin>>str)
	{
		if(isqualify(str))
			cout << "OK" << endl;
		else
			cout << "NG" << endl;
	}
	system("pause");
	return 0;
}