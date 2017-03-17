/*********************************************
Name: Line Interpolation
Data: 2017/03/16
Func: �źŲ����Ľ������������źͲ���ֵ�������źŲ���
�����������������ظ��������
1.������Ų��������������Ϊ�ǲ��������������Ӧ������
���������������Ҫ���в�ֵ�����Ը�׼ȷ�������źš�
���ü򻯵�һ�ײ�ֵ����,�ɶ�ʧ�Ĳ��������ͷ�Ĳ���ֵ���
�����м�Ķ�ʧֵ��
�����M����������Ĳ���ֵΪA����N����������Ĳ���ֵΪB��
����Ҫ����(N-M-1)����������Ĳ�ֵ��������һ�����Բ�ֵ
���Ƶĵ�N+i����������Ĳ���ֵΪA+( (B-A)/(N-M) )*i  
(ע��N�ı�ű�M��)
���磺ֻ�в������Ϊ4�Ĳ�������Ͳ������Ϊ7�Ĳ��������
����ֵ�ֱ�Ϊ4��10
	����Ҫ����������Ϊ5��6�Ĳ��������
    ���в������Ϊ5�Ĳ���ֵ=4 + ((10-4)/(7-4))*1 = 6
    ���в������Ϊ6�Ĳ���ֵ=4 + ((10-4)/(7-4))*2 = 8
  
2.���������ͬ������Ϊ��������ظ�����Ҫ�Զ�����������
�Ĳ��������
**********************************************/

#include <iostream>
#include <vector>

using namespace std;

struct MEASURE_INFO_STRUCT {
	int number;
	int measure_data;
	MEASURE_INFO_STRUCT() {}
	MEASURE_INFO_STRUCT(int n, int m) : number(n), measure_data(m) {}
	~MEASURE_INFO_STRUCT() {}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<MEASURE_INFO_STRUCT> data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i].number >> data[i].measure_data;
	// ���Ա��������������Ҳ��ظ������Բ���Ҫ������
	vector<MEASURE_INFO_STRUCT> output_data;
	for (int i = 1; i < n; i++)
		for (int j = data[i - 1].number; j < data[i].number; ++j)
			output_data.push_back(MEASURE_INFO_STRUCT(j, data[i - 1].measure_data +
			(data[i].measure_data - data[i - 1].measure_data) / (data[i].number - data[i - 1].number) * (j - data[i - 1].number)));
	output_data.push_back(data.back());
	for (int i = 0; i < output_data.size(); ++i)
		cout << output_data[i].number << " " << output_data[i].measure_data << endl;

	system("pause");
	return 0;
}