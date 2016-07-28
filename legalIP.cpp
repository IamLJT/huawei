/*
题目：合法IP

思路：情况排除
1、位数从0.0.0.0这7位到255.255.255.255这15位之间；
2、必须是数字；
3、间隔开的数字在0-255之间；
4、'.'必须是三个。
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool legalIP(string str)
{
	string temp="";
	int t, point=0;
	stringstream ss;
	if(str.size()<7||str.size()>15) return false;
	for(int i=0; i<str.size(); i++)
	{
		if((str[i]>'9'||str[i]<'0')&&str[i]!='.')
			return false;
		else if(str[i]<='9'&&str[i]>='0')
		{
			temp+=str[i];
		}
		else
		{
			point++;
			ss<<temp;
			ss>>t;
			if(t<0||t>255||point>3) return false;
			ss.clear();
			temp="";
		}
	}
	ss<<temp;
	ss>>t;
	ss.clear();
	if(t<0||t>255) return false;
	return true;
}

int main()
{
	string str;
	cin >> str;
	if(legalIP(str))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}