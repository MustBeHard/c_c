#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "myfunc.h"


#define USERNAMESIZE 20
#define EMAILSIZE 80



char * get_string(int str_size){
	char * tmp = (char*)malloc(str_size);
	int i=0;
	char ch;
	if(tmp==NULL)
		return NULL;

	while(i<str_size-1 && (ch = getchar())!='\n'){
		tmp[i] = ch;
		i++;
	}
	tmp[i] = '\0';
int garb;
if( (ch=getchar())!='\n' && ch!=EOF){
	while((garb = getchar())!='\n' && garb!=EOF);


}
return tmp;
}


User * create_user(int id){

	User * newuser = (User*)malloc(sizeof(* newuser));
	
	if(newuser == NULL){
		return NULL;
	}

	newuser->id = id;
	newuser->data = rand()%1000;
	printf("No. %d Choose your username:\n",id);
	newuser->username = get_string(USERNAMESIZE);
	printf("Sign up your email:\n");
	newuser->email = get_string(EMAILSIZE);
	
	newuser->next = NULL;

return newuser;
}

void create_link(User* *p,int linksize){
	int id;
	User * head=NULL;
	User * tail=NULL;

for(id=0;id<linksize;id++){
	User * node = create_user(id);
	if(node==NULL){
	printf("Error on create_user function: break!\n");
	break;
}
	if(head==NULL){
	head = tail = node;
	
	}else{

	tail->next = node;
	tail = tail->next;
	}
}	
*p = head;

}

void free_user(User* node){
	if (node ==NULL)
		return;
	// free every piece of memeory manully alloced	
	if(node->username)	free(node->username);
	if(node->email) free(node->email);
	free(node);
	
return;
}

void free_link(User **head){

		User * p=NULL;
		//since i quote address of the head pointer.
		p = *head;
		User * current=NULL;
		while(p!=NULL){
			current = p->next;
			free_user(p);
			p =current;
				
}
*head =NULL;
}

void show_link(User * head){

	while(head!=NULL){
		printf("ID: %d\t CODE: %d\t NAME: %s\t EMAIL:%s\n",head->id,head->data,head->username,head->email);
		head = head->next;
}

}

























