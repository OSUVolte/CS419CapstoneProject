#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "structs.h"

struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

TYPE _leftMost(struct Node *cur);
struct Node *_removeLeftMost(struct Node *cur);
struct Node *_removeNode(struct Node *cur, TYPE val);

void testRemoveLeftMost() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    
    cur = _removeLeftMost(tree->root);
    if (cur == tree->root)
        printf("_removeLeftMost: PASS removing leftmost of root 1st try\n");
    else 
        printf("_removeLeftMost: FAIL removing leftmost of root 1st try\n");
    
    cur = _removeLeftMost(tree->root->right);
    if (cur == NULL)
        printf("_removeLeftMost: PASS removing leftmost of right of root 1st try\n");
    else 
        printf("_removeLeftMost: FAIL removing leftmost of right of root 1st try\n");
        
    
    cur = _removeLeftMost(tree->root);
    if (cur == tree->root)
        printf("_removeLeftMost: PASS removing leftmost of root 2st try\n");
    else 
        printf("_removeLeftMost: FAIL removing leftmost of root 2st try\n");
    
}

int main(int argc, char *argv[])
{	
    testRemoveLeftMost();
    return 0;
}



