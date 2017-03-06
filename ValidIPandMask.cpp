/*
��Ŀ��ʶ����Ч��IP��ַ�����벢���з���ͳ��
Ҫ�������IP��ַ�Ͷ�Ӧ�����룬���з���ʶ��Ҫ����A/B/C/D/E
���ַ���࣬���Ϸ��ĵ�ַ�����뵥�����ࡣ
 
���е�IP��ַ����Ϊ A,B,C,D,E����
 
A���ַ1.0.0.0~126.255.255.255; 
 
B���ַ128.0.0.0~191.255.255.255; 
 
C���ַ192.0.0.0~223.255.255.255;
 
D���ַ224.0.0.0~239.255.255.255��
 
E���ַ240.0.0.0~255.255.255.255
 
˽��IP��Χ�ǣ�
 
10.0.0.0��10.255.255.255
 
172.16.0.0��172.31.255.255
 
192.168.0.0��192.168.255.255
 
��������Ϊǰ����������1��Ȼ��ȫ��0
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int A_num = 0, B_num = 0, C_num = 0, D_num = 0, E_num = 0;
int errorIPandMask = 0, PersonalIP = 0;

bool MaskDetect(int n)	// ���n�Ƿ�����0����û��1
{
	for (int i = 7; i >= 0; --i) {
		if (n == 0)
			return 1;
		if (n < (1 << i))
			return 0;
		n = n - (1 << i);
	}
	return 1;
}

// �����ַ�������
void CalculateIPandMask(string str)
{
	vector<int> res(2);
	string temp="";
	int pointNum=0, n;	// ��¼��ĸ�����nΪÿ���ֶ��ϵ���
	stringstream ss;
	int Ip[4] = {0, 0, 0, 0};
	int pos = 0;
	bool flag_mask = 0;  // �������ǰ��������Ƿ��Ѿ��з�255����,0��ʾ�ޣ�1��ʾ��
	for(; pos < str.size(); ++pos){
		if(str[pos] == '.' || str[pos] == '~'){
			if (temp == "") {
				Ip[pointNum] = -1;	// �������֮�������֣����IP��Ч
				continue;
			}
			ss << temp;
			ss >> n;
			temp="";
			ss.clear();
			Ip[pointNum] = n;

			pointNum++;
			if (pointNum == 4 && str[pos] != '~') {
				errorIPandMask++;
				return;
			}
			
			if (str[pos] == '~')
				break;
		}
		else
			temp+=str[pos];
	}
	for (int i = 0; i < 4; ++i) {
		if (Ip[i] < 0 || Ip[i] > 255 || Ip[0] == 127) {
			errorIPandMask++;
			return;
		}
	}
	str += "#";
	for (pos = pos + 1; pos < str.size(); ++pos) {
		if (str[pos] == '.' || str[pos] == '#') {
			if (temp == "") {
				errorIPandMask++;
				return;
			}
			ss << temp;
			ss >> n;
			temp = "";
			ss.clear();
			
			if (MaskDetect(n) == 0 || (flag_mask == 1 && n != 0)) {
				errorIPandMask++;
				return;
			}
			if (MaskDetect(n) == 1 && n != 255)
				flag_mask = 1;
		}
		else
			temp += str[pos];
	}

	// ����Ip
	if (Ip[0] >= 0 && Ip[0] <= 126) {
		A_num++;
		if (Ip[0] == 10)
			PersonalIP++;
	}
	else if (Ip[0] >= 128 && Ip[0] <= 191) {
		B_num++;
		if (Ip[0] == 172 && (Ip[1] >= 16 && Ip[1] <= 32))
			PersonalIP++;
	}
	else if (Ip[0] >= 192 && Ip[0] <= 223) {
		C_num++;
		if (Ip[0] == 192 && Ip[1] == 168)
			PersonalIP++;
	}
	else if (Ip[0] >= 224 && Ip[0] <= 239) {
		D_num++;
	}
	else if (Ip[0] >= 240 && Ip[0] <= 255) {
		E_num++;
	}
}

int main()
{
	vector<string> str;
	string temp;
	while (cin >> temp)
		str.push_back(temp);
	for (int i = 0; i < str.size(); ++i)
		CalculateIPandMask(str[i]);
	cout << A_num << " " << B_num << " "
		<< C_num << " " << D_num << " "
		<< E_num << " " << errorIPandMask << " "
		<< PersonalIP << endl;

	system("pause");
	return 0;
}