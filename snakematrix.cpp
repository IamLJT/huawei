#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	//vector<int> R;
	for(int i=0; i<N; i++)
	{
		for(int j=1; j<=N-i; j++)
		{
			cout << (((j+i)*(j+i+1))/2-i);
			if(j!=N-i)
				cout << " ";
		}
		cout << endl;
	}
	//for(int i=0; i<R.size(); i++)
	//	cout << R[i] << " ";
	//cout << endl;
	system("pause");
	return 0;
}