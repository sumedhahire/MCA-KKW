#include<stdio.h>
#include<stdlib.h>
int count;
typedef struct node{
	struct node* prev;
	int data;
	struct node* next;
}node;

node* head=NULL;
node* end=NULL;
node* search=NULL;
void display(){
	if(head==NULL){
		printf("list is empty\n");
		return;
	}
	
	node* temp=head->next;
	
	while(temp->next!=NULL){
		printf("%d<-->",temp->data);
		temp=temp->next;
	}
	printf("%d-->END",temp->data);
//	printf("%d",temp->data);
//	end=(node*)malloc(sizeof(node));
	
	
	printf("\n============end=========\n%d\n",end->data);
} 
//void structure(){
//	node* temp=head->next;
//	printf("NULL<--%d-->%d",temp->data,temp->next->data);
//	temp=temp->next;
//	while(temp->next!=head->next){
//		printf("%d<--%d-->%d",temp->prev->data,temp->data,temp->next->data);
//		temp=temp->next;
//	}
//	
//}
void create(){
	//printf("\nin create:");
	
	int i=0,d;
	
	printf("\ngive count:");
	scanf("%d",&count);
	while(i!=count){
		printf("\nin loop\n");
		if(head==NULL){
			head=(node*)malloc(sizeof(node));
			node* newnode=(node*)malloc(sizeof(node));
			head->next=newnode;
			printf("\ngive data for %dth node:",(i+1));
			scanf("%d",&d);
			newnode->data=d;
			newnode->next=NULL;
			newnode->prev=NULL;
			end=newnode;
		}else{
			node* newnode=(node*)malloc(sizeof(node));
			end->next=newnode;
			printf("\ngive data for %dth node:",(i+1));
			scanf("%d",&d);
			newnode->data=d;
			newnode->next=NULL;
			newnode->prev=end;
			end->next=newnode;
			printf("\n%d<--%d\n",newnode->prev->data,newnode->data);
			//printf("\n%d-->%d\n",newnode->data,newnode->next->data);
			end=newnode;
		}
		
		i++;
	}
	
	display();	
}

bool find(int key){
	if(count==0){
		printf("\ncreate list first\n");
		return false;
	}
	
	search=head->next;
	while(search!=NULL){
		if(search->data==key){
			return true;			
		}else{
			search=search->next;
		}
	}
	return false;
}
void inFirst(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	int d;
	printf("\ngive data:");
	scanf("%d",&d);
	node* temp=head->next;
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->next=temp;
	newnode->prev=NULL;
	head->next=newnode;
	temp->prev=newnode;
//	end->next=NULL;
	count++;
	display();
}
void inLast(){
	if(head==0){
		printf("\ncreate list first\n");
		return;
	}
	int d;
	printf("\ngive data:");
	scanf("%d",&d);
	//node* temp=head->next;
	node* newnode=(node*)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->prev=end;
	newnode->data=d;
	//temp->prev=newnode;
	end->next=newnode;
	end=newnode;
	count++;
	
	display();
}

void inPos(){
	if(head==NULL){
		printf("\ncreate list\n");
		return;
	}
	int key;
	printf("\nenter key to find:");
	scanf("%d",&key);
	if(find(key)){
		if(end==search)
			inLast();
		else{
			node* temp=search->next;
			node* newnode=(node*)malloc(sizeof(node));
			int d;
			printf("\ngive data for node:");
			scanf("%d",&d);
			newnode->data=d;
			newnode->next=temp;
			newnode->prev=search;
			search->next=newnode;
			temp->prev=newnode;
			
		}
		count++;
	}else{
		printf("\nnot found\n");
	}
	display();
}

void delFirst(){
	if(head==NULL){
		printf("\ncreate list first\n");
		return;
	}
	
	node* temp=head->next;
	head->next=temp->next;
	head->next->prev=NULL;
	free(temp);
	count--;
	display();
	
}

void isItThere(){
	if(head==NULL){
		printf("\ncreate list first\n");
		return;
	}
	int key;
	printf("\nenter data to find:");
	scanf("%d",&key);
	if(find(key))
		printf("\nfound\n");
	else
		printf("\n not found\n");
}
void delLast(){
	if(head==NULL){
		printf("\ncreate list first\n");
		return;
	}
	
	node* temp=end->prev;
	temp->next=NULL;
	end=temp;
	temp=end->next;
	free(temp);
	count--;
	display();
	
}

void delPos(){
	if(head==NULL){
		printf("\ncreate list first\n");
		return;
	}
	int key;
	printf("\nenter key to find:");
	scanf("%d",&key);
	if(find(key)){
		if(end==search)
			delLast();
		else{
			node* temp=search->prev;
			
			temp->next=search->next;
			temp->next->prev=temp;
			free(search);
			
		}
		count--;
	}else{
		printf("\nnot found\n");
	}
	display();

	
}

void getCount(){
	if(head==NULL){
		printf("\ncreate list first\n");
		return;
	}
	printf("count of nodes are %d",count);
}

void rev(){
	if(head==NULL){
		printf("\ncreate list first\n");
		return;
	}
	node* temp=end;
	while(temp->prev!=NULL){
		printf("%d\t",temp->data);
		temp=temp->prev;
	}	
	printf("NULL<--%d",temp->data);
}




