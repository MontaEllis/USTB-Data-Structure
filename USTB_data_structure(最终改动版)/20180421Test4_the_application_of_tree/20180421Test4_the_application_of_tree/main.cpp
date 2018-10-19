//                   _ooOoo_
//                  o8888888o
//                  88" . "88
//                  (| -_- |)
//                  O\  =  /O
//               ____/`---'\____
//             .'  \\|     |//  `.
//            /  \\|||  :  |||//  \
//           /  _||||| -:- |||||-  \
//           |   | \\\  -  /// |   |
//           | \_|  ''\---/''  |   |
//           \  .-\__  `-`  ___/-. /
//         ___`. .'  /--.--\  `. . __
//      ."" '<  `.___\_<|>_/___.'  >'"".
//     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//     \  \ `-.   \_ __\ /__ _/   .-` /  /
//======`-.____`-.___\_____/___.-`____.-'======
//                   `=---='
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//         ���汣��       ����BUG
//  ��ģ���Ѿ��������⴦�����޿����ٲ���bug
//=============================================


/*******************************************************************
*  Copyright(c) :Ellis
*  All rights reserved.
*
*  �ļ�����:USTB2018_data_structure_test4
*  ��Ҫ����:�����������Ĺ��������
*  Ҫ������һ��Ӣ�ľ��ӣ������ֵ�˳����һ������������
*		���÷ǵݹ��㷨���Դ˶��������������������ӡ�������
*
*
*	���������������������һ����㣬���ȷ������ӣ������ӽ���ֿ��Կ���һ����㣬�������������ӽ�㣬ֱ���ա�
*	���˲ŷ��ʡ�
*
*	��1���������Ӳ�Ϊ�գ�P��ջ���������ӵ���P��Ȼ���P������ͬ�Ĵ���
*	��2����������Ϊ�գ���ȡջ��Ԫ�ز���ջ�����ʸ�ջ��Ԫ�أ�Ȼ�󽫵�ǰP��Ϊջ���ڵ���Һ���
*	��3��ֱ��PΪNULL��ջΪ�գ��˳�
*
*
*  ��������:20180421_20:55
*  ����:Ellis
*  ˵��:�����������
*
*  �޸�����:20180521_00:21
*  ����:Ellis
*  ˵��:txt����
*  ע�⣺
******************************************************************/


/************************************************************************
* ����    : �궨�塢ͷ�ļ��������ռ���
* ��������: 20180421
* ����    : Ellis
* ˵��    : ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE		//��ܰ�ȫ���
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/************************************************************************/



/************************************************************************
* ����    : �ṹ�嶨����
* ��������: 20180421
* ����    : Ellis
* ˵��    : ������+��ջ
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
typedef struct BinaryTreeNode
{
	char m_nString[10];
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}BinaryTreeNode,*BinaryTreeList;


typedef struct stack
{
	BinaryTreeNode *pNode;
	struct stack *next;
}NodeStack,*LinkStack;
/************************************************************************/


/************************************************************************
* ����    : ����������
* ��������: 20180421
* ����    : Ellis
* ˵��    : ������ֺ���,���ɻ������׿�
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
BinaryTreeNode *CreateBinary(char *string);							//����������
BinaryTreeNode* DoneBinaryTree(char *sentence);						//����������
LinkStack CreatStack();												//����ջ
void Push(LinkStack top, BinaryTreeNode *mid);						//��ջ
void Pop(LinkStack top);											//��ջ
BinaryTreeNode* getTop(LinkStack top);								//ȡջ��
void infix_Output(BinaryTreeNode *pRoot);							//�������
void PrintTreeNode(BinaryTreeNode* pNode);							//��ӡ���
void PrintTree(BinaryTreeNode* pRoot);								//��ӡ��
void DestroyTree(BinaryTreeNode* pRoot);							//������
/************************************************************************/



