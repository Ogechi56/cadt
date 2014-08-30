#ifndef __BST__HELPERS__H__
#define __BST__HELPERS__H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "bst_types.h"

/*
	BST helper function used for setting node's values
		-> 	sets node's left and right children pointers to NULL
		->  sets parent pointer to whichever value is passed
			only root's parent pointer should be NULL
		->  set's node's value to passed value
		->  incremenents tree's size
*/
void __bst_helper_node_setter(bst_t *bst, node_t * node, node_t *parent, int value);

/*
	BST helper function used for deleting's nodes and releasing acquired memory
		->  will recursively free allocated memory, node by node

*/
void __bst_helper_node_deleter(node_t *node);

/*
	BST helper function used for recursively searching for a value in the tree
		->  will recursively search for a value, node by node
		-> 	if desired node is found, returns true, otherwise, returns false
*/
bool __bst_helper_node_lookup(node_t *node, int value);

/*
	BST helper function used for serializing the tree to an array of integers
		->  will do a preorder recursive traversal of tree
		->	uses a positional index passed by reference to correctly place
			values into the array

*/
void __bst_helper_node_serializer(int *array, node_t *node, int size, int *pos);

#endif