#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"tree.h"
typedef struct pair
{
	Node *parent;
	Node *child;
}Pair;

static Node*MakeNode(const Item*pi);

static bool ToLeft(const Item*i1, const Item*i2);

static bool ToRight(const Item*i1, const Item*i2);

static void AddNode(Node*new_node, Node*root);

static void InOrder(const Node*root, void(*pfun)(Item item));

static Pair SeekItem(const Item*pi, const Tree*ptree);

static void DeleteNode(Node**ptr);

static void DeleteAllNodes(Node*ptr);

void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
	return false;
}

bool TreeIsFull(const Tree * ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
	return false;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Node*new_node;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL)
	{
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't creat node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);
	return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;
	return true;
}

void Traverse(const Tree*ptree, void(*pfun)(Item))
{
	if (ptree->root != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree*ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static void InOrder(const Node*root, void(*pfun)(Item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Node*root)
{
	Node*pright;
	if(root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNode(pright);
	}
}





