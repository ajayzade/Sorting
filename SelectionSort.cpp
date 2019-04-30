#include<stdio.h>
int min(int a[],int k,int n,int loc){
	int m;
	m = a[k];
	loc = k;
	for(int j=k+1;j<n;j++){
		if(m > a[j]){
			m = a[j];
			loc = j;
		}
	}
	return loc;
}
int main(){
	int a[8] = {77,33,44,11,88,22,66,55};
	int k,loc = 0,temp;
	int n = sizeof(a)/sizeof(a[0]);
	for(k=0;k<n;k++){
		loc = min(a,k,n,loc);
		temp = a[k];
		a[k] = a[loc];
		a[loc] = temp;
	}
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
