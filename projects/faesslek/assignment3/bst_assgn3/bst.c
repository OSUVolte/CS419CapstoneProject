/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "bst.h"


struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
void initBSTree(struct BSTree *tree)
{	
	tree->cnt  = 0; 
	tree->root = 0;	
}

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);
	
	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);		
		free(node);
	}
}

void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
struct Node *_addNode(struct Node *cur, TYPE val)
{
	/*write this*/
	/*	return NULL; */
	
	struct Node *newnode;
	/* case1 - cur is null */
	if (cur == NULL)	
	{	/*create new node and return*/
		newnode = (struct Node *)malloc(sizeof(struct Node));
		assert(newnode != 0);
		newnode->val = val;
		/*newnode->val->number = val->number;*/
		newnode->left = newnode->right = 0;
		return newnode;
	}
	if (EQ(compare(val,cur->val),-1))
	{		
		cur->left = _addNode(cur->left,val);
	}
	else if (EQ(compare(val, cur->val),1))
	{	
		cur->right = _addNode(cur->right, val);
	}
	return cur;


}

void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);	
	tree->cnt++;
}

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	/*write this*/	
	/*	return 0; */
	struct Node *cur = tree->root;
	
	while (cur != 0) {
		if (EQ(compare(val,cur->val),0))
			return 1; /* Return true if val found. */
		if (EQ(compare(val, cur->val),-1))
			cur = cur->left; /* Otherwise, go to the left */
		else cur = cur->right; /* or right, depending on val. */
	}
	return 0;


}

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	/*write this*/	
	/*return NULL;*/
	while (cur->left != 0)
		cur = cur->left;
	return cur->val;

}

/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	/*write this*/
	/*	return NULL;*/
	
	struct Node *node;

  	if (cur->left != 0) {
    	cur->left = _removeLeftMost(cur->left);
    return cur;
	}

	node = cur->right;
    free(cur);
	return node;
}

/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	/*write this*/
	/*	return NULL; */
	struct Node *temp;
	if (EQ(compare(val, cur->val),0)) { /* Found val. */
		if (cur->right == 0) {
			temp = cur->left;
			free(cur);
			return temp;
		}
		cur->val = _leftMost(cur->right);
		cur->right = _removeLeftMost(cur->right);
	}
	else if (EQ(compare(val, cur->val),-1))
		cur->left = _removeNode(cur->left, val);
	else 
		cur->right = _removeNode(cur->right,val);
	return cur;
}

void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used 
  in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);	 
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");
}

void printTree(struct BSTree *tree) {
	 if (tree == 0) return;	 
	 printNode(tree->root);	 
}
/*----------------------------------------------------------------------------*/

#endif
