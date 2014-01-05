#include <stdio.h>
#include "util/hdr/gen.h"

int main(void) {
	int x[10001];
	printf("answer:%d\n", getPrime(x, 10001));
	return 0;
}

