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

void testContainsBSTree() {
    struct BSTree *tree = buildBSTTree();
    
    struct data myData1;
	struct data myData2;
	struct data myData3;
	struct data myData4;
	struct data myData5;
	
	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    myData5.number = 111;
	myData5.name = "not in tree";
    
    
    if (containsBSTree(tree, &myData1))
        printf("containsBSTree(): PASS when test containing 50 as root\n");
    else
        printf("containsBSTree(): FAIL when test containing 50 as root\n");
        
    if (containsBSTree(tree, &myData2))
        printf("containsBSTree(): PASS when test containing 13 as left of root\n");
    else
        printf("containsBSTree(): FAIL when test containing 13 as left of root\n");
        
        
    if (containsBSTree(tree, &myData3))
        printf("containsBSTree(): PASS when test containing 110 as right of root\n");
    else
        printf("containsBSTree(): FAIL when test containing 110 as right of root\n");
        
    if (containsBSTree(tree, &myData4))
        printf("containsBSTree(): PASS when test containing 10 as left of left of root\n");
    else
        printf("containsBSTree(): FAIL when test containing 10 as left of left of root\n");
        
    if (!containsBSTree(tree, &myData5))
        printf("containsBSTree(): PASS when test containing 111, which is not in the tree\n");
    else
        printf("containsBSTree(): FAIL when test containing 111, which shouldn't be in the tree.\n");
}

int main(int argc, char *argv[])
{
    testContainsBSTree();
    return 0;
}



