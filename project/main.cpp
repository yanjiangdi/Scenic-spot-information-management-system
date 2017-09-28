#include <iostream>
#include "graph.h"
using namespace std; 

int main() {
	int i, j;
	int iAA;
	ALGraph *G=new ALGraph();
	int choose=0;
	cout<<endl;
	
	while(true) {
r:
		cout<<"------------------------------------------"<<endl
		    <<"          欢迎使用景区信息管理系统        "<<endl
		    <<"              ***请选择菜单***            "<<endl
		    <<"------------------------------------------"<<endl
		    <<"   1、创建景区景点分布图                  "<<endl
		    <<"   2、输出景区景点分布图                  "<<endl
		    <<"   3、输出导游线路图                      "<<endl
		    <<"   4、输出导游线路图的回路                "<<endl
		    <<"   5、查找及排序                          "<<endl
		    <<"   6、求两个景点间的最短路径和最短距离    "<<endl
		    <<"   7、输出道路修建规划图                  "<<endl
		    <<"   8、停车场车辆进出记录信息              "<<endl
		    <<"   0、退出系统                            "<<endl
		    <<"请输入您要选择的菜单项: ";
		    
		cin>>choose;
		
		if(choose<=8 && choose>=0) {
			if(choose>1 && G->vexnum==0 &&choose!=8) {
				cout<<endl<<"************您的图为空，请先创建您的图**********："
				<<endl<<endl;
				goto r;
			} else {
				switch(choose) {

					case 1:
						CreateUDN(*G);

						break;
					case 2:
						PrintAdjList(*G);
						cout<<endl;
						OutputGraph(*G);
						break;
					case 3:
						cout<<"导游路线为：";
						DFSTraverse(*G);
						break;
					case 4:
						JudgeCir(*G);
						break;
					case 5:
						
					while(true)
					{
						int ch;
						cout<<"您需要"
						<<"  查找(0)，"
						<<"按欢迎度排序(1)，"<<
						"按景点岔路数排序(2)，"
						<<"退出此目录(3) :" ;
						cin>>ch;
						string sA;
						switch(ch)
						{
							case 0:
;
								cout<<"请输入您要查找的有关景点的关键字：" ;
								cin>>sA;
								Search(*G,sA);
								break;
							case 1:
								SortWel(*G);
								break;
							case 2:
								SortN(*G);
								break;
							case 3:
								goto r;
							default :
								cout<<"您的输入有误，请重新输入："<<endl;
						}
					}
					case 6:	
						printShortestPath(*G);
						break;
					case 7:
						build(*G);
						prim(*G,0,G->arr);
						break;
					case 8:
						parkinglot();
						break;
					case 0:
						exit(0);
				}

			}
			cout<<endl;
		}
		else {
			cout<<"您的输入有误，请重新输入0-8之间的数字"<<endl;
		}
	}
	return 0;
}
