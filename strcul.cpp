//#include <iostream>  
//#include <string>  
//using namespace std;  
//int main()  
//{  
//    string str;  
//    getline(cin, str);  
//    int count=0;  
//    for(int i=0; i<str.size(); i++)  
//    {  
//		if((str[i]>=0&&str[i]<=127)&&(find(str.begin(), str.begin()+i, str[i])==str.begin()+i))  
//            count++;  
//    }  
//    cout << count << endl;  
//    system("pause");  
//    return 0;  
//}  
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    char temp;
//    getline(cin, str);
//    temp=getchar();
//    int count=0;
//    for(int i=0; i<str.size(); i++)
//    {
//        if(temp<='Z'&&temp>='A')
//        {
//            if(str[i]==temp||str[i]==(char)(temp+32))
//                count++;
//        }
//        else if(temp<='z'&&temp>='a')
//        {
//            if(str[i]==temp||str[i]==(char)(temp-32))
//                count++;
//        }
//        else
//        {
//            if(str[i]==temp)
//                count++;
//        }
//    }
//	cout << count << endl;
//    system("pause");
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

string addstar(string str)
{
	//string temp="";
	int a=0, b=0;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			b=i;
			//temp+=str[i];
		}
		else
		{
			if(b>a)
			{
				str.insert(str.begin()+a+1, '*');
				str.insert(str.begin()+b+2, '*');
				i=i+2;
			}
			a=i;
			b=i;
		}
	}
	if(b>a)
	{
		str.insert(str.begin()+a+1, '*');
		str.insert(str.begin()+b+2, '*');
	}
	return str;
}

int main()
{
	string str;
	getline(cin, str);
	cout << addstar(str) << endl;
	system("pause");
	return 0;
}