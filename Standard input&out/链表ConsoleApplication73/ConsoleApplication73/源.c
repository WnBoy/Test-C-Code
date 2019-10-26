#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;
int main()
{
	struct student*creat();
	struct student*del(struct student *head, long num);
	struct student*insert(struct student*head, struct student*stu);
	void print(struct student*head);
	struct student*head, stu;
	long num_del;
	printf("please enter number:\n");
	head = creat();
	printf("please enter del num:");
	scanf("%ld", &num_del);
	head = del(head, num_del);
	print(head);
	printf("please enter insert stu:");
	scanf("%ld,%f", &stu.num, &stu.score);
	head = insert(head,&stu);
	print(head);
	getchar();
	return 0;
}
struct student *creat()
{
	struct student*head, *p1, *p2;
	n = 0;
	head = NULL;
	p1 = p2 = (struct student*)malloc(LEN);
	scanf("%ld,%f", &p1->num, &p1->score);
	while (p1->num != 0)
	{
		n = n + 1;
		if (n == 1)head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%ld,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return (head);
}
struct student*del(struct student*head, long num)
{
	struct student *p1, *p2;
	p1 = head;
	if (head == NULL)
	{
		printf("list is null\n");
		return(head);
	}
		while ((p1->num != num) && (p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p1->num == num)
		{
			if (p1 == head)head = p1->next;
			else p2->next = p1->next;
			n = n - 1;
		}
		else printf("%ld not been fount", num);
		return (head);
}
struct student*insert(struct student *head, struct student*stu)
{
	struct student *p0,*p1, *p2;
	p1 = head;
	p0 = stu;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	while ((p1->next != NULL) && (p1->num<p0->num))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->num >= p0->num)
	{
		if (head == p1)
		{
			head = p0;
			p0->next = p1;
		}
		else
		{
				p2->next = p0;
				p0->next = p1;
		}
	}
	else
	{
		p1 ->next = p0;
		p0->next = NULL;
	}
	n = n + 1;
	return (head);
}
void print(struct student*head)
{
	struct student*p;
	printf("\nNOW,these %d records are:\n", n);
	p = head;
	while (head != NULL)
	{
		printf("%ld %5.1f", p->num, p->score);
		p = p->next;
	}
}