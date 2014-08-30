#ifndef __BST__TYPES__H
#define __BST__TYPES__H

/*
	NODE struct
		-> 	contains value of node, pointer to left and right child,
			and pointer to parent node
		-> 	tree is constructed entirely from these nodes
*/
typedef struct node_t {
	//node value
	int value;
	//left child
	struct node_t *left;
	//right child
	struct node_t *right;
	//parent node
	struct node_t *parent;
} node_t;

/*
	BST struct
		-> holds pointer to root node
		-> contains size of tree
*/
typedef struct bst_t {
	//size of bst (number of elements within)
	int unsigned size;
	//pointer too root node
	struct node_t *root;
} bst_t;

#endif