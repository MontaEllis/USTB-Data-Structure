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
*  文件名称:USTB2018_data_structure_test1
*  简要描述:求相邻k个节点数值之和最大的第一节点
*  输入数据（设为整型）建立单链表，并求相邻k个节点data值之和为最大的第一节点。例如输入k = 2，数据为2 6 4 7 3 #（#为结束符），
*  建立下面链表，运行结果  输出（序号3，data值4）
*
*  创建日期:20180406_22:57
*  作者:Ellis
*  说明:完成建表
*
*  修改日期:20180407_10:02
*  作者:Ellis
*  说明:完成任务，修改完注释
*  注意：本程序因输入时有“#”符号，故所有函数都有意忽略了最后的节点
******************************************************************/

/************************************************************************
* 名称    : 宏定义、头文件、命名空间区
* 创建日期: 20180406
* 作者    : Ellis
* 说明    : 无
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
#define _CRT_SECURE_NO_WARNINGS              //解决scanf不安全问题
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstdio>
#include <iostream>
#include <string>
/************************************************************************/



/************************************************************************
* 名称    : 结构体定义区
* 创建日期: 20180406
* 作者    : Ellis
* 说明    : 链表式的结构体，数据+后继指针
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
typedef struct tagNONE
{
	int date;
	struct tagNONE *next;
}ListNode,*LinkList;
/************************************************************************/



/************************************************************************
* 名称    : 函数定义区
* 创建日期: 20180406
* 作者    : Ellis
* 说明    : 定义各种函数
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
LinkList Creatlist();													//创建链表
void Test_Print_List(LinkList pList);									//打印处于链表
int input();															//输入函数
int Adjmax(LinkList L, int k);											//求相邻k个节点数值之和最大的第一节点
void Destroy_List(LinkList L);											//销毁链表
/************************************************************************/



/************************************************************************
Function Name:int main(int argc, char** argv)
Author       :Ellis
Date         :20180406
Description  :主函数
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void main(int argc,char** argv)
{
	while (1)
	{
		//*********************************//
		LinkList p = Creatlist();  //建表
		//*********************************//

		//*********************************//
		Test_Print_List(p);        //打印
		//*********************************//

		printf("Please enter k : \t");
		int k = input();
		//getchar();

		printf("\n");

		printf(">>>The result is :...\n");
		
		
		//*********************************//
		printf("和为%d\n", Adjmax(p, k)); //打印出结果
		//*********************************//

		//*********************************//
		Destroy_List(p);			//销毁链表
		//*********************************//

		printf(">>>Continue or not ?... \n");
		printf("Enter Y to continue/t Enter N to exit...\n");
		while (1)
		{
			getchar();
			if (getchar() == 'Y')
			{
				//continue;
				break;
			}
			else if (
				getchar() == 'N')
			{
				exit(1);
			}
			else
			{
				//printf("Error!\n");
				//continue;
				system("pause");
				exit(1);
			}
		}


	}

	system("pause");
}
/************************************************************************/





/************************************************************************
Function Name:LinkList Creatlist()
Author       :Ellis
Date         :20180406
Description  :建表函数
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
LinkList Creatlist()
{
	printf(">>>================List Building Start=============\n");

	LinkList Middd = NULL;	//不断移动的节点
	LinkList Head = NULL;   //始终指向链表的头
	LinkList P_List = NULL; //不断创建的新节点
	Head = Middd = (LinkList)malloc(sizeof(ListNode));
	printf(">>>Please enter the numbers:...\n");


	while (1)
	{
		int s = input();

		P_List = (LinkList)malloc(sizeof(ListNode));
		P_List->date = s;
		Middd->next = P_List;
		Middd = P_List;
		if (getchar() == '#')
		{
			break;
		}
	}
	Middd->next= NULL;

	return Head;
		
}
/************************************************************************/






/************************************************************************
Function Name:void Test_Print_List(LinkList pList)
Author       :Ellis
Date         :20180406
Description  :打印函数
Inputs       :
Outputs      :
Notes        :打印出一切链表
Revision     :
************************************************************************/
void Test_Print_List(LinkList pList)
{
	printf("================Start to print=============.\n");
	LinkList nList = pList->next;

	while (nList->next)
	{
		printf("%d\t", nList->date);
		nList = nList->next;

	}
	printf("\n");
}
/************************************************************************/


/************************************************************************
Function Name:int input()
Author       :Ellis
Date         :20180406
Description  :输入函数
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int input()
{
	int w;
	scanf("%d", &w);
	return w;
}
/************************************************************************/


/************************************************************************
Function Name:int Length(LinkList x)
Author       :Ellis
Date         :20180407
Description  :求长度函数
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int Length(LinkList x)
{
	LinkList H = x->next;
	int i = -1;
	while (H)
	{
		++i;
		H = H->next;
	}
	return i;
}
/************************************************************************/


/************************************************************************
Function Name:int Adjmax(LinkList L, int k)
Author       :Ellis
Date         :20180407
Description  :求最大值函数
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int Adjmax(LinkList L, int k)
{
	int length = Length(L);
	if (k > length)
	{
		printf("Error! \n");
		exit(1);
	}
	LinkList LL = L;

	int sum_real = 0;
	//***************************************************//
	//第一次分开来写，因为比较难搞定头节点问题
	int count = k;
	int j = 1;							//序列号
	int realj = 0;						//需要输出的

	LinkList mid = L;          //注意，不能乱动L，要用中间变量
	while (count)
	{
		sum_real = sum_real + mid->next->date;
		mid = mid->next;
		--count;
	}
	L = L->next;    //重要
	//***************************************************//



	int nCount = length - k;
	int sum = 0; //和

	while (nCount)
	{
		count = k;

		//*******************************//
		LinkList mid_list = L;  //注意，不能乱动L，要用中间变量
		//*******************************//


		//******************************************//
		//求出k个连续量之和
		while (count)
		{
			count--;
			sum = sum + mid_list->next->date;
			mid_list = mid_list->next;
		}

		j++;									//序号加1
		//******************************************//

		//*******************************//
		L = L->next;  //重要，L不断后移
		//*******************************//

		nCount--;

		//**************************************//
		//求最大值
		if (sum > sum_real)
		{
			realj = j;									//若更新最大值，则赋值
			sum_real = sum;
			sum = 0;
		}
		else
		{
			sum = 0;
			continue;
		}
		//**************************************//


	}
	printf("序号%d\n", realj);

	for (int s = 0; s < realj;s++)
	{
		LL = LL->next;
	}
	printf("值%d\n", LL->date);

	return sum_real;
}
/************************************************************************/



/************************************************************************
Function Name:void Destroy_List(LinkList L)
Author       :Ellis
Date         :20180407
Description  :销毁链表函数
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Destroy_List(LinkList L)
{
	L = NULL;
}
/************************************************************************/
