#include "tool.h"

char* get_string(int string_size,char * n_type){
	int num=0;
	int letter;
	char* mystring = (char*)malloc(string_size);
	if(mystring ==NULL){
	printf("[error] : $s in %s \n",__func__,__FILE__);
	return NULL;
	}
	printf("Please input your %s:",n_type);
	while(num<string_size-1 && (letter=getchar())!='\n' && letter!=EOF){
	
	mystring[num] = letter;
	num++;
	}
	
	mystring[num] = '\0';

	if(letter!='\n' && letter!=EOF){
		while(		(letter = getchar())!='\n' && letter!=EOF);
	}

return mystring;
}

User * create_user(int id){
	User * user = (User*)malloc(sizeof(User));
	if(user==NULL){

	printf("[error] : $s in %s \n",__func__,__FILE__);
	return NULL;
	}
	user->id = id;
	user->data = rand()%1000;	
	user->username = get_string(Name_Size,"<username>");
	user->email = get_string(Mail_Size,"<email>");
	user->next = NULL;
printf("\n");
return user;
}

Contact * create_contact(int contact_count){
	User * phead = NULL;
	User * current = NULL;
	int i =0 ;

//--------create a contact node
Contact * contact = (Contact*)malloc(sizeof(Contact));
if(!contact){
	printf("Contact>>[error] : $s in %s \n",__func__,__FILE__);
	return NULL;
}

contact->index = (User **)malloc(sizeof(User*)*contact_count);


//-------------create the link for contact

	for(i=0;i<contact_count;i++){
		
	User* tmp = create_user(i);
	if(tmp ==NULL){
	
	printf("[error] : $s in %s \n",__func__,__FILE__);
	return NULL;
	}	
	contact->index[i] = tmp;

	if(phead==NULL){
		phead = current = tmp;
	}else{
	    current->next = tmp;
		current = current->next;
	}
}

contact->id = 0 ; //for now
contact->count = contact_count;
contact->head = phead;


return contact;
}


void show_contact(Contact *contact){
	if(!contact){
		printf("Something went wrong on contact!\n");
	}

int i=0;
	for(i=0;i<contact->count;i++){
		printf("ID:%d NAME:%s\t MAIL:%s\t DATA:%d\n",contact->index[i]->id,contact->index[i]->username,contact->index[i]->email,contact->index[i]->data);
		}
/*	
	User * head = contact->head;
	
	printf("You have %d contacts in ContactBook %d now:\n",contact->count,contact->id);
	while(head!=NULL){
	
		printf("ID:%d\t DATA:%5d\t NAME:%20s\t MAIL:%s\n",head->id,head->data,head->username,head->email);
		head=head->next;
	}
*/
printf("***The whole list of your contact!***\n");	
}
























