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
*  �ļ�����:USTB2018_data_structure_test3
*  ��Ҫ����:��ʽ���еĻ�������
*  ���Ӽ��������һϵ���ַ��洢����ʽ�����У���������ַ�Ϊ��0��ʱ��ִ�г��Ӳ�����������Ԫ�ش�ӡ
*  ����Ļ�ϣ���������ַ�Ϊ��@��ʱ��������ʣ������Ԫ�����γ��Ӳ���ӡ����Ļ�ϣ������������ַ�ʱ���ַ����
*
*  ��������:20180418_10:32
*  ����:Ellis
*  ˵��:������񣬴�������Լ�
*
*  �޸�����:
*  ����:Ellis
*  ˵��:
*  ע�⣺
******************************************************************/

/************************************************************************
* ����    : �궨�塢ͷ�ļ��������ռ���
* ��������: 20180418
* ����    : Ellis
* ˵��    : ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
#define _CRT_SECURE_NO_WARNINGS							 //�������ȫ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************************************************************************/


/************************************************************************
* ����    : �ṹ�嶨����
* ��������: 20180418
* ����    : Ellis
* ˵��    : ��ʽ�Ķ���
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
typedef struct node
{
	char str;
	struct node *next;
}Qnode,*Qlink;


typedef struct 
{
	Qnode *front, *rear;
}linkqueue;
/************************************************************************/



/************************************************************************
* ����    : ����������
* ��������: 20180418
* ����    : Ellis
* ˵��    : ������ֺ���
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
void CreateQueue(linkqueue *q);										//��������
bool isEmpty(linkqueue *q);											//�����п�
void EnQueue(linkqueue *q, char *str_new);							//���
void DeQueue(linkqueue *q);											//����
/************************************************************************/



/************************************************************************
Function Name:void main()
Author       :Ellis
Date         :20180418
Description  :������
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void main()
{
	//Qlink q = (Qlink)malloc(sizeof(Qnode));
	linkqueue *q = (linkqueue*)malloc(sizeof(linkqueue));
	//linkqueue *q = ;
	//q = (linkqueue *)malloc(sizeof(linkqueue));

	//q->front = NULL;
	//q->rear = NULL;
	CreateQueue(q);
	printf("Warning: Only character is supported!\n");
	while (1)
	{
		while (1)
		{
			printf("Please enter your number:\t");
			char mid[100];
			gets(mid);

			printf("%s\n", mid);
																					
			if (strcmp(mid,"0") == 0)						//0ʱ���һ������
			{
				if (!isEmpty(q))
				{
					DeQueue(q);
				}
				else
				{
					printf("Error! Please try again.\n");
				}
			}
			else if (strcmp(mid, "@") == 0)					//@ʱ��������ж���
			{
				if (!isEmpty(q))
				{
					while (1)
					{
						if (
							//!q->front->next
							isEmpty(q))
						{

							break;
						}
						DeQueue(q);
					}
					break;
				}
				else
				{
					printf("Error! Please try again!\n");
				}

			}
			//�������
			else
			{
				EnQueue(q, mid);
			}
			//Qlink new_q = (Qlink)malloc(sizeof(Qnode));


		}

		printf("Continue or not?\n");
		printf("Print arbitrary character to continue. \t Print 'No' to exit.\n");
		char recall[5];
		gets(recall);
		if (strcmp(recall, "No") == 0 || strcmp(recall, "no")  == 0)
		{
			//exit(1);
			break;
		}
		else
		{
			;
		}
	}
	system("pause");
}
/************************************************************************/



/************************************************************************
Function Name:void CreateQueue(linkqueue *q)
Author       :Ellis
Date         :20180418
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void CreateQueue(linkqueue *q)
{
	q->front = (Qlink)malloc(sizeof(Qnode));
	q->front->next = NULL;
	q->rear = q->front;
}
/************************************************************************/


/************************************************************************
Function Name:bool isEmpty(linkqueue *q)
Author       :Ellis
Date         :20180418
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
bool isEmpty(linkqueue *q)
{
	if (q->front == q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/************************************************************************/


/************************************************************************
Function Name:void EnQueue(linkqueue *q, char *str_new)
Author       :Ellis
Date         :20180418
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void EnQueue(linkqueue *q, char *str_new)
{
	Qlink new_q = (Qlink)malloc(sizeof(Qnode));
	new_q->str = *str_new;
	new_q->next = NULL;

	q->rear->next = new_q;
	q->rear = new_q;
}
/************************************************************************/


/************************************************************************
Function Name:void DeQueue(linkqueue *q)
Author       :Ellis
Date         :20180418
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void DeQueue(linkqueue *q)
{
	Qlink mid;
	if (isEmpty(q))
	{
		return;
	}
	else
	{
		mid = q->front;
		q->front = mid->next;
		printf("%c has out.\n", mid->next->str);
		free(mid);
	}
}
/************************************************************************/
