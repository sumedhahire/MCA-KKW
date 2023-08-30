// Online C compiler to run C program online
#include<stdio.h>
/*
binary seacrh is nothing but cutting in half 
*/
void binary(int arr[],int key){
    int first=0,last=sizeof(arr)-1;
  //  printf("hello\n %d",last);
    int middle=last/2;
    while(first<=last){
        if(arr[middle]==key){
            printf("got on %d",middle+1);
            return;
        }else{
        	//first     middle,first   key  last
            if(key>arr[middle]){
            //	printf("in first\n");
                first=middle+1;
                middle=(first+last)/2;
            }else{
            //	printf("in second\n");
                last=middle-1;
                middle=(first+last)/2;
            }
        }
    }
    printf("not present");
}

int main() {
    // Write C code here
    int arr[]={1,2,3,4,5,6,7,8};
 //   printf("dsfhgsfhbsjd");
    binary(arr,36);
   // printf("%d",a);
    
    return 0;
}