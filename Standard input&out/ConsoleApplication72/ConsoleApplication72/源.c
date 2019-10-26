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
	struct student*head,*stu;
	long num_del;
	printf("please enter number:\n");
	head = creat();
	printf("please enter del nu:\n");
	scanf("%ld", &num_del);
	head = del(head, num_del);
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
		p1=(struct student*)malloc(LEN);
		scanf("%ld,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return (head);
}
struct student*del(struct student*head, long num)
{
	struct student *p1, *p2;
	p1 = head;
	if (head == NULL)printf("list is null\n");
	else 
		while(p1->num!=num&&p1->next!=NULL)

}