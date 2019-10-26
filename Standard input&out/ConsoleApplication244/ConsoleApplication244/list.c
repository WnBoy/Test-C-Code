#include<stdio.h>
#include<stdlib.h>
#include"list.h"
static void CopyToNode(Item item, List pnew);
void InitializeList(List*plist)
{
	*plist = NULL;
}

bool ListIsEmpty(const List*plist)
{
	if (*plist == NULL)return true;
	else return false;
}

bool ListIsFull(const List*plist)
{
	List pt;
	bool full;
	pt = (List)malloc(sizeof(Node));
	if (pt == NULL)full = true;
	else full = false;
	free(pt);
	return full;
}

unsigned int ListItemCount(const List*plist)
{
	unsigned int n=0;
	List pt = *plist;
	while (pt != NULL)
	{
		n++;
		pt = pt->next;
	}
	return n;
}

bool AddItem(Item item, List*plist)
{
	List pnew;
	List scan = *plist;
	pnew = (List)malloc(sizeof(Node));
	if (pnew == NULL)return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;
	else
	{
		while (scan != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	return true;
}

void Traverse(const List*plist, void(*pfun)(Item item))
{
	List pt = *plist;
	while (pt != NULL)
	{
		(*pfun)(pt->item);
		pt = pt->next;
	}
}

void EmptyTheList(List*plist)
{
	List pt = *plist;
	while (*plist != NULL)
	{
		pt = (*plist)->next;
		free(*plist);
		*plist = pt;
	}
}

static void CopyToNode(Item item, List pnew)
{
	pnew->item = item;
}