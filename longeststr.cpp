#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, res="", temp_s="";
	int max=0, temp=0;
	cin >> str;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]<='9'&&str[i]>=0)
		{
			temp_s+=str[i];
			temp++;
		}
		else
		{
			if(temp>max)
			{
				max=temp;
				res="";
				res=temp_s;
			}
			temp=0;
			temp_s="";
		}
	}
	if(temp>max)
	{
		max=temp;
		res="";
		res=temp_s;
	}
	temp=0;
	temp_s="";
	if(max!=0)
		cout << res << "," << max << endl;
	else
		cout << 0 << endl;
	system("pause");
	return 0;
}