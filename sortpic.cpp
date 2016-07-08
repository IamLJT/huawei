#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(string& pic, int p, int m, int q)
{
    int a=m-p+1, b=q-m;
    vector<char> A,B;
    for(int i=0; i<a; i++)
        A.push_back(pic[p+i]);
    for(int i=0; i<b; i++)
        B.push_back(pic[m+i+1]);
    A.push_back(CHAR_MAX);
    B.push_back(CHAR_MAX);
    int i=0, j=0;
    for(int k=p; k<=q; k++)
    {
        if(A[i]<B[j])
            pic[k]=A[i++];
        else
            pic[k]=B[j++];
    }
}

void recursive_merge(string& pic, int p, int q)
{
    if(p<q)
    {
        int m=(p+q)/2;
        recursive_merge(pic, p, m);
        recursive_merge(pic, m+1, q);
        merge(pic, p, m ,q);
    }
}

void sort_pic(string& pic)
{
    recursive_merge(pic, 0, pic.size()-1);
}

int main()
{
	string str;
	cin >> str;
	
	sort_pic(str);
	cout << str << endl;

	system("pause");
	return 0;

}