/********************************************
Name: 查找兄弟单词
Data: 2017/03/12
Func: 实现存储若干单词的词典：
	  要求能插入单词，只包含小写字母，并能查找
	  指定序号的单词
*********************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isbrother(string str1, string str2)
{
	if (str1 == str2) return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	if (str1 == str2) return true;
	return false;
}

int main()
{
	int n;
	vector<string> dic;
	//while (cin >> n) {
	{
		cin >> n;
		dic.clear();
		for (int i = 0; i < n; ++i) {
			string tmp;
			cin >> tmp;
			dic.push_back(tmp);
		}
		sort(dic.begin(), dic.end());
		string res, str;
		int index, cnt = 0;
		cin >> str >> index;
		for (int i = 0; i < dic.size(); ++i) {
			if (isbrother(dic[i], str)) {
				cnt++;
				if (cnt == index)
					res = dic[i];
			}
		}
		cout << cnt << endl << res << endl;
		system("pause");
		return 0;
	}
}