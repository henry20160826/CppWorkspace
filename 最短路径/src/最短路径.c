/*
 ============================================================================
 Name        : 最短路径.c
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
	int edge[6][6] = {
			0, 12, 3, 0, 9, 10,
			12, 0, 0, 2, 6, 0,
			3, 0, 0, 2, 0, 6,
			0, 2, 2, 0, 4, 7,
			9, 6, 0, 4, 0, 4,
			10, 0, 6, 7, 4, 0,

	};
	routeFloyd(edge, 6);
	print(edge, 6);
	return EXIT_SUCCESS;
}
//弗洛伊德算法，计算定点到每个顶点的距离
void routeFloyd(int edge[][6], int n) {
	int newDistance;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == k || i == j || j == k) {
					//判断k是不是端点
					//判断是不是自己到自己的路径
					continue;
				} else {
					//判断i到k的距离和k到j的距离值是否有效
					if (edge[i][k] != 0 && edge[k][j] != 0) {
						newDistance = edge[i][k] + edge[k][j];
						//判断新的路径长度是否比原有路径长度短
						if (edge[i][j] > newDistance || edge[i][j] == 0) {
//							if(i==5){
//								printf("i=%d,j=%d,k=%d,newDistant=%d\n",i+1,j+1,k+1,newDistance);
//							}
							edge[i][j] = newDistance;
						}
					}
				}
			}
		}
	}
}
void print(int edge[][6], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d,\t", edge[i][j]);
		}
		printf("\n");
	}
}
