#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util/hdr/gen.h"


int main(void) {
	//int bits = sizeof(int) * CHAR_BIT;
	//int *ary;
	//long *dst, n;
	//long i;
	//long sum;
	//ary = (int *)malloc(sizeof(int) * (2000000L / bits + 1));
	//n = eratosthenes(ary, (2000000L / bits + 1));
	//dst = (long *)malloc(sizeof(long) * n);
	//eratosToArray(dst, ary, (2000000L / bits + 1));
	//for (i = 0, sum = 0; i < n && dst[i] <= 2000000L; i++) {
	//	printf("%d\r\n", dst[i]);
	//	sum += dst[i];
	//}
	//printf("answer:%d\n", sum);
	//return 0;
	
	int ary[10000];
	int n;
	long dst[100000];
	int x;
	long sum;
	eratosthenes(ary, 10000);
	n = eratosToArray(dst, ary, 10000);
	sum = 0;
	for (x = 0; x < n; x++) {
		printf("xx%3d:%d\n", x, dst[x]);
		sum += dst[x];
	}
	printf("es:%d\n", sum);
	return 0;
}

