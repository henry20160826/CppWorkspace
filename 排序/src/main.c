/*
 ============================================================================
 Name        : 排序.c
 Author      : dh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	puts("Hello World"); /* prints Hello World */
	char a[] = { 's', 'b', 'h', 'c', 'a'};
//	char b[] = { 'b', 'c', 'd', 'e' ,'z'};
	int len = strlen(a) - 2;
	//字符串长度会算上最后的结尾符号。
	print(a, 0, len+1);
	printf("Len:%d\n",len);
	mergeSort(a,0,len);
	print(a, 0, len+1);

	return EXIT_SUCCESS;
}
