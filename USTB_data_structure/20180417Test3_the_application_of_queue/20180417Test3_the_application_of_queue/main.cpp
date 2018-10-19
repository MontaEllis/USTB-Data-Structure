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
//         佛祖保佑       永无BUG
//  本模块已经经过开光处理，绝无可能再产生bug
//=============================================


/*******************************************************************
*  Copyright(c) :Ellis
*  All rights reserved.
*
*  文件名称:USTB2018_data_structure_test3
*  简要描述:链式队列的基本操作
*  将从键盘输入的一系列字符存储到链式队列中，当输入的字符为’0’时，执行出队操作并将出队元素打印
*  到屏幕上；当输入的字符为’@’时，队列中剩余所有元素依次出队并打印到屏幕上；当输入其他字符时，字符入队
*
*  创建日期:20180418_10:32
*  作者:Ellis
*  说明:完成任务，此任务相对简单
*
*  修改日期:
*  作者:Ellis
*  说明:
*  注意：
******************************************************************/

/************************************************************************
* 名称    : 宏定义、头文件、命名空间区
* 创建日期: 20180418
* 作者    : Ellis
* 说明    : 无
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
#define _CRT_SECURE_NO_WARNINGS							 //解决不安全问题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************************************************************************/


/************************************************************************
* 名称    : 结构体定义区
* 创建日期: 20180418
* 作者    : Ellis
* 说明    : 链式的队列
*
* 修改日期:
* 作者    :
* 说明    :
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
* 名称    : 函数定义区
* 创建日期: 20180418
* 作者    : Ellis
* 说明    : 定义各种函数
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
void CreateQueue(linkqueue *q);										//创建队列
bool isEmpty(linkqueue *q);											//队列判空
void EnQueue(linkqueue *q, char *str_new);							//入队
void DeQueue(linkqueue *q);											//出队
/************************************************************************/



/************************************************************************
Function Name:void main()
Author       :Ellis
Date         :20180418
Description  :主函数
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
																					
			if (strcmp(mid,"0") == 0)						//0时候出一个队列
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
			else if (strcmp(mid, "@") == 0)					//@时候出完所有队列
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
			//否则进队
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
