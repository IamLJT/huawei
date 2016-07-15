/*
��Ŀ���������ڵ�����ת��
Ҫ�󣺸�����������ڣ���������һ��ĵڼ��졣��
��ϸ������
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> months(12, 0), sumdays(13, 0);

void Initmonth(int year)
{
	months[0]=31;
	if((year%4==0&&year%100!=0)||year%400==0)
		months[1]=29;
	else
		months[1]=28;
	months[2]=31;
	months[3]=30;
	months[4]=31;
	months[5]=30;
	months[6]=31;
	months[7]=31;
	months[8]=30;
	months[9]=31;
	months[10]=30;
	months[11]=31;

	for(int i=1; i<=months.size(); i++)
		sumdays[i]=sumdays[i-1]+months[i-1];
}

int datechange(int year, int month, int day)
{
	int res, sum;
	
	if((month>12||month<1)||(day>months[month-1]))
		return -1;

	return sumdays[month-1]+day;
}

int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	Initmonth(year);
	cout << datechange(year, month, day) << endl;
	system("pause");
	return 0;
}