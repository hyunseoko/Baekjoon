#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}