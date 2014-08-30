#ifndef __BST__H__
#define __BST__H__

#include "bst_helpers.h"

/*
	BST initializer function
		->  sets size to 0
		->  sets root node to NULL
*/
void bst_init(bst_t *bst);

/*
	BST inserter function
		->  inserts a node of desired value
			at appropriate place
*/
void bst_insert(bst_t *bst, int value);

/*
	BST element lookup function
		->	will perform a seach for required element
		->  will return true if element is contained in the tree,
			and false if it is not
*/
bool bst_contains(bst_t *bst, int value);

/*
	BVT node removal function
		-> 	will removed required element from tree
		->  will return false if the tree is empty or the element is not found,
			or true if the element has been successfully deleted
*/
bool bst_delete(bst_t *bst, int value);

/*
	BST serializer function
		-> 	will allocate an array of intergers of size N,
			where N is the size of the tree
		->	will do a preorder traversal of tree and return
			the array containing all elements sorted in an increasing order

	WARNING: 	

	since this function allocated memory on the heap, it is up to the
	programmer to release this memory once it is no longer needed,
	in order to prevent memory leaks.
*/
int* bst_serialize(bst_t *bst);

/*
	BST destructor
		-> 	will release heap memory allocated by the tree
		->	should be called after the tree is no longer needed,
			in order to prevent memory leaks
*/
void bst_close(bst_t *bst);

#endif