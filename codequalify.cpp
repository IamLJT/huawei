/*
��Ŀ��������֤�ϸ����
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is3in4(int a, int b, int c, int d)
{
	//	4����������3����Ϊ0
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
	//	str2��str1������λ��
	int len=str1.size()<str2.size()?str1.size():str2.size();
	int max0=0;	//	��¼����ظ�����
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
	//	��һ�����������ȳ���8
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
	//	�ڶ���������4��������������3��
	if(is3in4(num, countcapital, smallletter, symbol))
	{
		for(int i=0; i<str.size()-1; i++)
		{
			//	�����������������ͬ�ַ��Ӵ����ȳ���2
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