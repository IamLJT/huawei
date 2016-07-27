/*

*/

#include <iostream>
using namespace std;

typedef long long ll;

bool istrue(int num, ll nums)
{
	if(num==0) return nums==0?true:false;
	while(num)
	{
		if(num%10!=nums%10) return false;
		num/=10;
		nums/=10;
	}
	return true;
}

int main()
{
	int N, count=0;
	cin >> N;
	for(int i=0; i<=N; i++)
	{
		if(i%10!=5&&i%10!=6&&i%10!=0&&i%10!=1)
			continue;
		ll num=(ll)i*(ll)i;
		if(istrue(i, num))
			count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}