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
*  ��Ҫ����:������׺�������ʽ���磺5+(4-2)*3������ת���ɺ�׺���ʽ�������542-3*+���ٶԺ�׺���ʽ��ֵ���������Ϊ11������������
*  Ҫ��1��������֧�ֶ�λ����С��
*  		2�������������+��-��*��/����������#��#��������������
*		3����׺���ʽ�Ӽ����������ļ����롣���������׺���ʽҪ���кϷ��Լ�飨���ʽͷβ�Լ���������ҿ��԰������ɿո�
*	�㷨������
*	������ɨ����ʽ������һ��ջs��Ų�����;
*	����������ÿ������x�������¼����������
*	1) x = �����������x;
*	2) x = '('��x��ջ��
*	3) x = �������������ţ���
*	while (1) {
*	if (EmptyStack(s)) break;
*	y = GetTop(s);  
*   if (y = '(') break;
*	if (y ���ȼ�< x) break;
*	y��ջ�������
*	}
*	x��ջ;
*	4) x = ')' ��//֮ǰ��ջ��'('��')'֮��Ĳ�����Ӧ�ȼ��㣡
*	������ջ�������ջ�Ĳ�������ֱ����'('���˵�;
*	��ɨ�����ʱ����ջ�ǿգ���ջ���������γ�ջ���;
*
*
*
*  ��������:20180416_22:31
*  ����:Ellis
*  ˵��:��ɱ��ʽ�͸������ı�ʾ����������ע��
*
*  �޸�����:20180417_8:37
*  ����:Ellis
*  ˵��:�����������
*  ע�⣺��
*
*  �޸�����:20180511_14��01
*  ����:Ellis
*  ˵��:�޲�������bug
*  ע�⣺��
******************************************************************/


/************************************************************************
* ����    : �궨�塢ͷ�ļ��������ռ���
* ��������: 20180416
* ����    : Ellis
* ˵��    : ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE		//��ܰ�ȫ���
#include <stdio.h>
#include <string>
#include <stdlib.h>
/************************************************************************/



/************************************************************************
* ����    : �ṹ�嶨����
* ��������: 20180416
* ����    : Ellis
* ˵��    : ��ʽ�Ķ�ջ������+��+���ָ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
typedef struct _link_stack
{
	char num_operator;
	double num_number;
	_link_stack *next;
}stack,*Lstack;
/************************************************************************/



/************************************************************************
* ����    : ����������
* ��������: 20180417
* ����    : Ellis
* ˵��    : ������ֺ���,���ɻ������׿�
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
Lstack CreateStack();										//����ջ
bool IsEmpty(Lstack L);										//�ж��Ƿ�Ϊ��
void Push_Operator(Lstack top, char cal_operator);			//��ջ����
void Push_Num(Lstack top, double cal_num);					//��ջ����
char Pop_Operator(Lstack top);								//��ջ����
double Pop_Num(Lstack top);									//��ջ����
char GetTop(Lstack top);									//ȡջ������
char GetTop_Num(Lstack top);								//ȡջ������
int Priority_check(char ch1, char ch2);						//���ȼ��ж�
void Mid_Post(char infix[100], char* suffix);				//��׺ת��׺����
double Postcount(char *suffix);								//����ֵ
/************************************************************************/







/************************************************************************
Function Name:void main()
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :�������
Revision     :
************************************************************************/
void main()
{
	while(1)
	{
		getchar();

		printf("Enter Y to Start , N to end.\n");
		int c;
		c = getchar();
		getchar();
		if (c == 'Y')
		{
			//------------------------------------------------------------
			//��������
			//------------------------------------------------------------

			printf("txt or keyboard?\nEntet 1 to load txt,2 to use keyboard.\n");
			char d;
			d = getchar();
			getchar();

			char suffix[100] = "";
			char ins[100];


			if (d == '1')
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
					ins[k] = ch;
					k++;
					ch = NULL;

				}
				ins[k] = '\0';

			}
			else if (d == '2')
			{

				printf(">>>Please enter your string:\t");
				gets(ins);
			}
			else
			{
				printf("Errot enter!\n");
				system("pause");
				return;
			}


			//------------------------------------------------------------


			//Infix2Suffix("2 * ( 2 + 2 - 2 + 3) * 2 / 3", suffix);
			//Infix2Suffix(" 2+3*(7-4)", suffix);


			//------------------------------------------------------------
			//��׺ת��׺
			//------------------------------------------------------------
			printf("\n");
			Mid_Post(ins, suffix);
			printf("The infix you enter in is: %s\t", ins);
			printf("\n");
			printf("The suffix is: %s\t", suffix);
			printf("\n");
			//------------------------------------------------------------


			//------------------------------------------------------------
			//��׺����ֵ
			//------------------------------------------------------------
			printf(">>>------------------------------\n");
			double x = Postcount(suffix);
			printf("The result is :\t %lf", x);
			printf("\n");
			//------------------------------------------------------------

		}
		else if (c == 'N')
		{
			system("pause");
			return;
		}
		else
		{
			printf("Error enter!Please try again!\n");
			continue;
		}
	}


	

	system("pause");
}
/************************************************************************/




