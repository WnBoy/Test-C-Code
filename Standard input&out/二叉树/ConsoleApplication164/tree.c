#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"
typedef struct pair
{
	Node*parent;
	Node*child;
}Pair;

static Node*MakeNode(const Item*pi);

static bool ToLeft(const Item*i1, const Item*i2);

static bool ToRight(const Item*i1, const Item*i2);

static void AddNode(Node*new_node, Node*root);

static void InOrder(const Node*root, void(*pfun)(Item item));

static Pair SeekItem(const Item*pi, const Tree*ptree);

static void DeleteNode(Node**ptr);

static void DeleteAllNodes(Node*ptr);

void InitializeTree(Tree*ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree*ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree*ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree*ptree)
{
	return (ptree->size);
}

bool AddItem(const Item*pi, Tree*ptree)
{
	Node*new_node;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "This is full\n");
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

bool InTree(const Item*pi, const Tree*ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item*pi, Tree*ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;

	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else
		DeleteNode(&look.child);

		/*if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);*/

	ptree->size--;
	return true;
}

void Traverse(const Tree*ptree, void(*pfun)(Item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree*ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root=NULL;
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
	if (root != NULL)
	{
		DeleteAllNodes(root->left);
		DeleteAllNodes(root->right);
		free(root);
	}

	/*Node*pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}*/
}

static void AddNode(Node*new_node, Node*root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item*i1, const Item*i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item*i1, const Item*i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 && (strcmp(i1->petkind, i2->petkind)) > 0)
		return true;
	else
		return false;
}

static Node*MakeNode(const Item*pi)
{
	Node*new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static Pair SeekItem(const Item*pi, const Tree*ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

static void DeleteNode(Node**ptr)
{
	Node*temp;
	puts((*ptr)->item.petname);
	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else
	{
		for (temp = (*ptr)->left;temp->right != NULL;temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}