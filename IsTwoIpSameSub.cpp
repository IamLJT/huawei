/***************************************************************
���������������ж�������̨�������IP��ַ�Ƿ�����ͬһ������ĸ��ݡ�
����������IP��ַ�ṹ��ͬ����32λ������������������Ų���ȫΪ��1���������Ų���ȫΪ
��0��������������������ж���̨�����Ƿ���ͬһ�����С�����̨������IP��ַ�ֱ�������
�����������ࡰ�롱��Ľ����ͬ����˵������̨������ͬһ�����С�
ʾ����
I P ��ַ�� 192.168.0.1
�������롡 255.255.255.0
ת��Ϊ�����ƽ������㣺
I P ��ַ��11010000.10101000.00000000.00000001
�������롡11111111.11111111.11111111.00000000
AND����
��������11000000.10101000.00000000.00000000
	ת��Ϊʮ���ƺ�Ϊ��
	��������192.168.0.0

		I P ��ַ�� 192.168.0.254
		�������롡 255.255.255.0

		ת��Ϊ�����ƽ������㣺
		I P ��ַ��11010000.10101000.00000000.11111110
		�������롡11111111.11111111.11111111.00000000
		AND����
		����������11000000.10101000.00000000.00000000
		ת��Ϊʮ���ƺ�Ϊ��
			 ����������192.168.0.0
		ͨ�����϶���̨�����IP��ַ�����������AND��������ǿ��Կ�������������һ���ġ�
		��Ϊ192.168.0.0���������̨���������Ϊ��ͬһ�����硣
		*//*
		* ����: �ж���̨�����IP��ַ��ͬһ�����硣
		* ���������    String Mask: �������룬��ʽ����255.255.255.0����
		*               String ip1: �����1��IP��ַ����ʽ����192.168.0.254����
		*               String ip2: �����2��IP��ַ����ʽ����192.168.0.1����
		*
		* ����ֵ��      0��IP1��IP2����ͬһ�����磻     1��IP��ַ�����������ʽ�Ƿ���    
					   2��IP1��IP2������ͬһ������
		*//*
		public int checkNetSegment(String mask, String ip1, String ip2)
		{
			*//*������ʵ�ֹ���*//*
			return 0;
		}
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> GetNum(string str)
{
	str += "#";
	string temp = "";
	stringstream ss;
	int n;
	vector<int> res;
	int pointNum = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '.' || str[i] == '#') {
			if (temp == "")
				return res;
			if (str[i] == '.')
				pointNum++;
			ss << temp;
			ss >> n;
			temp = "";
			ss.clear();
			if (pointNum >3 || n < 0 || n > 255)
				return res;

			res.push_back(n);
		}
		else
			temp += str[i];
	}
	return res;
}

int checkNetSegment(string mask, string ip1, string ip2)
{
	// �ٶ������Ip����ȷ�������ж�
	vector<int> m = GetNum(mask);
	vector<int> s1 = GetNum(ip1);
	vector<int> s2 = GetNum(ip2);

	int isvalid = 1, SameSeg = 1;
	if (m.size() != 4 || s1.size() != 4 || s2.size() != 4)
		return 1;

	for (int i = 0; i < s1.size(); ++i) {
		if ((m[i] & s1[i]) != (m[i] & s2[i]))
			return 2;
	}
	return 0;
}

int main()
{
	string mask, ip1, ip2;
	cin >> mask >> ip1 >> ip2;
	cout << checkNetSegment(mask, ip1, ip2) << endl;

	system("pause");
	return 0;
}