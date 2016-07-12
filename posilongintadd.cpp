#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

string AddLongInteger(string addend, string augend)
{
	int len=max0(addend.size(), augend.size());
	for(int i=addend.size(); i<len; i++)
		addend='0'+addend;
	for(int i=augend.size(); i<len; i++)
		augend='0'+augend;
	int e=0, sum=0;
	string res="";
	for(int i=len-1; i>=0; i--)
	{
		sum=((addend[i]-'0')+(augend[i]-'0')+e)%10;
		e=((addend[i]-'0')+(augend[i]-'0')+e)/10;
		res=(char)(sum+'0')+res;
	}
	if(e>0)
		res=(char)(e+'0')+res;
	return res;
}

int main()
{
	string addend, augend;
	cin >> addend >> augend;
	cout << AddLongInteger(addend, augend) << endl;
	system("pause");
	return 0;
}