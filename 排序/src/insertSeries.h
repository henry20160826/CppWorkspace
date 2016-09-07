/*
 * ≤Â»Î.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef INSERTSERIES_H_
#define INSERTSERIES_H_
#include <basis.h>
//≤Â»Î≈≈–Ú
void insertSort(char a[], int n) {
	//≤ª π”√a[0]
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
//œ£∂˚≈≈–Ú
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

#endif /* INSERTSERIES_H_ */
