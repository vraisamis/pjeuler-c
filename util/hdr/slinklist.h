#ifndef MY_SLINKLIST
#define MY_SLINKLIST

#include "gen.h"
typedef struct tagSILinkNode {
	struct tagSILinkNode *next;
	int data;
} SILNode;

typedef struct tagSILinkList {
	SILNode *start;
	SILNode *end;
	int items;
} SILList;

typedef struct tagSILinkListIterator {
	SILNode *current;
	SILList *target;
} SILIterator;


SILNode *newSILNode(int *data);

void deleteSILNode(SILNode *node);


SILList *newSILList(void);

SILList *initSILList(SILList *list);

void deleteSILList(SILList *list);

#define SIL_INDEX_LAST -1
SILList *addSILNode(SILList *list, SILNode *node, int index);

SILNode *removeSILNode(SILNode **node);

SILNode **searchSILNode(SILList *list, int data);

SILIterator *getSILIterator(SILList *list);

void deleteSILIterator(SILIterator *iterator);

boolean hasNextSILNode(SILIterator *iterator);

void nextSILNode(SILIterator *iterator);

SILNode *getCurrentSILNode(SILIterator *iterator);
#endif
