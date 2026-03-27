#include <time.h>
#include <stdio.h>

#include "myfunc.h"

int main(){
srand(time(NULL));

int x;

printf("How many users do you want?\n");
scanf("%d",&x);
while( getchar()!='\n');

printf("Okay, it will be %d users.\n",x);


	User * head = NULL;
	create_link(&head,x);


	show_link(head);

free_link(&head);
return 0;

}	
