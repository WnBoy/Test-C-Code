#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct student)
struct student
{
	char num[6];
	char name[8];
	char sex[2];
	int age;
	struct student*next;
};
int n;
int main()
{
	struct student*creat();
	struct student*del(struct student*, int);
	void print(struct student*);
	struct student*head;
	int del_age;
	printf("please input record:\n");
	head = creat();
	print(head);
	printf("please input del age:");
	scanf("%d", &del_age);
	head = del(head,del_age);
	print(head);
	getchar();
	return 0;
}
struct student*creat()
{
	struct student*head, *p1, *p2;
	head = NULL;
	n = 0;
	p1 = p2 = (struct student*)malloc(LEN);
	scanf("%s,%s,%s,%d", p1->num, p1->name, p1->sex, &p1->age);
	while (p1->age != 0)
	{
		n = n + 1;
		if (n == 1)head = p1;
		else p2->next = p1;
		p2 = p1;
		p1= (struct student*)malloc(LEN);
		scanf("%s,%s,%s,%d", p1->num, p1->name, p1->sex, &p1->age);
	}
	p2->next = NULL;
	return (head);
}
struct student*del(struct student*head,int age)
{
	struct student *p1, *p2;
	p1 = head;
	if (head == NULL)printf("NO");
	while ((p1->age != age)&&(p1->next!=NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->age == age)
	{
		if (p1 == head)head = p1->next;
		else p2->next = p1->next;
		printf("del:%d age\n", age);
		n = n - 1;
	}
	else
		printf("%d not be found!\n", age);
	return (head);
}
void print(struct student*head)
{
	struct student*p;
	p = head;
	if (head == NULL)printf("NO");
	while (p!= NULL)
	{
		printf("%s%s%s%d", p->num, p->name, p->sex, p->age);
		p = p->next;
	}
}
