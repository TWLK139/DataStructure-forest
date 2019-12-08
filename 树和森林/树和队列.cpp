#include"BiTree.h"

int main(void)
{
	tNP biTrees = nullptr;
	int order = NULL;

	while (1)
	{
		cout << "实验六：二叉树实验" << endl;
		cout << "*****************************************" << endl;
		cout << "*1，森林的三种遍历序。\t\t\t*" << endl;
		cout << "*2，森林的高度。\t\t\t*" << endl;
		cout << "*3，森林结点总数。\t\t\t*" << endl;
		cout << "*4，森林叶子结点数。\t\t\t*" << endl;
		cout << "*5，森林的度。\t\t\t\t*" << endl;
		cout << "*6，先序输出结点值及其层次号。\t\t*" << endl;
		cout << "*7，输出广义表表示的树。\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验（文件：tree11.tre）：";
			createTrees(biTrees, "tree11.tre");
			cout << endl << "先序遍历序：\t";
			preOrder(biTrees);
			cout << endl << "后序遍历序：\t";
			postOrder(biTrees);
			cout << endl << "层次遍历序：\t";
			floorOrder(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验（文件：f20.tre）：";
			createTrees(biTrees, "f20.tre");
			cout << endl << "先序遍历序：\t";
			preOrder(biTrees);
			cout << endl << "后序遍历序：\t";
			postOrder(biTrees);
			cout << endl << "层次遍历序：\t";
			floorOrder(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验（文件：tree11.tre）：" << endl;
			cout << "森林的高度：";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << treesHeight(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验（文件：f20.tre）：" << endl;
			cout << "森林的高度：";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << treesHeight(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 3:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：tree11.tre）" << endl;
			cout << "森林结点总数：";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << countNodes(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：f20.tre）" << endl;
			cout << "森林结点总数：";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << countNodes(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 4:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：tree11.tre）" << endl;
			cout << "森林叶子结点数：";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << countLeaves(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：f20.tre）" << endl;
			cout << "森林叶子结点数：";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << countLeaves(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 5:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：tree11.tre）" << endl;
			cout << "森林的度：";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << countDegree(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：f20.tre）" << endl;
			cout << "森林的度：";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << countDegree(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：tree11.tre）" << endl;
			cout << "先序输出结点值及其层次号：" << endl;
			createTrees(biTrees, "tree11.tre");
			prePrintFloor(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：f20.tre）" << endl;
			cout << "先序输出结点值及其层次号：" << endl;
			createTrees(biTrees, "f20.tre");
			prePrintFloor(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 7:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：tree11.tre）" << endl;
			cout << "输出广义表表示的树：" << endl;
			createTrees(biTrees, "tree11.tre");
			generalList(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：f20.tre）" << endl;
			cout << "输出广义表表示的树：" << endl;
			createTrees(biTrees, "f20.tre");
			generalList(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 0:
			cout << "退出程序！" << endl;
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}