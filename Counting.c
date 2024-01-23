#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int main() {
	int n, t;
	int* c;
	scanf("%d", &n);
	c = (int*)malloc(sizeof(int) * 10000);
	memset(c, 0, sizeof(int) * 10000);
	for (int i=0; i<n; i++) {
		scanf("%d", &t);
		c[t-1]++;
	}
	for (int i=0; i<10000; i++) {
		while (c[i]--) {
			printf("%d\n", i+1);
		}
	}
	free(c);
}