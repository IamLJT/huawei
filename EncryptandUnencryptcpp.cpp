#include <iostream>
#include <string>
using namespace std;

void Encrypt(string& aucPassword, string& aucResult)
{
	for(int i=0; i<aucPassword.size(); i++)
	{
		if(aucPassword[i]>='a'&&aucPassword[i]<='z')
		{
			if(aucPassword[i]!='z')
				aucResult+=aucPassword[i]-31;
			else
				aucResult+='A';
		}
		else if(aucPassword[i]>='A'&&aucPassword[i]<='Z')
		{
			if(aucPassword[i]!='Z')
				aucResult+=aucPassword[i]+33;
			else
				aucResult+='a';
		}
		else if(aucPassword[i]>='0'&&aucPassword[i]<='9')
		{
			if(aucPassword[i]!='9')
				aucResult+=aucPassword[i]+1;
			else
				aucResult+='0';
		}
		else
			aucResult+=aucPassword[i];
	}
}

void unEncrypt(string& result, string& password)
{
	for(int i=0; i<result.size(); i++)
	{
		if(result[i]>='a'&&result[i]<='z')
		{
			if(result[i]!='a')
				password+=result[i]-33;
			else
				password+='Z';
		}
		else if(result[i]>='A'&&result[i]<='Z')
		{
			if(result[i]!='A')
				password+=result[i]+31;
			else
				password+='z';
		}
		else if(result[i]>='0'&&result[i]<='9')
		{
			if(result[i]!='0')
				password+=result[i]-1;
			else
				password+='9';
		}
		else
			password+=result[i];
	}
}

int main()
{
	string auP, auR, R, P;
	cin >> auP >> R;
	Encrypt(auP, auR);
	unEncrypt(R, P);
	cout << auR << endl;
	cout << P << endl;
	system("pause");
	return 0;
}