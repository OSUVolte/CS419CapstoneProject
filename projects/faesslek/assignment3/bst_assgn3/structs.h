/* You can modify the structure to store whatever you'd like in your BST */
# ifndef __STRUCTS_H
# define __STRUCTS_H
# include<stdlib.h>

struct data {
	int number;
	char *name;
};


/* For testing purpose */
struct BSTree *buildBSTTree();

# endif