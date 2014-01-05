#include <string.h>
#include <stdlib.h>
#include "../hdr/string.h"

void reverseString(char *dst, char *src, int length) {
	int i, j;
	char *str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = 0;
	strncpy(str, src, length);
	for (i = 0, j = length - 1; i < length; i++, j--) dst[i] = str[j];
}
