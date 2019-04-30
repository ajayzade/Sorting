#include<stdio.h>
int partition(int arr[],int lb,int ub){
	int i,j,pivot,temp;
	pivot = arr[lb];
	i = lb;
	j = ub;
	while(i<j){
		while(arr[i]<=pivot && i<j){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[lb] = arr[j];
	arr[j] = pivot;
	return j;
}
void quickSort(int arr[],int lb,int ub){
	if(lb < ub){
		int loc = partition(arr,lb,ub);
	    quickSort(arr,lb,loc-1);
	    quickSort(arr,loc+1,ub);
	}
}
int main(){
	int arr[12] = {44,33,11,55,77,90,40,60,99,22,88,66};
	int lb,ub;
	lb = 0;
	ub = (sizeof(arr)/sizeof(arr[0])) - 1;
	quickSort(arr,lb,ub);
	for(int m=0;m<ub;m++){
		printf("%d\t",arr[m]);
	}
	return 0;
}
