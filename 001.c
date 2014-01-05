#include <stdio.h>

int main(void) {
	int i, n;

	for (n = 0, i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) n += i;
	}
	printf("answer:%d\n", n);

	return 0;
}
