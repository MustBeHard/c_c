#ifndef TOOL_H
#define TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Name_Size 16
#define Mail_Size 32

typedef struct _User{
	int id;
	int data;
	char * username;
	char * email ;
	struct _User * next;
}User;


typedef struct _Contact{
	int id;
	int count;
	struct _User * head;
	struct _User **index;
}Contact;


char* get_string(int string_size,char* n_type);

User * create_user(int id);

Contact *  create_contact(int caontact_count);

void show_contact(Contact * contact);

//void free_user(User* user);

//void free_contact(User **head);


#endif
