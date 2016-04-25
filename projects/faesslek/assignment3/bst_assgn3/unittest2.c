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

void testLeftMost() {
    struct BSTree *tree = buildBSTTree();
    
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
    
    if (compare(_leftMost(tree->root), &myData4) == 0)
        printf("_leftMost(): PASS left most of root\n");
    else
        printf("_leftMost(): FAIL left most of root\n");
    
    if (compare(_leftMost(tree->root->left), &myData4) == 0)
        printf("_leftMost(): PASS left most of left of root\n");
    else
        printf("_leftMost(): FAIL left most of left of root\n");
        
    if (compare(_leftMost(tree->root->left->left), &myData4) == 0)
        printf("_leftMost(): PASS left most of left of left of root\n");
    else
        printf("_leftMost(): FAIL left most of left of left of root\n");
    
    if (compare(_leftMost(tree->root->right), &myData3) == 0)
        printf("_leftMost(): PASS left most of right of root\n");
    else
        printf("_leftMost(): FAIL left most of right of root\n");
}



int main(int argc, char *argv[])
{
    testLeftMost();
    return 0;
}



