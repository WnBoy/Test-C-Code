#include<stdio.h>
#define SIZE 5
struct Student_type
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[SIZE];
void save()
{
	int i;
	FILE *fp;
	if ((fp = fopen("stu.dat", "wb")) == NULL)
	{
		printf("打开文件失败");
		return;
	}
	for (i = 0;i < SIZE;i++)
		if (fwrite(&stud[i], sizeof(struct Student_type), 1, fp) != 1)
			printf("file write is error\n");
	fclose(fp);
}
int main()
{
	int i;
	printf("请输入学生数据:\n");
	for (i = 0;i < SIZE;i++)
		scanf("%s,%d,%d,%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
	save();
	return 0;
}