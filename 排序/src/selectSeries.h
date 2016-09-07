/*
 * 选择.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef SELECTSERIES_H_
#define SELECTSERIES_H_
//选择排序
void selectSort(char a[], int len) {
	int min;
	for (int i = 0; i < len; i++) {
		min = i;
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (i != min) {
			swap(&a[i], &a[min]);
		}
	}
}
//堆排序
//建立堆
void buildMaxHeap(char a[], int len) {

}
//向下调整
void adjustDown(char a[], int k, int len) {

}
//堆排序调用
void heapSort(char a[], int len) {

}
//向上调整
void adjustUp(char a[], int len) {
	//int len = strlen(a) - 1;
	//函数里面和外面字符串长度不一样
//	printf("函数中len:%d\n", len);
//	len=5-1;
	int boss;
	//小i的升职之路
	for (int i = len-1; i > 0; i = boss) {
		boss = i / 2;
		if (a[boss] < a[i]) {
			swap(&a[boss], &a[i]);
		} else {
			break;
		}
	}
	//测试过后看是否需要返回原有字符串
//	print(a, 0, 5);
//	printf("******\n");

}
#endif /* SELECTSERIES_H_ */
