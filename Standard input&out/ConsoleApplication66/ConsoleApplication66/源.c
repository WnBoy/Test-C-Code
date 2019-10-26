#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student 
{
	long num;
	float score;
	struct Student *next;
};
int n;
struct Student*creat(void)
{
	struct Student *head, *p1, *p2;
	head = NULL;
	n = 0;
	p1 = p2 = (struct Student*)malloc(LEN);
	scanf("%ld,%f", &p1->num, &p1->score);
	while (p1->num != 0)
	{
		n = n + 1;
		if (n == 1)head = p1;
		else p2->next = p1;
		p2 = p1;
		p1= (struct Student*)malloc(LEN);
		scanf("%ld,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return(head);
}
int main()
{
	struct Student *pt;
	pt = creat();
	printf("\nnum=%ld\n=score%5.1f\n", pt->num, pt->score);
	return 0;
}