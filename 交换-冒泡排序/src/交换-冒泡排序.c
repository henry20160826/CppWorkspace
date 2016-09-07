/*
 ============================================================================
 Name        : Ωªªª-√∞≈›≈≈–Ú.c
 Author      : dh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("Hello World"); /* prints Hello World */
	char a[] = { 's', 'b', 'h', 'c', 'a' };
	int len = strlen(a) - 1;
	popSort(a, len);
	print(a, len);
	return EXIT_SUCCESS;
}
void popSort(char a[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}
void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}
void print(char a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%c,", a[i]);
	}
	printf("\n");
}
