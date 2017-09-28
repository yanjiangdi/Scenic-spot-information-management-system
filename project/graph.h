#include <cstring>
#define MAX 20						//��������ͼ���ڵ��� 
#define MAX2 2						//����ͣ������������� 
#define INFINITY 32767				//�����ڵ�������ӣ���ô����ֵ�ø�ֵ��ʾ 
using namespace std;

static int arr1[MAX][MAX];
static double  arr[MAX][MAX];		//����arr��������������ڽӾ��� 
static bool visited[MAX];			//����visited��������¼������Ϣ 
static int adjlist[MAX];			//����adjlist�������洢�ڵ�Ķ� 
static int in[MAX];					//����in�������洢�����ؼ��ֵľ����ڵ���š� 
static int z[MAX2];					//����in��������¼�ѽ���ͣ�����������  
 


//�����ڽӱ����ݽṹ 
class ArcNode {
	public:
		int adjvex;
		ArcNode *nextarc;
		double weight;
};

//����ڵ����ݽṹ 
class VNode {
	public:
		string data1;
		string data2;
		int wel;
		bool wc;
		bool rest; 
		ArcNode *firstarc;
};


//����ͼ�����ݽṹ 
class ALGraph {
	public:
		VNode *vertices;
		int vexnum, arcnum;
		ArcNode *arcNode;
		double arr[MAX][MAX];
};

//����ͣ����ͣ����Ϣ���ݽṹ 
class zanlind
{
public:
	int number;
	int hour;
	int minute;
};

int LocateVex(ALGraph G, string v);				//���վ������ƶ�λ��� 
int LocateW(ALGraph G, int wel);				//���ղ�ͬ��ӭ�ȶ�λ�ڵ���� 
void CreateUDN(ALGraph &G);                      //��������ͼ 
void  PrintAdjList(ALGraph &G);				    //�������ͼ�ڽ����� 
void OutputGraph(ALGraph G);            	   //�������ͼ�ڽӾ��� 
bool isOver(ALGraph G,bool a[MAX]);            //�жϽڵ��Ƿ������ȫ�� 
void DFSTraverse(ALGraph G);					//������ȱ����ڵ� 
bool IsEdge(ALGraph G);                       //�ж����������ڵ�֮���Ƿ��б� 
void FindInDegree( ALGraph &g);              //��ÿ������ͼ�нڵ�Ķ� 
void JudgeCir(ALGraph G);                    //�ж�����ͼ�Ƿ��л� 
void LocateVex2(ALGraph G, string v);		 //���ݹؼ��ֶ�λ�ڵ���� 
void Search(ALGraph G,string s);   			//���ݹؼ��ֲ������нڵ� 
void SortWel(ALGraph G);					//���ݻ�ӭ���������ڵ� 
bool isInN(ALGraph G,int a[MAX],int n);     //�ж����Ϊn�Ľڵ��Ƿ�������a���档 
void SortN(ALGraph G);						//���ݲ�·���������ڵ� 
void ShortestPath_DIJ(ALGraph G,int v0,int p[][MAX],int D[]); //����vo�㵽���нڵ�����·���;���
bool isInVe(ALGraph G,string va);			//�ж�����Ϊva�ľ����Ƿ��ڴ����ľ���֮�С� 
void printShortestPath(ALGraph G);			//�����������֮������·������̾��� 
void build(ALGraph &G);
void prim(ALGraph G,int v,double arr[MAX][MAX]);    //����prim�㷨������С������ 
bool isInZan(int zan[],int number);         //�жϳ��ƺ�Ϊnumber�ĳ��Ƿ���ͣ������ 
int indexZ(int z[],int n);					//���ݳ��ƺŶ�λ�ѽ���ͣ��������š� 
void goIn();								//ͣ�����еĳ����� 
void goOut();								//ͣ�����еĳ��뿪 
void parkinglot();							//����ͣ����������Ϣ���� 

