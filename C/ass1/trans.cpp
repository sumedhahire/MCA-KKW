#include<stdio.h>

int main(){
	
	int m,n,t;
	printf("give m:");
	scanf("%d",&m);
	printf("give n:");
	scanf("%d",&n);
	printf("give t:");
	scanf("%d",&t);
	int arr[t][3],trans[t][3];
	
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("arr[%d][%d]:",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	arr[0][0]=trans[0][0]=m;
	arr[0][1]=trans[0][1]=n;
	arr[0][2]=trans[0][2]=t;
	
	for(int i=0;i<=t;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",arr[i][j]);
	
		}
		printf("\n");
	}
//	
//	int k=0;
//	while(k!=t+1)
//	{
//		for(int i=1;i<=t;i++){
//			printf("\n--->%d<---\n",k);
//			if(arr[i][1]==k){
//				printf("\n--->%d<loop\n",k);
//				trans[i][0]=arr[i][1];
//				trans[i][1]=arr[i][0];
//				trans[i][2]=arr[i][2];
//			}
//		}
//		k++;
//	}
//
//	int rows=1,col=0;
//	for(int i=1;i<=t;i++){
//		for(int j=0;j<=t;j++)
//		{
//			if(arr[i][1]==j)
//			{
//			
//				trans[rows][0]=arr[i][1];
//				trans[rows][1]=arr[i][0];
//				trans[rows][2]=arr[i][2];
//				rows++;
//			}
//		}
//	}
	
	for(int i=0;i<=t;i++){
		int temp=arr[i][0];
		arr[i][0]=arr[i][1];
		arr[i][1]=temp;
	}
	int rows=0;
	for(int k=0;k<=t;k++){
		for(int i=1;i<=t;i++){
			if(arr[i][0]==k){
				trans[rows][0]=arr[i][0];
				trans[rows][1]=arr[i][1];
				trans[rows][2]=arr[i][2];
				rows++;
			}
		}
	}
	
	printf("\n================\n");
	for(int i=0;i<=t;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",arr[i][j]);
	
		}
		printf("\n");
	}
//
//	int k=0;
//	while(k!=t+1)
//		for(int i=1;i<=t;i++){
//			
//		}
	printf("\n===============================\n");
	for(int i=0;i<=t;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",trans[i][j]);
	
		}
		printf("\n");
	}
	
	
	
}






