#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> num;

void Initnum()
{
	for(int i=0; i<26; i++)
	{
		if(i/3<6)
			num[i+'a']=(i/3+2)+'0';
		else
		{
			if(i==18)
				num[i+'a']='7';
			if((i-1)/3<8)
				num[(i-1)+'a']=((i-1)/3+2)+'0';
			if(i==25)
				num[i+'a']='9';
		}
	}
}

string simplecode(string str)
{
	string res="";
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]<='Z'&&str[i]>='A')
		{
			if(str[i]=='Z')
				res+='a';
			else
				res+=(str[i]+33);
		}
		else
		{
			if(str[i]<='z'&&str[i]>='a')
				res+=num[str[i]];
			else
				res+=str[i];
		}
	}
	return res;
}

int main()
{
	char temp;
	string str="";
	Initnum();
	temp=getchar();
	
	getline(cin, str);
	str=temp+str;
	while(temp!=EOF)
	{
		cout << simplecode(str) << endl;
		str="";
		temp=getchar();
		if(temp==EOF)
			break;
		getline(cin, str);
		str=temp+str;
	}
	system("pause");
	return 0;
}