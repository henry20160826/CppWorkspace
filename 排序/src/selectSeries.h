/*
 * ѡ��.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef SELECTSERIES_H_
#define SELECTSERIES_H_
//ѡ������
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
//������
//������
void buildMaxHeap(char a[], int len) {

}
//���µ���
void adjustDown(char a[], int k, int len) {

}
//���������
void heapSort(char a[], int len) {

}
//���ϵ���
void adjustUp(char a[], int len) {
	//int len = strlen(a) - 1;
	//��������������ַ������Ȳ�һ��
//	printf("������len:%d\n", len);
//	len=5-1;
	int boss;
	//Сi����ְ֮·
	for (int i = len-1; i > 0; i = boss) {
		boss = i / 2;
		if (a[boss] < a[i]) {
			swap(&a[boss], &a[i]);
		} else {
			break;
		}
	}
	//���Թ����Ƿ���Ҫ����ԭ���ַ���
//	print(a, 0, 5);
//	printf("******\n");

}
#endif /* SELECTSERIES_H_ */
