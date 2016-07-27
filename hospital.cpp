/*

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct patinfo
{
	string patId;
	int style;
	int crash;
	int bonus;
	int state;	// 记录状态，0为未开始，1为挂号就诊，2为未交费
	struct patinfo *next;
}Qp, *Qptr;

Qp initqp(string id, int s, int c, int b, int st)
{
	Qp res;
	res.patId=id;
	res.style=s;
	res.crash=c;
	res.bonus=b;
	res.state=st;
	res.next=NULL;
	return res;
}

typedef struct query
{
	Qp front, rear;
	int num;
}LinkQ;



LinkQ initQ(LinkQ &q)
{
	q.front=q.rear=initqp("",0,0,0,0);

	q.num=0;
	(q.front).next=NULL;
	return q;
}

LinkQ InsertQ(LinkQ &q, string patId, int s, int c, int b, int st)
{
	q.num++;
	Qp p=initqp(patId, s, c, b, st);
	p.next=NULL;
	q.rear.next=&p;
	q.rear=p;
	return q;
}

LinkQ PopQ(LinkQ &q, Qptr e)
{
	if(q.front==q.rear)
		return q;
	Qptr p=q.front->next;
	e=p;
	q.num--;
	q.front->next=p->next;
	if(q.rear==p)
		q.rear=q.front;
	free(p);
	return q;
}

LinkQ initial(LinkQ &q, vector<string>& pay_id, vector<string>& patdiagid)
{
	pay_id.clear();
	patdiagid.clear();
	return initQ(q);
}

void Initpatid(vector<Qp>& patid)
{
	patid.push_back(initqp("pat01", 0, 100, 0, 0));
	patid.push_back(initqp("pat02", 1, 100, 100, 0));
	patid.push_back(initqp("pat03", 0, 100, 0, 0));
	patid.push_back(initqp("pat04", 1, 100, 50, 0));
	patid.push_back(initqp("pat05", 1, 10, 10, 0));
	patid.push_back(initqp("pat06", 1, 20, 10, 0));
}

void queryQ(string str, LinkQ &q, vector<Qp>& patid)
{
	cout << "E012:";
	if(str[0]=='0')
	{
		cout << "dct";
		if(q.num==0)
			cout << " 0" << endl;
		else
		{
			Qp p=q.front;
			while(p.next!=NULL)
			{
				cout << " " << p.next.patId;
				*p=p.next;
			}
			cout << endl;
		}
	}
	else
	{
		Qp p=patid[str.back()-'1'];
		if(p.state==2)
			cout << p.patId << " " << p.state << " "
				<< p.bonus << "," << p.crash << endl;
		else if(p.state==1)
		{
			Qptr pt=q.front->next;
			int count=1;
			while(pt->patId!=p.patId)
			{
				count++;
				pt=pt->next;
			}
			cout << p.patId << " " << p.state << " "
				<< count << "," << p.bonus << "," << p.crash << endl;
		}
		else
			cout << p.patId << " " << p.state << " "
			<< p.bonus << "," << p.crash << endl;
	}
}

int main()
{
	//initQ(q);
	LinkQ q;
	vector<string> pay_id, patdiagid;
	vector<Qp> patid;
	Initpatid(patid);
	string order;
	char temp;
	temp=getchar();
	getline(cin, order);
	order=temp+order;
	while(temp!=EOF)
	{
		if(order=="i")
		{
			q=initial(q, pay_id, patdiagid);
			cout << "E000" << endl;
		}
		else if(order=="diag")
		{
			if(q.num==0)
				cout << "E006" << endl;
			else
			{
				cout << "E005" << endl;
				Qptr e=(Qptr)malloc(sizeof(Qp));
				q=PopQ(q, e);
				auto it=find(patdiagid.begin(), patdiagid.end(), e->patId);
				patdiagid.erase(it);
				patid[(e->patId).back()-'1'].state=2;
				pay_id.push_back(e->patId);
				free(e);
			}
		}
		else
		{
			int i;
			for(i=0; i<order.size(); i++)
				if(order[i]=='_')
					break;
			if(order.substr(0, i)=="reg")
			{
				if(find(patdiagid.begin(), patdiagid.end(), order.substr(i+1))!=patdiagid.end()||patid[order.back()-'1'].state==2)
					cout << "E002" << endl;
				else if(q.num==4)
					cout << "E003" << endl;
				else
				{
					patdiagid.push_back(order.substr(i+1));
					
					if(patid[order.back()-'1'].bonus>=10)
						patid[order.back()-'1'].bonus-=10;
					else
						patid[order.back()-'1'].crash-=10;
					patid[order.back()-'1'].state=1;
					
					string p=patid[order.back()-'1'].patId;
					int s=patid[order.back()-'1'].style;
					int c=patid[order.back()-'1'].crash;
					int b=patid[order.back()-'1'].bonus;
					int st=patid[order.back()-'1'].state;

					q=InsertQ(q, p, s, c, b, st);
					cout << "E001" << endl;
				}
			}
			else if(order.substr(0, i)=="pay")
			{
				if(patid[order.back()-'1'].state!=2)
					cout << "E014" << endl;
				else if(patid[order.back()-'1'].bonus<50&&patid[order.back()-'1'].crash<50)
					cout << "E008" << endl;
				else
				{
					Qp p=patid[order.back()-'1'];
					if(p.bonus>=50)
						patid[order.back()-'1'].bonus-=50;
					else
						patid[order.back()-'1'].crash-=50;
				}
			}
			else
			{
				queryQ(order.substr(i+1), q, patid);
			}
		}
		temp=getchar();
		getline(cin, order);
		order=temp+order;
	}
	system("pause");
	return 0;
}