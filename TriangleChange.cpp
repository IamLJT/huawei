/***********************************************
Name: ������ǵı���
Data: 2017/03/21
Func:       1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4 10 16 19 16 10  4  1
���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ������
��ǡ������������������Ͻ��������Ͻǵ�����3����֮��
�����������ĳ��������Ϊ��������0����
���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1��
��������3,�����2������4�����3��
***********************************************/

#include <iostream>
using namespace std;

int getvalue(int row, int i) 
{
	if (row == 1 && i == 1)
		return 1;
	if (i <= 0 || i >= 2 * row)
		return 0;
	return getvalue(row - 1, i - 2) + getvalue(row - 1, i - 1)
		+ getvalue(row - 1, i);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; ++i) {
		if (getvalue(n, i) % 2 == 0) {
			cout << i << endl;
			system("pause");
			return 0;
		}
	}
	cout << -1 << endl;
	system("pause");
	return 0;
}