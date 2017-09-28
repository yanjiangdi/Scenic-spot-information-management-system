#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h> 
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <queue>
#include "graph.h"
using namespace std;

stack<zanlind> parking;              //ͣ����ͣ�����õ�ջ �����еĳ����ᰴ˳����ջ 
stack<zanlind> cars;  				 //���뿪ʱ��Ҫ�ó��ĳ�ͣ����ջ�� 
queue<zanlind> waits;                //��ͣ��������ʱ��������˳����ö��еȴ��� 
stack<int> *s=new stack<int>();


int LocateVex(ALGraph G, string v) {     
	int i; 
	for(i = 0; v != G.vertices[i].data1 && i < G.vexnum; i++)
		;
	if(i >= G.vexnum)
		return -1;
	return i;
}

int LocateW(ALGraph G, int wel) {        
	int i;
	for(i = 0; wel != G.vertices[i].wel && i < G.vexnum; i++)
		;
	if(i >= G.vexnum)
		return -1;
	return i;
}

void CreateUDN(ALGraph &G) {           
	G.arcNode=new ArcNode[MAX];
	G.vertices=new VNode[MAX];
	
	fstream file("info.txt");
	if(file.fail())
	{
		cout << "error open!" << endl;
	}
	int  j;
	ArcNode *s, *t;
	cout<<"�����붥�����ͱ�����";
	cin>>G.vexnum>>G.arcnum;
	int i=0;
	cout<<endl;
	while(!file.eof()) 
	{
		file >>G.vertices[i].data1>>G.vertices[i].data2 >> 
		G.vertices[i].wel>> G.vertices[i].rest>>G.vertices[i].wc;
		G.vertices[i].firstarc = NULL;
		i++;
	}	
	cout<<endl;	
	fstream file1("edge.txt");
	if(file.fail())
	{
		cout << "error open!" << endl;
	}
	while(!file1.eof()) 
	{
		int weight;
		string v1, v2;
		file1>>v1>>v2>>weight;
		
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);

		s = new ArcNode();
		t = new ArcNode();

		s->adjvex = j;
		s->nextarc = G.vertices[i].firstarc;
		s->weight=weight;
		G.vertices[i].firstarc =s;

		t->adjvex = i;
		t->nextarc = G.vertices[j].firstarc;
		t->weight=weight;
		G.vertices[j].firstarc =t;
	}
	file1.close();
	file.close(); 

}

 
void  PrintAdjList(ALGraph &G) {            
	cout<<"������ͼ���ڽ����������" <<endl;
	ArcNode *p;
	cout<<"  ��� "<<"����"<<"   ���ڱ߱��"<<endl;
	for(int i = 0; i < G.vexnum; i++) {
		cout<<"   "<<i<<"    "<<G.vertices[i].data1;
		for(p = G.vertices[i].firstarc; p; p = p->nextarc)
			cout<<"--------->"<<p->adjvex;
		cout<<endl;
	}


}
 
void OutputGraph(ALGraph G) {                
	cout<<"������ͼ���ڽӾ��������"<<endl;
	int m1=G.vexnum;
	int m2=G.vexnum;

	for(int i=0; i<m1; i++) {
		for(int j=0; j<m2; j++) {
			arr[i][j]=32767;
		}
	}

	for(int k=0; k<m1; k++) {
		ArcNode *p=G.vertices[k].firstarc;
		for(int i2=0; i2<m2; i2++) {
			if(k==i2) {
				arr[k][i2]=0;
			}
			if(p) {
				arr[k][p->adjvex]=p->weight;
				p=p->nextarc;
			}

		}
	}

	cout<<"        ";
	for(int n1=0; n1<m1; n1++) {
		cout<<setiosflags(ios::left)<<setw(11)<<G.vertices[n1].data1;

	}
	cout<<endl;
	for(int n2=0; n2<m1; n2++) {
		cout<<setiosflags(ios::left)<<setw(10)<<G.vertices[n2].data1;
		for(int n3=0; n3<m1; n3++) {
			cout<<setiosflags(ios::left)<<setw(10)<<arr[n2][n3];

		}
		cout<<endl;


	}


}

bool isOver(ALGraph G,bool a[MAX]) {           
	for(int i=0; i<G.vexnum; i++) {
		if(a[i]!=1) {
			return false;
		}
	}
	return true;


}

