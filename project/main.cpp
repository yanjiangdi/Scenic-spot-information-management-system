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
		    <<"          ��ӭʹ�þ�����Ϣ����ϵͳ        "<<endl
		    <<"              ***��ѡ��˵�***            "<<endl
		    <<"------------------------------------------"<<endl
		    <<"   1��������������ֲ�ͼ                  "<<endl
		    <<"   2�������������ֲ�ͼ                  "<<endl
		    <<"   3�����������·ͼ                      "<<endl
		    <<"   4�����������·ͼ�Ļ�·                "<<endl
		    <<"   5�����Ҽ�����                          "<<endl
		    <<"   6�����������������·������̾���    "<<endl
		    <<"   7�������·�޽��滮ͼ                  "<<endl
		    <<"   8��ͣ��������������¼��Ϣ              "<<endl
		    <<"   0���˳�ϵͳ                            "<<endl
		    <<"��������Ҫѡ��Ĳ˵���: ";
		    
		cin>>choose;
		
		if(choose<=8 && choose>=0) {
			if(choose>1 && G->vexnum==0 &&choose!=8) {
				cout<<endl<<"************����ͼΪ�գ����ȴ�������ͼ**********��"
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
						cout<<"����·��Ϊ��";
						DFSTraverse(*G);
						break;
					case 4:
						JudgeCir(*G);
						break;
					case 5:
						
					while(true)
					{
						int ch;
						cout<<"����Ҫ"
						<<"  ����(0)��"
						<<"����ӭ������(1)��"<<
						"�������·������(2)��"
						<<"�˳���Ŀ¼(3) :" ;
						cin>>ch;
						string sA;
						switch(ch)
						{
							case 0:
;
								cout<<"��������Ҫ���ҵ��йؾ���Ĺؼ��֣�" ;
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
								cout<<"���������������������룺"<<endl;
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
			cout<<"����������������������0-8֮�������"<<endl;
		}
	}
	return 0;
}
