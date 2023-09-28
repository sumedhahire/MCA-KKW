#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;

node* head;
node* search;
int n=0;
void createList(){

	node* temp;
	int data;
	printf("give list number:");
	scanf("%d",&n);
	if(n==0){
		printf("give something");
		return ;
		
	}
	int i=0;
	while(i!=n){
		printf("==============in while==============\n");
		if(head==NULL){
			printf("\n==============head ka next null=====================\n");
			node* newnode;
			head=(node*)malloc(sizeof(node));
			newnode=(node*)malloc(sizeof(node));
			printf("\ngive data:");
			scanf("%d",&data);
			newnode->data=data;
			newnode->next=NULL;
			head->next=newnode;
			temp=newnode;
			
		}else{
			printf("\n==============end ka next null=====================\n");
			node* newnode;
			newnode=(node*)malloc(sizeof(node));
			printf("\ngive data:");
			scanf("%d",&data);
			newnode->data=data;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
			
		}
		i++;
	}
	
	
}

void display(){
	node* temp=head->next;
	if(head->next==NULL){
		printf("no data\n");
		return;
	}
	
	while(temp->next!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d->NULL",temp->data);
	
}

void searchList(int key){
	if(head==NULL){
		printf("\nList is null\n");
		return;
	}
	int flag=0;
	search=head;
	while(search->next!=NULL){
		if(search->next->data==key){
			printf("\nelement found\n");
			return;
		}
		else{
			search=search->next;
		}
	}
	if(search->data==key){
		printf("\nelement found\n");
		return;
	}
	printf("\nelement not found\n");
	
}


void inFirst(){
	node* temp=head;
	node* newnode=(node*)malloc(sizeof(node));
	if(head==NULL){
		printf("please make list\n");
		return;
	}
	int data;
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	if(head->next==NULL)
	{
		head->next=newnode;
	}else{
		newnode->next=head->next;
		head->next=newnode;
		printf("\ninserted\n");
	}
	n++;
}

void inLast(){
	node* temp=head;
	node* newnode=(node*)malloc(sizeof(node));
	if(head==NULL){
		
		printf("please make list\n");
		return;
	}
	int data;
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	if(head->next==NULL)
	{
		head->next=newnode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		printf("\ninserted\n");
	}
	display();
	n++;
}

void inPos(){
	int data;
	if(head==NULL){
		printf("please make list\n");
		return;
		
	}
	printf("\nenter element to insert in place:");
	scanf("%d",&data);
	node* temp;
	node* newnode;
	searchList(data);
	//if(temp)	
	if(search->next==NULL){
	 	printf("use different choice to enter in last");
		return;
	}
	temp=search->next;
	newnode=(node*)malloc(sizeof(node));
	int key;
	printf("\ninsert value:");
	scanf("%d",&key);
	newnode->data=key;
	search->next=newnode;
	newnode->next=temp;
	n++;
}


void delFirst(){
	
	if(head==NULL){
		printf("\nplease make list\n");
		return;
	}
	node* temp;
	//int data;
	//scanf("%d",&data);
	//newnode->data=data;
	//newnode->next=NULL;
	temp=head->next;
	head->next=temp->next;
	temp->next=NULL;
	free(temp);
	n--;
}

void delLast(){
	//node* temp=head;
	//node* newnode=(node*)malloc(sizeof(node));
	if(head==NULL){
		printf("\nplease make list\n");
		return;
	}
	//int data;
	//scanf("%d",&data);
	//newnode->data=data;
	//newnode->next=NULL;
	node* temp=head->next;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	node* temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	n--;
}

void delPos(){
	if(head==NULL){
		printf("\nplease make list\n");
		return;
	}
	int data;
	printf("\nenter val to deleted:");
	scanf("%d",&data);
	searchList(data);
	if(search->next==NULL){
		printf("\nplease use another function to delete from last\n");
		return;
	}
	node* temp=search->next;
	search->next=temp->next;
	temp->next=NULL;
	free(temp);
	n--;
}
// 1 2 3 4 5->null
// prev curr ahead
/*
	1		2	 3		4		5
	prev  curr	ahead
	
	1	<-2	 	3		4		5
	prev  curr	ahead
	
	1	<-2	 	3		4		5
		curr	ahead
				prev
	
	
	1	<-2	 <-	 3		4		5
		curr			ahead
				prev
				
				
	1	<-2	 <-	 3		4		5
		curr			ahead
				prev   curr
				
	1	<-2	 <-	 3		<-4		<-5
		curr			       ahead
				prev   curr
	
*/
void rev(){
		node* prev;
		node* curr;
		node* ahead;
		node* newHead=(node*)malloc(sizeof(node));
		
		prev=head->next;
		printf("%d(prev)\t",prev->data);
		
		curr=prev->next;
		printf("%d(curr)\t",curr->data);
		ahead=curr->next;
		printf("%d(ahead)\t",ahead->data);
		prev->next=NULL;
		while(ahead->next!=NULL){
			printf("\n===============\n");
			curr->next=prev;
			printf("%d(prev)\t",prev->data);
			prev=ahead;
			printf("%d(prev) %d(ahead)\t",prev->data,ahead->data);
			ahead=prev->next;
			printf("%d(ahead)\t",ahead->data);
			prev->next=curr;
			curr=ahead;
			printf("%d(curr) %d(ahead)\t",curr->data,ahead->data);
			ahead=curr->next;
		}
		ahead->next=curr;
		curr->next=prev;
		newHead->next=ahead;
		
		node* temp=newHead->next;

	int i=0;
	while(temp->next!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
		
	}
	printf("%d->NULL",temp->data);
}

void reverse(){
	
	if(n>2){
		node* prev=head->next;
		node* curr=prev->next;
		node* temp=curr->next;
		prev->next=NULL;
		while(temp->next!=NULL){
			curr->next=prev;
			prev=curr;
			curr=temp;
			temp=curr->next;
		}
		curr->next=prev;
		temp->next=curr;
		head->next=temp;
	
	}else{
	//	printf("=====hello=====");
		node* prev=head->next;
		//node* curr=prev->next;
		head->next=prev->next;
		head->next->next=prev;
		prev->next=NULL;
	}
	
	display();
}
