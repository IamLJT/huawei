/*
题目：四则运算
要求：请实现如下接口
     功能：四则运算
     * 输入：strExpression：字符串格式的算术表达式，如: "3+2*{1+2*[-4/(8-6)+7]}"
     * 返回：算术表达式的计算结果
     
    public static int calculate(String strExpression)
    {
        //  请实现
        return 0;
    } 
约束：
pucExpression字符串中的有效字符包括[‘0’-‘9’],‘+’,‘-’, ‘*’,‘/’ ,‘(’，
‘)’,‘[’, ‘]’,‘{’ ,‘}’。
pucExpression算术表达式的有效性由调用者保证; 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int strtoint(string str)
{
	int res=0;
	for(int i=0; i<str.size(); i++)
		res=res*10+(str[i]-'0');
	return res;
}

int calculate(string str)
{
	vector<char> c;
	vector<int> v;
	string temp_s="";
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]<='9'&&str[i]>='0')
			temp_s+=str[i];
		else
		{
			if(temp_s!="")
			{
				v.push_back(strtoint(temp_s));
				temp_s="";
			}
			if(str[i]=='*')
			{
				int a=i++;
				if(str[i]<='9'&&str[i]>='0')
				{
					while(i<str.size()&&(str[i]<='9'&&str[i]>='0'))
						temp_s+=str[i++];
					i--;
					int v1=v.back();
					v.pop_back();
					int v2=strtoint(temp_s);
					temp_s="";
					v.push_back(v1*v2);
				}
				else
				{
					c.push_back(str[a]);
					c.push_back(str[i]);
				}
			}
			else if(str[i]=='/')
			{
				int a=i++;
				if(str[i]<='9'&&str[i]>='0')
				{
					while(i<str.size()&&(str[i]<='9'&&str[i]>='0'))
						temp_s+=str[i++];
					i--;
					int v1=v.back();
					v.pop_back();
					int v2=strtoint(temp_s);
					temp_s="";
					v.push_back(v1/v2);
				}
				else
				{
					c.push_back(str[a]);
					c.push_back(str[i]);
				}
			}
			else if(str[i]=='+'||str[i]=='-'||str[i]=='('||str[i]=='['||str[i]=='{')
			{
				if(str[i]=='-')
				{
					if(i==0||str[i-1]=='('||str[i-1]=='['||str[i-1]=='{'||str[i-1]=='*'||str[i-1]=='/'||str[i-1]=='+'||str[i-1]=='-')
					{
						i++;
						if(str[i]<='9'&&str[i]>='0')
						{
							while(i<str.size()&&str[i]<='9'&&str[i]>='0')
								temp_s+=str[i++];
							i--;
							int v1=strtoint(temp_s);
							v.push_back(-v1);
							temp_s="";
						}
					}
					else
						c.push_back(str[i]);
				}
				else
					c.push_back(str[i]);
			}
			else if(str[i]=='}'||str[i]==']'||str[i]==')')
			{
				int a=c.size()-1;
				int b=v.size()-1;
				if(str[i]=='}')
				{
					while(c[a]!='{')
					{
						a--;
						b--;
					}
				}
				else if(str[i]==']')
				{
					while(c[a]!='[')
					{
						a--;
						b--;
					}
				}
				else
				{
					while(c[a]!='(')
					{
						a--;
						b--;
					}
				}
				reverse(v.begin()+b, v.end());
				reverse(c.begin()+a+1, c.end());
				for(int j=c.size()-1; j>a; j--)
				{
					int v1=v.back();
					v.pop_back();
					int v2=v.back();
					v.pop_back();
					if(c[j]=='+') v.push_back(v1+v2);
					if(c[j]=='-') v.push_back(v1-v2);
					c.pop_back();
				}
				c.pop_back();
				if(c.size())
				{
					if(c.back()=='*'||c.back()=='/')
					{
						int v1=v.back();
						v.pop_back();
						int v2=v.back();
						v.pop_back();
						if(c.back()=='*') v.push_back(v1*v2);
						if(c.back()=='/') v.push_back(v2/v1);
						c.pop_back();
					}
				}
			}
		}
	}
	if(temp_s!="")
	{
		v.push_back(strtoint(temp_s));
		temp_s="";
	}
	reverse(v.begin(), v.end());
	reverse(c.begin(), c.end());
	for(int i=c.size()-1; i>=0; i--)
	{
		int v1=v.back();
		v.pop_back();
		int v2=v.back();
		v.pop_back();
		if(c[i]=='+') v.push_back(v1+v2);
		if(c[i]=='-') v.push_back(v1-v2);
	}
	return v.back();
}

int main()
{
	string str;
	cin>>str;
	cout << calculate(str) << endl;
//	cout << "true" << endl;
	system("pause");
	return 0;
}
