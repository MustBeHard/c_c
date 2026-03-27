#ifndef MYFUNC_H
#define MYFUNC_H

#include <stdlib.h>


typedef struct _User {
	int id;
	int data;
	char * username;
	char * email;
	struct _User * next;
}	User;

char * get_string(int str_size);
User * create_user(int id);
void create_link(User ** p, int linksize);

void free_user(User * node);
void free_link(User **head);
void show_link(User * p);

#endif