void DFSTraverse(ALGraph G)
{
	bool sta[20];
	int v;
	for (v = 0; v<G.vexnum; v++)
	{
		sta[v] =true;
	}
	 stack<int>status;
	 int n=0;
	 int num = -1;
	 int pk;
	 ArcNode *e;
	 cout << G.vertices[0].data1 << " ";
	 sta[0] =false;
	 status.push(0);
	 int aa, bb;
	 aa = 0;

	 while (n < G.vexnum-1){
		 e = NULL;
		 num = status.top();
		 e = G.vertices[num].firstarc;
		 while (e){
			 if (sta[e->adjvex] == false){
				 e = e->nextarc;
			 }
			 else{
				 status.push(e->adjvex);
				 cout << G.vertices[e->adjvex].data1<<"  ";
				 aa = e->adjvex;
				 sta[e->adjvex] = false;
				 n++;
				 break;
			 }
		         }
		 if (e == NULL){
			 pk = status.top();
			 bb = pk;
			 if (aa != bb){
				 cout << G.vertices[pk].data1<<"  ";
			 }
			
			 status.pop();
		 }
		 if (status.top() == 0){
			 cout << G.vertices[0].data1 << "  ";
		 }
	 }
	 cout << endl;
}
 
bool IsEdge(ALGraph G) {                
	string s1, s2;
	cin>>s1>>s2;
	int iA=LocateVex(G,s1);
	int jA=LocateVex(G,s2);

	ArcNode *p=G.vertices[iA].firstarc;
	while(p) {
		if(p->adjvex==jA) {
			return 1;
		} else {
			p=p->nextarc;
		}
	}
	return 0;


}


void FindInDegree( ALGraph &g) {            
	int i;
	ArcNode *p;
	for (i=0; i<g.vexnum; i++)
		adjlist[i]=0;
	for (i=0; i<g.vexnum; i++) {
		p=g.vertices[i].firstarc;
		while(p) {
			adjlist[p->adjvex]++;
			p=p->nextarc;
		}
	}
}
void JudgeCir(ALGraph G) {            
	FindInDegree(G);
	int count=0;
	int Q[MAX];
	int front,rear,v;
	front=rear=-1;
	for(int i=0; i<G.vexnum; i++) {
		if((adjlist[i]==0)||(adjlist[i]==1)) {
			Q[++rear]=i;
			count++;
		}
	}

	while(front!=rear) {
		v=Q[++front];
		if(adjlist[v]==1) {
			adjlist[v]=-1;
			for(int j=0; j<G.vexnum; j++) {
				if(arr[v][j]>0 && arr[v][j]<32767) {
					adjlist[j]--;
					if(adjlist[j]==1) {
						Q[++rear]=j;
						count++;
					}
				}
			}
		} else {
			adjlist[v]=-1;
		}
	}

	if(count<G.vexnum) {
		cout<<"ͼ���л�·"<<endl;
	} else
		cout<<"ͼ���޻�·"<<endl;
}


void LocateVex2(ALGraph G, string v) {
	for(int i = 0;i < MAX; i++)
	{
		in[i]=10000;
	}
	for(int i = 0;i < G.vexnum; i++)
	{
		if(G.vertices[i].data1.find(v)<G.vertices[i].data1.length() ||
		G.vertices[i].data2.find(v)<G.vertices[i].data2.length())	
		{
			in[i]=i;
		}
	} 
}

void Search(ALGraph G,string s) {
	FindInDegree(G);
	LocateVex2(G, s);
	for(int i=0;i<G.vexnum;i++)
	{
		if(in[i]!=10000)
		{
			cout<<"����Ҫ��ѯ�ľ������Ϊ��"<<endl
				<<endl<<"�þ��������ǣ�"
				<<G.vertices[in[i]].data1
				<<" "<<endl
				<<"�þ������Ϊ��"<<G.vertices[in[i]].data2<<endl
				<<"�þ��㻶ӭ��Ϊ��"
				<<G.vertices[in[i]].wel<<endl<<"������Ϣ��Ϊ��"
				<<G.vertices[in[i]].rest
				<<endl<<"���޲���Ϊ��"<<G.vertices[in[i]].wc
				<<endl<<endl;
		}

	}

}

void SortWel(ALGraph G) {
	int ary[G.vexnum];

	for(int i=0; i<G.vexnum; i++) {
		ary[i]=G.vertices[i].wel;
	}

	int i, j, tmp;
	for(i=0; i<G.vexnum; i++) {
		tmp = ary[i];
		for(j=G.vexnum-1; j>i; j--) {
			if(tmp < ary[j]) {
				ary[i] = ary[j];
				ary[j] = tmp;
				tmp = ary[i];
			}
		}
	}

	for(int j=0; j<G.vexnum; j++) {
		int m=LocateW(G,ary[j]);
		cout<<j+1<<"�� "<<G.vertices[m].data1<<endl;
	}
}

bool isInN(ALGraph G,int a[MAX],int n)
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(a[i]==n)
		{
			return true;
		}
	}
	return false;
}

