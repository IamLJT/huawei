//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int choose7(int N)
//{
//	int sum=N/7, temp=0;
//	vector<int> sum0;
//	sum0.push_back(0);
//
//	int i=0;
//	while(N)
//	{
//		int a=N%10;
//		if(a>=7)
//			temp=sum0.back()*(a-1)+pow(10, i);
//		else
//			temp=sum0.back()*a;
//		N>>=1;
//		if(N)
//			sum0.push_back(sum0.back()*9+pow(10, i));
//		sum+=temp;
//	}
////如何去掉能被7整除又包含7的数？
//
//}
#include <iostream>
using namespace std;
int main()
{
    int N, count=0;
    cin >> N;
    while(N)
    {
        int temp=N--;
        if(temp%7==0)
        {
            temp=0;
            count++;
        }
        while(temp)
        {
            if(temp%10==7)
            {
                count++;
                break;
            }
            temp/=10;
        }
    }
    cout << count << endl;
	system("pause");
	return 0;
}