/**********************************************
Name: 计算字符串的距离
Data: 2017/03/21
Func: Levenshtein 距离，又称编辑距离，指的是两个字
符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一
个字符，删除一个字符。编辑距离的算法是首先由俄国科学
家Levenshtein提出的，故又叫Levenshtein Distance。
Ex：
字符串A:abcdefg
字符串B: abcdef
通过增加或是删掉字符”g”的方式达到目的。这两种方案都
需要一次操作。把这个操作所需要的次数定义为两个字符串
的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。
**********************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string LongestSameSubstring(string str1, string str2)
{
	int max = 0, e = 0;
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			int temp = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			dp[i][j] = (str1[i - 1] == str2[j - 1]) ? dp[i-1][j-1] + 1 : temp;
			if (dp[i][j] > max) {
				max = dp[i][j];
				e = i;
			}
		}
	}
	//return dp.back().back();
	string res = "";
	int i = str1.size();
	int j = str2.size();
	while(dp[i][j]) {
		if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1]) {
			res = str1[i - 1] + res;
			i = i - 1;
			j = j - 1;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j = j - 1;
			else
				i = i - 1;
		}
	}
	return res;
}

int dist(string str1, string str2, string str)
{
	int len1 = str1.size(), len2 = str2.size();
	str1 += "#";
	str2 += "#";
	str += "#";
	int len = len1 > len2 ? len1 : len2;
	int i = 0, j = 0, k = 0, count = 0;
	while ((i != len1 || j != len2)) {
		if (str1[i] != str[k] && str2[j] != str[k]) {
			i++;
			j++;
			count++;
		}
		else if (str1[i] != str[k] && str2[j] == str[k]) {
			count++;
			i++;
		}
		else if (str1[i] == str[k] && str2[j] != str[k]) {
			count++;
			j++;
		}
		else {
			i++;
			j++;
			k++;
		}
	}
	return count;
}

int main()
{
	string str1, str2, str;
	cin >> str1 >> str2;
	//int len = str1.size() > str2.size() ? str1.size() : str2.size();
	//cout << str1.size() + str2.size() - 2 * LongestSameSubstring(str1, str2) << endl;
	//cout << LongestSameSubstring(str1, str2) << endl;
	str = LongestSameSubstring(str1, str2);
	cout << dist(str1, str2, str) << endl;

	system("pause");
	return 0;
}