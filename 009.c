#include <stdio.h>

// 愚直版
int main(void) {
	int x, y, z;
	for (x = 1; x <= 998; x++) {
		for (y = x + 1; y <= 998; y++) {
			if (x * x + y * y == (1000 - x - y) * (1000 - x - y)) goto END;
		}
	}
END:
	printf("answer:%d\n", x * y * (1000 - x - y));
	return 0;
}

