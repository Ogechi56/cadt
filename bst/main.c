#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {

	int 	i 					= 0;
	int *	serialized_tree		= NULL;
	bst_t 	tree;

	bst_init(&tree);

	bst_insert(&tree, 10);
	bst_insert(&tree, 20);
	bst_insert(&tree, 30);
	bst_insert(&tree, 5);
	bst_insert(&tree, 100);

	if(bst_contains(&tree, 10)) {
		printf("contains\n");
	}

	serialized_tree = bst_serialize(&tree);

	for(i = 0; i < tree.size; ++i) {
		printf("%0d ", serialized_tree[i]);
	}
	printf("\n");

	bst_delete(&tree, 20);

	serialized_tree = bst_serialize(&tree);

	for(i = 0; i < tree.size; ++i) {
		printf("%0d ", serialized_tree[i]);
	}
	printf("\n");

	bst_close(&tree);

	free(serialized_tree);


	return 0;
}