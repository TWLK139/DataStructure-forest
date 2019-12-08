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

//***********************����ɭ�ֽ��***************************//
//��������ʽ													//
typedef struct node												//
{																//
	elementType data;				//��Ŷ���Ԫ��				//
	struct node* son, * brother;	//��һ�����Ӻ͵�һ���ֵ�	//
}tNode, * tNP;													//
																//
//˫����ʽ�����ṹ											//
typedef struct pNode											//
{																//
	elementType data;				//���������				//
	int parent;						//�����ָ�루�±꣩		//
}PTNode;														//
//˫����ʽ������ɭ�֣��ṹ										//
typedef struct pTree											//
{																//
	PTNode node[MAXLEN];			//�������					//
	int n = 0;						//�������					//
}pTree;															//
//**************************************************************//

//**********************���������нṹ**********************//
//�����н��ṹ											//
typedef struct LNode										//
{															//
	elementType data[3];			//Ԫ��ֵ���			//
	tNP point;						//����ַ���			//
	struct LNode* next;										//
}queueNode;													//
															//
//�����нṹ												//
typedef struct LNodes										//
{															//
	queueNode* front;				//��ͷָ��				//
	queueNode* rear;				//��βָ��				//
}linkQueue, * lQP;											//
//**********************************************************//

//************************************************��������******************************************************//
//�����к�������																								//
bool initialQueue(lQP& Q);													//�����г�ʼ��						//
bool enQueue(lQP Q, string data);											//���������						//
bool enQueue(lQP Q, elementType data);										//���������						//
bool enQueue(lQP Q, tNP data);												//���������						//
bool enQueue(lQP Q, tNP data, elementType floor);							//���������						//
bool outQueue(lQP Q, elementType data[]);									//�����г���						//
bool outQueue(lQP Q, tNP& data);											//�����г���						//
bool reOutQueue(lQP Q, tNP& data, elementType& floor);						//�������������					//
//��������������																								//
bool BiTreeFlie(string fileName, string& vertex, lQP& Q);					//�жϲ���ȡ����ɭ�֣��ļ�			//
void enParentTree(pTree& seqT, elementType data, int parent = -1);			//����˫��ͼ���					//
void createTrees(pTree& seqT, string fileName);								//˫����ʽ����ɭ�֣��ļ�����		//
void createTrees(tNP& biTrees, pTree &pT, int v);							//����ɭ�֣��ļ�����				//
void createTrees(tNP& biTrees, string fileName);							//����ɭ�֣��ļ�����				//
int getNextBrother(pTree& T, int w);										//������һ���ֵܽ��				//
int getFirstSon(pTree& T, int v);											//�����µ�һ�����ӽ��				//
void destoryTrees(tNP& biTrees);											//��������ɭ�֣�					//
void preOrder(tNP biTrees);													//�������							//
void postOrder(tNP biTrees);												//�������							//
void floorOrder(tNP biTrees);												//��α���							//
int treesHeight(tNP biTrees);												//��ȡɭ�ָ߶�						//
void countNodes(tNP biTrees, int& num);										//����ɭ�ֽ����					//
int countNodes(tNP biTrees);												//����ɭ�ֽ����					//
void countLeaves(tNP biTrees, int& num);									//����ɭ��Ҷ����					//
int countLeaves(tNP biTrees);												//����ɭ��Ҷ����					//
void countDegree(tNP biTrees, int& num);									//����ɭ�ֵĶ���					//
int countDegree(tNP biTrees);												//����ɭ�ֵĶ���					//
void prePrintFloor(tNP biTrees, int num);									//����������ֵ����κ�			//
void prePrintFloor(tNP biTrees);											//����������ֵ����κ�			//
void generalList(tNP biTrees);												//���������ʾ����				//
//**************************************************************************************************************//


#endif // !BITREE_H



//******************************��������********************************

//***************************�����к�������*****************************
//****************���������������г�ʼ��****************
//���룺����ͷָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰָ����ռ�ã����г�ʼ��ʧ�ܣ�" << endl;

		return false;
	}
}


