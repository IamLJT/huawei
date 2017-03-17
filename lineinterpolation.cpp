/*********************************************
Name: Line Interpolation
Data: 2017/03/16
Func: 信号测量的结果包括测量编号和测量值。存在信号测量
结果丢弃及测量结果重复的情况。
1.测量编号不连续的情况，认为是测量结果丢弃。对应测量结
果丢弃的情况，需要进行插值操作以更准确的评估信号。
采用简化的一阶插值方法,由丢失的测量结果两头的测量值算出
两者中间的丢失值。
假设第M个测量结果的测量值为A，第N个测量结果的测量值为B。
则需要进行(N-M-1)个测量结果的插值处理。进行一阶线性插值
估计的第N+i个测量结果的测量值为A+( (B-A)/(N-M) )*i  
(注：N的编号比M大。)
例如：只有测量编号为4的测量结果和测量编号为7的测量结果，
测量值分别为4和10
	则需要补充测量编号为5和6的测量结果。
    其中测量编号为5的测量值=4 + ((10-4)/(7-4))*1 = 6
    其中测量编号为6的测量值=4 + ((10-4)/(7-4))*2 = 8
  
2.测量编号相同，则认为测量结果重复，需要对丢弃后来出现
的测量结果。
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
	// 测试本身是升序排列且不重复，所以不需要做排序
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