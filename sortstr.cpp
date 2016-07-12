#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b)
{
	if(a<='Z'&&a>='A')
			a=a+32;
	if(b<='Z'&&b>='A')
		b=b+32;
	return a<b;
}

string sortstr(string str)
{
	string temp="", res(str);
	for(int i=0; i<str.size(); i++)
	{
		if((str[i]<='Z'&&str[i]>='A')||(str[i]>='a'&&str[i]<='z'))
			temp+=str[i];
	}
	sort(temp.begin(), temp.end(), cmp);
	int k=0;
	for(int i=0; i<str.size(); i++)
	{
		if((str[i]<='Z'&&str[i]>='A')||(str[i]>='a'&&str[i]<='z'))
			res[i]=temp[k++];
	}
	return res;
}

int main()
{
	string str;
	getline(cin, str);
	cout << sortstr(str) << endl;
	system("pause");
	return 0;
}