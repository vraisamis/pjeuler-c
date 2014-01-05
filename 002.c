#include <stdio.h>

int main(void) {
	int x = 1, y = 1, k, sum = 0;

	while (y < 4000000) {
		k = x + y;
		if (!((x & 0x01) ^ (y & 0x01))) sum += k;
		x = y;
		y = k;
	}
	printf("answer:%d\n", sum);

	return 0;
}
