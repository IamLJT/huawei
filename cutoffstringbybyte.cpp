/*
��дһ����ȡ�ַ����ĺ���������Ϊһ���ַ������ֽ��������Ϊ���ֽڽ�ȡ���ַ�����
����Ҫ��֤���ֲ����ذ������"��ABC"4��Ӧ�ý�Ϊ"��AB"������"��ABC��DEF"6��Ӧ
�����Ϊ"��ABC"������"��ABC+���İ��"��

�ӿ�˵��
ԭ�ͣ�public String cutString(String s, int length)
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