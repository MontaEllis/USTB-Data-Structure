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
*  �ļ�����:USTB2018_data_structure_test2
*  ��Ҫ����:������׺�������ʽ���磺5+(4-2)*3������ת���ɺ�׺���ʽ�������542-3*+���ٶԺ�׺���ʽ��ֵ���������Ϊ11��������������
*  Ҫ�󣺲�����֧�ֶ�λ����С����
*  ���������+��-��*��/����������#��#��������������
*  ��׺���ʽ�Ӽ����������ļ����롣���������׺���ʽҪ���кϷ��Լ�飨���ʽͷβ�Լ���������ҿ��԰������ɿո�
///////////////////////////////////////////////////
�㷨������
1����׺���ʽ->>��׺���ʽ
	1����ʼ������ջ��һ�����м�����һ���������
	2�������ұ���
	3��������������ѹ���һ��stack1
	4���������������Ƚ�����stack2ջ��Ԫ�ص����ȼ�
		4.1�����stack2Ϊ�գ���Ϊ��������ֱ����ջ
		4.2��������ȼ���stack2��ջ���ߣ�ѹ��
		4.3��������ȼ�bistack2��ջ���ͻ���ȣ�����ջ����
///////////////////////////////////////////////////

*
*  ��������:20180414 11��02
*  ����:Ellis
*  ˵��:��������
*
*  �޸�����:
*  ����:Ellis
*  ˵��:
*  ע�⣺
******************************************************************/

/************************************************************************
* ����    : �궨�塢ͷ�ļ��������ռ���
* ��������: 20180414
* ����    : Ellis
* ˵��    : ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
//#define _CRT_SECURE_NO_WARNINGS              //���scanf����ȫ����
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstdio>
#include <iostream>
#include <string>

#define MAXSIZE 100		//ջ���
/************************************************************************/



/************************************************************************
* ����    : �ṹ�嶨����
* ��������: 20180414
* ����    : Ellis
* ˵��    :
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
typedef struct link_stack
{
	double data_double;
	char data_char;
	link_stack* next;
}stack,*Lstack;

/************************************************************************/



/************************************************************************
* ����    : ����������
* ��������: 
* ����    : Ellis
* ˵��    : 
*
* �޸�����:
* ����    :
* ˵��    :
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
		//1���Թ��ո�
		if (mid[i] == ' ')
		{
			continue;
		}
		//2����������֣�ֱ�����
		else if (isDigital(mid[i]))
		{
			Last[k++] = mid[i];
		}
		//3�����������ţ�ֱ����ջ
		else if (mid[i] == '(' || mid[i] == '��')
		{
			Push_char(stack, mid[i]);

		}
		else if (mid[i] == ')' || mid[i] == '��')
		{
			while (GetTop_char(stack) != '(' || GetTop_char(stack) != '��')
			{
				Last[k++] = Pop_char(stack);
			}
			Pop_char(stack);
		}
		//5�������+-����ջ��Ԫ�ػ���ջ���С���������ֱ����ջ������ȫ����ջ������������Ҳֹͣ��������ջ
		//+-���ȼ����
		else if (mid[i] == '+' || mid[i] == '-')
		{
			Last[k++] = ' ';
			if (IsEmpty(stack) || GetTop_char(stack) == '(' || GetTop_char(stack) == '��')
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
				(GetTop_char(stack) != '(' || GetTop_char(stack) != '��')
				);
				Push_char(stack, mid[i]);
			}
		}
		//6�������*/����ջ�����ȼ����ڵ�ǰ���������ֱ����ջ�������ȳ�ջ����ջ
		else if (mid[i] == '*' || mid[i] == '/')
		{
			Last[k++] = ' ';
			//����������ȼ�����ջ�������ȼ�ʱֱ����ջ
			if (GetPriority(GetTop_char(stack),mid[i]) == 1)
			{
				Push_char(stack, mid[i]);
			}
			else
			{
				//��ջ��Ϊ�գ��ҵ�ǰ����������ȼ�С�ڵ���ջ�������ȼ���ջ�����ǡ����������ܳ�ջ
				while (!IsEmpty(stack) && (GetPriority(GetTop_char(stack), mid[i]) < 1)&&( GetTop_char(stack) != '(' || GetTop_char(stack)!= '��'))
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
	char temp[32] = "";   //��ʱ���
	int k = 0;
	for (int i = 0; i < length;++i)
	{
		//1��ɨ�赽��������ջ
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
	//char Mid_Form[MAXSIZE ] = "";            //��������
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


