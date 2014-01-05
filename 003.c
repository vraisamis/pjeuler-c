#include <stdio.h>

int main(void) {
	unsigned long long n = 600851475143UL, i = 2;
	while (i < n) {
		if (n % i == 0) n /= i;
		else i++;
	}
	printf("%ld\n", i);
	return 0;
}

