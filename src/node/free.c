#include "tool.h"

void free_user(User* user){

	if(!user){
	printf("[ error ]>> free a node : %s in %s \n",__func__,__FILE__);
	exit -1;
	}
	if(user->username)	free(user->username);
	if(user->email)		free(user->email);
	
free(user);
}


void free_contact( Contact  * contact){

	if(!contact) 
	exit -1;

	User * phead =NULL;

	phead = contact->head;
	
	User * prev = phead;

	while(phead!=NULL){

		prev = phead->next;
		free_user(phead);
		phead = prev;
	}
//the contact is deleted.

	if(contact->index!=NULL){
	free(contact->index);
	}	
contact->id =0;
contact->count=0;
contact->head = NULL;
contact->index = NULL;

printf("WARNING: Your contact is closing!\n");
}

