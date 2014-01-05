#include <stdlib.h>
#include "../hdr/slinklist.h"


SILNode *newSILNode(int *data) {
	SILNode *node = (SILNode *)malloc(sizeof(SILNode));
	if (node == NULL) putErr("can't create SILNode.");
	else {
		node->data = data == NULL ? 0 : *data;
		node->next = NULL;
	}
	return node;
}

void deleteSILNode(SILNode *node) {
	free(node);
}

SILList *newSILList(void) {
	SILList *list = (SILList *)malloc(sizeof(SILList));
	if (list == NULL) putErr("can't create SILList.");
	else {
		list->start = NULL;
		list->end   = NULL;
		list->items = 0;
	}
	return list;
}

SILList *initSILList(SILList *list) {
	SILNode *node;
	for (node = list->start; node != NULL; node = list->start) {
		list->start = list->start->next;
		deleteSILNode(node);
	}
	list->end = NULL;
	list->items = 0;
	return list;
}

void deleteSILList(SILList *list) {
	initSILList(list);
	free(list);
}

SILList *addSILNode(SILList *list, SILNode *node, int index) {
	SILNode **point, *tmp;
	if (index > list->items) {
		putErr("Index out of bound.");
		return NULL;
	}
	if (index == SIL_INDEX_LAST) point = &(list->end->next);
	else for (point = &(list->start); index > 0 && *point != NULL; point = &((*point)->next), index--) ;
	tmp = *point;
	*point = node;
	node->next = tmp;
	if (tmp == NULL) list->end = node;
	return list;
}

SILNode *removeSILNode(SILNode **node) {
	SILNode *r = *node;
	*node = r->next;
	return r;
}

SILNode **searchSILNode(SILList *list, int data) {
	SILNode **point;
	for (point = &(list->start); *point != NULL && (*point)->data != data; point = &((*point)->next)) ;
	return point;
}

SILIterator *getSILIterator(SILList *list) {
	SILIterator *iterator = (SILIterator *)malloc(sizeof(SILIterator));
	iterator->target = list;
	iterator->current = list->start;
}

void deleteSILIterator(SILIterator *iterator) {
	free(iterator);
}

boolean hasNextSILNode(SILIterator *iterator) {
	return iterator->current != NULL ? TRUE : FALSE;
}

void nextSILNode(SILIterator *iterator) {
	if (iterator->current != NULL) iterator->current = iterator->current->next;
}

SILNode *getCurrentSILNode(SILIterator *iterator) {
	return iterator->current;
}

