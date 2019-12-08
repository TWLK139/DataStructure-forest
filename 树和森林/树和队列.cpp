#include"BiTree.h"

int main(void)
{
	tNP biTrees = nullptr;
	int order = NULL;

	while (1)
	{
		cout << "ʵ������������ʵ��" << endl;
		cout << "*****************************************" << endl;
		cout << "*1��ɭ�ֵ����ֱ�����\t\t\t*" << endl;
		cout << "*2��ɭ�ֵĸ߶ȡ�\t\t\t*" << endl;
		cout << "*3��ɭ�ֽ��������\t\t\t*" << endl;
		cout << "*4��ɭ��Ҷ�ӽ������\t\t\t*" << endl;
		cout << "*5��ɭ�ֵĶȡ�\t\t\t\t*" << endl;
		cout << "*6������������ֵ�����κš�\t\t*" << endl;
		cout << "*7�����������ʾ������\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0���˳�����\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "������˵���ţ�\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���tree11.tre����";
			createTrees(biTrees, "tree11.tre");
			cout << endl << "���������\t";
			preOrder(biTrees);
			cout << endl << "���������\t";
			postOrder(biTrees);
			cout << endl << "��α�����\t";
			floorOrder(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���f20.tre����";
			createTrees(biTrees, "f20.tre");
			cout << endl << "���������\t";
			preOrder(biTrees);
			cout << endl << "���������\t";
			postOrder(biTrees);
			cout << endl << "��α�����\t";
			floorOrder(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���tree11.tre����" << endl;
			cout << "ɭ�ֵĸ߶ȣ�";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << treesHeight(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���f20.tre����" << endl;
			cout << "ɭ�ֵĸ߶ȣ�";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << treesHeight(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 3:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���tree11.tre��" << endl;
			cout << "ɭ�ֽ��������";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << countNodes(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���f20.tre��" << endl;
			cout << "ɭ�ֽ��������";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << countNodes(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 4:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���tree11.tre��" << endl;
			cout << "ɭ��Ҷ�ӽ������";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << countLeaves(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���f20.tre��" << endl;
			cout << "ɭ��Ҷ�ӽ������";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << countLeaves(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 5:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���tree11.tre��" << endl;
			cout << "ɭ�ֵĶȣ�";
			createTrees(biTrees, "tree11.tre");
			cout << "\t" << countDegree(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���f20.tre��" << endl;
			cout << "ɭ�ֵĶȣ�";
			createTrees(biTrees, "f20.tre");
			cout << "\t" << countDegree(biTrees) << endl;
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���tree11.tre��" << endl;
			cout << "����������ֵ�����κţ�" << endl;
			createTrees(biTrees, "tree11.tre");
			prePrintFloor(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���f20.tre��" << endl;
			cout << "����������ֵ�����κţ�" << endl;
			createTrees(biTrees, "f20.tre");
			prePrintFloor(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 7:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���tree11.tre��" << endl;
			cout << "���������ʾ������" << endl;
			createTrees(biTrees, "tree11.tre");
			generalList(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���f20.tre��" << endl;
			cout << "���������ʾ������" << endl;
			createTrees(biTrees, "f20.tre");
			generalList(biTrees);
			destoryTrees(biTrees);
			cout << endl;
			//********************************************************************
			break;
		case 0:
			cout << "�˳�����" << endl;
			return 0;
		default:
			system("cls");
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}