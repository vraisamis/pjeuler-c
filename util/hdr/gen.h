#ifndef MY_GEN
#define MY_GEN

typedef enum enBool {
	FALSE = 0,
	TRUE  = 1
} boolean;

void putErr(char *str);

int gcd(int x1, int x2);

int getPrime(int dst[], int n);

long eratosthenes(int *ary, int length);

int eratosToArray(long dst[], int era[], int srcLength);

#endif
