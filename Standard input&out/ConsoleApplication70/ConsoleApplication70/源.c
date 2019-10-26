#include<stdio.h>
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;
struct student*del(struct student*head, long num)
{
	struct student*p1, *p2;
	p1 = head;
	if(head==NULL)
	{
		printf("\nlist is null!\n");
		return (head);
	}
		while ((num != p1->num) && (p1->next != NULL))
		{
			p2 = p1;p1 = p1->next;
		}
		if (num == p1->num)
		{
			if (p1 == head)head = p1->next;
			else p2->next = p1->next;
			printf("delete:%ld\n", num);
			n = n - 1;
		}
		else printf("%ld not be found!\n", num);
		return(head);
}