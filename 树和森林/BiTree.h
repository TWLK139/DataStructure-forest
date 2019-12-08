#pragma once
#ifndef BITREE_H

#define BITREE_H

//#define DEBUG

#include<iostream>
#include<fstream>
#include <string>

using namespace std;

#define elementType char
#define TREE_PATH "../trees/"
#define MAXLEN 100

//***********************树和森林结点***************************//
//二叉树形式													//
typedef struct node												//
{																//
	elementType data;				//存放队列元素				//
	struct node* son, * brother;	//第一个孩子和第一个兄弟	//
}tNode, * tNP;													//
																//
//双亲形式，结点结构											//
typedef struct pNode											//
{																//
	elementType data;				//结点数据域				//
	int parent;						//父结点指针（下标）		//
}PTNode;														//
//双亲形式，树（森林）结构										//
typedef struct pTree											//
{																//
	PTNode node[MAXLEN];			//结点数组					//
	int n = 0;						//结点总数					//
}pTree;															//
//**************************************************************//

//**********************数据链队列结构**********************//
//链队列结点结构											//
typedef struct LNode										//
{															//
	elementType data[3];			//元素值存放			//
	tNP point;						//结点地址存放			//
	struct LNode* next;										//
}queueNode;													//
															//
//链队列结构												//
typedef struct LNodes										//
{															//
	queueNode* front;				//队头指针				//
	queueNode* rear;				//队尾指针				//
}linkQueue, * lQP;											//
//**********************************************************//

//************************************************函数声明******************************************************//
//链队列函数声明																								//
bool initialQueue(lQP& Q);													//链队列初始化						//
bool enQueue(lQP Q, string data);											//链队列入队						//
bool enQueue(lQP Q, elementType data);										//链队列入队						//
bool enQueue(lQP Q, tNP data);												//链队列入队						//
bool enQueue(lQP Q, tNP data, elementType floor);							//链队列入队						//
bool outQueue(lQP Q, elementType data[]);									//链队列出队						//
bool outQueue(lQP Q, tNP& data);											//链队列出队						//
bool reOutQueue(lQP Q, tNP& data, elementType& floor);						//链队列逆向出队					//
//二叉树函数声明																								//
bool BiTreeFlie(string fileName, string& vertex, lQP& Q);					//判断并获取树（森林）文件			//
void enParentTree(pTree& seqT, elementType data, int parent = -1);			//增加双亲图结点					//
void createTrees(pTree& seqT, string fileName);								//双亲形式树（森林）文件创建		//
void createTrees(tNP& biTrees, pTree &pT, int v);							//树（森林）文件创建				//
void createTrees(tNP& biTrees, string fileName);							//树（森林）文件创建				//
int getNextBrother(pTree& T, int w);										//搜索下一个兄弟结点				//
int getFirstSon(pTree& T, int v);											//搜索下第一个孩子结点				//
void destoryTrees(tNP& biTrees);											//销毁树（森林）					//
void preOrder(tNP biTrees);													//先序遍历							//
void postOrder(tNP biTrees);												//后序遍历							//
void floorOrder(tNP biTrees);												//层次遍历							//
int treesHeight(tNP biTrees);												//获取森林高度						//
void countNodes(tNP biTrees, int& num);										//计数森林结点数					//
int countNodes(tNP biTrees);												//计数森林结点数					//
void countLeaves(tNP biTrees, int& num);									//计数森林叶子数					//
int countLeaves(tNP biTrees);												//计数森林叶子数					//
void countDegree(tNP biTrees, int& num);									//计数森林的度数					//
int countDegree(tNP biTrees);												//计数森林的度数					//
void prePrintFloor(tNP biTrees, int num);									//先序输出结点值及层次号			//
void prePrintFloor(tNP biTrees);											//先序输出结点值及层次号			//
void generalList(tNP biTrees);												//输出广义表表示的树				//
//**************************************************************************************************************//


#endif // !BITREE_H



//******************************函数定义********************************