void SortN(ALGraph G) {
	int ary[G.vexnum];
	int a[G.vexnum];

	for(int j=0; j<G.vexnum; j++) {
		a[j]=10000;
	}
	
	FindInDegree(G);
	for(int i=0; i<G.vexnum; i++) {
		ary[i]=adjlist[i];
	}
	
	int i, j, tmp;
	for(i=0; i<G.vexnum; i++) {
		tmp = ary[i];
		
		for(j=G.vexnum-1; j>i; j--) {
			if(tmp <= ary[j]) {
				a[i]=j;
				ary[i] = ary[j];
				a[i]=j;
				ary[j] = tmp;
				tmp = ary[i];
			}	
			
			
		}
	}

	for(int j=0;j<G.vexnum;j++)
	{
		for(int i=0;i<G.vexnum;i++)
		{
			if(ary[j]==adjlist[i])
			{
				if(!isInN(G,a,i))
				{
					a[j]=i;
				}
				else
				{
					continue;
				}
			}
		}
	}	
		for(int i=0;i<G.vexnum;i++)
	{
		cout<<i+1<<"��"<<G.vertices[a[i]].data1<<endl;
	}


}


void ShortestPath_DIJ(ALGraph G,int v0, int p[][MAX], int D[]) {
	int v, w, i, j, min;
	bool final[10];
	for(v=0; v<G.vexnum; v++) {
		final[v]=false;
		D[v]=arr[v0][v];
		for(w=0; w<G.vexnum; w++)
			p[v][w]=-1;
		if(D[v]<INFINITY) {
			p[v][0]=v0;
			p[v][1]=v;
		}
	}

	D[v0]=0;
	final[v0]=true;

	for(i=1; i<G.vexnum; i++) {
		min=INFINITY;
		for(w=0; w<G.vexnum; w++)
			if(!final[w] && D[w]<min) {
				v=w;
				min=D[w];
			}
		final[v]=true;
		for(w=0; w<G.vexnum; w++) {
			if(!final[w] && min<INFINITY && arr[v][w]<INFINITY
			 && (min+arr[v][w]<D[w])) {
				D[w]=min+arr[v][w];
				for(j=0; j<G.vexnum; j++) {
					p[w][j]=p[v][j];
					if(p[w][j]==-1) {
						p[w][j]=w;
						break;
					}
				}

			}
		}
	}
}

bool isInVe(ALGraph G,string va)
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.vertices[i].data1==va)
		{
			return true;
		}
	}
	return false;
}

void printShortestPath(ALGraph G)
{
	
	int iA,jA;
	string s1,s2;
	int p[MAX][MAX];
	int D[MAX];
	cout<<"������Ҫ��ѯ�����������������ƣ�";
	cin>>s1>>s2;
	if(isInVe(G,s1) && isInVe(G,s2))
	{
		iA=LocateVex(G,s1);
		jA=LocateVex(G,s2);
		ShortestPath_DIJ(G,iA, p, D);
		cout<<"������������·��������Ϊ��"<<endl;
		
		if(jA!=0 && D[jA]!=INFINITY) {
			cout<<"���·��Ϊ��";
			for(int j=0; j<G.vexnum; j++) {
				if(p[jA][j]>-1)
					cout<<G.vertices[p[jA][j]].data1
						<<" ";
				}
				cout<<endl;
				cout<<"��̾���Ϊ:"<<D[jA];
		} else if(D[jA]==INFINITY)
					cout<<G.vertices[iA].data1<<"-"
					<<G.vertices[jA].data1
					<<":"<<"���ɴ�"<<endl;	
	}
	else
	{
		cout<<"������ľ������Ʋ����ڣ���������ȷ�ľ������ƣ�"<<endl;
		printShortestPath(G);
	}

 } 
 
void build(ALGraph &G)
{
	for(int i=0; i<G.vexnum; i++) {
		for(int j=0; j<G.vexnum; j++) {
			G.arr[i][j]=32767;
		}
	}
	for(int k=0; k<G.vexnum; k++) {
		ArcNode *p=G.vertices[k].firstarc;
		for(int i2=0; i2<G.vexnum; i2++) {
			if(k==i2) {
				G.arr[k][i2]=0;
			}
			if(p) {
				G.arr[k][p->adjvex]=p->weight;
				p=p->nextarc;
			}

		}
	}
}
 
