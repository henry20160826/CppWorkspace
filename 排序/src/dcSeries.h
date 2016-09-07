/*
 * 分治.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef DCSERIES_H_
#define DCSERIES_H_
//分治排序算法
//归并排序
void mergeSort(char a[], int start, int end) {
	/*
	 * 使用归并排序排列字符串a下标从start到end中的内容，包括start和end
	 */
	int len = end - start + 1;
	int mid = (start + end) / 2;
	if (len > 1) {
		//将问题分解为规模更小的子问题
//		printf("start:%d,mid:%d.\n",start,mid);
		mergeSort(a, start, mid);
//		printf("mid+1:%d,end:%d.\n",mid+1,end);
		mergeSort(a, mid + 1, end);
		merge(a,start,mid,end);
//		print(a,0,5);
	}
}
void merge(char a[], int start, int mid, int end) {
	char s1[100],s2[100];
	//归并排序使用的辅助空间最多
	strcpym(s1,a,start,mid);
//	print(s1,0,mid-start+1);
	strcpym(s2,a,mid+1,end);
//	print(s2,0,end-mid);
	int i=0;
	int len1=mid-start+1;
	int j=0;
	int len2=end-mid;
	int k=start;
	//合并两个字符串
	while(i<len1 && j<len2){
		if(s1[i]<s2[j]){
			a[k]=s1[i];
			i++;
			k++;
		}
		else{
			a[k]=s2[j];
			j++;
			k++;
		}
	}
	while(i<len1){
		a[k]=s1[i];
		i++;
		k++;
	}
	while(j<len2){
		a[k]=s2[j];
		j++;
		k++;
	}
}
void strcpym(char s[],char a[],int start,int end){
	for(int i=start;i<=end;i++){
		s[i-start]=a[i];
	}
//	print(s,0,end-start+1);
}
#endif /* DCSERIES_H_ */
