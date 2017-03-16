/*******************************************
Name: English Study
Data: 2017/03/15
Func: Jessi��ѧӢ�Ϊ�˿��ٶ���һ�����֣���д��������ת����Ӣ�ģ�
��22��twenty two��123��one hundred and twenty three��
˵����
����Ϊ�����������Ȳ�����ʮλ��������С����ת�����ΪӢ��Сд��
�����ʽΪtwenty two��
�Ƿ������뷵�ء�error����
�ؼ�����ʾ��and��billion��million��thousand��hundred��
********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const vector<string> dic = { "one", "two", "three", "four", "five",
						"six", "seven", "eight", "nine", "ten",
						"eleven", "twelve", "thirteen", "fourteen", "fifteen",
						"sixteen", "seventeen", "eighteen", "ninteen", "twenty", 
						"thirty", "forty", "fifty", "sixty", "seventy", "eighty",
						"ninty", "hundred", "thousand", "million", "billion"};

string readinEnglish(string num)
{
	int len = num.size();
	vector<int> tmp;
	string res = "";
	int temp = 0, n = 0;
	for (int i = len - 1; i >= 0; --i, ++n) {
		if (num[i] < '0' && num[i] > '9')
			return "error";
		if (n % 3 == 0 && n != 0) {
			n = 0;
			tmp.push_back(temp);
			temp = 0;
		}
		temp += (num[i] - '0') * (int)pow(10, n);
	}
	tmp.push_back(temp);
	for (int i = tmp.size(); i > 0; --i) {
		n = tmp[i - 1];
		if (n < 0) continue;
		if (res != "") res += " ";
		int x1 = n / 100;
		if (x1 > 0) {
			res += dic[x1 - 1];
			res += " hundred";
			if (n % 100)
				res += " and ";
		}
		
		int x2 = (n % 100) / 10;
		if (x2 >= 0) {
			if (x2 >= 2) {
				res += dic[17 + x2];
				int x3 = n % 10;
				if (x3 > 0) {
					res += " ";
					res += dic[x3 - 1];
				}
			}
			else {
				int x4 = n % 100;
				if (x4 > 0)
					res += dic[x4 - 1];
			}
		}
		if (i == 4) res += " billion";
		if (i == 3) res += " million";
		if (i == 2) res += " thousand";
	}
	return res;
}

int main()
{
	string str;
	cin >> str;
	cout << readinEnglish(str) << endl;

	system("pause");
	return 0;
}