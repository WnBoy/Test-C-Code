#include<stdio.h>
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;
struct student*insert(struct student*head, struct student*stu)
{
	struct student *p0, *p1, *p2;
	p0 = stu;
	p1 = head;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->num > p1->num) && (p1->next!=NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num <= p1->num)
		{
			if (p1 == head)
			{
				head = p0;p0->next = p1;
			}
			else
			{
				p2->next = p0; p0->next = p1;
			}
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;
	return(head);
}