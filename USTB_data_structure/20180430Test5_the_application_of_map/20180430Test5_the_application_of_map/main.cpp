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
*  �ļ�����:USTB2018_data_structure_test5
*  ��Ҫ����:
*  Ҫ����Ŀ��ͼ�Ĵ洢�ṹ����������
*  �Ӽ��̻��ļ���������ͼ�Ķ�����Ϣ�ͻ���Ϣ�������ʽ���⣩��
*  ��������ͼ��ʮ������洢�ṹ��
*  �����������򷽷��жϸ�ͼ�Ƿ�Ϊ�����޻�ͼ��
*
*
*  ��������:20180501_16:18
*  ����:Ellis
*  ˵��:�����������
*
*  �޸�����:
*  ����:Ellis
*  ˵��:
*  ע�⣺
******************************************************************/




/************************************************************************
* ����    : �궨�塢ͷ�ļ��������ռ���
* ��������: 20180501
* ����    : Ellis
* ˵��    : ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE              //��ܰ�ȫ���
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
/************************************************************************/


/************************************************************************
* ����    : �ṹ�嶨����
* ��������: 20180501
* ����    : Ellis
* ˵��    : ��ջ + ���� + �����
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
typedef struct Node
{
	int date;
	struct Node *next;
}NodeStack,*LinkStack;

typedef char vtype;  //һ��������

typedef struct Anode
{
	int head;
	int tail;
	struct Anode *hlink, *tlink;
}arcNode;

typedef struct Vnode
{
	vtype date;
	arcNode *fin, *fout;
}vexNode;
/************************************************************************/



/************************************************************************
* ����    : ȫ�ֱ�����
* ��������: 20180501
* ����    : Ellis
* ˵��    : 
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
int n;            //��¼����
vexNode G[100];   //�����
/************************************************************************/


/************************************************************************
* ����    : ����������
* ��������: 20180501
* ����    : Ellis
* ˵��    : ������ֺ���,���ɻ������׿�
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
bool IsEmpty(LinkStack s);									//ջ�п�
LinkStack CreateStack();									//����һ��ջ
void Push(LinkStack top, int input);						//��ջ
void Pop(LinkStack top);									//��ջ
char GetTop(LinkStack top);									//ȡջ��
int loactevex(vexNode G[], char u);							//�����
void createList(vexNode G[]);								//����ʮ������
void Creatid(vexNode G[], int id[]);						//�����
void TopSort(vexNode G[]);									//ʮ��������������
/************************************************************************/



/************************************************************************
Function Name:void main()
Author       :Ellis
Date         :20180501
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void main()
{
	printf("Enter 'Y' to start.\n");
	char a = getchar();
	getchar();
	while (a == 'Y')
	{
		createList(G);
		TopSort(G);
		printf("Continue or not ?\nEnter 'Y' to continue,'N' to exit.\n");
		char s = getchar();
		getchar();
		while (1)
		{
			if (s == 'Y')
			{																	//---------------
				//continue;														//Y������N�˳�
				break;															//������������
			}																	//---------------
			else if (s == 'N')
			{
				return;
			}
			else
			{
				printf("Invalid!\nPlease try again.\n");
				s = getchar();
				getchar();
			}
		}
	}
}
/************************************************************************/



/************************************************************************
Function Name:bool IsEmpty(LinkStack s)
Author       :Ellis
Date         :20180501
Description  :�ж϶�ջ�Ƿ�Ϊ��
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
bool IsEmpty(LinkStack s)
{
	return s->next ? false : true;
}
/************************************************************************/


/************************************************************************
Function Name:LinkStack CreateStack()
Author       :Ellis
Date         :20180501
Description  :�½�һ����ջ
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
LinkStack CreateStack()
{
	LinkStack top = (LinkStack)malloc(sizeof(NodeStack));
	top->next = NULL;
	return top;
}
/************************************************************************/



/************************************************************************
Function Name:void Push(LinkStack top, int input)
Author       :Ellis
Date         :20180501
Description  :push
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Push(LinkStack top, int input)
{
	LinkStack node = (LinkStack)malloc(sizeof(NodeStack));
	node->date = input;
	node->next = top->next;
	top->next = node;
}
/************************************************************************/