/************************************************************************
Function Name:Lstack CreateStack()
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
Lstack CreateStack()
{
	Lstack top = (Lstack)malloc(sizeof(stack));
	top->next = NULL;
	top->num_operator = 0;
	top->num_number = 0;
	return top;
}
/************************************************************************/


/************************************************************************
Function Name:bool IsEmpty(Lstack L)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
bool IsEmpty(Lstack L)
{
	return L->next ? false : true;
}
/************************************************************************/



/************************************************************************
Function Name:void Push_Operator(Lstack top, char cal_operator)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Push_Operator(Lstack top, char cal_operator)
{
	Lstack node = (Lstack)malloc(sizeof(stack));
	node->num_operator = cal_operator;
	node->num_number = 0;
	node->next = top->next;
	top->next = node;

}
/************************************************************************/



/************************************************************************
Function Name:void Push_Num(Lstack top, double cal_num)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Push_Num(Lstack top, double cal_num)
{
	Lstack node = (Lstack)malloc(sizeof(stack));
	node->num_operator = 0;
	node->num_number = cal_num;
	node->next = top->next;
	top->next = node;
}
/************************************************************************/


/************************************************************************
Function Name:char Pop_Operator(Lstack top)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
char Pop_Operator(Lstack top)
{
	if (IsEmpty(top))
	{
		return 0;
	}
	else
	{
		Lstack temp = top->next;
		top->next = temp->next;
		char x = temp->num_operator;
		free(temp);
		return x;
	}
}
/************************************************************************/



/************************************************************************
Function Name:double Pop_Num(Lstack top)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
double Pop_Num(Lstack top)
{
	if (IsEmpty(top))
	{
		return 0;
	}
	else
	{
		Lstack temp = top->next;
		top->next = temp->next;
		double x = temp->num_number;
		free(temp);
		return x;
	}
}
/************************************************************************/



/************************************************************************
Function Name:char GetTop(Lstack top)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
char GetTop(Lstack top)
{

	if (IsEmpty(top))
	{
		return false;
	}
	else
	{
		return  top->next->num_operator;
	}
	//return IsEmpty(top) ? false : top->next->num_operator;
}
/************************************************************************/



/************************************************************************
Function Name:char GetTop_Num(Lstack top)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
char GetTop_Num(Lstack top)
{

	if (IsEmpty(top))
	{
		return false;
	}
	else
	{
		return  top->next->num_number;
	}
	//return IsEmpty(top) ? false : top->next->num_operator;
}
/************************************************************************/



/************************************************************************
Function Name:int Priority_check(char ch1, char ch2)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int Priority_check(char ch1, char ch2)
{
	if ((ch1 == '+' || ch1 == '-') && (ch2 == '+' || ch2 == '-'))
	{
		return 0;
	}
	else if ((ch1 == '*' || ch1 == '/') && (ch2 == '*' || ch2 == '/'))
	{
		return 0;
	}
	else if ((ch1 == '+' || ch1 == '-') && (ch2 == '*' || ch2 == '/'))
	{
		return 1;
	}
	else if ((ch1 == '*' || ch1 == '/') && (ch2 == '+' || ch2 == '-'))
	{
		return 0;
	}
}
/************************************************************************/



