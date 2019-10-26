#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>

typedef struct {
	char name[10];  //姓名
	float grade;   //成绩
	int number;   //学号
}Item;
                                //链表节点
typedef struct node {
	Item item;
	struct node*next;    
}Node;

typedef Node * List;

void menu(void);

void InitializeList(List*plist);   //初始化链表

bool ListIsEmpty(const List*plist);  

bool ListIsFull(const List*plist);

void ReadList(List*plist);//从文件读入数据

void WriteList(const List*plist);//写进文件

void ListItemCount(const List*plist);  //统计数量

void ListSearch(const List*plist);//查找

void ListInsertItem(List*plist);//插入项目

void ListUpdate(const List*plist);//修改

void ListDeleteItem(List*plist);//删除

void show(const List *plist);  //输出

void EmptyTheList(List*plist);   //清空

#endif // !LIST_H_