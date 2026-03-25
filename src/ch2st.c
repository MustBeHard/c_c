#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 20

typedef struct _Node{
	int id;
	int data;
	char * myname;
	struct _Node * next;
}Node;

char * get_str( int name_size){
	char * name_str = (char*) malloc(sizeof(char)* name_size);
	char tmp;
	int i = 0;
	printf("Get str from typeing:::::::::::\n");
	while((tmp = getchar())!='\n'&& i < name_size-1){
		name_str[i] = tmp;
		i++;
		}
	name_str[i] = '\0';
return name_str;
}

char * get_string(int namesize){
	char * namestr = (char*)malloc(sizeof(char)*namesize);
	char tmp;
	int i;
	printf("GET STRING:\n");
	for(i = 0; i<namesize-1 && (tmp = getchar())!='\n' ; i++){
		namestr[i] = tmp;
	}
	namestr[i] = '\0';
	return namestr;
}

// Create a node
Node * create_node(int sort){
	Node * tmp = NULL; //init a node;
	
	tmp = (Node*)malloc(sizeof(Node));
	if(!tmp){
		printf("#-- error while create memeory --#\n");
		return NULL;
	}
	tmp->id = sort;
	tmp->data = rand()%1000;
	tmp->myname = get_str(SIZE);
	tmp->next = NULL;

return tmp;
}

void create_link2(Node **p,int num){
// rewrite this in a dumb but my way.
Node * head = create_node(0);
Node * tmp = head;

for(int i = 1;i<num;i++){
	Node * p = create_node(i);
	tmp->next = p;
	tmp = tmp->next;
}
printf("The link2 has been created successfully!\n");
*p = head;

}

void create_link(Node** pp,int num){
	Node * head =NULL;		// this is working node
	Node * tail =NULL;		// first, they both point to the same 2nd leverl pointer

	for(int i=0;i<num;i++){
		Node* p = create_node(i);
		if(head == NULL){
			head=p;
			tail=p;
		}else{
		tail->next = p;
		tail = p;
		}

	}
*pp = head;


}

void show_link(Node* p){

	Node * node = p;
	while(node!=NULL){
		printf("%d: %s : %d \n",node->id,node->myname,node->data);
		node = node->next;

}
}

int main(){
srand(time(NULL));
char * str;
Node * head = NULL;

create_link2(&head,5);
show_link(head);

return 0;
}


