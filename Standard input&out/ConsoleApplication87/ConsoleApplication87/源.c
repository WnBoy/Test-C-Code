#include<stdio.h>
#include<stdlib.h>
struct Student_date
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[5];
void save()
{
	FILE *fp;
	if ((fp = fopen("E:\\LLL.doc", "wb")) == NULL)
	{
		printf("�ļ�����ʧ��");
		exit(1);
	}
	if (fwrite(stud, sizeof(struct Student_date), 5, fp) != 5)
		printf("�ļ�дʧ��");
	fclose(fp);
	return 0;
}
int main()
{
	int i;
	for (i = 0;i < 5;i++)
	{
		printf("���������ݣ�\n");
		scanf("%s,%d,%d,%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
	}
	save();
	return 0;
}