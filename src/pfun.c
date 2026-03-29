#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define NAMESIZE 16

typedef struct _node {
	int id;
	int data;
	char * name;
	struct _node * next;
}Node;

char * get_string(int size);
Node * create_node(int id);
void create_link(Node * * head, int num);
void free_node(Node * node);
void free_link(Node * * head);
void show_link(Node* head);

int main(){
	Node * head = NULL;
	create_link(&head,5);
	show_link(head);
	free_link(&head);
printf("Thanks for , Bye!\n");
return 0;
}

char * get_string( int size){
	//Create a node for a name
	char ch;
	char * name = (char*)malloc(size);
	if(name==NULL){
		printf("Error on input name!\n");
		return NULL;
	}
	int key = 0;
	while( key<size-1 && (ch=getchar())!='\n' && ch!=EOF){
		name[key] = ch;
		key++;
			}
	name[key] = '\0';
//Gemini , this part was the biggest problem for us, ring a bell?
if(ch!='\n' && ch!=EOF)
{	while(ch!='\n' && ch!=EOF);
}
return name;
}

Node* create_node(int id){
	printf("Here is the customer %d : \n",id);
	Node * node = (Node*)malloc(sizeof(Node));
	if(node==NULL){
	printf("Error while create a node\n");
	return NULL;
	}
	node->id = id;
	node->data = rand()%1000;
	printf("Choose a name(length<16):\n");
	
	node->name= get_string(NAMESIZE);
	node->next = NULL;

return node;
}

void create_link(Node* *head, int num){

	Node * phead = NULL;
	Node * tmp=NULL;

	int i;
for(i = 0; i<num; i++){

	Node* node = create_node(i);
		if(node==NULL) {
		printf("Not gooooooo\n");
		break;
}
	if(phead==NULL){
		phead = tmp = node;
	} else{
		tmp->next = node;
		tmp = tmp->next;
	}
}
*head = phead;
}

void show_link(Node * head){

printf("#-----------------------------#\n");
	while(head!=NULL){
		printf("Customer %d\t NAME:%s\t CODE:%d\t \n",head->id,head->name,head->data);
		head = head->next;
	}
printf("#-----------------------------#\n");
}


void free_node(Node * node){
	if(node==NULL) return;
	if(node->name) free(node->name);
	free(node);
}

void free_link(Node ** head){
	Node * tmp = NULL;
	tmp = * head;

	while( tmp!=NULL ){
	Node* curr = tmp ->next;
		free_node(tmp);
		tmp = curr;
	}

*head = NULL;
}
