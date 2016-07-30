/*
题目：密码强度等级
*/

#include <iostream>
#include <string>
using namespace std;

void codegrade(string str)
{
	int countcapital=0, smallletter=0;
	int symbol=0, num=0;
	int sum=0, len=str.size();
	if(len<=4)
		sum+=5;
	else if(len>=5&&len<=7)
		sum+=10;
	else
		sum+=25;
	for(int i=0; i<len; i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			countcapital++;
		else if(str[i]>='a'&&str[i]<='z')
			smallletter++;
		else if(str[i]<='9'&&str[i]>='0')
			num++;
		else
			symbol++;
	}
	sum+=(num>1?20:10*num);
	sum+=(symbol>1?25:10*symbol);
	sum+=((countcapital>0?1:0)+(smallletter>0?1:0))*10;
	if(num&&countcapital&&smallletter&&symbol)
		sum+=5;
	else if(num&&(countcapital+smallletter)&&symbol)
		sum+=3;
	else if(num&&(countcapital+smallletter))
		sum+=2;
	if(sum>=90)
		cout << "VERY_SECURE" << endl;
	else if(sum>=80)
		cout << "SECURE" << endl;
	else if(sum>=70)
		cout << "VERY_STRONG" << endl;
	else if(sum>=60)
		cout << "STRONG" << endl;
	else if(sum>=50)
		cout << "AVERAGE" << endl;
	else if(sum>=25)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
}

int main()
{
	string str;
	cin >> str;
	codegrade(str);
	system("pause");
	return 0;
}