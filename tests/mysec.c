#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Node_ { 
int id;
char * name;
struct _Node_ * prev;
struct _Node_ * next;
} Node;

Node * init_node(int id, char* name){

Node * node = (Node* ) malloc( sizeof(Node));
node->id =id;
node->name = name;
node->next = NULL;
node->prev = NULL;
return node;
}


void insert_anyway( Node**head,int id){

	Node * curr = * head;
	Node* ins = init_node(id,"opo----pop");

	if(curr==NULL){
		*head = ins;
		printf("Inserted into an empty list:Head\n");
		return;
		}

	while(curr!=NULL && strcmp(ins->name,curr->name)<0){
		curr = curr->next; 
printf("\033[35mNew node\033[0m\n");
}
	ins->next =curr->next;
		if(curr->next!=NULL)curr->next->prev =ins;
	curr->next = ins;
	ins->prev = curr;

return;

}
void show(Node*head){

printf("----------------------------\n");
	while(head!=NULL){

printf("ID:%d,\tName:%s\n",head->id,head->name);
head= head->next;
}
printf("----------------------------\n");
}

int main(){
printf("\n\033[32m*--------------------------*\033[0m\n");
Node* head = init_node(0,"head");
printf("ID:%d,\tName:%s\n",head->id,head->name);

insert_anyway(&head,2);

show(head);
return 0;
}

