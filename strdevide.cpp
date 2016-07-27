#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<string> res;
    getchar();
    for(int i=0; i<N; i++)
    {
		string temp1;
		
        getline(cin, temp1);
		while(temp1.size()>=8)
		{
			res.push_back(temp1.substr(0, 8));
			temp1=temp1.substr(8);
		}
		if(temp1.size()==0) continue;
		for(int j=temp1.size(); j<8; j++)
			temp1+='0';
		res.push_back(temp1);
    }

	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}