/************************************************************************
Function Name:void main()
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void main()
{
	char sentence[50];

	while (1)
	{
		printf("Enter 1 to use keyborad,2 to use txt.\n");
		char d;
		d = getchar();
		getchar();
		if (d == '1' )
		{
			gets(sentence);
			break;
		}
		else if (d =='2' )
		{
			FILE *file;
			char name_of_txt[20];
			printf("Please enter the name of the txt...\n");
			scanf("%s", name_of_txt);
			file = fopen(name_of_txt, "r");

			if (!file)
			{
				printf("Could not open this txt!\n");
				system("pause");
			}
			else
			{
				printf("Open the txt successfully!\n");
			}

			char ch;
			int k = 0;

			while (
				(ch = fgetc(file)) != EOF					  //����ַ�ȥ��ȡ
				)
			{
				sentence[k] = ch;
				k++;
				ch = NULL;

			}
			sentence[k] = '\0';
			break;
		}
		else
		{
			printf("Error! Please try again!\n");
			continue;
		}
	}


	BinaryTreeNode *DTree;
	DTree = DoneBinaryTree(sentence);

	PrintTree(DTree);
	infix_Output(DTree);
	
	DestroyTree(DTree);
	printf("\n");
	system("pause");
}
/************************************************************************/



/************************************************************************
Function Name:BinaryTreeNode *CreateBinary(char *string)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
BinaryTreeNode *CreateBinary(char *string)
{
	BinaryTreeNode *pNode = (BinaryTreeList)malloc(sizeof(BinaryTreeNode));
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	strcpy(pNode->m_nString, string);

	return pNode;
}
/************************************************************************/




/************************************************************************
Function Name:BinaryTreeNode* DoneBinaryTree(char *sentence)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
BinaryTreeNode* DoneBinaryTree(char *sentence)
{
	char mid[10];
	//memset(mid, '0', sizeof(mid));
	int j = 0;
	BinaryTreeNode *pRoot = NULL;
	for (int i = 0; i < 50; i++)
	{
		if (sentence[i] == ' ')
		{
			continue;
		}
		else if (
			(sentence[i] >= 'a' && sentence[i] <= 'z')
			||
			(sentence[i] >= 'A' && sentence[i] <= 'Z')
			)
		{

			//-----------------------------------------------------------------------------------------
			//ȥһ������
			//-----------------------------------------------------------------------------------------
			while (
				//sentence[i] != ' ' || sentence[i] != '\0'		
				(sentence[i] >= 'a' && sentence[i] <= 'z')
				||
				(sentence[i] >= 'A' && sentence[i] <= 'Z')
				)
			{
				mid[j] = sentence[i];
				j++;
				i++;
			}
			mid[j] = '\0';														//�ǳ���Ҫ���ַ�����β
			//-----------------------------------------------------------------------------------------

			j = 0;

			BinaryTreeNode *pNode = CreateBinary(mid);
			if (!pRoot)												//��root��Node����ȥ
			{
				pRoot = pNode;
			}

			BinaryTreeNode *midTree = pRoot;
			while (midTree)
			{
				if (strcmp(midTree->m_nString, pNode->m_nString) == 1)				//midTree��
				{
					if (!midTree->m_pLeft)											//��������������
					{
						midTree->m_pLeft = pNode;
						break;
					}
					else  															//�������Ƶ�������
					{
						midTree = midTree->m_pLeft;
					}
				}
				else if (strcmp(midTree->m_nString, pNode->m_nString) == -1)		//midTreeС
				{
					if (!midTree->m_pRight)											//��������������
					{
						midTree->m_pRight = pNode;
						break;
					}	
					else                                                           //�������Ƶ�������
					{
						midTree = midTree->m_pRight;
					}
				}
				else
				{
					break;
				}
			}

		}
		else if (sentence[i] == '.')											//ȡ��.�˳�
		{
			break;
		}
	}
	return pRoot;
}
/************************************************************************/