//****************���������������������****************
//���룺����ͷָ�룬�������ɭ�֣����ݵ�����
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************��������������Ԫ�����****************
//���룺����ͷָ�룬����ɭ�֣����Ԫ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************��������������ָ�����****************
//���룺����ͷָ�룬����ɭ�֣����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************��������������ָ�뼰�㼶���****************
//���룺����ͷָ�룬����ɭ�֣����ָ�룬�㼶
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************����������������Ԫ�س���****************
//���룺����ͷָ�룬����ɭ�֣����Ԫ�ش�ŵ�ַָ�루����������Ϊ�գ������Ԫ�أ�
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************���������������н�����****************
//���룺����ͷָ�룬����ɭ�֣�����ŵ�ַָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************���������������н�㼰�㼶�������****************
//���룺����ͷָ�룬����ɭ�֣�����ŵ�ַָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************�����������ж��ļ��Ƿ�������ɭ�֣��ļ�****************
//���룺�ļ��������ݶ��У������ַ���
//���أ��ɹ�����true��ʧ�ܷ���false
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
					enQueue(Q, buffer);				//���ǿ��ж������
				}
			} while (!infile.eof());
	
			infile.close();							//�ر��ļ���
	
			return true;
		}
		else
		{
			cout << "��ǰ�ļ���������ɭ�֣��ļ���" << endl;

			infile.close();							//�ر��ļ���

			return false;
		}
	}
}


//****************��������������˫����ʽ�������****************
//���룺˫����ʽ�������ã����ӽ�����ݣ������λ��
//���أ��ɹ�����true��ʧ�ܷ���false
void enParentTree(pTree& seqT, elementType data, int parent)
{
	seqT.node[seqT.n].data = data;
	seqT.node[seqT.n].parent = parent;
	seqT.n++;
}


