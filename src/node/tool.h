#ifndef TOOL_H
#define TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void free_user(User* user);

void free_contact(Contact * contact);
void find_user_by_name(char* keyname,Contact * con);

void write_to_db(Contact * con);
void read_db(Contact * con);
void bubble_sort(Contact * con);
#endif