/************************************************************************
Function Name:LinkStack CreatStack()
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
LinkStack CreatStack()
{
	LinkStack top = (LinkStack)malloc(sizeof(NodeStack));
	top->next = NULL;
	top->pNode = NULL;
	return top;
}
/************************************************************************/


/************************************************************************
Function Name:void Push(LinkStack top, BinaryTreeNode *mid)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Push(LinkStack top, BinaryTreeNode *mid)
{
	LinkStack node = (LinkStack)malloc(sizeof(NodeStack));
	node->pNode = mid;
	node->next = top->next;
	top->next = node;
}
/************************************************************************/



/************************************************************************
Function Name:void Pop(LinkStack top)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Pop(LinkStack top)
{
	if (!top->next)
	{
		return;
	}
	else
	{
		LinkStack temp = top->next;
		top->next = temp->next;
		free(temp);
	}
}
/************************************************************************/


/************************************************************************
Function Name:BinaryTreeNode* getTop(LinkStack top)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
BinaryTreeNode* getTop(LinkStack top)
{
	if (!top->next)
	{
		return 0;
	}
	else
	{
		return top->next->pNode;
	}
}
/************************************************************************/


/************************************************************************
Function Name:void infix_Output(BinaryTreeNode *pRoot)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void infix_Output(BinaryTreeNode *pRoot)
{
	//LinkStack S = NULL;
	LinkStack top = CreatStack();
	BinaryTreeNode* p = pRoot;
	while (1)
	{
		while (p)
		{
			Push(top, p);
			p = p->m_pLeft;
		}
		if (!top->next)
		{
			break;
		}
		p = getTop(top);
		Pop(top);
		printf("%s\t", p->m_nString);
		p = p->m_pRight;
	}
	//��1���������Ӳ�Ϊ�գ�P��ջ���������ӵ���P
	//��2����������Ϊ�գ���ȡջ��Ԫ�ز���ջ�����ʸ�ջ��Ԫ�أ�Ȼ�󽫵�ǰP��Ϊջ���ڵ���Һ���
	//��3��ֱ��PΪNULL��ջΪ�գ��˳�
}
/************************************************************************/



/************************************************************************
Function Name:void PrintTreeNode(BinaryTreeNode* pNode)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void PrintTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != NULL)
	{
		printf("The value of this node is %s\n", pNode->m_nString);

		if (pNode->m_pLeft != NULL)
		{
			printf("The value of its left child is %s\n", pNode->m_pLeft->m_nString);
		}
		else
		{
			printf("The value doesn't exist.Its left child is Null.\n");
		}

		if (pNode->m_pRight != NULL)
		{
			printf("The value of its right child is %s\n", pNode->m_pRight->m_nString);

		}
		else
		{
			printf("The value doesn't exist.Its right child is Null.\n");
		}
	}
	else
	{
		printf("The node is Null!\n");
	}

	printf("\n");
}
/************************************************************************/


/************************************************************************
Function Name:void PrintTree(BinaryTreeNode* pRoot)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void PrintTree(BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != NULL)
	{
		if (pRoot->m_pLeft != NULL)
		{
			PrintTree(pRoot->m_pLeft);
		}

		if (pRoot->m_pRight != NULL)
		{
			PrintTree(pRoot->m_pRight);
		}
	}
}
/************************************************************************/


/************************************************************************
Function Name:void PrintTree(BinaryTreeNode* pRoot)
Author       :Ellis
Date         :20180421
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		BinaryTreeNode* pleft = pRoot->m_pLeft;
		BinaryTreeNode* pright = pRoot->m_pRight;
		delete pRoot;												//C++Cdelete��
		pRoot = NULL;

		//DestroyTree(pRoot->m_pLeft);
		//DestroyTree(pRoot->m_pRight);
		DestroyTree(pleft);
		DestroyTree(pright);
	}
}
/************************************************************************/
