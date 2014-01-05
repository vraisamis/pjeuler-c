#include <stdio.h>
#include "util/hdr/slinklist.h"

int main(void) {
	SILList *list = newSILList();
	SILIterator *first, *last;
	SILNode *node;
	int now, max;
	int ichar, i;
	FILE *fp;

	fp = fopen("008in.txt", "r");
	if (fp == NULL) return 1;
	while ((ichar = fgetc(fp)) != EOF) {
		if(isdigit(ichar)) {
			ichar -= '0';
			addSILNode(list, newSILNode(&ichar), SIL_INDEX_LAST);
		}
	}

	first = getSILIterator(list);
	last  = getSILIterator(list);
	for (i = 0; hasNextSILNode(last) && i < 4; nextSILNode(last), i++) ;
	for (max = 0, now = 1; hasNextSILNode(last); nextSILNode(first), nextSILNode(last), now = 1) {
		for (i = 0, now = 1, node = getCurrentSILNode(first); i < 5; i++, node = node->next) now *= node->data;
		if (now > max) {
			max = now;
		}
	}

	printf("answer:%d\n", max);

	deleteSILIterator(first);
	deleteSILIterator(last);
	deleteSILList(list);

	return 0;
}

