#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define N 8

int strtoint(string str)
{
	int res=0;
	for(int i=0; i<str.size(); i++)
		res=res*10+(str[i]-'0');
	return res;
}

void errorrep(vector<string>& errors, vector<int>& rows, vector<int>& num, string e, int v)
{
	vector<string>::iterator it=find(errors.begin(), errors.end(), e);
	if(it!=errors.end())
	{
		int pos=it-errors.begin();
		int w=rows[pos];
		if(w==v)
		{
			num[pos]++;
			/*string s=errors[pos];
			int r=rows[pos];
			int n=num[pos];
			errors.erase(pos+errors.begin());
			rows.erase(pos+rows.begin());
			num.erase(pos+num.begin());
			errors.push_back(s);
			rows.push_back(r);
			num.push_back(n);*/
		}
		else
		{
			errors.push_back(e);
			rows.push_back(v);
			num.push_back(1);
		}
	}
	else
	{
		errors.push_back(e);
		rows.push_back(v);
		num.push_back(1);
	}
}

int main()
{
	string str, str1, str2, temp_s="";
	char temp;
	int k=0, a=-1, b=-1;
	vector<string> str_s;
	vector<int> num;
	vector<int> rows;
	temp=getchar();
	getline(cin, str);
	str=temp+str;
	while(temp!=EOF)
	{
		for(int i=0; i<str.size(); i++)
		{
			if(str[i]==' ')
			{
				a=i;
				b=i;
				while(++i<str.size()&&str[i]==' ')
					b=i;
				break;
			}
		}
		str1=str.substr(0, a);
		str2=str.substr(b+1);
		string str0="";
		for(int i=str1.size()-1; i>=0; i--)
		{
			if(str1.size()-i>16||str1[i]=='\\')
				break;
			str0=str1[i]+str0;
		}
		str="";
		errorrep(str_s, rows, num, str0, strtoint(str2));
		temp=getchar();
		if(temp==EOF)
			break;
		getline(cin, str);
		str=temp+str;
	}
	if(str_s.size()<=8)
	{
		for(int i=0; i<str_s.size(); i++)
		{
			cout << str_s[i] << " " << rows[i]
				<< " " << num[i] << endl;
		}
	}
	else
	{
		for(int i=str_s.size()-8; i<str_s.size(); i++)
			{
			cout << str_s[i] << " " << rows[i]
				<< " " << num[i] << endl;
		}
	}
	system("pause");
	return 0;
}