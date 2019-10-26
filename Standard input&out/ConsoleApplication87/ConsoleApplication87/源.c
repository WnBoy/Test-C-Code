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
		printf("文件打来失败");
		exit(1);
	}
	if (fwrite(stud, sizeof(struct Student_date), 5, fp) != 5)
		printf("文件写失败");
	fclose(fp);
	return 0;
}
int main()
{
	int i;
	for (i = 0;i < 5;i++)
	{
		printf("请输入数据：\n");
		scanf("%s,%d,%d,%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
	}
	save();
	return 0;
}