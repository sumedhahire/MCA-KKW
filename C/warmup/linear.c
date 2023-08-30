#include<stdio.h>


void linear(int arr[],int key){
	int size=sizeof(arr);
//	printf("size : %d \n",size);
	for(int i=0;i<size;i++){
	//	printf("%d \n",arr[i]);
		if(arr[i]==key){
			printf("element found on %d",(i+1));
			break;
		}
	}
	
}

int main(){
	int arr[]={1,2,3,4,5,6,7};
	
	linear(arr,5);
	
	return 0;
	
	
}