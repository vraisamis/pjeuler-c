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
	DILNode *p;
	if (index > list->items) {
		putErr("Index out of bound.");
		return NULL;
	}
	if (index == DIL_INDEX_LAST) p = NULL;
	else for (p = list->start; index > 0 && p != NULL; p = p->next, index--) ;
	/* node->next = (*point)->next;
	node->prev = *point;
	if ((*point)->next != NULL) (*point)->next->prev = node;
	else list->end = node;
	(*point)->next = node; */
	node->next = p;
	if (p == NULL) {
		node->prev = list->end;
		list->end = p;
	} else {
		node->prev = p->prev;
		p->prev = node;
	}
	if (node->prev == NULL) list->start = node;
	else node->prev->next = node;

	return list;
}

DILNode *removeDILNode(DILList *list, DILNode *node) {
	DILNode *tmp = node;
	if (node->prev == NULL) list->start = node->next;
	else node->prev->next = node->next;
	if (node->next == NULL) list->end = node->prev;
	else node->next->prev = node->prev;
	return tmp;
}

DILNode *searchDILNode(DILList *list, int data) {
	DILNode *point;
	for (point = list->start; point != NULL && point->data != data; point = point->next) ;
	return point;
}

DILIterator *getDILIterator(DILList *list, boolean isForward) {
	DILIterator *iterator = (DILIterator *)malloc(sizeof(DILIterator));
	if (iterator == NULL) {
		putErr("can't crate DILIterator.");
	} else {
		iterator->current = list->start;
		iterator->target = list;
		iterator->isForward = isForward;
	}
	return iterator;
}

void deleteDILIterator(DILIterator *iterator) {
	free(iterator);
}

boolean hasNextDILNode(DILIterator *iterator) {
	return iterator->current == NULL ? FALSE : TRUE;
}

void nextDILNode(DILIterator *iterator) {
	iterator->current = iterator->isForward ? iterator->current->next : iterator->current->prev;
}

DILNode *getCurrentDILNode(DILIterator *iterator) {
	return iterator->current;
}

