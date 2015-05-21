/***************************************
 * 
 * bitree test
 *
 ***************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "bitree.h"
#include "traverse.h"

void data_destroy (void *data) {
	
	//printf("%s\n", (char *)data );
	//free(data);
	return;
}


int main(void) {
	BiTree * tree;
	char * a[] = {"kobe", "bryant", "james", "jordan", "johnson"};
	List *list;
	ListNode *node;

	tree = (BiTree *) malloc(sizeof(BiTree));
	if (tree == NULL) return -1;

	list = (List *) malloc(sizeof(List));
	if (list == NULL) return -1;

	bitree_init(tree, &data_destroy);
	bitree_ins_left(tree, NULL, a[0]);


	bitree_ins_left(tree, tree->root, a[1]);
	bitree_ins_right(tree, tree->root, a[2]);

	bitree_ins_left(tree, tree->root->left, a[3]);
	bitree_ins_right(tree, tree->root->left, a[4]);

	//list init

	list_init(list, &data_destroy);
	
	postorder(tree->root, list);
	node = list->head;
	
	while(node != NULL) {
		printf("%s\n", (char *) node->data );
		node = node->next;
	}
	

	bitree_destroy(tree);
	list_destroy(list);
	return 0;	
}