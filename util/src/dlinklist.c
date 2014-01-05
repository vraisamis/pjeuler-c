#include <stdlib.h>
#include "../hdr/dlinklist.h"

DILNode *newDILNode(int *data) {
	DILNode *node =(DILNode *)malloc(sizeof(DILNode));
	if (node == NULL) putErr("can't create DILNode.");
	else {
		node->data = data == NULL ? 0 : *data;
		node->next = NULL;
		node->prev = NULL;
	}
	return node;
}

void deleteDILNode(DILNode *node) {
	free(node);
}

DILList *newDILList(void) {
	DILList *list = (DILList *)malloc(sizeof(DILList));
	if (list == NULL) putErr("can't create DILList.");
	else {
		list->start = NULL;
		list->end   = NULL;
		list->items = 0;
	}
	return list;
}

DILList *initDILList(DILList *list) {
	DILNode *node;
	for (node = list->start; node != NULL; node = list->start) {
		list->start = list->start->next;
		deleteDILNode(node);
	}
	list->end = NULL;
	list->items = 0;
	return list;
}

void deleteDILList(DILList *list) {
	initSILList(list);
	free(list);
}

DILList *addDILNode(DILList *list, DILNode *node, int index) {
	DILNode **point;
	if (index > list->items) {
		putErr("Index out of bound.");
		return NULL;
	}
	if (index == DIL_INDEX_LIST) point = &(list->end->next);
	else for (point = &(list->start); index > 0 && *point != NULL; point = &((*point)->next), index--) ;
	node->next = (*point)->next;
	node->prev = *point;
	if ((*point)->next != NULL) (*point)->next->prev = node;
	else list->end = node;
	(*point)->next = node;
	return list;
}

DILNode *removeDILNode(DILNode **node);

DILNode **searchDILNode(DILList *list, int data) {
	DILNode **point;
	for (point = &(list->start); *point != NULL && (*point)->data != data; point = &((*point)->next)) ;
	return point;
}

DILIterator *getDILIterator(DILList *list);

void deleteDILIterator(DILIterator *iterator);

boolean hasNextDILNode(DILIterator *iterator);

void nextDILNode(DILIterator *iterator);

DILNode *getCurrentDILNode(DILIterator *iterator);

