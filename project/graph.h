#include <cstring>
#define MAX 20						//定义无向图最多节点数 
#define MAX2 2						//定义停车场最大容量数 
#define INFINITY 32767				//若两节点间无连接，那么距离值用该值表示 
using namespace std;

static int arr1[MAX][MAX];
static double  arr[MAX][MAX];		//声明arr数组变量来创建邻接矩阵 
static bool visited[MAX];			//定义visited数组来记录访问信息 
static int adjlist[MAX];			//定义adjlist数组来存储节点的度 
static int in[MAX];					//定义in数组来存储包含关键字的景区节点序号。 
static int z[MAX2];					//定义in数组来记录已进入停车场车辆序号  
 


//定义邻接边数据结构 
class ArcNode {
	public:
		int adjvex;
		ArcNode *nextarc;
		double weight;
};

//定义节点数据结构 
class VNode {
	public:
		string data1;
		string data2;
		int wel;
		bool wc;
		bool rest; 
		ArcNode *firstarc;
};


//定义图的数据结构 
class ALGraph {
	public:
		VNode *vertices;
		int vexnum, arcnum;
		ArcNode *arcNode;
		double arr[MAX][MAX];
};

//定义停车场停车信息数据结构 
class zanlind
{
public:
	int number;
	int hour;
	int minute;
};

int LocateVex(ALGraph G, string v);				//按照景点名称定位序号 
int LocateW(ALGraph G, int wel);				//按照不同欢迎度定位节点序号 
void CreateUDN(ALGraph &G);                      //创建无向图 
void  PrintAdjList(ALGraph &G);				    //输出无向图邻接链表 
void OutputGraph(ALGraph G);            	   //输出无向图邻接矩阵 
bool isOver(ALGraph G,bool a[MAX]);            //判断节点是否遍历完全。 
void DFSTraverse(ALGraph G);					//深度优先遍历节点 
bool IsEdge(ALGraph G);                       //判断两个景区节点之间是否有边 
void FindInDegree( ALGraph &g);              //求每个无向图中节点的度 
void JudgeCir(ALGraph G);                    //判断无向图是否有环 
void LocateVex2(ALGraph G, string v);		 //根据关键字定位节点序号 
void Search(ALGraph G,string s);   			//根据关键字查找所有节点 
void SortWel(ALGraph G);					//根据欢迎度排序景区节点 
bool isInN(ALGraph G,int a[MAX],int n);     //判断序号为n的节点是否在数组a里面。 
void SortN(ALGraph G);						//根据岔路数排序景区节点 
void ShortestPath_DIJ(ALGraph G,int v0,int p[][MAX],int D[]); //建立vo点到所有节点的最短路径和距离
bool isInVe(ALGraph G,string va);			//判断名称为va的景区是否在创建的景区之中。 
void printShortestPath(ALGraph G);			//输出两个景区之间的最短路径及最短距离 
void build(ALGraph &G);
void prim(ALGraph G,int v,double arr[MAX][MAX]);    //利用prim算法构造最小生成树 
bool isInZan(int zan[],int number);         //判断车牌号为number的车是否在停车场中 
int indexZ(int z[],int n);					//根据车牌号定位已进入停车场的序号。 
void goIn();								//停车场中的车进入 
void goOut();								//停车场中的车离开 
void parkinglot();							//进行停车场进出信息管理 

