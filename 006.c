#include <stdio.h>

int main(void) {
	int i, j, ans;
	ans = 0;
	for (i = 1; i <= 100; i++) {
		for (j = i + 1; j <= 100; j++) {
			ans += i * j;
		}
	}
	printf("answer:%d\n", ans * 2);
	return 0;
}
