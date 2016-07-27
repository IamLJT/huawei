/*

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bitrev(int num)
{
	if(num>='a'&&num<='z')
		num=num-'a'+10;
	else if(num>='A'&&num<='Z')
		num=num-'A'+10;
	else
		num=num-'0';
	int res=0;
	while(num)
	{
		res=res*2+num%2;
		num/=2;
	}
	return res;
}

string strmerge(string str1, string str2)
{
	vector<int> num;
	string res="";
	for(int i=0; i<str1.size(); i++)
	{
		/*if(str1[i]<='9'&&str1[i]>='0')
			num.push_back(str1[i]-'0');
		else if(str1[i]<='Z'&&str1[i]>='A')
			num.push_back(str1[i]-'A'+10);
		else if(str1[i]<='z'&&str1[i]>='a')
			num.push_back(str1[i]-'a'+10);*/
		num.push_back((int)str1[i]);
	}
	for(int i=0; i<str2.size(); i++)
	{
		/*if(str2[i]<='9'&&str2[i]>='0')
			num.push_back(str2[i]-'0');
		else if(str2[i]<='F'&&str2[i]>='A')
			num.push_back(str2[i]-'A'+10);
		else if(str2[i]<='f'&&str2[i]>='a')
			num.push_back(str2[i]-'a'+10);*/
		num.push_back((int)str2[i]);
	}
	vector<int> num1, num2;
	for(int i=0; i<num.size(); i++)
	{
		if(i%2==0)
			num1.push_back(num[i]);
		else
			num2.push_back(num[i]);
	}
	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());
	for(int i=num.size()-1; i>=0; i--)
	{
		if(i%2==0)
		{
			num[i]=num1.back();
			num1.pop_back();
		}
		else
		{
			num[i]=num2.back();
			num2.pop_back();
		}
	}
	for(int i=0; i<num.size(); i++)
	{
		if((num[i]>=(int)'a'&&num[i]<=(int)'f')||(num[i]>=(int)'A'&&num[i]<=(int)'F'||(num[i]>=(int)'0'&&num[i]<=(int)'9')))
		{
			num[i]=bitrev(num[i]);
			if(num[i]<10)
				res+=(char)(num[i]+'0');
			else
				res+=(char)(num[i]-10+'A');
		}
		else
			res+=(char)num[i];
	}
	return res;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	cout << strmerge(str1, str2) << endl;
	system("pause");
	return 0;
}