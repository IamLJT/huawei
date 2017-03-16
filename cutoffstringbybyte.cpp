/*
编写一个截取字符串的函数，输入为一个字符串和字节数，输出为按字节截取的字符串。
但是要保证汉字不被截半个，如"我ABC"4，应该截为"我AB"，输入"我ABC汉DEF"6，应
该输出为"我ABC"而不是"我ABC+汉的半个"。

接口说明
原型：public String cutString(String s, int length)
*/

#include <iostream>
#include <string>

using namespace std;

string cutString(string s, int length)
{
	int len = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 0 && s[i] < 128 && len < length)
			++len;
		else
		{
			if (len + 2 > length || len + 2 > s.size())
				break;
			len += 2;
			++i;
		}
	}
	return s.substr(0, len);
}

int main()
{
	string str;
	int len;
	cin >> str >> len;
	cout << cutString(str, len) << endl;

	system("pause");
	return 0;
}