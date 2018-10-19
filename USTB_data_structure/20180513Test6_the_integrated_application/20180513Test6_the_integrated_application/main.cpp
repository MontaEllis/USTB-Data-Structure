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
*  �ļ�����:USTB2018_data_structure_test6
*  ��Ҫ����:
*  Ҫ����Ŀ��ͳ�����ɸ�����Ӣ��txt�ļ�����Ӣ��С˵�������е��ʳ��ֵĴ�������������ִ�������ǰ10�����ʼ�����ִ�����
*
*  �����ַ�����Ϊ��Сд��ĸ�����ֺ��»��ߣ�
*  �����ַ����������ʷָ�����
*  ������ƺ��ʵ����ݽṹ������㷨��
*  �������н���ʱ��txt�ļ����Լ�ͳ�ƽ��д����̣�
*  ÿ�γ�������ʱ�������״����У����ϴεĽ�������ڴ桢��ʾ��
*  �ܸ����û�ѡ��ʵ�����³�ʼ��������ĳ���ʳ��ִ�����׷��ͳ�ơ��˳��ȹ��ܡ�
*
*
*  ��������:20180519_10:20
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
* ��������: 20180519
* ����    : Ellis
* ˵��    : ��
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
#define NUM 9999												 //������Ҫ��
/************************************************************************/


/************************************************************************
* ����    : �ṹ�嶨����
* ��������: 20180519
* ����    : Ellis
* ˵��    : ��ʽ��ϣ
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
typedef struct HashList
{
	char word[20]; 
	int count = 0;            //��������Ϊ��
	struct HashList* next;
}HashList;
/************************************************************************/



/************************************************************************
* ����    : ȫ�ֱ�����
* ��������: 20180519
* ����    : Ellis
* ˵��    :
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
HashList* HashKeyList[NUM];
int Num_word = 0;												 //������
/************************************************************************/



/************************************************************************
* ����    : ����������
* ��������: 20180519
* ����    : Ellis
* ˵��    : ������ֺ���,���ɻ������׿�
*
* �޸�����:
* ����    :
* ˵��    :
************************************************************************/
void Put_in(char* word);											//���뺯��
int Cal_The_Key_Value(char* word);									//��ؼ�ֵ
bool BuildHash(FILE *file);											//������ϣ��
void PrintTheList(HashList** HashKeyList);							//��ӡ����ϣ�������ã�
void WriteResult(HashList** HashKeyList);							//д�����txt
void QuickSort(HashList** List, int l, int r);						//����
void ReList(HashList** HashKeyList, HashList** sort_hash);			//����ϣ���ع�Ϊһ���޳�ͻ�ı�
void Print_Most(HashList** sort);									//��ӡ��Ƶ����ߵ�ʮ��Ƶ�ʶ�Ӧ�ĵ���
void Seek_for();													//׷����������ϣ����
void DataLastTime();												//��ʾ�ϴε�ͳ�ƽ��
/************************************************************************/






/************************************************************************
Function Name:void main()
Author       :Ellis
Date         :20180519
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int main()
{
	DataLastTime();																//��ʾ���ϴ�ͳ������

	//-------------------------------------------//
	//����Ҫ�򿪵�txt�ļ�������
	//-------------------------------------------//
	FILE *file;
	char name_of_txt[20];
	printf("Please enter the name of the txt...\n");
	scanf("%s", name_of_txt);
	file = fopen(name_of_txt, "r");
	//-------------------------------------------//


	HashList* sort_hash[NUM];


	if (!file)
	{
		printf("Could not open this txt!\n");
		system("pause");
	}
	else
	{
		printf("Open the txt successfully!\n");
	}
	
	BuildHash(file);
	//PrintTheList(HashKeyList);

	//WriteResult(HashKeyList);

	ReList(HashKeyList, sort_hash);
	//��ʼ����
	QuickSort(sort_hash, 0, Num_word - 1);
	WriteResult(sort_hash);


	//printf("%d", Num_word);

	//ȡ���ʮ��
	printf("////////////////////////////////");
	Print_Most(sort_hash);


	char t;

	while (1)
	{
		printf("/***********************************************************************/\n");
		printf("\/\t\t\t\t����̨\t\t\t\t\t\/\n");
		printf("\/\t\t\tCopyRight:\tEllis\t\t\t\t\/\n");
		printf("/***********************************************************************/\n");
		printf("\/\t\t\t\tDescription:\t\t\t\t\/\n");
		printf("\/\t\t\tEnter'A'to initialize the program.\t\t\/\n");
		printf("\/\t\t\tEnter'B'to seek ont word.\t\t\t\/\n");
		printf("\/\t\t\tEnter'C'to count more.\t\t\t\t\/\n");
		printf("\/\t\t\tEnter'D'to exit.\t\t\t\t\/\n");
		printf("/***********************************************************************/\n");

		//scanf("%d", &t);
		getchar();									     //��س�
		t = getchar();


		if (t == 'A')
		{
			remove("���.txt");
			printf("Remove ���.txt successfully.\n");
		}
		else if (t == 'B')
		{
			Seek_for();
			continue;
		}
		else if (t == 'C')
		{
			//---------------------------------//
			//��ֹ����ĳ�ʼ��
			//---------------------------------//
			for (int j = 0; j < NUM;j++)
			{
				HashKeyList[j] = NULL;
			}
			Num_word = 0;
			//---------------------------------//

			FILE *filee;
			char name[20];
			printf("Please enter the name of the txt...\n");
			scanf("%s", name);
			filee = fopen(name, "r");

			HashList* sort_hash1[NUM];


			if (!filee)
			{
				printf("Could not open this txt!\n");
				system("pause");
			}
			else
			{
				printf("Open the txt successfully!\n");
			}

			BuildHash(filee);
			//PrintTheList(HashKeyList);

			//WriteResult(HashKeyList);

			ReList(HashKeyList, sort_hash1);
			//��ʼ����
			QuickSort(sort_hash1, 0, Num_word - 1);
			WriteResult(sort_hash1);

			//ȡ���ʮ��
			printf("////////////////////////////////");
			Print_Most(sort_hash1);
		}
		else if (t == 'D')
		{
			//free(HashKeyList);
			

			//free(sort_hash);
			*sort_hash = NULL;
			return 0;

		}
		else
		{
			printf("Error input!Please try again!\n");
			continue;
		}

	}


	system("pause");
	return 0;
}
/************************************************************************/



