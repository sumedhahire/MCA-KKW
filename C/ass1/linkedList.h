#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;

node* head;
node* search;
void createList(){

	node* temp;
	int n,data;
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
	
}

void rev(){
	node* prev;
	node* curr;
	node* nextnode;
	node* temp;
	prev=head->next;
	
	while(nextnode->next!=NULL){
		printf("\n=========in loop========\n");
		curr=prev->next;
		nextnode=curr->next;
		temp=nextnode->next;
		nextnode->next=curr;
		curr->next=prev;
		prev=temp;
	}
	
	display();
}
