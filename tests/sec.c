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


//双向链表追加节点

Node * init_node(int id, char* name){

Node * node = (Node* ) malloc( sizeof(Node));
node->id =0;
node->name = "Bob";
node->next = NULL;
node->prev = NULL;
return node;
}


void insert_anyway( Node**head,int id){

printf("\033[35mNew node\033[0m\n");
	Node * curr = * head;
	//声明二级指针pphead来接收head指针的地址
	Node* ins = init_node(id,"opopop");

	if(curr==NULL){
		*head = ins;
		printf("Inserted into an empty list:Head\n");
		return;
		}

	while(curr!=NULL && strcmp(ins->name,curr->name)<0){
		//只要pphead这块地址指向的不是空，就循环到下一个节点
		curr = curr->next; // 让pphead指向下一个节点

}	//找到合适的点或结尾后
	ins->next =curr->next;// 目标节点的下一个节点挂在ins后面
	curr->next->prev =ins;	// 目标节点下个节点的prev指针指向ins
	curr->next = ins;//目标节点接入新节点
	ins->prev = curr;
return;
//应为传入的head地址没动，*head自动更新里后面的数据，

}


int main(){
printf("\n\033[32m*--------------------------*\033[0m\n");
Node* head = init_node(0,"head");
printf("ID:%d,\tName:%s\n",head->id,head->name);

insert_anyway(&head,2);
return 0;
}

