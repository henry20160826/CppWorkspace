/*
 * ����.h
 *
 *  Created on: Dec 5, 2015
 *      Author: kamui
 */

#ifndef DCSERIES_H_
#define DCSERIES_H_
//���������㷨
//�鲢����
void mergeSort(char a[], int start, int end) {
	/*
	 * ʹ�ù鲢���������ַ���a�±��start��end�е����ݣ�����start��end
	 */
	int len = end - start + 1;
	int mid = (start + end) / 2;
	if (len > 1) {
		//������ֽ�Ϊ��ģ��С��������
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
	//�鲢����ʹ�õĸ����ռ����
	strcpym(s1,a,start,mid);
//	print(s1,0,mid-start+1);
	strcpym(s2,a,mid+1,end);
//	print(s2,0,end-mid);
	int i=0;
	int len1=mid-start+1;
	int j=0;
	int len2=end-mid;
	int k=start;
	//�ϲ������ַ���
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
