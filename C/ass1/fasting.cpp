#include<stdio.h>

int main(){
	
	//int arr[][3]={{6,6,8},{0,0,15},{0,3,22},{0,5,15},{1,1,11},{1,2,3},{2,3,6},{4,0,91},{5,2,28}};
	int arr[][3]={{5,6,6},{0,4,9},{1,1,8},{2,0,4},{2,2,2},{3,5,5},{4,2,2}};
	int t=sizeof(arr)/sizeof(int)/3;
	int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<3;j++){
			printf("%d	",arr[i][j]);
		}
		printf("\n");
	}
	int limit=arr[0][1],k=0;
	int freq[limit]={0},start[limit]={0};
	while(k!=limit){
		for(i=0;i<t;i++){
			if(k==arr[i][1]){
				freq[k]+=1;
			}
		}	
		k++;
	}
	printf("\n======freq=========\n");
	for(j=0;j<limit;j++){
		printf("%d	",freq[j]);
	}
	
	printf("\n======start=========\n");
	if(freq[0]>0)
		start[0]=1;
	else
		start[0]=0;
		
	for(i=1;i<limit;i++){
		start[i]=start[i-1]+freq[i-1];
	}
	for(j=0;j<limit;j++){
		printf("%d	",start[j]);
	}
	int trans[t][3];
	trans[0][0]=arr[0][1];
	trans[0][1]=arr[0][0];
	trans[0][2]=arr[0][2];
	int in=0;
	printf("\n======transpose=========\n");
	
//	int place=0,row=1;
//	for(i=0;i<sizeof(start);i++){
//		for(j=1;j<sizeof(arr);j++){
//			while(
//		}
//	}
	/*
	start pos is given
	
	*/
	int up=1;
//	for(int s=0;s<sizeof(start);s++){
//		while(up!=start[i+1]){
//			for(i=1;i<sizeof(arr);i++){
//				if(arr[i][0]==s){
//					trans[up]
//				}
//			}
//		}
//	}

	for(i=1;i<t;i++){
		int temp=arr[i][1];
		trans[start[temp]][0]=temp;
		trans[start[temp]][1]=arr[i][0];
		trans[start[temp]][2]=arr[i][2];
		start[temp]+=1;
	}
	for(i=0;i<t;i++){
		for(j=0;j<3;j++){
			printf("%d	",trans[i][j]);
		}
		printf("\n");
	}
}
