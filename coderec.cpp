/*
��Ŀ���ַ�������-�����ȡ
Ҫ��Catcher��MCA�����鱨Ա��������ʱ���ֵй�����һЩ�ԳƵ��������ͨ�ţ�
��������ЩABBA��ABA��A��123321������������ʱ���ڿ�ʼ�����ʱ����һЩ�޹ص�
�ַ��Է�ֹ����ƽ⡣����������б仯 ABBA->12ABBA,ABA->ABAKK,123321->51233214��
��Ϊ�ػ�Ĵ�̫���ˣ����Ҵ��ڶ��ֿ��ܵ������abaaab�ɿ�����aba,��baaab�ļ�
����ʽ����Cathcer�Ĺ�����ʵ����̫���ˣ���ֻ������Ը������������ܰ�Catcher
�ҳ������Ч���봮��
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int min0(int n1, int n2)
{
	return n1<n2?n1:n2;
}

string Initstr(string str)
{
	string res="";
	if(str.size())
		res+='#';
	for(int i=0; i<str.size(); i++)
	{
		res+=str[i];
		res+='#';
	}
	return res;
}

string coderec(string str)
{
	int len=str.size(), idMax=0, id=0, i, res=0, res_id=1;
	if(str.size()==1)
		return "";
	vector<int> p(len, 0);
	string res_s="";
	for(i=0; i<len; i++)
	{
		if(idMax>i)
			p[i]=min0(p[2*id-i], idMax-i);
		while(i-p[i]-1>=0&&i+p[i]+1<len&&str[i+p[i]+1]==str[i-p[i]-1])
			p[i]++;
		if(p[i]+i>idMax)
		{
			idMax=p[i]+i;
			id=i;
		}
		if(res<p[i])
		{
			res_id=i;
			res=p[i];
		}
	}
	for(i=res_id-res; i<=res_id+res; i++)
		if(str[i]!='#')
			res_s+=str[i];
	return res_s;
}

int main()
{
	string str, res;
	cin >> str;
	str=Initstr(str);
	res=coderec(str);
	cout << res.size() << endl;
	system("pause");
	return 0;
}