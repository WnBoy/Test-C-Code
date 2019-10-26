#include<stdio.h>
#include<stdlib.h>
struct Student_date
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[5];
int main()
{
	int i;
	FILE *fp;
	if ((fp = fopen("E:\\LLL.doc", "rb")) == NULL)
	{
		printf("文件打来失败");
		exit(1);
	}
	if (fread(stud, sizeof(struct Student_date), 5, fp) != 5)
		printf("文件写失败");
	for (i = 0;i < 5;i++)
		printf("%s%5d%6d%s\n", stud[i].name, stud[i].num, stud[i].age, stud[i].addr);
	fclose(fp);
	getchar();
	return 0;
}