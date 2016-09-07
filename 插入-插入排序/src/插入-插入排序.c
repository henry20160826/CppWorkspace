/*
 ============================================================================
 Name        : 插入-插入排序.c
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
	char a[] = { 'd', 'b', 'h', 'c', 'a' };

	int len = strlen(a) - 1;
	printf("%d\n", len);
	print(a, len);
	insertSort(a, len);
	print(a, len);
	return EXIT_SUCCESS;
}

void insertSort(char a[], int n) {
	//不使用a[0]
	int j = 0;
	for (int i = 2; i < n; i++) {
		if (a[i] < a[i - 1]) {
			a[0] = a[i];
			for (j = i - 1; j > 0 && a[j] > a[0]; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}

	}
}
void print(char a[], int n) {
	for (int i = 1; i < n; i++) {
		printf("%c,", a[i]);
	}
	printf("\n");
}
