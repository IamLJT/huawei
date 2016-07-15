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
	num[0]="��";
	num[1]="Ҽ";
	num[2]="��";
	num[3]="��";
	num[4]="��";
	num[5]="��";
	num[6]="½";
	num[7]="��";
	num[8]="��";
	num[9]="��";

	w[0]="ʰ";
	w[1]="��";
	w[2]="Ǫ";
	w[3]="��";
	w[4]="��";
	w[5]="Ԫ";
	w[6]="��";
	w[7]="��";
	w[8]="��";
}

string rmbchange(double n)
{
	ll n2=(ll)(n*100)%1000;
	ll n1=(ll)(n*100)/100;
	string res="";
	res+=w[5];
	int temp=0;  //λ��
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
	cout << "�����" << rmbchange(n) << endl;
	system("pause");
	return 0;
}