/************************************************************************
Function Name:int Cal_The_Key_Value(char* word)
Author       :Ellis
Date         :20180519
Description  :
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
int Cal_The_Key_Value(char* word)
{
	char* p = word;
	int key = *p;					//���õ������
	while (*p != '\0')				
	{
		key = key + *p;
		p++;
	}
	key = key % 100;
	return key;
}
/************************************************************************/


/************************************************************************
Function Name:bool BuildHash(FILE *file)
Author       :Ellis
Date         :20180519
Description  :������ϣ��
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
bool BuildHash(FILE *file)
{
	int k = 0;
	char ch;
	char word[20];
	int flag = 0;

	while (
		(ch = fgetc(file)) != EOF					  //����ַ�ȥ��ȡ
		)
	{
		//-------------------------------------------------
		if (ch >= 'A' && ch <= 'z')
		{

			ch = tolower(ch);							//������ĸ�Ĳ���������ת��ΪȫΪСд��
			word[k] = ch;								//��־λ��Ϊ1��Ϊ��һ��һͬ������ĸ�ķ��ź����ֵļ���ṩ����
			k++;
			flag = 1;
		}
		//------------------------------------------------
		else if (
			(
			ch == '_'
			||
			(
			ch <= '9'
			&&
			ch >= '0'
			)
			)
			&&
			flag == 1
			)
		{
			word[k] = ch;
			k++;
		}
		else
		{
			if (flag == 0)
			{
				continue;
			}
			else
			{
				//------------------------------------
				//�����������β��\0,�ұ�־λ���ϣ���ע������Ҫ���־λ���ÿ�word
				//------------------------------------
				word[k] = '\0';
				Put_in(word);

				k = 0;
				//*word = NULL;
				memset(word, 0, sizeof(word));
				flag = 0;
				//------------------------------------
			}
		}
	}

	fclose(file);									//�ļ��п�һ��Ҫ�б�
	return true;
}
/************************************************************************/


/************************************************************************
Function Name:void Put_in(char* word)
Author       :Ellis
Date         :20180519
Description  :���뺯��
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Put_in(char* word)
{
	int order = Cal_The_Key_Value(word);								//����ؼ���ֵ
	HashList* mid = HashKeyList[order];									//��ֹ�Թ�ϣ��ĸı䣬ȡһ���м����

	while (1)
	{
		if (!mid)
		{
			break;
		}

		if (strcmp(word, mid->word) == 0)								//�����ֵ��Ӧ�ı���û�����ݣ������ڴ沢����
		{																//��������������ݴ��ڣ��嵽��ͷ
			mid->count++;												//��������Ѿ����ڣ�count++
			//break;
			return;
		}
		mid = mid->next;
	}
	HashList* fact = (HashList*)malloc(sizeof(HashList));
	fact->next = HashKeyList[order];
	HashKeyList[order] = fact;
	fact->count = 1;
	strcpy(fact->word, word);
}
/************************************************************************/


/************************************************************************
Function Name:void PrintTheList(HashList** HashKeyList)
Author       :Ellis
Date         :20180519
Description  :��ӡ��ϣ�������õģ�
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void PrintTheList(HashList** HashKeyList)
{
	if (!HashKeyList)
	{
		return;
	}
	for (int i = 0; i < NUM - 1; i++)
	{
		HashList* mid = HashKeyList[i];
		while (mid)
		{
			printf("%s\t\t", mid->word);
			printf("%d\n", mid->count);
			mid = mid->next;
		}
	}
}
/************************************************************************/


