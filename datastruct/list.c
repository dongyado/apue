/*******************************************
 *
 * list.c 
 *
 ********************************************/

#include <stdlib.h>
#include <string.h>

#include "list.h"

/********************************************
 *
 * list_init
 *
 ********************************************/

void list_init (List *list, void (*destroy)(void *data) ) {
 	list->size = 0;
 	list->head = NULL;
 	list->tail = NULL;
 	list->destroy = destroy;
 	return ;
}

/********************************************
*
* list_init
*
********************************************/

void list_destroy(List *list) {
	void *data;
	while (list_size(list) > 0 ) {
		if (list_rm_next(list, NULL, (void **)&data) == 0 
			&& list->destroy != NULL) 
		{
			list->destroy(data);
		}
	}
	memset(list, 0, sizeof(List));
	return;
}

/********************************************
 *
 * list_ins_ne
 *
 ********************************************/
int list_ins_next(List *list, ListNode *node, const void *data) {
	ListNode *_node;

	if ((_node = (ListNode*) malloc(sizeof(ListNode))) == NULL)
		return -1;

	_node->data = (void *) data;

	if (node == NULL) {
		if (list_size(list) == 0) {
			list->tail = _node;
		}
		_node->next = list->head;
		list->head = _node;
	} else {
		if (node->next == NULL) {
			list->tail = _node;
		}

		_node->next = node->next;
		node->next = _node;
	}
	list->size++;
	return 0;
}

/********************************************
 *
 * list_rm_next
 *
 ********************************************/
int list_rm_next(List *list, ListNode *node, void **data) {
	ListNode *old_node;

	if (list_size(list) == 0)
		return -1;

	if (node == NULL) {
		*data = list->head->data;
		old_node = list->head;
		list->head = list->head->next;
		if (list_size(list) == 1) {
			list->tail = NULL;
		}
	} else {
		if (node->next == NULL)
			return -1;

		*data = node->next->data;
		old_node = node->next;
		node->next = node->next->next;

		if (node->next == NULL)
			list->tail = node;
	}

	free(old_node);
	list->size--;
	return 0;
}
