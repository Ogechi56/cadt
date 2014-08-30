#include "bst_helpers.h"

void __bst_helper_node_setter(bst_t *bst, node_t * node, node_t *parent, int value) {
	node->value 	= value;
	node->left  	= NULL;
	node->right 	= NULL;
	node->parent 	= parent;
	//increment tree size
	++bst->size;
}

void __bst_helper_node_deleter(node_t *node) {
	if(node != NULL) {
		__bst_helper_node_deleter(node->left);
		__bst_helper_node_deleter(node->right);

		if(node->left != NULL) {
			free(node->left);
		}
		if(node->right != NULL) {
			free(node->right);
		}
	}
}

bool __bst_helper_node_lookup(node_t *node, int value) {
	if(
		node != NULL && 
		node->value == value
	) {
		return true;
	} else {
		return (
					__bst_helper_node_lookup(node->left, value) || 
					__bst_helper_node_lookup(node->right, value)
				);
	}

	return false;
}

void __bst_helper_node_serializer(int *array, node_t *node, int size, int *pos) {
	if(node != NULL) {
		if(*pos < size) {

			__bst_helper_node_serializer(array, node->left, size, pos);

			array[(*pos)++] = node->value;

			__bst_helper_node_serializer(array, node->right, size, pos);
		} else {
			fprintf(stderr, "serialization out of bounds, positional counter inconsistent with tree size!\n");
		}
	}

	return;
}