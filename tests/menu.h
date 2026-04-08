#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct User_ {
	int id;
	char * name;
	char * email;
	struct User_ * next;
	unsigned int flag;
}User;

typedef void ( * UserAction)(void*);

typedef struct _Userdata{
    struct User_ * self;
    UserAction create_user;
    UserAction create_contact;
    UserAction search_user;
    UserAction insert_user;
    UserAction delete_user;
    UserAction change_user;
}Userdata;

char * get_string(int num);

typedef enum{
	MODE_STRICT,
	MODE_CONFIRM,
	MODE_OPTIONAL
}InputMode;

typedef struct{
	char * label;
	int max_len;
	InputMode mode;
}FieldConfig;


#endif
