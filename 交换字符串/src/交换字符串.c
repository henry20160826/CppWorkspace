/*
 ============================================================================
 Name        : ½»»»×Ö·û´®.c
 Author      : dh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *pa, char *pb) {
	char temp[100];
	strcpy(temp, pa);
	strcpy(pa, pb);
	strcpy(pb, temp);
}
int main(void) {
	char a[50] = { "china" };
	char b[50] = { "us" };
	swap(a, b);
	printf("a:%s,b:%s", a, b);
	return EXIT_SUCCESS;
}
