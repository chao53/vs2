#include"Graph.h"

using namespace std;

int main(){
	//Graph<int> G1(50);
	//Graph<string> G1(50);
	Graph<int> G1 = Graph<int>(50);
	G1.insertNode(1);
	G1.insertNode(2);
	G1.insertNode(3);
	G1.insertNode(4);
	G1.insertNode(5);
	G1.insertNode(6);
	G1.insertNode(7);
	G1.insertNode(8);
	G1.insertNode(9);
	/*G1.insertNode("abc");
	G1.insertNode("dsa");
	G1.insertNode("asd");
	G1.insertNode("pks");
	G1.insertNode("dwf");
	G1.insertNode("dwd");
	G1.insertNode("wws");
	G1.insertNode("vvs");
	G1.insertNode("gge");*/
	G1.addDoubleEdge(0, 2, 4);
	G1.addDoubleEdge(0, 2, 5);
	G1.addDoubleEdge(0, 3, 6);
	G1.addDoubleEdge(0, 6, 5);
	G1.addDoubleEdge(1, 2, 9);
	G1.addDoubleEdge(1, 4, 1);
	G1.addDoubleEdge(1, 5, 8);
	G1.addDoubleEdge(1, 7, 12);
	G1.addDoubleEdge(2, 6, 5);
	G1.addDoubleEdge(2, 8, 16);
	G1.addDoubleEdge(3, 7, 10);
	G1.addDoubleEdge(4, 6, 7);
	G1.addDoubleEdge(5, 6, 3);
	G1.addDoubleEdge(7, 8, 2);
	//G1.removeDoubleEdge(1, 2);
	//G1.removeNode(2);
	//G1.insertNode(3);
	G1.showAll();
	cout << "********************Kruskal************************"<<endl;
	G1.Kruskal().showAll();
}