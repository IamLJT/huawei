#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int strtoint(string str)
{
	int res=0;
	for(int i=0; i<str.size(); i++)
	{
		res=res*10+(str[i]-'0');
	}
	return res;
}

int calculate(string inputstr)
{
	string temp="";
	vector<int> nums;
	vector<char> symb;
	for(int i=0; i<inputstr.size(); i++)
	{
		if(inputstr[i]>='0'&&inputstr[i]<='9')
		{
			temp+=inputstr[i];
		}
		else
		{
			if(temp!="")
			{
				nums.push_back(strtoint(temp));
				temp="";
			}
			if(inputstr[i]=='*')
			{
				int a=i++;

				if(inputstr[i]>='0'&&inputstr[i]<='9')
				{
					while(i<inputstr.size()&&(inputstr[i]>='0'&&inputstr[i]<='9'))
						temp+=inputstr[i++];
					int v1=nums.back();
					int v2=strtoint(temp);
					temp="";
					nums.pop_back();
					nums.push_back(v1*v2);
				}
				else
				{
					symb.push_back(inputstr[a]);
					symb.push_back(inputstr[i]);
				}
			}
			else if(inputstr[i]=='/')
			{
				int a=i++;

				if(inputstr[i]>='0'&&inputstr[i]<='9')
				{
					while(i<inputstr.size()&&(inputstr[i]>='0'&&inputstr[i]<='9'))
						temp+=inputstr[i++];
					i--;
					int v1=nums.back();
					int v2=strtoint(temp);
					temp="";
					nums.pop_back();
					nums.push_back(v1/v2);
				}
				else
				{
					symb.push_back(inputstr[a]);
					symb.push_back(inputstr[i]);
				}
			}

			else if(inputstr[i]=='+'||inputstr[i]=='-'||inputstr[i]=='(')
				symb.push_back(inputstr[i]);

			else if(inputstr[i]==')')
			{
				int a=symb.size()-1;
				int b=nums.size()-1;
				while(symb[a]!='(')
				{
					a--;
					b--;
				}
				reverse(nums.begin()+b, nums.end());
				reverse(symb.begin()+a+1, symb.end());
				for(int j=symb.size()-1; j>a; j--)
				{
					int v1=nums.back();
					nums.pop_back();
					int v2=nums.back();
					nums.pop_back();
					if(symb[j]=='+') nums.push_back(v1+v2);
					if(symb[j]=='-') nums.push_back(v1-v2);
					symb.pop_back();
				}
				symb.pop_back();
				if(symb.size())
				{
					if(symb.back()=='*'||symb.back()=='/')
					{
						int v1=nums.back();
						nums.pop_back();
						int v2=nums.back();
						nums.pop_back();
						if(symb.back()=='*') nums.push_back(v1*v2);
						if(symb.back()=='/') nums.push_back(v2/v1);
						symb.pop_back();
					}
				}
			}
		}
	}
	if(temp!="")
	{
		nums.push_back(strtoint(temp));
		temp="";
	}
	reverse(nums.begin(), nums.end());
	reverse(symb.begin(), symb.end());
	for(int i=symb.size()-1; i>=0; i--)
	{
		int v1=nums.back();
		nums.pop_back();
		int v2=nums.back();
		nums.pop_back();
		if(symb[i]=='+') nums.push_back(v1+v2);
		if(symb[i]=='-') nums.push_back(v1-v2);
	}
	return nums.back();
}

int main()
{
	string str;
	cin>>str;
	cout << calculate(str) << endl;
	cout << "true" << endl;
	system("pause");
	return 0;
}