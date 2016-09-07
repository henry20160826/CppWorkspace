/*
 ============================================================================
 Name        : ≤Â»Î-œ£∂˚≈≈–Ú.c
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
	print(a,len);
	shellSort(a,len);
	print(a,len);
	return EXIT_SUCCESS;
}

void print(char a[], int n) {
	for (int i = 1; i < n; i++) {
		printf("%c,", a[i]);
	}
	printf("\n");
}

void shellSort(char a[], int n) {
	int j=0;
	for (int dk = n / 2; dk > 0; dk /= 2) {
		for(int i=dk+1;i<n;i++){
			if(a[i]<a[i-dk]){
				a[0]=a[i];
				for(j=i-dk;j>0 && a[j]>a[0];j-=dk){
					a[j+dk]=a[j];
				}
				a[j+dk]=a[j];
			}
		}
	}
}
