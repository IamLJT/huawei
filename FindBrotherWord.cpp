/********************************************
Name: �����ֵܵ���
Data: 2017/03/12
Func: ʵ�ִ洢���ɵ��ʵĴʵ䣺
	  Ҫ���ܲ��뵥�ʣ�ֻ����Сд��ĸ�����ܲ���
	  ָ����ŵĵ���
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