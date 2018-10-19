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
*  文件名称:USTB2018_data_structure_test2
*  简要描述:输入中缀算术表达式，如：5+(4-2)*3，将其转换成后缀表达式并输出：542-3*+，再对后缀表达式求值（本例结果为11）并将结果输出。
*  要求：操作数支持多位数和小数；
*  算符仅考虑+、-、*、/、（、）、#（#可用作结束符）
*  中缀表达式从键盘输入或从文件输入。对输入的中缀表达式要进行合法性检查（表达式头尾以及运算符左右可以包含若干空格）
///////////////////////////////////////////////////
算法描述：
1、中缀表达式->>后缀表达式
	1）初始化两个栈，一个存中间结果，一个存操作符
	2）从左到右遍历
	3）遇到操作数，压入第一个stack1
	4）遇到操作符，比较它和stack2栈顶元素的优先级
		4.1）如果stack2为空，或为“（”，直接入栈
		4.2）如果优先级比stack2中栈顶高，压入
		4.3）如果优先级bistack2中栈顶低或相等，弹出栈顶并
///////////////////////////////////////////////////

*
*  创建日期:20180414 11：02
*  作者:Ellis
*  说明:建个工程
*
*  修改日期:
*  作者:Ellis
*  说明:
*  注意：
******************************************************************/

/************************************************************************
* 名称    : 宏定义、头文件、命名空间区
* 创建日期: 20180414
* 作者    : Ellis
* 说明    : 无
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
//#define _CRT_SECURE_NO_WARNINGS              //解决scanf不安全问题
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstdio>
#include <iostream>
#include <string>

#define MAXSIZE 100		//栈深度
/************************************************************************/



/************************************************************************
* 名称    : 结构体定义区
* 创建日期: 20180414
* 作者    : Ellis
* 说明    :
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/
typedef struct link_stack
{
	double data_double;
	char data_char;
	link_stack* next;
}stack,*Lstack;

/************************************************************************/



/************************************************************************
* 名称    : 函数定义区
* 创建日期: 
* 作者    : Ellis
* 说明    : 
*
* 修改日期:
* 作者    :
* 说明    :
************************************************************************/