/************************************************************************
Function Name:void Pop(LinkStack top)
Author       :Ellis
Date         :20180501
Description  :pop
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Pop(LinkStack top)
{
	if (IsEmpty(top))
	{
		return;
		//return 0;
	}
	else
	{
		LinkStack temp = top->next;
		top->next = temp->next;
		//int x = temp->date;
		free(temp);
		//return x;
	}
}
/************************************************************************/


/************************************************************************
Function Name:char GetTop(LinkStack top)
Author       :Ellis
Date         :20180501
Description  :ȡջ��
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
char GetTop(LinkStack top)
{
	if (IsEmpty(top))
	{
		return false;
	}
	else
	{
		return  top->next->date;
	}
	//return IsEmpty(top) ? false : top->next->num_operator;
}
/************************************************************************/



/************************************************************************
Function Name:int loactevex(vexNode G[], char u)
Author       :Ellis
Date         :20180501
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int loactevex(vexNode G[], char u)
{
	for (int i = 0; i < 100; i++)
	{
		if (
			//(&G[i])->date == u
			G[i].date == u
			)
		{
			return i;
		}
	}
	printf("Error!\n");
	return false;
}
/************************************************************************/


/************************************************************************
Function Name:void createList(vexNode G[])
Author       :Ellis
Date         :20180501
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void createList(vexNode G[])
{
	arcNode *p;
	vtype ch, u, v;
	n = 0;												 //ȫ�ֱ������������ƶ�����
	int i = 0;
	int j;
	//----------------------------����-------------------------------//
	printf("Please enter your vertexs.\n");
	printf("# to end.\n");
	ch = getchar();
	getchar();
	while (ch != '#')
	{
		n++;                        //�ƶ�����
		G[i].date = ch;
		G[i].fin = NULL;            //��ʼ��
		G[i].fout = NULL;           //��ʼ��
		i++;
		ch = getchar();
		getchar();

	}
	//---------------------------------------------------------------//

	//----------------------------��---------------------------------//
	printf("Please enter yout arcs.\n");
	printf("Example: a,b");
	printf("# to end.\n");
	scanf("%c,%c", &u, &v);			//����u��v����
	getchar();
	while (u != '#')
	{
		i = loactevex(G, u);
		j = loactevex(G, v);
		p = (arcNode*)malloc(sizeof(arcNode));       //���뻡���
		p->tail = i;
		p->head = j;

		p->hlink = G[j].fin;
		G[j].fin = p;

		p->tlink = G[i].fout;
		G[i].fout = p;

		scanf("%c,%c", &u, &v);			//����u��v����
		getchar();
	}
}
/************************************************************************/



/************************************************************************
Function Name:void Creatid(vexNode G[], int id[])    
Author       :Ellis
Date         :20180501
Description  :�����
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Creatid(vexNode G[], int id[])    //�����
{
	int count;

	arcNode *p;
	for (int i = 0; i < n; i++)   //�����ڽӱ���
	{
		count = 0;
		p = G[i].fin;
		while (p)
		{
			count++;
			p = p->hlink;
		}
		id[i] = count;
	}
}
/************************************************************************/


/************************************************************************
Function Name:void TopSort(vexNode G[])        
Author       :Ellis
Date         :20180501
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void TopSort(vexNode G[])         //ʮ��������������
{
	int j;
	int k;
	int count;
	int id[100];

	LinkStack mid = CreateStack();
	arcNode *p;
	Creatid(G, id);

	for (int i = 0; i < n; i++)
	{
		if (id[i] == 0)
		{
			Push(mid, i);
		}
	}
	count = 0;
	printf("\n");
	while (mid->next)
	{
		j = GetTop(mid);
		Pop(mid);
		//printf("%c \t", G[j].date);
		count++;
		p = G[j].fout;
		while (p)
		{
			k = p->head;
			id[k]--;
			if (id[k] == 0)
			{
				Push(mid, k);

			}
			p = p->tlink;
		}
	}
	printf("\n");

	if (count == n)
	{
		printf("This graph has no cycles.\n");
	}
	else
	{
		printf("This graph has cycles.\n");
	}
}
/************************************************************************/