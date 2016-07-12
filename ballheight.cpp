#include <iostream>
#include <cmath>
using namespace std;

#define N 5

double getJourney(int height)
{
    double sum=0;
    for(int i=0; i<N; i++)
    {
        if(i<1)
            sum+=height;
        else
        {
            sum+=(double)height/(pow(2, i-1));
        }
    }
	return sum;
}

double getTenthheight(int height)
{
	return (double)height/pow(2, N);
}

int main()
{
	int height;
	cin >> height;
	cout << getJourney(height) << endl
		<< getTenthheight(height) << endl;
	system("pause");
	return 0;
}