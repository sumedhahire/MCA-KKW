#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* head=NULL;
node* end=NULL;
node* beforeSearch=NULL;
node* search=NULL;
node* beforeEnd=NULL;
int count=0;


void display(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	
	node* temp=head->next;
	printf("\n-->");
	while(temp!=end){
		printf("%d-->",temp->data);
		beforeEnd=temp;
		temp=temp->next;
	}
	printf("%d-->",temp->data);
	
}

bool find(int key){
	node* temp=head->next;
	while(temp!=end){
		if(temp->data==key){
			search=temp;
			printf("\nelement found\n");
			return true;
	
		}else{
			beforeSearch=temp;
			temp=temp->next;
			
		}
	}
	if(end->data==key){
		search=temp;
		printf("\nelement found\n");
		return true;
		
	}else{
		printf("\nelement not found");
		return false;
	}
	
}

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
			newnode->next=head->next;
			end=newnode;
		}else{
			node* newnode=(node*)malloc(sizeof(node));
			end->next=newnode;
			printf("\ngive data for %dth node:",(i+1));
			scanf("%d",&d);
			newnode->data=d;
			newnode->next=head->next;
			end->next=newnode;
			end=newnode;
		}
		
		i++;
	}
	
	display();	
}

void inFirst(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	printf("\ngive data:");
	node* newnode=(node*)malloc(sizeof(node));
	scanf("%d",&newnode->data);
	newnode->next=head->next;
	end->next=newnode;
	head->next=newnode;
	
	count++;
	
	display();
}

void inLast(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	printf("\ngive data:");
	node* newnode=(node*)malloc(sizeof(node));
	scanf("%d",&newnode->data);
	newnode->next=head->next;
	end->next=newnode;
	end=newnode;
	
	count++;
	
	display();
}

void inPos(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	int key;
	printf("\ngive data to put after:");
	scanf("%d",&key);
	node* temp=head->next;
	
	if(find(key)){
		if(search==end){
			inLast();
			return;
		}else if(head->next->data==key){
			inFirst();
			return;
		}else{
			node* newnode=(node*)malloc(sizeof(node));
			printf("\nenter data:");
			scanf("%d",&newnode->data);
			newnode->next=search->next;
			search->next=newnode;
		}
	}
	
	count++;
	
	display();
}

void delFirst(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	
	end->next=head->next->next;
	node* temp=head->next;
	head->next=temp->next;
	temp->next=NULL;
	free(temp);
	
	count--;
	
	display();
}

void delLast(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	beforeEnd->next=head->next;
	end->next=NULL;
	node* temp=end;
	free(temp);
	end=beforeEnd;
	count--;
	
	display();
}

void delPos(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	int key;
	printf("\ngive data to put after:");
	scanf("%d",&key);
	node* temp=head->next;
	
	if(find(key)){
		if(search==end){
			delLast();
			return;
		}else if(head->next->data==key){
			delFirst();
			return;
		}else{
			beforeSearch->next=search->next;
			//search->next=temp->next;
			//temp->next=NULL;
			node* temp=search;
			temp->next=NULL;
			free(temp);
		}
	}
	
	count--;
	
	display();
}

void isItThere(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	
	int key;
	printf("\ngive data to find:");
	scanf("%d",&key);
	if(find(key)){
		display();
	}
}

void rev(){
	node *revHead=NULL;
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	
	node* start=head->next;
	node* prev=start;
	node* curr=prev->next;
	node* ahead=curr->next;
	
	while(ahead!=end){
		curr->next=prev;
		prev=curr;
		curr=ahead;
		ahead=curr->next;
	}
	curr->next=prev;
	ahead->next=curr;
	start->next=ahead;
	head->next=ahead;
	end=start;
	
	display();
}

void getCount(){
	if(count==0){
		printf("\ncreate list first\n");
		return;
	}
	
	printf("\nnode count is %d\n",count);
}
