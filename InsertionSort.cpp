#include<stdio.h>
int main(){
	int a[8] = {77,33,44,11,88,22,66,55}; 
	int k,ptr,temp;
	int n = sizeof(a)/sizeof(a[0]);
	for(k=1;k<n;k++){
		temp = a[k];
		ptr = k - 1;
		while(temp < a[ptr]){
			a[ptr + 1] = a[ptr];
			ptr = ptr - 1;
		}
		a[ptr + 1] = temp;
	}
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
