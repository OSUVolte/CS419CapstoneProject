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

void testRemoveNode() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    struct data myData1;
	struct data myData2;
	struct data myData3;
	struct data myData4;
		
	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    
    _removeNode(tree->root, &myData4);
    if (compare(tree->root->val, &myData1) == 0 && tree->root->left->left == NULL)
        printf("_removeNode(): PASS remove left of left of root 1st try\n");
    else
        printf("_removeNode(): FAIL remove left of left of root 1st try\n");
        
    _removeNode(tree->root, &myData3);
    if (compare(tree->root->val, &myData1) == 0 && tree->root->right == NULL)
        printf("_removeNode(): PASS remove right of root 2st try\n");
    else
        printf("_removeNode(): FAIL remove right of root 2st try\n");
    
    _removeNode(tree->root, &myData2);
    if (compare(tree->root->val, &myData1) == 0 && tree->root->left == 0)
        printf("_removeNode(): PASS remove left of root 3st try\n");
    else
        printf("_removeNode(): FAIL remove left of root 3st try\n");
        
    cur = _removeNode(tree->root, &myData1);
    if (cur == NULL)
        printf("_removeNode(): PASS remove root 4st try\n");
    else
        printf("_removeNode(): FAIL remove root 4st try\n");
        
}


int main(int argc, char *argv[])
{
    testRemoveNode();
    return 0;
}



