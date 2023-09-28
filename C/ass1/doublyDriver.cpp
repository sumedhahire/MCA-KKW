
#include<stdio.h>
#include<stdlib.h>
#include"doubly.h"

int main(){
	printf("running");
//	create();
//	inFirst();
//	inLast();
//	rev();
//	inPos();
//	delFirst();
//	delLast();

//	delPos();

//	getCount();

	int choice=1;
	while(choice!=12){
		printf("\n========MENU========\n");
		printf("\n1)create\n2)display\n3)insert in first\n4)insert in last\n5)insert anywhere\n6)delete in first\n");
		printf("7)delete in last\n8)delete anywhere\n9)search\n10)get count\n11)reverse the nodes\n12)exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		
		
		switch(choice){
			case 1:create();
				break;
			case 2:display();
				break;
			case 3:inFirst();
				break;
			case 4:inLast();
				break;
			case 5:inPos();
				break;
			case 6:delFirst();
				break;
			case 7:delLast();
				break;
			case 8:delPos();
				break;
			case 9:isItThere();
				break;
			case 10:getCount();
				break;
			case 11:rev();
				break;
			case 12:break;
			default:printf("\nwronge choice :(\n");			
		}		
	}
}
















