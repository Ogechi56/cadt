#include "bst.h"

void bst_init(bst_t *bst) {
	bst->size = 0;
	bst->root = NULL;
}

void bst_insert(bst_t *bst, int value) {
	//allocation check
	if(bst == NULL) {
		fprintf(stderr, "bst not allocated!\n");
		exit(1);
	}
	//size check
	if(bst->size == 0) {
		if((bst->root = (node_t*) malloc (sizeof(node_t))) == NULL) {
			fprintf(stderr, "alloc error!\n");
			exit(2);
		}

		__bst_helper_node_setter(bst, bst->root, NULL, value);

	} else {
		bool alloc_left;
		node_t *previous = NULL;
		node_t *current = bst->root;

		while(current != NULL) {
			previous = current;

			if(current->value > value) {
				current = current->left;
				alloc_left = true;
			} else if (current->value < value) {
				current = current->right;
				alloc_left = false;
			}
		}

		if(alloc_left == true) {
			previous->left = (node_t*) malloc (sizeof(node_t));
			current = previous->left;
		} else {
			previous->right = (node_t*) malloc (sizeof(node_t));
			current = previous->right;
		}

		if(current == NULL) {
			fprintf(stderr, "alloc error!\n");
			exit(2);
		}

		__bst_helper_node_setter(bst, current, previous, value);

	}
}


bool bst_contains(bst_t *bst, int value) {
	node_t *current = bst->root;

	if(current != NULL) {
		return __bst_helper_node_lookup(current, value);
	}

	return false;
}

bool bst_delete(bst_t *bst, int value) {
	node_t *current = bst->root;

	//find required node
	//if node does not exists, it's pointer (current) will be NULL
	while(current != NULL) {
		if(value == current->value) {
			break;
		}

		if(value < current->value) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	//entry implies that required node exists and is valid
	if(current != NULL) {
		//tree's size is decremented
		--bst->size;
		//leaf node - has no children
		//set parent's left/right pointer to NULL as appropriate
		//release node's memory
		if(current->left == NULL && current->right == NULL) {
			if(
				//short circuit NULL pointer check
				current->parent->left != NULL && 
				value == current->parent->left->value
			) {
				//set parent's left pointer to NULL
				//sever's connection to node to be deleted
				current->parent->left = NULL;
			} else if (
				//short circuit NULL pointer check
				current->parent->right != NULL &&
				value == current->parent->right->value
			) {
				//set parent's right pointer to NULL
				//sever's connection to node to be deleted
				current->parent->right = NULL;
			}
			//relase node's allocated memory
			free(current);
			//return to caller (prevents fall through)
			//indicates successful deletion
			return true;
		}
		//node has exactly one child
		//set parent left/right pointer to point to required node's child
		//release required node's memory
		if(
			(current->left == NULL && current->right != NULL) ||
			(current->right == NULL && current->left != NULL)
		) {
			if(
				current->parent->left != NULL &&
				value == current->parent->left->value
			) {
				if(current->left != NULL) {
					current->parent->left = current->left;
				} else {
					current->parent->right = current->right;
				}
			} else if (
				//short circuit NULL pointer check
				current->parent->right != NULL &&
				value == current->parent->right->value
			) {
				if(current->right != NULL) {
					current->parent->right = current->right;
				} else {
					current->parent->left = current->left;
				}
			}
			//relase node's allocated memory
			free(current);
			//return to caller (prevents fall through)
			//indicates successful deletion
			return true;
		}
		//node has two children
		//TODO
		if(
			current->left != NULL &&
			current->right != NULL
		) {
			//TODO
			fprintf(stderr, "functionality not yet implemented");
		}
	}
	//node with required value not found
	return false;
}

int* bst_serialize(bst_t *bst) {
	int *array 	= NULL;
	int pos 	= 0;

	if(bst->size != 0) {
		if((array = (int*) malloc (bst->size * sizeof(int))) == NULL) {
			fprintf(stderr, "alloc error!\n");
			exit(2);
		}

		__bst_helper_node_serializer(array, bst->root, bst->size, &pos);
	}

	return array;
}

void bst_close(bst_t *bst) {
	if(bst->root != NULL) {
		__bst_helper_node_deleter(bst->root->left);
		__bst_helper_node_deleter(bst->root->right);
	}
}