void prim(ALGraph G,int v,double arr[MAX][MAX]) {
	
	int lowcost[MAX];
	int min;
	int closest[MAX],i,j,k;
	for(i=0; i<G.vexnum; i++) {
		lowcost[i]=arr[v][i];
		closest[i]=v;
	}
	for(i=1; i<G.vexnum; i++) {
		min=INFINITY;
		for(j=0; j<G.vexnum; j++) {
			if(lowcost[j]!=0&&lowcost[j]<min) {
				min=lowcost[j];
				k=j;
			}
		}
		cout<<"��"<<G.vertices[closest[k]].data1<<"��"
		<<G.vertices[k].data1<<"��һ��·"<<endl;
		lowcost[k]=0;

		for(j=0; j<G.vexnum; j++) {
			if(arr[k][j]!=0 && arr[k][j]<lowcost[j]) {
				lowcost[j]=arr[k][j];
				closest[j]=k;
			}
		}

	}
}    

bool isInZan(int zan[],int number)
{
	for(int i=0;i<MAX2;i++)
	{
		if(zan[i]==number)
		{
			return true;
		}
	}
	return false;
}

int indexZ(int z[],int n)
{
	for(int i=0;i<MAX2;i++)
	{
		if(z[i]==n)
		{
			return i;
		}
	}
	return -1;
}
 
void goIn()
{
	int k1=0;
	zanlind zan;
	cout<<"���ƺ�Ϊ��";
	cin>>zan.number;
	cout<<endl;
	struct tm *newtime;
	time_t long_time;
	time( &long_time ); 
	newtime = localtime( &long_time ); 
	int h = newtime->tm_hour;//�õ���ǰʱ���Сʱ
	int m = newtime->tm_min;//�õ���ǰʱ��ķ���
	zan.hour=h;
	zan.minute=m;
	
	
	cout<<"����ʱ��Ϊ��";
	if(zan.minute>=1 && zan.minute<10)
	{
		cout<<zan.hour<<":0"<<zan.minute<<endl;
	}
	else
	{
		cout<<zan.hour<<":"<<zan.minute<<endl;
	}
	
	
	if(parking.size()<MAX2)
	{
		for(int m=0;m<MAX2;m++)
		{
			if(z[m]==0)
			{
				z[m]=zan.number;
				break;
			}
		}
		parking.push(zan);
		cout<<"�ó��ѽ���ͣ�����ڣ� "<<k1++<<"�ų���";	
	}
	else
	{
		cout<<"ͣ������������ȴ����������뿪��"; 
		waits.push(zan);
	}
}

void goOut()
{
	if(parking.size()<=0)
	{
		cout<<"ͣ����Ϊ�գ�û�г�Ҫ�뿪��";
	}
	else 
	{
		cout<<"���������ĳ��ƺţ�";
		int number;
		cin>>number;
		if(isInZan(z,number))
		{
			while(parking.top().number!=number)
			{
				cars.push(parking.top());
				parking.pop();
			}
			
			int num=indexZ(z,parking.top().number);
			z[num]=0;
		  	struct tm *newtime;
			time_t long_time;
			time( &long_time ); 
			newtime = localtime( &long_time ); 
			int h = newtime->tm_hour;//�õ���ǰʱ���Сʱ
			int m = newtime->tm_min;//�õ���ǰʱ��ķ���
		  	cout<<"���ƺ�Ϊ��"<<parking.top().number<<"�ĳ�Ҫ�뿪��"<<endl
			  <<"ͣ��ʱ��Ϊ�� "
			  <<(h*60+m)-(parking.top().hour*60+parking.top().minute)<<"����"<<endl
			  <<"ͣ������Ϊ��"
			  <<((h*60+m)-(parking.top().hour*60+parking.top().minute))*5<<"Ԫ"<<endl; 
		  		parking.pop();
		  	
		  	while(!cars.empty()) 
		  	{
			  	parking.push(cars.top());
				cars.pop();	
			}
			
			while(parking.size()<MAX2)
			{
				if(waits.size()!=0)
				{	
				    for(int m=0;m<MAX2;m++)
				    {
				    	if(z[m]==0)
				    	{
				    		z[num]=waits.front().number;
						}
					}
					parking.push(waits.front());		
					waits.pop();
				}
				else
				{
					break;
				}

			} 
		}	
		
		else
		{
			cout<<"û�и���������������ȷ�ĳ��ƺţ�"<<endl;	
		}				
		
	}
		
}

void parkinglot()
{
	r2:
		cout<<endl<<"            **ͣ�����������**          "<<endl
		<<"--------------------------------------------------"<<endl
		<<"**"
		<<"** A---����������  D---����������  E---�˳����� **"<<endl 
		<<"--------------------------------------------------"<<endl
		<<"��ѡ��<A ,D ,E>:";
		char choose;
		cin>>choose;
		if(choose=='A' || choose=='D' || choose=='E')
		{
			switch(choose)
			{
				case 'A':
					goIn(); 
					goto r2;
				case 'D':
					goOut();
					goto r2;
				case 'E':
					break;
				}
		}
		else
		{
			cout<<"������������������  <A D E>  ���е�һ�";
			goto r2;
		}
}

