/*
 * basis.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef BASIS_H_
#define BASIS_H_

void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}
void print(char a[], int start,int end) {
	/*
	 * ����ַ���a���±��start��end�м�����ݣ�����start����������end
	 */
	for (int i = start; i < end; i++) {
		printf("%c,", a[i]);
	}
	printf("\n");
}

#endif /* BASIS_H_ */
