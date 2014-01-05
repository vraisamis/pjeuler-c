#ifndef MY_DLINKLIST
#define MY_DLINKLIST

#include "gen.h"
typedef struct tagDILinkNode {
	struct tagDILinkNode *prev;
	struct tagDILinkNode *next;
	int data;
} DILNode;

typedef struct tagDILinkList {
	DILNode *start;
	DILNode *end;
	int items;
} DILList;

typedef struct tagDILinkListIterator {
	DILNode *current;
	DILList *target;
	boolean isFront;
} DILIterator;


DILNode *newDILNode(int *data);

void deleteDILNode(DILNode *node);


DILList *newDILList(void);

DILList *initDILList(DILList *list);

void deleteDILList(DILList *list);

#define DIL_INDEX_LADT -1
DILList *addDILNode(DILList *list, DILNode *node, int index);

DILNode *removeDILNode(DILNode **node);

DILNode **searchDILNode(DILList *list, int data);

DILIterator *getDILIterator(DILList *list);

void deleteDILIterator(DILIterator *iterator);

boolean hasNextDILNode(DILIterator *iterator);

void nextDILNode(DILIterator *iterator);

DILNode *getCurrentDILNode(DILIterator *iterator);

#endif
