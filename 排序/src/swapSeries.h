/*
 * ����.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef SWAPSERIES_H_
#define SWAPSERIES_H_
#include <basis.h>
//ð������
void popSort(char a[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
	//printf("������?");����
}

#endif /* SWAPSERIES_H_ */
