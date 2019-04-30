#include<stdio.h>
int main(){
	int a[8] = {77,33,44,11,88,22,66,55};
	int i,j,temp;
	int n = sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