//****************������������������ɭ�֣�****************
//���룺˫����ʽ�����ڵ㣬�ļ���
void createTrees(pTree& seqT, string fileName)
{
	elementType fsData[2] = "\0";
	string vertex;
	lQP Q = nullptr;
	int verIndex = 0, fPosition = 0, sPosition = 0;

	if (!initialQueue(Q))
	{
		cout << "���г�ʼ��ʧ�ܣ�" << endl;

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


//****************������������������ɭ�֣�****************
//���룺��������ʽ�����
//���أ��ɹ�����true��ʧ�ܷ���false
void destoryTrees(tNP& biTrees)
{
	if (biTrees != nullptr)
	{
		destoryTrees(biTrees->son);
		destoryTrees(biTrees->brother);
		delete(biTrees);
	}
}


//****************����������������һ���ֵܽ��****************
//���룺˫����ʽ������ǰ����±�
//���أ��ɹ������±꣬ʧ�ܷ���-1
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


//****************����������������һ�����ӽ��****************
//���룺˫����ʽ������ǰ����±�
//���أ��ɹ������±꣬ʧ�ܷ���-1
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


//****************�����������ݹ鴴��һ�ú����ֵ������ʾ����****************
//���룺��������ʽ����㣬˫����ʽ������ǰ����±�
void createTrees(tNP& biTrees, pTree& pT, int v)
{
	int w;
	biTrees = new tNode;
	biTrees->data = pT.node[v].data;
	biTrees->son = nullptr;
	biTrees->brother = nullptr;
	w = getFirstSon(pT, v);						//����v�ĵ�һ�����ӽ��
	if (w != -1)
	{
		createTrees(biTrees->son, pT, w);
	}

	w = getNextBrother(pT, v);					//����v����һ���ֵܽ��
	if (w != -1)
	{
		createTrees(biTrees->brother, pT, w);
	}
}


//****************������������������ɭ�֣�****************
//���룺��������ʽ�����ڵ㣬�ļ���
//���أ��ɹ�����true��ʧ�ܷ���false
void createTrees(tNP& biTrees, string fileName)
{
	pTree seqT;
	int i;

	createTrees(seqT, fileName);

	//����T1�ĵ�һ�������
	for (i = 0; i < seqT.n; i++)
	{
		if (seqT.node[i].parent == -1)			//�ҵ���һ�������
		{
			break;
		}
	}
	if (i < seqT.n)
	{
		createTrees(biTrees, seqT, i);
	}
}


//****************�������****************
//ʵ����.����ɭ��.1�����������
//���룺��������ʽ�����ڵ�
void preOrder(tNP biTrees)
{
	if (biTrees != nullptr)
	{
		cout << biTrees->data << "\t";
		preOrder(biTrees->son);
		preOrder(biTrees->brother);
	}
}


//****************�������****************
//ʵ����.����ɭ��.1���������������
//���룺��������ʽ�����ڵ�
void postOrder(tNP biTrees)
{
	if (biTrees != nullptr)
	{
		postOrder(biTrees->son);
		cout << biTrees->data << "\t";
		postOrder(biTrees->brother);
	}
}


//****************��α���****************
//ʵ����.����ɭ��.1����������α���
//���룺��������ʽ�����ڵ�
void floorOrder(tNP biTrees)
{
	lQP Q = nullptr;
	tNP tP = biTrees;

	if (!initialQueue(Q))
	{
		cout << "���г�ʼ��ʧ�ܣ�" << endl;

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


//****************��ȡɭ�ָ߶�****************
//ʵ����.����ɭ��.2����ȡɭ�ָ߶�
//���룺��������ʽ�����ڵ�
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


//****************��ȡɭ�ֽ����****************
//ʵ����.����ɭ��.3����ȡɭ�ֽ����
//���룺��������ʽ�����ڵ㣬��ǰ��¼�����
void countNodes(tNP biTrees, int& num)
{
	if (biTrees)
	{
		num++;
		countNodes(biTrees->son, num);
		countNodes(biTrees->brother, num);
	}
}


//****************��ȡɭ�ֽ����****************
//ʵ����.����ɭ��.3����ȡɭ�ֽ����
//���룺��������ʽ�����ڵ�
int countNodes(tNP biTrees)
{
	int num = 0;

	countNodes(biTrees, num);

	return num;
}


//****************��ȡɭ��Ҷ����****************
//ʵ����.����ɭ��.4����ȡɭ��Ҷ����
//���룺��������ʽ�����ڵ㣬��ǰ��¼��Ҷ����
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


//****************��ȡɭ��Ҷ����****************
//ʵ����.����ɭ��.4����ȡɭ��Ҷ����
//���룺��������ʽ�����ڵ�
int countLeaves(tNP biTrees)
{
	int num = 0;

	countLeaves(biTrees, num);

	return num;
}


//****************����ɭ�ֵĶ���****************
//ʵ����.����ɭ��.5������ɭ�ֵĶ���
//���룺��������ʽ�����ڵ㣬��ǰ��¼�Ľ�����
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


//****************����ɭ�ֵĶ���****************
//ʵ����.����ɭ��.5������ɭ�ֵĶ���
//���룺��������ʽ�����ڵ�
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


//****************����������ֵ����κ�****************
//ʵ����.����ɭ��.6������������ֵ����κ�
//���룺��������ʽ�����ڵ㣬��ǰ�����
void prePrintFloor(tNP biTrees, int num)
{
	if (biTrees != nullptr)
	{
		cout << "(" << biTrees->data << "��" << num << "��\t";
		prePrintFloor(biTrees->son, num+1);
		prePrintFloor(biTrees->brother, num);
	}
}


//****************����������ֵ����κ�****************
//ʵ����.����ɭ��.6������������ֵ����κ�
//���룺��������ʽ�����ڵ㣬��ǰ�����
void prePrintFloor(tNP biTrees)
{
	prePrintFloor(biTrees, 1);
}


//****************���������ʾ����****************
//ʵ����.����ɭ��.7�����������ʾ����
//���룺��������ʽ�����ڵ�
void generalList(tNP biTrees)
{
	lQP Q = nullptr;
	tNP tP = biTrees;
	elementType lastFloor = '1', nowFloor = '1';

	if (!initialQueue(Q))
	{
		cout << "���г�ʼ��ʧ�ܣ�" << endl;

		return;
	}
	while (tP)
	{
		cout << tP->data;
		if (!(tP->brother || tP->son))
		{
			cout << "��";
		}

		if (tP->brother)
		{
			enQueue(Q, tP->brother, nowFloor);
		}
		if (tP->son)
		{
			tP = tP->son;
			nowFloor++;
			cout << "��";
		}
		else
		{
			if (reOutQueue(Q, tP, lastFloor))
			{
				while (nowFloor - lastFloor > 1)
				{
					cout << "��";
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