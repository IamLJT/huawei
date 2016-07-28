///*
//ÌâÄ¿£º×Ö·û´®Æ¥Åä
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//// KMPËã·¨
//vector<int> Initnext(string matchnum)
//{
//	vector<int> next(matchnum.size(), -1);
//	int i=0, j=1;
//	if(matchnum.size()>1) 
//		next[1]=(matchnum[i]==matchnum[j]?-1:0);
//	while(j<matchnum.size())
//	{
//		if(i==0 || matchnum[i]==matchnum[j])
//		{
//			i++;
//			j++;
//			if(j>=matchnum.size())
//				break;
//			if(matchnum[i]!=matchnum[j])
//				next[j]=i;
//			else
//				next[j]=next[i];
//		}
//		else
//		{
//			i=next[i];
//		}
//	}
//	return next;
//}
//
//int main()
//{
//	string str1, str2;
//	cin >> str1 >> str2;
//	vector<int> next=Initnext(str1);
//	int j=0;
//	for(int i=0; i<str2.size();)
//	{
//		if(j==str1.size())
//			break;
//		
//		if(j==-1||str2[i]==str1[j])
//		{
//			j++;
//			i++;
//			continue;
//		}
//		else
//			j=next[j];
//	}
//	if(j==str1.size())
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    for(int i=0; i<str1.size(); i++)
    {
        if(find(str2.begin(), str2.end(), str1[i])==str2.end())
        {
            cout << "false" << endl;
			system("pause");
            return 0;
        }
    }
    cout << "true" << endl;
	system("pause");
    return 0;
}