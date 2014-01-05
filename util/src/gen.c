#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "../hdr/gen.h"


void putErr(char *str) {
	fprintf(stderr, "**Error**\n%s\n++EndErr**\n", str);
}

int gcd(int x1, int x2) {
	int y;
	x1 = abs(x1);
	x2 = abs(x2);
	while (x2 != 0) {
		y = x1 % x2;
		x1 = x2;
		x2 = y;
	}
	return x1;
}

int getPrime(int dst[], int n) {
	int i = 0, k = 1, j;
	while (i < n) {
		dst[i] = ++k;
		for (j = 0; k % dst[j] != 0; j++) ;
		if (j == i) i++;
	}
	return k;
}

long eratosthenes(int *ary, int length) {
	int bits = sizeof(int) * CHAR_BIT;
	int i, j, k, l;
	long count = 0;
	for (i = 0; i < length; i++) ary[i] = ~0x00;
	ary[0] &= ~0x03;
	for (i = 0; i < length; i++) {
		for (j = 0; j < bits; j++) {
			if (((ary[i] >> j) & 0x01) == 0x00) continue;
			count++;
			for (l = 2 * j, k = 2 * i + l / bits; k < length; l += j, k += i + l / bits) {
				l %= bits;
				ary[k] &= ~(0x01 << l);
			}
		}
	}
	return count;
}

int eratosToArray(long dst[], int era[], int srcLength) {
	int bits = sizeof(int) * CHAR_BIT;
	int i, j, k = 0;
	for (i = 0; i < srcLength; i++) {
		for (j = 0; j < bits; j++) {
			if (((era[i] >> j) & 0x01) == 0x1) {
				dst[k++] = i * bits + j;
			}
		}
	}
	return k;
}