/************************************************************************
Function Name:void Mid_Post(char infix[100], char* suffix)
Author       :Ellis
Date         :20180417
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Mid_Post(char infix[100], char* suffix)
{
	Lstack L = CreateStack();
	int length = strlen(infix);
	int k = 0;                        //suffix��ֵ�ı�־�ƶ�λ

	int count_oper = 0;
	int count_num = 0;

	int flag_l = 0;						//�����ŵ��ж���־λ����
	int flag_r = 0;						//�����ŵ��ж���־λ���ң�

	int last = 1;
	for (int i = 0; i < length; i++)
	{
		//suffix[k] = ' ';
		//k++;
		

		if (infix[i] == ' ')
		{
			continue;
		}
		else if (infix[i] <= '9' && infix[i] >= '0')
		{
			//if (flag_num == 1)
			//{
			//	//continue;
			//	;
			//}
			//else
			//{
			//	printf("Error!\n");														//�������
			//	system("pause");

			//	//exit(1);
			//}
			//flag_oper = 0;  //���ſ���
			count_num++;
			last = 1;

			suffix[k] = infix[i];
			k++;

			//suffix[k] = ' ';
			//k++;
			while ((infix[i + 1] <= '9' && infix[i + 1] >= '0') || infix[i + 1] == '.')
			{
				suffix[k] = infix[i + 1];
				k++;
				i++;
			}
			suffix[k] = ' ';
			k++;
		}
		else if (infix[i] == '(')										//ɨ�������Ž�ջ
		{
			Push_Operator(L, infix[i]);
			flag_l = 1;
			last = 0;
			//char x = GetTop(L);
			//printf("%c", x);


		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			//if (flag_oper ==1)										//��������
			//{															//��ջ��Ϊ������
			//	//continue;												//��ջ�����ȼ��ͣ�����
			//	;														//��ջ�����
			//}															//��ջ����
			//else
			//{
			//	printf("Error!\n");
			//	system("pause");

			//	//exit(1);
			//}
			//flag_oper = 0; //����׼��

			count_oper++;
			last = 0;
			//if (IsEmpty(L))
			//{
			//	break;
			//}
			//else if (GetTop(L) == '(')
			//{
			//	continue;
			//	//i = i - 1;
			//}
			while (1)
			{
				if (IsEmpty(L))
				{
					break;
				}

				char y = GetTop(L);

				//printf("%c\n", y);


				if (y == '(')
				{
					break;
				}

				if (!Priority_check(infix[i], y))
				{
					break;
				}
				suffix[k] = y;
				Pop_Operator(L);
				k++;
				suffix[k] = ' ';
				k++;
			}
			Push_Operator(L, infix[i]);

			printf("%c\n", suffix[i]);

		}
		else if (infix[i] == ')')									//��������(������һֱ��ջ���
		{
			flag_r = 1;
			last = 1;
			int flag_k = 0;											//�õ����ı�־λ��ƥ��ı�־λ
			while (1)
			{
				if (GetTop(L) == '(')
				{
					Pop_Operator(L);

					flag_k = 1;
					break;
				}
				suffix[k] = Pop_Operator(L);
				k++;
				suffix[k] = ' ';
				k++;



			}
			if (flag_k == 0)
			{
				printf("Error!\n");
				//exit(1);
				system("pause");
			}

			if (flag_r & flag_l) 
			{
				flag_l = 0;
				flag_r = 0;
			}
		}
		else if (infix[i] == '#')
		{
			if (count_num - count_oper != 1)
			{
				printf("Error!\n");
				system("pause");

				//exit(1);
			}
			if ((!flag_l)&&(!flag_r))
			{
				;
			}
			else
			{
				printf("Error!\n");
				system("pause");
			}

			if (last == 1)
			{
				;
			}
			else
			{
				printf("Error!\n");
				system("pause");
			}
			break;
		}
		else
		{
			printf("Error!\n");
			system("pause");

			//exit(1);
		}
	}
	while (!IsEmpty(L))																	//�����ջ��Ϊ�գ�ȫ�����ջ
	{
		suffix[k] = Pop_Operator(L);
		k++;
		suffix[k] = ' ';
		k++;
	}

}
/************************************************************************/






/************************************************************************
Function Name:double Postcount(char *suffix)
Author       :Ellis
Date         :20180417
Description  :����˵������popһ�����ţ����������������ջ
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
double Postcount(char *suffix)
{
	Lstack L = CreateStack();
	int length = strlen(suffix);

	double result;

	char temp[100];
	int k = 0;

	for (int i = 0; i < length; i++)
	{
		if (suffix[i] == ' ')
		{
			continue;
		}
		else if (suffix[i] <= '9' && suffix[i] >= '0')
		{
			temp[k] = suffix[i];
			k++;

			while ((suffix[i + 1] <= '9' && suffix[i + 1] >= '0') || suffix[i + 1] == '.')
			{
				temp[k] = suffix[i + 1];
				k++;
				i++;
			}
			double x = atof(temp);
			Push_Num(L, x);
			k = 0;
			memset(temp, 0, sizeof(temp));
		}
		else if (suffix[i] == '+')
		{
			double x1 = Pop_Num(L);
			double x2 = Pop_Num(L);
			double x = x1 + x2;
			Push_Num(L, x);
		}
		else if (suffix[i] == '-')
		{
			double x1 = Pop_Num(L);
			double x2 = Pop_Num(L);
			double x = x2 - x1;
			Push_Num(L, x);
		}
		else if (suffix[i] == '*')
		{
			double x1 = Pop_Num(L);
			double x2 = Pop_Num(L);
			double x = x2 * x1;
			Push_Num(L, x);
		}
		else if (suffix[i] == '/')
		{
			double x1 = Pop_Num(L);
			double x2 = Pop_Num(L);
			double x = x2 / x1;
			Push_Num(L, x);
		}
	}

	if (!L->next->next)
	{
		return result = Pop_Num(L);

	}
	else
	{
		return false;
	}
}
/************************************************************************/