#include <stdio.h>
#include "util/hdr/gen.h"

int main(void) {
	int i, ans;
	for (ans = 1, i = 20; i > 1; i--) if (ans % i != 0) ans *= i / gcd(ans, i);
	printf("answer:%d\n", ans);
	return 0;
}

