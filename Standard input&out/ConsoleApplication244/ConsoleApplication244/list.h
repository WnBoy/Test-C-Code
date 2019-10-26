#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#define TITLE 45

typedef struct film{
	char title[TITLE];
	int rating;
}Item;

typedef struct node {
	Item item;
	struct node*next;
}Node;

typedef Node*List;

void InitializeList(List*plist);

bool ListIsEmpty(const List*plist);

bool ListIsFull(const List*plist);

unsigned int ListItemCount(const List*plist);

bool AddItem(Item ietm, List*plist);

void Traverse(const List*plist, void(*pfun)(Item item));

void EmptyTheList(List*plist);

#endif // !LIST_H_