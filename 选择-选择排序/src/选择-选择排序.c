/*
 ============================================================================
 Name        : —°‘Ò-—°‘Ò≈≈–Ú.c
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
	char a[] = { ' ', 'b', 'h', 'c', 'a' };
	int len = strlen(a) - 1;
	selectSort(a,len);
	print(a,len);
	return EXIT_SUCCESS;
}
void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}
void selectSort(char a[], int n) {
	char min;
	for (int i = 0; i < n; i++) {
		min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(i!=min){
			swap(&a[i],&a[min]);
		}
	}
}
void print(char a[], int n) {
	for (int i = 1; i < n; i++) {
		printf("%c,", a[i]);
	}
	printf("\n");
}
