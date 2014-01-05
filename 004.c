#include <stdio.h>
#include <string.h>
#include "util/hdr/string.h"

int main(void) {
	char str[8], rev[8];
	int i, j;
	i = 999 * 2;
	do {
		for (j = i / 2; j <= 999; j++) {
			sprintf(str, "%d", (i - j) * j);
			reverseString(rev, str, strlen(str));
			if (strcmp(str, rev) == 0) break;
		}
		i--;
	} while (strcmp(str, rev));
	printf("answer:%s\n", str);
	return 0;
}
// memo: 二回比較してるのが気に入らない
