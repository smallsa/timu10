/*���һ�����溯������������9����Ŀ�ĺ������ã���
        ��ѡ��
	���õ�һ������������ĺ�������
	���õڶ�������������ĺ�������
	...
	���õھŸ����������庯������
		����������y������һ��ѡ������n����*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 2
double f(double x);
void maxMinAver(int* data, int* max, int* min, float* ave, int size);
int mystrcmp(const char* str1, const char* str2);
//float ave(STU stu[], int size);
//float ave(STU stu[], int size);
typedef struct student
{
	int id;
	char name[20];
	float math, Chinese, computer, English, total, ave;
}STU;
STU stu[SIZE];
float ave(STU stu[], int size);
void load();
struct student_type
{
	char name[30];
	int id;
	float grade;
}stud[SIZE];
void output();
struct Student
{
	char name[30];
	char gender[10];
	int id;
	int age;
	int height;
	int grade;
	int total;
	float ave;
}Stu[SIZE];
void print(struct sTudent sTu[], int size);
struct sTudent
{
	char name[30];
	int id;
	float grade;
}sTu[SIZE];
void sort();
struct StUdent
{
	char name[30];
	int id;
	float grade;
}StU[SIZE];
void search(struct stuDent stu[]);
struct stuDent
{
	char name[30];
	int id;
	int math;
	int English;
	int Chinese;
};
int sw(int n);
void menu();
int main()
{
	int num1, num2;
	char str;
	menu();
	scanf_s("%d", &num1);
	sw(num1);
	str=getchar();
	scanf_s("%c", &str,100);
	while (str=='y'||str=='n')
	{
		if (str == 'y')
		{
			scanf_s("%d", &num2);
			sw(num2);
		}
		if (str == 'n')
			break;
		getchar();
		scanf_s("%c", &str,100);
	}
	return 0;
}
int sw(int n)
{
	int x, m, i, max, min;
	char str1[100], str2[100];
	float kave;
	int* data;
	struct stuDent stuD[5] = { {"zhangsan",11111,99,99,99},{"lisi",22222,88,88,88},{"wangwu",33333,77,77,77},{"cuici",44444,66,66,66},{"asan",55555,55,55,55} };
	switch (n)
	{
	case 1:printf("��������ֵ��");
		scanf_s("%d", &x);
		printf("%f\n", f(x)); break;
	case 2:printf("���������ݸ�����\n");
		scanf_s("%d", &n);
		data = (int*)malloc(n * sizeof(int));
		for (i = 0; i <n; i++)
		{
			printf("please input numbers:\n");
			scanf_s("%d", &data[i]);
		}
		maxMinAver(data, &max, &min, &kave, n);
		printf("max:%d\nmin:%d\nave:%.1f\n", max, min, kave); break;
	case 3:printf("please enter str1:");
		scanf_s("%s", str1, 100);
		printf("please enter str2:");
		scanf_s("%s", str2, 100);
		printf("result:%d\n",mystrcmp(str1, str2)); break;
	case 4:printf("������ѧ������\n");
		scanf_s("%d", &n);
		for (i = 0; i < n; i++)
		{
			printf("������ѧ��������ѧ�ż����ſ�Ŀ�ɼ���\n");
			scanf_s("%s %d %f %f %f %f", &stu[i].name, 30, &stu[i].id, &stu[i].math, &stu[i].Chinese, &stu[i].computer, &stu[i].English);
		}
		ave(stu, n);
		for (i = 0; i < n; i++)
		{
			printf("������%s\n", stu[i].name);
			printf("ѧ�ţ�%d\n", stu[i].id);
			printf("ƽ���֣�%g\n", stu[i].ave);
		}break;
			//printf("����:%s\nѧ��:%d\nƽ����:%.2f\n\n", stu[i].id, stu[i].name, stu[i].ave); break;
	case 5:load(); break;
	case 6:output(); break;
	case 7:for (m = 0; m < SIZE; m++)
		scanf_s("%s %d %f", &sTu[m].name,30, &sTu[m].id, &sTu[m].grade); 
		print(sTu, SIZE); break;
	case 8:for (m = 0; m < SIZE; m++)
		scanf_s("%s %d %f", &StU[m].name,30, &StU[m].id, &StU[m].grade);
		printf("���Ϊ��\n");
		sort(StU);
		for (m = 0; m < SIZE; m++)
			printf("%10s%6d%8.1f\n", StU[m].name, StU[m].id, StU[m].grade); break;
	case 9:search(stuD); break;
	}
	printf("\n");
	printf("������\n");
}
void menu()
{
	printf("|----------------------------------------------|\n");
	printf("|             ��ѡ����Ҫ�ĺ���                  |\n");
	printf("|----------------------------------------------|\n");
	printf("|    1.��ֶκ�����ֵ                           |\n");
	printf("|    2.��һ�����ݵ����ֵ����Сֵ��ƽ��ֵ         |\n");
	printf("|    3.�Ƚ������ַ�����С                       |\n");
	printf("|    4.��һ��ѧ��ÿ��ѧ�����ſγ̵�ƽ��ֵ         |\n");
	printf("|    5.���ļ�����һ��ѧ������Ϣ                  |\n");
	printf("|    6.����ṹ���������Ϣ���ļ�                |\n");
	printf("|    7.��ӡ���ѧ���ṹ���������Ϣ����Ļ��       |\n");
	printf("|    8.��һ��ѧ���ɼ���Ϣ���ֽܷ�������          |\n");
	printf("|    9.���Ҹ���ѧ�ŵ�ѧ���ɼ���Ϣ                |\n");
	printf("|---------------------------------------------|\n");
	printf("����������Ҫ���ú��������:\n");
}
double f(double x)
{
	if (x > 0)
		return 3 * x* x - 4;
	if (x == 0)
		return 2;
	else
		return 0;
}
void maxMinAver(int* data, int* max, int* min, float* ave, int n)
{
	int i;
	int sum = *data;
	*max = *data;
	*min = *data;
	for (i = 1; i < n; i++)
	{
		if (*(data + i) > * max)
			* max = *(data + i);
		if (*(data + i) < *min)
			* min = *(data + i);
		sum += *(data + i);
	}
	*ave = 1.0 * sum / n;
}
int mystrcmp(const char* str1, const char* str2)
{
	for (; *str1 != 0 || *str2 != 0; str1++, str2++)
	{
		if (*str1 > * str2)
			return 1;
		if (*str1 == *str2)
			return 0;
		else
			return -1;
	}
}
float ave(STU stu[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		stu[i].total = stu[i].math + stu[i].Chinese + stu[i].computer + stu[i].English;
		stu[i].ave = stu[i].total / 4;
	}
	return stu[i].ave;
}
void load()
{
	int i;
	FILE* fp;
	fp = fopen("D:\\student\\grade.txt", "r");
	if (fp == NULL)
	{
		printf("can't open file\n");
		exit(0);
	}
	for (i = 0; i < SIZE; i++)
	{
		fscanf_s(fp, "%s", &stud[i].name, 30);
		fscanf_s(fp, "%d", &stud[i].id);
		fscanf_s(fp, "%f", &stud[i].grade);
		printf("%-5s %4d %10.2f\n", stud[i].name, stud[i].id, stud[i].grade);
	}
	fclose(fp);
}
void output()
{
	int i;
	FILE* fp;
	fp = fopen("D:\\student\\input2.txt", "w");
	for (i = 0; i < SIZE; i++)
	{
		scanf_s("%s", &Stu[i].name, 30);
		scanf_s("%s", &Stu[i].gender, 10);
		scanf_s("%d", &Stu[i].id);
		scanf_s("%d", &Stu[i].age);
		scanf_s("%d", &Stu[i].height);
		scanf_s("%d", &Stu[i].grade);
		scanf_s("%d", &Stu[i].total);
		scanf_s("%f", &Stu[i].ave);
		fprintf(fp, "%s %s %d %d %d %d %d %5.2f\n", Stu[i].name, Stu[i].gender, Stu[i].id, Stu[i].age, Stu[i].height, Stu[i].grade, Stu[i].total, Stu[i].ave);
	}
}
void print(struct sTudent sTu[],int size)
{
	int j;
	for (j = 0; j < size; j++)
	{
		printf("name:%s\n", sTu[j].name);
		printf("id:%d\n", sTu[j].id);
		printf("grade:%5.2f\n", sTu[j].grade);
	}
}
void sort()
{
	int i, j;
	float t;
	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = i + 1; j < SIZE; j++)
		{
			if (StU[j].grade < StU[j + 1].grade)
			{
				t = StU[j].grade;
				StU[j].grade = StU[j + 1].grade;
				StU[j + 1].grade = t;
			}
		}
	}
}
void search(struct stuDent stu[])
{
	int i, j, flag = 0;
	printf("����Ҫ���ҵ�ѧ��id:");
	scanf_s("%d", &j);
	printf("���ҽ��Ϊ:\n");
	for (i = 0; i < 6; i++)
	{
		if (j == stu[i].id)
		{
			printf("����:%s ѧ��:%d ��ѧ:%d Ӣ��:%d ����:%d", stu[i].name, stu[i].id, stu[i].math, stu[i].English, stu[i].Chinese);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("not found!\n");
}