/************************************************************************
Function Name:
Author       :Ellis
Date         :
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/

Lstack CreateStack()
{
	Lstack First = (Lstack)malloc(sizeof(stack));
	First->data_double = 0;
	First->data_char = 0;
	First->next = NULL;
	return First;
}


bool IsEmpty(Lstack S)
{
	return S ? 
		(
		((int)S->data_char || S->data_double) ?
		false : true
		) 
		: 
		true;
}


void Push_double(Lstack S, double x)
{
	Lstack new_node = (Lstack)malloc(sizeof(stack));
	//new_node->data_char = 
	new_node->data_double = x;
	new_node->next = S->next;
	S->next = new_node;


	S->data_double++;

}



void Push_char(Lstack S, char x)
{
	Lstack new_node = (Lstack)malloc(sizeof(stack));
	//new_node->data_char = 
	new_node->data_char = x;
	new_node->next = S->next;
	S->next = new_node;


	S->data_double++;
}


double Pop_double(Lstack S)
{

	double x;

	if (IsEmpty(S))
	{
		return 0;
	}

	Lstack temp = S->next;
	x = temp->data_double;
	S->next = temp->next;
	S->data_double--;
	free(temp);
	return x;
}


char Pop_char(Lstack S)
{
	char x;

	if (IsEmpty(S))
	{
		return 0;
	}

	Lstack temp = S->next;
	x = temp->data_char;
	S->next = temp->next;
	S->data_double--;
	free(temp);
	return x;
}


double GetTop_double(Lstack S)
{
	return IsEmpty(S) ? false : S->next->data_double;
}

char GetTop_char(Lstack S)
{
	return IsEmpty(S) ? false : S->next->data_char;
}


bool isDigital(char x)
{
	return (x >= '0' && x <= '9') || (x == '.') ? true : false;
}


bool isOperator(char ch)
{
	return ch == '+' ||
		ch == '-' ||
		ch == '*' ||
		ch == '/' ?
		true : false;
}

int GetPriority(char x1,char x2)
{
	if ((x1 == '+' || x1 == '-') && (x2 == '+' || x2 == '-'))
	{
		return 0;
	}
	else if (x1 == x2)
	{
		return 0;
	}
	else if ((x1 == '+' || x1 == '-') && (x2 == '*' || x2 == '/'))
	{
		return 1;
	}
	else if ((x1 == '*' || x1 == '/') && (x2 == '+' || x2 == '-'))
	{
		return -1;
	}
	else if ((x1 == '*' || x1 == '/') && (x2 == '*' || x2 == '/') && x1 != x2)
	{
		return -1;
	}
}


double Calc(double x1, double x2, char s)
{
	switch (s)
	{
	case '+':return x2 + x1;
	case '-':return x2 - x1;
	case '*':return x2 * x1;
	case '/':return x2/x1;
		

	}
	return 0;
}



void Mid2Last(char* mid, char* Last)
{
	Lstack stack = CreateStack();
	int length = strlen(mid);
	double num = 0;
	int k = 0;
	for (int i = 0; i < length; i++)
	{
		//1、略过空格
		if (mid[i] == ' ')
		{
			continue;
		}
		//2、如果是数字，直接输出
		else if (isDigital(mid[i]))
		{
			Last[k++] = mid[i];
		}
		//3、若是左括号，直接入栈
		else if (mid[i] == '(' || mid[i] == '（')
		{
			Push_char(stack, mid[i]);

		}
		else if (mid[i] == ')' || mid[i] == '）')
		{
			while (GetTop_char(stack) != '(' || GetTop_char(stack) != '（')
			{
				Last[k++] = Pop_char(stack);
			}
			Pop_char(stack);
		}
		//5、如果是+-，若栈中元素或者栈顶有‘（’，则直接入栈，否则全部出栈（遇到‘（’也停止）后再入栈
		//+-优先级最低
		else if (mid[i] == '+' || mid[i] == '-')
		{
			Last[k++] = ' ';
			if (IsEmpty(stack) || GetTop_char(stack) == '(' || GetTop_char(stack) == '（')
			{
				Push_char(stack, mid[i]);
			}
			else
			{
				do 
				{
					Last[k++] = Pop_char(stack);
				} 
				while (IsEmpty(stack)&&
				(GetTop_char(stack) != '(' || GetTop_char(stack) != '（')
				);
				Push_char(stack, mid[i]);
			}
		}
		//6、如果是*/，若栈顶优先级低于当前运算符，则直接入栈，否则先出栈再入栈
		else if (mid[i] == '*' || mid[i] == '/')
		{
			Last[k++] = ' ';
			//当运算符优先级大于栈顶的优先级时直接入栈
			if (GetPriority(GetTop_char(stack),mid[i]) == 1)
			{
				Push_char(stack, mid[i]);
			}
			else
			{
				//当栈不为空，且当前运算符的优先级小于等于栈顶的优先级，栈顶不是‘（‘，才能出栈
				while (!IsEmpty(stack) && (GetPriority(GetTop_char(stack), mid[i]) < 1)&&( GetTop_char(stack) != '(' || GetTop_char(stack)!= '（'))
				{
					Last[k++] = Pop_char(stack);
				}
				Push_char(stack, mid[i]);
			}
		}
		
	}
	while (!IsEmpty(stack))
	{
		Last[k++] = Pop_char(stack);
	}
}

double CalLast(char* Last)
{
	Lstack stack = CreateStack();
	int length = strlen(Last);
	double result = 0;
	char temp[32] = "";   //临时存放
	int k = 0;
	for (int i = 0; i < length;++i)
	{
		//1、扫描到数字则入栈
		if (isDigital(Last[i]))
		{
			temp[k++] = Last[i];
		}
		else if (Last[i] == ' ')
		{
			if (k >0)
			{
				Push_double(stack, atof(temp));
				memset(temp,0,sizeof(temp));
				k = 0;

			}
			double op1 = Pop_double(stack);
			double op2 = Pop_double(stack);
			result = Calc(op1, op2, Last[i]);
			Push_double(stack, result);
		}
	}
	return Pop_double(stack);
}

int main()
{
	//char Mid_Form[MAXSIZE ] = "";            //输入中序
	//gets(Mid_Form);
	//printf("The string you type in is:\n");
	//printf("%s\n", Mid_Form);
	////printf("Please check.\n");


	char last[MAXSIZE] = "";
	Mid2Last("2*(2 + 2 -2 +3 -3)*2*3", last);
	printf("%s\n", last);
	printf("%d\n", CalLast(last));
	system("pause");
	return 0;
}











/************************************************************************
Function Name:
Author       :Ellis
Date         :
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/


