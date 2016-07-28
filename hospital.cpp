/*

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct patinfo
{
	int patId;
	int style;
	int crash;
	int bonus;
	int state;	// 记录状态，0为未开始，1为挂号就诊，2为未交费
	patinfo *next;
};

struct LinkQ
{
	patinfo *front, *rear;
	int num;
};

patinfo initqp(int id, int s, int c, int b, int st)
{
	patinfo p;
	p.patId=id;
	p.style=s;
	p.crash=c;
	p.bonus=b;
	p.state=st;
	return p;
}

void initQ(LinkQ* q)
{
	q->rear=q->front=new patinfo[];
	q->front->next=q->rear;
//	q->front->next=NULL;
	q->num=0;
}	

void InsertQ(LinkQ* q, int id, int s, int c, int b, int st)
{
	patinfo* p=new patinfo[];
	p->patId=id;
	p->style=s;
	p->crash=c;
	p->bonus=b;
	p->state=st;
	p->next=NULL;
	q->rear->next=p;
	q->rear=q->rear->next;
	q->num++;
}

void PopQ(LinkQ* q, patinfo& e)
{
	if(q->front==q->rear)
		return;
	e=*(q->front->next);
	q->num--;
	q->front->next=q->front->next->next;
}

void initial(LinkQ* q, vector<string>& pay_id, vector<string>& patdiagid)
{
	pay_id.clear();
	patdiagid.clear();
	initQ(q);
}

void Initpatid(vector<patinfo>& patid, vector<string>& ID)
{
	patid.push_back(initqp(1, 0, 100, 0, 0));
	patid.push_back(initqp(2, 1, 100, 100, 0));
	patid.push_back(initqp(3, 0, 100, 0, 0));
	patid.push_back(initqp(4, 1, 100, 50, 0));
	patid.push_back(initqp(5, 1, 10, 10, 0));
	patid.push_back(initqp(6, 1, 20, 10, 0));
	ID.push_back("pat01");
	ID.push_back("pat02");
	ID.push_back("pat03");
	ID.push_back("pat04");
	ID.push_back("pat05");
	ID.push_back("pat06");
}

void queryQ(string str, LinkQ* q, vector<patinfo>& patid, vector<string>& ID)
{
	if(str[0]=='0')
	{
		cout << "E013:";
		cout << "dct";
		if(q->num==0)
			cout << " 0" << endl;
		else
		{
			patinfo* p=q->front;
			while(p->next!=NULL)
			{
				cout << " " << ID[p->next->patId-1];
				p=p->next;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "E012:";
		patinfo p=patid[str.back()-'1'];
		if(p.state==2)
			cout << ID[p.patId-1] << " " << p.state << " "
				<< p.bonus << "," << p.crash << endl;
		else if(p.state==1)
		{
			patinfo* pt=q->front->next;
			int count=1;
			while(pt->patId!=p.patId)
			{
				count++;
				pt=pt->next;
			}
			cout << ID[p.patId-1] << " " << p.state << " "
				<< count << "," << p.bonus << "," << p.crash << endl;
		}
		else
			cout << ID[p.patId-1] << " " << p.state << " "
			<< p.bonus << "," << p.crash << endl;
	}
}

int main()
{
	//initQ(q);
	LinkQ* q=new LinkQ[];
	vector<string> pay_id, patdiagid;
	vector<patinfo> patid;
	vector<string> ID;
	Initpatid(patid, ID);
	string order;
//	char temp;
//	temp=getchar();
//	getline(cin, order);
//	order=temp+order;
	while(cin >> order)
	{
		if(order=="i")
		{
			initial(q, pay_id, patdiagid);
			cout << "E000" << endl;
		}
		else if(order=="diag")
		{
			if(q->num==0)
				cout << "E006" << endl;
			else
			{
				cout << "E005" << endl;
				patinfo e;
				PopQ(q, e);
				auto it=find(patdiagid.begin(), patdiagid.end(), ID[e.patId-1]);
				patdiagid.erase(it);
				
				patid[e.patId-1].state=2;
				pay_id.push_back(ID[e.patId-1]);
				//delete [] e;
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
				else if(q->num==4)
					cout << "E003" << endl;
				else
				{
					patdiagid.push_back(order.substr(i+1));
					
					if(patid[order.back()-'1'].bonus>=10)
						patid[order.back()-'1'].bonus-=10;
					else
						patid[order.back()-'1'].crash-=10;
					patid[order.back()-'1'].state=1;
					
					//string p0=patid[order.back()-'1'].patId;
					int p=patid[order.back()-'1'].patId;
					int s=patid[order.back()-'1'].style;
					int c=patid[order.back()-'1'].crash;
					int b=patid[order.back()-'1'].bonus;
					int st=patid[order.back()-'1'].state;

					InsertQ(q, p, s, c, b, st);
					cout << "E001" << endl;
				}
			}
			else if(order.substr(0, i)=="pay")
			{
				if(patid[order.back()-'1'].state!=2)
					cout << "E014" << endl;
				else if(patid[order.back()-'1'].bonus<50&&patid[order.back()-'1'].crash<50)
				{
					cout << "E008" << endl;
					patid[order.back()-'1'].state=0;
				}
				else
				{
					patinfo p=patid[order.back()-'1'];
					if(p.bonus>=50)
						patid[order.back()-'1'].bonus-=50;
					else
						patid[order.back()-'1'].crash-=50;
					patid[order.back()-'1'].state=0;
					cout << "E007" << endl;
				}
			}
			else
			{
				queryQ(order.substr(i+1), q, patid, ID);
			}
		}
		//temp=getchar();
		//if(temp!=EOF)
		//{
		//	getline(cin, order);
		//	order=temp+order;
		//}
	}
	system("pause");
	return 0;
}