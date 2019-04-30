#include<stdio.h>
int heap[20],heap_size = 0,ptr,par,top,left,right;
void insHeap(int heap[],int n,int v){
	heap_size++;
	ptr = heap_size - 1;
	while(ptr > 0){
		par = (int)(ptr / 2);
		if(v <= heap[par]){
			heap[ptr] = v;
			return;
		}
		heap[ptr] = heap[par];
		ptr = par;
	}
	heap[0] = v;
	return;
}
void delHeap(int heap[],int n){
	top = heap[0];
	int last = heap[heap_size - 1];
	heap_size = heap_size - 1;
	ptr = 0;
	left = 1;
	right = 2;
	while(right < heap_size){
		if(last >= heap[left] && last >= heap[right]){
			heap[ptr] = last;
			return;
		}
		if(heap[right] >= heap[left]){
			heap[ptr] = heap[right];
			ptr = right;
		}else{
			heap[ptr] = heap[left];
			ptr = left;
		}
		left = 2 * ptr;
		right = left + 1;
	}
	if(left == heap_size && last < heap[left]){
		ptr = left;
	}
	heap[ptr] = last;
	return;
}
int main(){
	int arr[10] = {12,98,43,67,23,87,77,66,44,99};
	int n = sizeof(arr)/sizeof(arr[0]),i;
	for(i=0;i<n;i++){
		insHeap(heap,heap_size,arr[i]);
	}
	printf("Heap tree is\n\t");
	for(i=0;i<n;i++){
		printf("%d |",heap[i]);
	}
	while(heap_size > 0){
		delHeap(heap,heap_size);
		arr[heap_size] = top;
	}
	printf("\nSorted heap tree\n\t");
	for(i=0;i<n;i++){
		printf("%d |",arr[i]);
	}
	return 0;
}
