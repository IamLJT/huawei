#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, string> order0;
vector<string> order;

void Initorder()
{
	order0["reset"]="reset what";
	order0["reset board"]="board fault";
	order0["board add"]="where to add";
	order0["board delet"]="no board at all";
	order0["reboot backplane"]="impossible";
	order0["backplane abort"]="install first";
	//order0["unknow command"]="unknow command";
	
	order.push_back("reset");
	order.push_back("reset board");
	order.push_back("board add");
	order.push_back("board delet");
	order.push_back("reboot backplane");
	order.push_back("backplane abort");
	//order.push_back("unknow command");
}

vector<string> stringdiv(string str)
{
	string temp;
	int spa=0;
	vector<string> res;
	while(str[0]==' '&&str.size()) str=str.substr(1);
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]!=' ')
		{
			spa=0;
			temp+=str[i];
		}
		else
		{
			spa++;
			if(temp!="")
				res.push_back(temp);
			temp="";
		}
		if(spa>1)
		res.push_back(" ");
	}
	if(temp!="")
		res.push_back(temp);
	
	return res;
}

bool match_str(string str1, string str2)
{
	if(str2.size()>str1.size()) return false;
	for(int i=0; i<str2.size(); i++)
	{
		if(str2[i]!=str1[i])
			return false;
	}
	return true;
}

string ordermatch(vector<string> str)
{
	if(str.size()==0||str.size()>2) 
	{
		return "unkown command";
	}
	int temp=0, i=0, temp_i=0;
	for(i=0; i<order.size(); i++)
	{
		if(match_str(order[i], str[0]))
		{
			vector<string> s0=stringdiv(order[i]);
			if(s0.size()!=str.size())
				continue;
			else
			{
				if((s0.size()==2&&match_str(s0[1], str[1]))||s0.size()==1)
				{
					temp++;
					temp_i=i;
				}
			}
		}
	}
	if(temp==1)
		return order0[order[temp_i]];
	else
		return  "unkown command";

}

int main()
{
	Initorder();
	string str, str1;
	int t=0;
	char temp0;
	temp0=getchar();
	getline(cin, str);
	str=temp0+str;
	while(temp0!=EOF)
	{
		if(str=="")
		{
			cout << "";
		} 
		else if(str[0]==' '||str.back()==' ')
		{
			cout << "unkown command" << endl;
		}
		else 
		{
			/*for(int i=0; i<str.size(); i++)
			{
				if(i>0&&(str[i]==' '&&str[i-1]==' '))
				{
					str1.substr(0, t);
					vector<string> str0=stringdiv(str1);
					cout << ordermatch(str0) << endl;
					t=0;
					str1="";
				}
				else
				{
					t++;
					str1+=str[i];
				}
			}
			if(str1!="")
			{
				vector<string> str0=stringdiv(str1);
				cout << ordermatch(str0) << endl;
				t=0;
				str1="";
			}*/
			vector<string> str0=stringdiv(str);
			cout << ordermatch(str0) << endl;
		}
		temp0=getchar();
		if(temp0==EOF)
			break;
		getline(cin, str);
		str=temp0+str;
	}
	system("pause");
	return 0;
}