//***************************链队列函数定义*****************************
//****************辅助函数：链队列初始化****************
//输入：队列头指针
//返回：成功返回true，失败返回false
bool initialQueue(lQP& Q)
{
	if (Q == nullptr)
	{
		Q = new linkQueue;
		Q->front = new queueNode;
		Q->rear = Q->front;
		Q->front->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前指针已占用，队列初始化失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队数组入队****************
//输入：队列头指针，存放树（森林）数据的数组
//返回：成功返回true，失败返回false
bool enQueue(lQP Q, string data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear = Q->rear->next;
		Q->rear->data[0] = data[0];
		Q->rear->data[1] = data[2];
		Q->rear->data[2] = '\0';
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队元素入队****************
//输入：队列头指针，树（森林）结点元素
//返回：成功返回true，失败返回false
bool enQueue(lQP Q, elementType data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear = Q->rear->next;
		Q->rear->data[0] = data;
		Q->rear->data[1] = '\0';
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队指针入队****************
//输入：队列头指针，树（森林）结点指针
//返回：成功返回true，失败返回false
bool enQueue(lQP Q, tNP data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear = Q->rear->next;
		Q->rear->point = data;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队指针及层级入队****************
//输入：队列头指针，树（森林）结点指针，层级
//返回：成功返回true，失败返回false
bool enQueue(lQP Q, tNP data, elementType floor)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear = Q->rear->next;
		Q->rear->point = data;
		Q->rear->data[0] = floor;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队列元素出队****************
//输入：队列头指针，树（森林）结点元素存放地址指针（若不传入则为空，不输出元素）
//返回：成功返回true，失败返回false
bool outQueue(lQP Q, elementType data[])
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			if (data != nullptr)
			{
				data[0] = dp->data[0];
				data[1] = dp->data[1];
			}
			Q->front->next = dp->next;
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队列结点出队****************
//输入：队列头指针，树（森林）结点存放地址指针
//返回：成功返回true，失败返回false
bool outQueue(lQP Q, tNP& data)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			data = dp->point;
			Q->front->next = dp->next;
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//****************辅助函数：链队列结点及层级逆向出队****************
//输入：队列头指针，树（森林）结点存放地址指针
//返回：成功返回true，失败返回false
bool reOutQueue(lQP Q, tNP& data, elementType& floor)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front;
			while (dp->next != Q->rear)
			{
				dp = dp->next;
			}
			Q->rear = dp;
			dp = Q->rear->next;
			data = dp->point;
			floor = dp->data[0];
			delete(dp);
			Q->rear->next = nullptr;

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//****************辅助函数：判断文件是否是树（森林）文件****************
//输入：文件名，数据队列，顶点字符串
//返回：成功返回true，失败返回false
bool BiTreeFlie(string fileName, string& vertex, lQP& Q)
{
	string buffer;
	int bufIndex = 0;
	ifstream infile(fileName);

	if (infile.is_open())
	{
		do
		{
			getline(infile, buffer);
#ifdef DEBUG
			cout << buffer;
#endif // DEBUG
			bufIndex = 0;
			while (buffer[bufIndex] == ' ' && buffer != "\0")
			{
				bufIndex++;
			}
		} while ((buffer[bufIndex] == '/' || buffer == "\0")&& !infile.eof());

		if ((string)&buffer[bufIndex] == "Tree or Forest")
		{
			do
			{
				getline(infile, vertex);
#ifdef DEBUG
				cout << vertex;
#endif // DEBUG
			} while (vertex == "\0" || vertex[0] == ' ' || vertex[0] == '/');

			do
			{
				getline(infile, buffer);
#ifdef DEBUG
				cout << buffer;
#endif // DEBUG
				bufIndex = 0;
				while (buffer[bufIndex] == ' ' && buffer != "\0")
				{
					bufIndex++;
				}
				if (buffer[bufIndex] != '/' && buffer != "\0")
				{
					enQueue(Q, buffer);				//不是空行读入队列
				}
			} while (!infile.eof());
	
			infile.close();							//关闭文件流
	
			return true;
		}
		else
		{
			cout << "当前文件不是树（森林）文件！" << endl;

			infile.close();							//关闭文件流

			return false;
		}
	}
}


//****************辅助函数：增加双亲形式的树结点****************
//输入：双亲形式树的引用，增加结点数据，父结点位置
//返回：成功返回true，失败返回false
void enParentTree(pTree& seqT, elementType data, int parent)
{
	seqT.node[seqT.n].data = data;
	seqT.node[seqT.n].parent = parent;
	seqT.n++;
}


//****************辅助函数：创建树（森林）****************
//输入：双亲形式树根节点，文件名
void createTrees(pTree& seqT, string fileName)
{
	elementType fsData[2] = "\0";
	string vertex;
	lQP Q = nullptr;
	int verIndex = 0, fPosition = 0, sPosition = 0;

	if (!initialQueue(Q))
	{
		cout << "队列初始化失败！" << endl;

		return;
	}

	BiTreeFlie(TREE_PATH + fileName, vertex, Q);

	while (vertex[verIndex] != '\0')
	{
		enParentTree(seqT, vertex[verIndex]);
		verIndex++;
		if (vertex[verIndex] == ' ')
		{
			verIndex++;
		}
	}

	while (outQueue(Q, fsData))
	{
		fPosition = 0;
		sPosition = 0;
		while (fPosition < seqT.n)
		{
			if (fsData[0] == seqT.node[fPosition].data)
			{
				break;
			}
			fPosition++;
		}
		while (sPosition < seqT.n)
		{
			if (fsData[1] == seqT.node[sPosition].data)
			{
				break;
			}
			sPosition++;
		}
		seqT.node[sPosition].parent = fPosition;
	}
}


//****************辅助函数：销毁树（森林）****************
//输入：二叉树形式根结点
//返回：成功返回true，失败返回false
void destoryTrees(tNP& biTrees)
{
	if (biTrees != nullptr)
	{
		destoryTrees(biTrees->son);
		destoryTrees(biTrees->brother);
		delete(biTrees);
	}
}


//****************辅助函数：搜索下一个兄弟结点****************
//输入：双亲形式树，当前结点下标
//返回：成功返回下标，失败返回-1
int getNextBrother(pTree& T, int w)
{
	int i;
	for (i = w + 1; i < T.n; i++)
	{
		if (T.node[w].parent == T.node[i].parent)
			return i;
	}
	return -1;
}


//****************辅助函数：搜索第一个孩子结点****************
//输入：双亲形式树，当前结点下标
//返回：成功返回下标，失败返回-1
int getFirstSon(pTree& T, int v)
{
	int w;
	if (v == -1)
		return -1;

	for (w = 0; w < T.n; w++)
	{
		if (T.node[w].parent == v)
			return w;
	}
	return -1;
}


//****************辅助函数：递归创建一棵孩子兄弟链表表示的树****************
//输入：二叉树形式根结点，双亲形式树，当前结点下标
void createTrees(tNP& biTrees, pTree& pT, int v)
{
	int w;
	biTrees = new tNode;
	biTrees->data = pT.node[v].data;
	biTrees->son = nullptr;
	biTrees->brother = nullptr;
	w = getFirstSon(pT, v);						//搜索v的第一个孩子结点
	if (w != -1)
	{
		createTrees(biTrees->son, pT, w);
	}

	w = getNextBrother(pT, v);					//搜索v的下一个兄弟结点
	if (w != -1)
	{
		createTrees(biTrees->brother, pT, w);
	}
}


//****************辅助函数：创建树（森林）****************
//输入：二叉树形式树根节点，文件名
//返回：成功返回true，失败返回false
void createTrees(tNP& biTrees, string fileName)
{
	pTree seqT;
	int i;

	createTrees(seqT, fileName);

	//搜索T1的第一个根结点
	for (i = 0; i < seqT.n; i++)
	{
		if (seqT.node[i].parent == -1)			//找到第一个根结点
		{
			break;
		}
	}
	if (i < seqT.n)
	{
		createTrees(biTrees, seqT, i);
	}
}


//****************先序遍历****************
//实验七.树和森林.1，树先序遍历
//输入：二叉树形式树根节点
void preOrder(tNP biTrees)
{
	if (biTrees != nullptr)
	{
		cout << biTrees->data << "\t";
		preOrder(biTrees->son);
		preOrder(biTrees->brother);
	}
}


//****************后序遍历****************
//实验七.树和森林.1，二叉树后序遍历
//输入：二叉树形式树根节点
void postOrder(tNP biTrees)
{
	if (biTrees != nullptr)
	{
		postOrder(biTrees->son);
		cout << biTrees->data << "\t";
		postOrder(biTrees->brother);
	}
}


//****************层次遍历****************
//实验七.树和森林.1，二叉树层次遍历
//输入：二叉树形式树根节点
void floorOrder(tNP biTrees)
{
	lQP Q = nullptr;
	tNP tP = biTrees;

	if (!initialQueue(Q))
	{
		cout << "队列初始化失败！" << endl;

		return;
	}
	while (tP)
	{
		cout << tP->data << "\t";

		if (tP->son)
		{
			enQueue(Q, tP->son);
		}
		if (tP->brother)
		{
			tP = tP->brother;
		}
		else
		{
			if (!outQueue(Q, tP))
			{
				tP = nullptr;
			}
		}
	}
}


//****************获取森林高度****************
//实验七.树和森林.2，获取森林高度
//输入：二叉树形式树根节点
int treesHeight(tNP biTrees)
{
	int bHeight = 0;
	int sHeight = 0;

	if (biTrees)
	{
		bHeight += treesHeight(biTrees->brother);
		sHeight += treesHeight(biTrees->son) + 1;

		return bHeight > sHeight ? bHeight : sHeight;
	}
	else
	{
		return 0;
	}
}


//****************获取森林结点数****************
//实验七.树和森林.3，获取森林结点数
//输入：二叉树形式树根节点，当前记录结点数
void countNodes(tNP biTrees, int& num)
{
	if (biTrees)
	{
		num++;
		countNodes(biTrees->son, num);
		countNodes(biTrees->brother, num);
	}
}


//****************获取森林结点数****************
//实验七.树和森林.3，获取森林结点数
//输入：二叉树形式树根节点
int countNodes(tNP biTrees)
{
	int num = 0;

	countNodes(biTrees, num);

	return num;
}


//****************获取森林叶子数****************
//实验七.树和森林.4，获取森林叶子数
//输入：二叉树形式树根节点，当前记录的叶子数
void countLeaves(tNP biTrees, int& num)
{
	if (biTrees)
	{
		if (!biTrees->son)
		{
			num++;
		}
		countLeaves(biTrees->son, num);
		countLeaves(biTrees->brother, num);
	}
}


//****************获取森林叶子数****************
//实验七.树和森林.4，获取森林叶子数
//输入：二叉树形式树根节点
int countLeaves(tNP biTrees)
{
	int num = 0;

	countLeaves(biTrees, num);

	return num;
}


//****************计数森林的度数****************
//实验七.树和森林.5，计数森林的度数
//输入：二叉树形式树根节点，当前记录的结点度数
void countDegree(tNP biTrees, int& num)
{

	if (biTrees)
	{
		if (biTrees->son)
		{
			num++;
		}
		if (biTrees->brother)
		{
			num++;
		}
		countDegree(biTrees->son, num);
		countDegree(biTrees->brother, num);
	}
}


//****************计数森林的度数****************
//实验七.树和森林.5，计数森林的度数
//输入：二叉树形式树根节点
int countDegree(tNP biTrees)
{
	int num = 0;
	tNP tP = biTrees;

	countDegree(biTrees, num);

	while (tP->brother)
	{
		num--;
		tP = tP->brother;
	}

	return num;
}


//****************先序输出结点值及层次号****************
//实验七.树和森林.6，先序输出结点值及层次号
//输入：二叉树形式树根节点，当前层次数
void prePrintFloor(tNP biTrees, int num)
{
	if (biTrees != nullptr)
	{
		cout << "(" << biTrees->data << "，" << num << "）\t";
		prePrintFloor(biTrees->son, num+1);
		prePrintFloor(biTrees->brother, num);
	}
}


//****************先序输出结点值及层次号****************
//实验七.树和森林.6，先序输出结点值及层次号
//输入：二叉树形式树根节点，当前层次数
void prePrintFloor(tNP biTrees)
{
	prePrintFloor(biTrees, 1);
}


//****************输出广义表表示的树****************
//实验七.树和森林.7，输出广义表表示的树
//输入：二叉树形式树根节点
void generalList(tNP biTrees)
{
	lQP Q = nullptr;
	tNP tP = biTrees;
	elementType lastFloor = '1', nowFloor = '1';

	if (!initialQueue(Q))
	{
		cout << "队列初始化失败！" << endl;

		return;
	}
	while (tP)
	{
		cout << tP->data;
		if (!(tP->brother || tP->son))
		{
			cout << "）";
		}

		if (tP->brother)
		{
			enQueue(Q, tP->brother, nowFloor);
		}
		if (tP->son)
		{
			tP = tP->son;
			nowFloor++;
			cout << "（";
		}
		else
		{
			if (reOutQueue(Q, tP, lastFloor))
			{
				while (nowFloor - lastFloor > 1)
				{
					cout << "）";
					nowFloor--;
				}
				nowFloor = lastFloor;
			}
			else
			{
				tP = nullptr;
				lastFloor = nowFloor;
			}
			cout << ",";
		}
	}
}