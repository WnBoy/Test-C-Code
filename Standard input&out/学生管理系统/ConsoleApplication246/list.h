#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>

typedef struct {
	char name[10];  //����
	float grade;   //�ɼ�
	int number;   //ѧ��
}Item;
                                //����ڵ�
typedef struct node {
	Item item;
	struct node*next;    
}Node;

typedef Node * List;

void menu(void);

void InitializeList(List*plist);   //��ʼ������

bool ListIsEmpty(const List*plist);  

bool ListIsFull(const List*plist);

void ReadList(List*plist);//���ļ���������

void WriteList(const List*plist);//д���ļ�

void ListItemCount(const List*plist);  //ͳ������

void ListSearch(const List*plist);//����

void ListInsertItem(List*plist);//������Ŀ

void ListUpdate(const List*plist);//�޸�

void ListDeleteItem(List*plist);//ɾ��

void show(const List *plist);  //���

void EmptyTheList(List*plist);   //���

#endif // !LIST_H_