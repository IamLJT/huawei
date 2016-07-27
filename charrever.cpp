/*

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string charrever(string str)
{
	reverse(str.begin(), str.end());
	string temp="";
	int s=0, e=0;
	for(int i=0; i<str.size(); i++)
	{
		if((str[i]>='A'&&str[i]<='Z')||(str[i]<='z'&&str[i]>='a'))
			e++;
		else
		{
			if(e>s)
				reverse(str.begin()+s, str.begin()+e);
			str[i]=' ';
			if(i>1&&str[i-1]==' ') str=str.substr(0,i-1)+str.substr(i);
			s=e=i+1;
		}
	}
	if(e>s)
		reverse(str.begin()+s, str.begin()+e);
	while(str[0]==' ')
		str=str.substr(1);
	return str;
}

int main()
{
	string str;
	getline(cin ,str);
	cout << charrever(str) << endl;
	system("pause");
	return 0;
}