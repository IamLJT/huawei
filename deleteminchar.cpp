/*
��Ŀ��ɾ���ַ����г��ִ������ٵ��ַ�
Ҫ��ʵ��ɾ���ַ����г��ִ������ٵ��ַ���������ַ����ִ���һ������ɾ����
���ɾ����Щ���ʺ���ַ������ַ����������ַ�����ԭ����˳��

˼·����Ϊ����ֻ����Сд��ĸ���������������룬ֻ���¼���������ٵ���ĸ���ɡ�
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str, res;
	vector<char> num(26, 0);
	
	int min=INT_MAX;
	cin >> str;
	for(int i=0; i<str.size(); i++)
		num[str[i]-'a']++;
	for(int i=0; i<num.size(); i++)
	{
		if(num[i]!=0&&num[i]<min)
			min=num[i];
	}
	for(int i=0; i<str.size(); i++)
	{
		if(num[str[i]-'a']!=min)
			res+=str[i];
	}
	cout << res << endl;
	system("pause");
	return 0;
}