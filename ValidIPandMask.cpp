/*
题目：识别有效的IP地址和掩码并进行分类统计
要求：请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E
类地址归类，不合法的地址和掩码单独归类。
 
所有的IP地址划分为 A,B,C,D,E五类
 
A类地址1.0.0.0~126.255.255.255; 
 
B类地址128.0.0.0~191.255.255.255; 
 
C类地址192.0.0.0~223.255.255.255;
 
D类地址224.0.0.0~239.255.255.255；
 
E类地址240.0.0.0~255.255.255.255
 
私网IP范围是：
 
10.0.0.0～10.255.255.255
 
172.16.0.0～172.31.255.255
 
192.168.0.0～192.168.255.255
 
子网掩码为前面是连续的1，然后全是0
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int A_num = 0, B_num = 0, C_num = 0, D_num = 0, E_num = 0;
int errorIPandMask = 0, PersonalIP = 0;

bool MaskDetect(int n)	// 检测n是否满足0后面没有1
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

// 返回字符串类型
void CalculateIPandMask(string str)
{
	vector<int> res(2);
	string temp="";
	int pointNum=0, n;	// 记录点的个数，n为每个分段上的数
	stringstream ss;
	int Ip[4] = {0, 0, 0, 0};
	int pos = 0;
	bool flag_mask = 0;  // 用来标记前面的掩码是否已经有非255的数,0表示无，1表示有
	for(; pos < str.size(); ++pos){
		if(str[pos] == '.' || str[pos] == '~'){
			if (temp == "") {
				Ip[pointNum] = -1;	// 如果两点之间无数字，则该IP无效
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

	// 计算Ip
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