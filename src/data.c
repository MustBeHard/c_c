#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAMESIZE 20
#define USERNUM 6

typedef struct People_{

	int id; // random number
	int sort;
	char * username;
	struct People_ * previous;
	struct People_ * next;
}User;



char * get_name(int namesize);
char * get_phone(int numbersize);

//User * create_node(int sort);


//User * create_head(int sort);
//void create_link(User* *head,int usernum);
//void show_link(User* head);
//User* find_node //pausing, i am leaving for langing pointer of functions.....
//**************************************

int main(){
char * name;
char * phone;

char (* remote)(int);
char * router( char *(*remote)(int),char * label){
	printf("#------ Beginning to get %s ----------#\n", label);
	char * data = remote(20);
	return data;	
	}
name = router(get_name,"NAME");
phone = router(get_phone,"PHONE");
printf("%s : %s \n",name,phone);;
return 0;
}

//**************************************
char * get_name(int namesize){
	char * str = (char*)malloc(namesize);
	int i = 0;
	int ch=0;
	while((ch = getchar())!='\n' && ch!=EOF&&i<namesize-1){
		str[i] = ch;
		i++;
	}
str[i] = '\0';
return str;	
}

char * get_phone(int numbersize){

	char * num = (char*)malloc(numbersize);
	int i=0;
	int ch = 0;
	while((ch = getchar())!='\n' && ch!=EOF && i<numbersize-1){
		num[i] = ch;
		i++;
	}
num[i] = '\0';

if(i<12 && i > 7) {
	return num;
}else{
 num = "88880000";
return num;
}
}

 














