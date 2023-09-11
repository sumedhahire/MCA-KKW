#include<stdio.h>

int main(){
	
	int m,n;
	printf("enter m:");
	scanf("%d",&m);
	printf("enter n:");
	scanf("%d",&n);
	int arr[m][n],t=0;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("arr[%d][%d]:",i,j);
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0)
				t++;
		}
	}
	printf("\n=========%d=============\n",t);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	int spa[t][3],rows=1;
	spa[0][0]=m;
	spa[0][1]=n;
	spa[0][2]=t;
	
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j]!=0){
				spa[rows][0]=i;
				spa[rows][1]=j;
				spa[rows][2]=arr[i][j];
				rows++;
			}
		}
	}
	
	printf("\n========================\n");
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",spa[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
}
