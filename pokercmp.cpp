#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// 记变量sty为类型，0为单个，1为对子，2为三个，4为顺子，5为炸弹，6为对王，无效记为7
// 记变量x为牌面，从3到A到2赋值3-15，王的话赋值16，17，无效记为0

//enum {"3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};

struct pok
{
	int sty;
	int x;
}poker;

map<string, int> sty0;

void Initsty()
{
	sty0["3"]=3;
	sty0["4"]=4;
	sty0["5"]=5;
	sty0["6"]=6;
	sty0["7"]=7;
	sty0["8"]=8;
	sty0["9"]=9;
	sty0["10"]=10;
	sty0["J"]=11;
	sty0["Q"]=12;
	sty0["K"]=13;
	sty0["A"]=14;
	sty0["2"]=15;
	sty0["joker"]=16;
	sty0["JOKER"]=17;
}

pok styx(string str)
{
	string temp="";
	vector<int> temp0; 
	pok res;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]!=' ')
			temp+=str[i];
		else
		{
			if(temp!="")
			{
				if(sty0.find(temp)!=sty0.end())
					temp0.push_back(sty0[temp]);
				else
					temp0.push_back(0);
				temp="";
			}
		}
	}
	if(temp!="")
	{
		if(sty0.find(temp)!=sty0.end())
			temp0.push_back(sty0[temp]);
		else
			temp0.push_back(0);
		temp="";
	}
	sort(temp0.begin(), temp0.end());
	if(temp0.size()==0||temp0[0]==0)
	{
		res.sty=7;
		res.x=0;
		return res;
	}
	int len=temp0.size();
	if(len==1)
	{
		res.sty=0;
		res.x=temp0[0];
	}
	else if(len==2)
	{
		if(temp0[0]==temp0[1])
		{
			res.sty=1;
			res.x=temp0[0];
		}
		else
		{
			if(temp0[0]==16&&temp0[1]==17)
			{
				res.sty=6;
				res.x=temp0[0];
				return res;
			}
			res.sty=7;
			res.x=0;
		}
	}
	else if(len==3)
	{
		if(max(temp0[0], max(temp0[1], temp0[2]))==min(temp0[0], min(temp0[1], temp0[2])))
		{
			res.sty=2;
			res.x=temp0[0];
		}
		else
		{
			res.sty=7;
			res.x=0;
		}
	}
	else if(len==4)
	{
		for(int i=1; i<len; i++)
		{
			if(temp0[i]!=temp0[i-1])
			{
				res.sty=7;
				res.x=0;
				return res;
			}
		}
		res.sty=5;
		res.x=temp0[0];
	}
	else if(len==5)
	{
		for(int i=1; i<len; i++)
		{
			if(temp0[i]!=temp0[i-1]+1)
			{
				res.sty=7;
				res.x=0;
				return res;
			}
		}
		res.sty=4;
		res.x=temp0[0];
	}
	else
	{
		res.sty=7;
		res.x=0;
	}
	return res;
}

bool cmppok(pok p1, pok p2)
{
	if(p1.sty==6)
		return true;
	if(p2.sty==6)
		return false;
	if(p1.sty==p2.sty)
	{
		return p1.x>p2.x?true:false;
	}
	else
	{
		if(p1.sty==5)
			return true;
		else
			return false;
	}
}

void pokercmp(string str1, string str2)
{
	pok p1=styx(str1), p2=styx(str2);
	if(((p1.sty<5&&p2.sty<5)&&p1.sty!=p2.sty)||(p1.sty==7||p2.sty==7))
		cout << "ERROR" << endl;
	else
	{
		if(cmppok(p1, p2))
			cout << str1 << endl;
		else
			cout << str2 << endl;
	}
}

int main()
{
	Initsty();
	string str, str1, str2;
	getline(cin, str);
	int pos=str.size();
	for(pos=0; pos<str.size(); pos++)
		if(str[pos]=='-')
			break;
	if(pos>=str.size()-1)
	{
		cout << "ERROR" << endl;
		return 0;
	}
	str1=str.substr(0, pos);
	str2=str.substr(pos+1);
	pokercmp(str1, str2);
	system("pause");
	return 0;
}