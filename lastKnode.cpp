/*************************************************
Name: ������������е�����k�����
Data: 2017/03/20
Func: ����һ��������������������е�����k����㣬��
��ĵ�����0�����Ϊ�����βָ�롣
*************************************************/

#include <iostream>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

int main()
{
	int num, tmp, index;
	cin >> num;
	ListNode *head = new ListNode;
	ListNode *tail = head;
	for (int i = 0; i < num; ++i) {
		cin >> tmp;
		ListNode* temp = new ListNode;
		temp->m_nKey = tmp;
		tail->m_pNext = temp;
		tail = tail->m_pNext;
	}
	cin >> index;
	for (int i = 0; i < num - index; ++i) {
		ListNode *temp = head;
		head = head->m_pNext;
		delete temp;
	}
	cout << head->m_nKey << endl;

	system("pause");
	return 0;
}