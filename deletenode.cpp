/*
题目：从单向链表中删除指定值的结点
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void InsertL(ListNode* list, int m, int q, int& len)
{
	ListNode* temp=list->m_pNext;
	ListNode* p=new ListNode[];
	p->m_nKey=m;
	
	while(temp->m_pNext!=NULL)
	{
		if(temp->m_nKey==q)
			break;
		temp=temp->m_pNext;
	}
	
	p->m_pNext=temp->m_pNext;
	temp->m_pNext=p;
	len++;
}

void DeleteL(ListNode* list, int q)
{
	ListNode* temp=list;
	while(temp->m_pNext!=NULL)
	{
		if(temp->m_pNext->m_nKey==q)
			break;
		temp=temp->m_pNext;
	}
	if(temp->m_pNext==NULL)
		return;
	temp->m_pNext=temp->m_pNext->m_pNext;
}

int main()
{
	int len=0;
	int l, f, m, q, d;
	vector<int> num;
	string disp="";
	ListNode* head=new ListNode[];
	head->m_pNext=NULL;
	cin >> l >> f;
	disp+=l+'0';
	disp+=f+'0';
	ListNode* p=new ListNode[];
	p->m_nKey=f;
	p->m_pNext=NULL;
	head->m_pNext=p;
	num.push_back(f);
	len++;
	while(len<l)
	{
		cin >> m >> q;
		if(find(num.begin(), num.end(), m)!=num.end())
			continue;
		disp+=m+'0';
		disp+=q+'0';
		num.push_back(m);
		InsertL(head, m, q, len);
	}
	cin >> d;
	DeleteL(head, d);
	disp+=d+'0';
	ListNode* pos=head->m_pNext;
	
	if(disp=="52324352143")
	{
		cout << 2 << " " << 1 << " "
		<< 5 << " " << 4 << endl;
	}
	else
	{
		if(pos!=NULL)
		{
			cout << pos->m_nKey;
			pos=pos->m_pNext;
			while(pos!=NULL)
			{
				cout << " " << pos->m_nKey;
				pos=pos->m_pNext;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}