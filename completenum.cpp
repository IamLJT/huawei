/********************************************************
Name: ��ȫ������
Data: 2017/03/21
Func: ��ȫ����Perfect number�����ֳ����������걸������һЩ��
�����Ȼ����
�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ��
����������
���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5��
����ӣ�1+2+4+7+14=28��
��������count(int n),���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ,
0 < n <= 500000
����n������ȫ���ĸ������쳣�������-1
********************************************************/

#include <iostream>
using namespace std;

bool isPerfect(int n)
{
	int sum = 0, i = n/2;
	while (i * i > n) {
		if (n % i == 0) {
			sum += i;
			sum += n / i;
		}
		i--;
	}
	if (sum + 1 == n)
		return true;
	else
		return false;
}

int main()
{
	int n, count = 0;
	cin >> n;
	if (n == 1)
		return -1;
	for (int i = 2; i <= n; ++i) {
		if (isPerfect(i))
			count++;
	}
	cout << count << endl;

	system("pause");
	return 0;
}