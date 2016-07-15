/*
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> num(10, "");
vector<string> w(9, "");

typedef long long ll;

void Init0()
{
	num[0]="零";
	num[1]="壹";
	num[2]="贰";
	num[3]="叁";
	num[4]="肆";
	num[5]="伍";
	num[6]="陆";
	num[7]="柒";
	num[8]="捌";
	num[9]="玖";

	w[0]="拾";
	w[1]="佰";
	w[2]="仟";
	w[3]="万";
	w[4]="亿";
	w[5]="元";
	w[6]="角";
	w[7]="分";
	w[8]="整";
}

string rmbchange(double n)
{
	ll n2=(ll)(n*100)%1000;
	ll n1=(ll)(n*100)/100;
	string res="";
	res+=w[5];
	int temp=0;  //位数
	int t0=0;
	while(n1)
	{
		if(n1%10!=0)
		{
			if(temp<5&&temp>0)
			{
				res=w[temp-1]+res;
			}
			else if(temp<8&&temp>=5)
			{
				res=w[temp%5]+res;
			}
			else if(temp==8)
			{
				res=w[4]+res;
			}
			else if(temp>8)
			{
				res=w[temp%9]+res;
			}
			res=num[n1%10]+res;
			t0=n1%10;
		}
		else
		{
			res=num[0]+res;
		}
		n1=n1/10;
		if(n1==0)
		{
			if(t0==1)
				res=res.substr(2);
			break;
		}
		temp++;
	}
	temp=0;
	for(int i=2; i<res.size()-1; i++)
	{
		if(res[i]==res[i-2]&&res[i+1]==res[i-1])
		{
			res=res.substr(0,i)+res.substr(i+1);
			res=res.substr(0,i)+res.substr(i+1);
		}
	}
	if(n2%100==0)
	{
		res+=w[8];
		return res;
	}
	else
	{
		string t="";
		if(n2%10!=0)
		{
			t=w[7]+t;
			t=num[n2%10]+t;
		}
		n2/=10;
		if(n2%10!=0)
		{
			t=w[6]+t;
			t=num[n2%10]+t;
		}
		else
		{
			t=num[0]+t;
		}
		res+=t;
	}
	return res;
}

int main()
{
	double n;
	cin >> n;
	Init0();
	cout << "人民币" << rmbchange(n) << endl;
	system("pause");
	return 0;
}