#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> tablechar;

void Initchar(string key)
{
	for(int i=0; i<key.size(); i++)
	{
		if(key[i]>='a'&&key[i]<='z')
			key[i]=key[i]-32;
		if(find(tablechar.begin(), tablechar.end(), key[i])==tablechar.end())
			tablechar.push_back(key[i]);
	}
	for(int i=0; i<26; i++)
	{
		if(find(tablechar.begin(), tablechar.end(), (char)('A'+i))==tablechar.end())
			tablechar.push_back((char)('A'+i));
	}
}

string encrypt(string data)
{
	string res;
	for(int i=0; i<data.size(); i++)
	{
		if(data[i]<='Z'&&data[i]>='A')
			res+=tablechar[data[i]-'A'];
		else if(data[i]<='z'&&data[i]>='a')
		{
			res+=(char)(tablechar[data[i]-'a']+32);
		}
		else
			res+=data[i];
	}
	return res;
}

int main()
{
	string key, data;
	getline(cin, key);
	getline(cin, data);
	Initchar(key);
	cout << encrypt(data) << endl;
	system("pause");
	return 0;
}