/************************************************************************
Function Name:void WriteResult(HashList** HashKeyList)
Author       :Ellis
Date         :20180519
Description  :д�뺯��
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void WriteResult(HashList** HashKeyList)
{
	FILE *file;
	char name_of_txt[20] = "���.txt";
	file = fopen(name_of_txt, "w");

	if (!HashKeyList)
	{
		fprintf(file, "�޽����");
		return;
	}

	//for (int i = 0; i < NUM-1; i++)
	for (int i = 0; i < Num_word; i++)
	{
		HashList* mid = HashKeyList[i];


		fprintf(file, "%s\t\t", mid->word);			//ע��fprintf��ʹ��
		//printf("\t");
		fprintf(file, "%d\n", mid->count);
		//mid = mid->next;

	}
	printf("д��ɹ���\n");
	fclose(file);									//һ����סҪ�ر�
}
/************************************************************************/



/************************************************************************
Function Name:void QuickSort(HashList** List, int l, int r)
Author       :Ellis
Date         :20180519
Description  :���ŵݹ鷨
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void QuickSort(HashList** List, int l, int r)
{
	int i, j;
	HashList* x;
	HashList* mid = NULL;
	if (l < r)
	{
		i = l;
		j = r;
		x = List[i];     //ȡ0λ��
		//x = List[i]->count;     

		while (i < j)
		{
			while (i < j && List[j]->count >= (x->count))
			{
				j--;
			}
			if (i < j)
			{
				List[i] = List[j];
				i++;
			}

			while (i < j && List[i]->count <= (x->count))
			{
				i++;
			}
			if (i < j)
			{
				List[j] = List[i];
				j--;
			}
		}

		//mid = List[i] ;
		//List[i] = x;
		//List[l] = mid;

		List[i] = x;

		QuickSort(List, l, i - 1);
		QuickSort(List, i + 1, r);
	}
}
/************************************************************************/


/************************************************************************
Function Name:void ReList(HashList** HashKeyList, HashList** sort_hash)
Author       :Ellis
Date         :20180519
Description  :�ع���ϣ��
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void ReList(HashList** HashKeyList, HashList** sort_hash)
{
	if (!HashKeyList)
	{
		return;
	}

	//�������ݵ�һ����next�Ĺ�ϣ��
	int k = 0;
	for (int i = 0; i < NUM - 1; i++)
	{
		if (HashKeyList[i])
		{
			HashList* mid = HashKeyList[i];
			//HashList* st = sort_hash[k];
			sort_hash[k] = mid;
			//strcpy(sort_hash[k]->word, mid->word);
			//st->count = mid->count;
			k++;
			Num_word++;
			while (mid->next)
			{
				mid = mid->next;
				sort_hash[k] = mid;
				k++;
				Num_word++;
				//strcpy(st->word, mid->word);
				//st->count = mid->count;

			}
		}
		else
		{
			continue;
		}
	}
}
/************************************************************************/


/************************************************************************
Function Name:void Print_Most(HashList** sort)
Author       :Ellis
Date         :20180519
Description  :��ӡ������Ƶ����ߵ�ʮ��Ƶ�ʶ�Ӧ�ĵ���
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Print_Most(HashList** sort)
{
	int counting = 1;
	printf("\n");
	printf("Ƶ����ߵģ�\n");
	for (int i = Num_word - 1; i > 0; i--)
	{
		if (counting == 10)
		{
			break;
		}
		if (i < Num_word && sort[i]->count != sort[i - 1]->count)
		{
			counting++;
		}
		printf("%s\t\t%d\n", sort[i]->word, sort[i]->count);
	}
}
/************************************************************************/


/************************************************************************
Function Name:void Seek_for()
Author       :Ellis
Date         :20180519
Description  :��һ����ѯ����
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void Seek_for()
{
	printf("Enter the word you want to seek for ...\n");
	int flag = 0;
	char name[20];
	scanf("%s", &name);
	int s = Cal_The_Key_Value(name);										//����ؼ���ֵ������
	HashList* mid = HashKeyList[s];											//������������
	while (mid)
	{
		if (!strcmp(mid->word, name))
		{
			printf("%s\t%d\n", name, mid->count);
			flag = 1;
		}

		mid = mid->next;

	}
	if (flag ==0)
	{
		printf("δ�ҵ��������ԣ�\n");
	}
}
/************************************************************************/



/************************************************************************
Function Name:void DataLastTime()
Author       :Ellis
Date         :20180519
Description  :����ϴε�ͳ�ƽ���������ڵĻ����Ѿ������ˣ��Ͳ���ʾ
Inputs       :
Outputs      :
Notes        :
Revision     :
************************************************************************/
void DataLastTime()
{
	FILE *file;
	char name[20] = "���.txt";
	if (file = fopen(name, "r"))
	{
		char c;
		printf("��һ�ε�ͳ������:\n");
		while ((c = fgetc(file)) != EOF)
		{
			printf("%c", c);
		}
		fclose(file);
	}
}
/************************************************************************/