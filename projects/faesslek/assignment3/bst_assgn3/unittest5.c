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

void testAddNode() {
    struct BSTree *tree	= newBSTree();
    
    struct data myData1;
	struct data myData2;
	struct data myData3;
	struct data myData4;
		
	myData1.number = 50;
	myData1.name = "rooty";
    addBSTree(tree, &myData1);
    
    
    if (compare(tree->root->val, (TYPE *) &myData1) != 0) {
        printf("addNode() test: FAIL to insert 50 as root\n");
        return;
    }
    else if (tree->cnt != 1) {
        printf("addNode() test: FAIL to increase count when inserting 50 as root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 50 as root\n");
    
    
	myData2.number = 13;
	myData2.name = "lefty";
    addBSTree(tree, &myData2);
    
    
    if (compare(tree->root->left->val, (TYPE *) &myData2) != 0) {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
    else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 13 as left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 13 as left of root\n");
    
    
	myData3.number = 110;
	myData3.name = "righty";
    addBSTree(tree, &myData3);
        
        
    if (compare(tree->root->right->val, (TYPE *) &myData3) != 0) {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
    else if (tree->cnt != 3) {
        printf("addNode() test: FAIL to increase count when inserting 110 as right of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 110 as right of root\n");
    
    
	myData4.number = 10;
	myData4.name = "righty of lefty";
	addBSTree(tree, &myData4);
    
    if (compare(tree->root->left->left->val, (TYPE *) &myData4) != 0) {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
    else if (tree->cnt != 4) {
        printf("addNode() test: FAIL to increase count when inserting 10 as left of left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 10 as left of left of root\n");
}

int main(int argc, char *argv[])
{	
    testAddNode();
    return 0;
}



